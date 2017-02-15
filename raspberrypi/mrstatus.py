#!/usr/bin/env python

# Copyright 2015 - Mr.booker
# No restriction on distribution/modification of the source
# Info - This program is for PIR sensor. Contionusly checks for state,
#        set LED if movement detected and send the room status to HCP IoTMMS.

import RPi.GPIO as GPIO
import time
import urllib3
import datetime
import socket
import fcntl
import struct
import pytz

def get_ip_address(ifname):
    # raspberry pi get ip address from wlan0, this
    # http://stackoverflow.com/questions/24196932/how-can-i-get-the-ip-address-of-eth0-in-python
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    return socket.inet_ntoa(fcntl.ioctl(
        s.fileno(),
        0x8915,  # SIOCGIFADDR
        struct.pack('256s', ifname[:15])
        )[20:24])

# disable InsecureRequestWarning if your are working without certificate verification
# see https://urllib3.readthedocs.org/en/latest/security.html
# be sure to use a recent enough urllib3 version if this fails
try:
    urllib3.disable_warnings()
except:
    print('urllib3.disable_warnings() failed - get a recent enough urllib3 version to avoid potential InsecureRequestWarning warnings! Can and will continue though.')

# use with or without proxy
http = urllib3.PoolManager()
# http = urllib3.proxy_from_url('http://proxy_host:proxy_port')
# interaction for a specific Device instance - replace 1 with your specific Device ID
# url = 'https://iotmms_on_your_trial_system.hanatrial.ondemand.com/com.sap.iotservices.mms/v1/api/http/data/1'
# Steps to revive iotmms
# 1. goto hana cockpit start iotmms application, start
# 2. after start, open https://account.hanatrial.ondemand.com/cockpit#/acc/p1941731645trial/app/iotmms/dashboard
# 3. look up registered device and device types
# There is no easy way to get

# DATA SCHEME HERE:
# 1. url -> url for db
# 2. device ID + authorization -> table and user control
# DATA CONTAINS:
# 1. roomid -> KEY
# 2. status
url = 'https://iotmmsp1941731645trial.hanatrial.ondemand.com/com.sap.iotservices.mms/v1/api/http/data/'
deviceID = '0c51daaa-e145-4f28-90d6-a8fa90bbf190'

url = url +deviceID

headers = urllib3.util.make_headers()

# use with authentication
# please insert correct OAuth token
headers['Authorization'] = 'Bearer ' + '3e5d9eb25c40afe76fb9238c96d4b823'
headers['Content-Type'] = 'application/json;charset=utf-8'

# initial data status
roomid = '"APJ-CN-BJG-BJG07/16/16.04"'
status = 0
match_key2 = '0'

old_time = 0
has_ip_address = False
while has_ip_address == False:
    try:
        ipaddress = get_ip_address('eth0')
        has_ip_address = True
    except IOError:
        try:
            ipaddress = get_ip_address('wlan0')
            has_ip_address = True
        except IOError:
            # TODO: this is a status need to be double checked.
            # If there is no network, loop every two seconds.
            # There should be log on this
            time.sleep(2)

PIR = 7         # On-board pin number 7 (GPIO04)
LED = 11        # On-board pin number 11 (GPIO17)

val = False

GPIO.setmode(GPIO.BOARD)        # Change this if using GPIO numbering
GPIO.setup(PIR, GPIO.IN)        # Set PIR as input
GPIO.setup(LED, GPIO.OUT)       # Set LED as output

try:
    while True:
        val = GPIO.input(PIR)            # read input value
            if (val == True):                # check if the input is HIGH
                GPIO.output(LED, True)          # turn LED ON
                # ON
                timestamp = datetime.datetime.now(pytz.timezone('Asia/Shanghai')).strftime('%Y-%m-%dT%XZ')
                str_timestamp = '"'+timestamp+'"'
                printStr = 'Movement detected at ' + timestamp
                print (printStr)
                old_time = 0

                if (status == 0):
                    status = 1
                    stringStatus = str(status)
                    match_key1 = str (int (time.time() *100))

                    # send message of Message Type and the corresponding payload layout that you defined in the IoT Services Cockpit
                    body='{"messageType":"4844e19192bb3536ddb2","mode":"sync","messages":[{"timestamp":'
                    body = body+str_timestamp
                    body = body +',"roomid":'+roomid
                    body = body +',"status":'+stringStatus
                    body = body +',"matchkey1":'+match_key1
                    body = body +',"ipaddress":'+str(ipaddress)
                    body = body +',"matchkey2":'+match_key2+'}]}'

                    print (body)

                    r = http.urlopen('POST', url, body=body, headers=headers)
                    print(r.status)
                    print(r.data)
                    print ("")

                time.sleep(3)
                GPIO.output(LED, False)         # turn LED OFF
            else:
                GPIO.output(LED, False)         # turn LED OFF
                # OFF
                if (status == 1):
                    if (old_time == 0):
                        old_time = int (time.time() *100)
                            old_timestamp = datetime.datetime.now(pytz.timezone('Asia/Shanghai')).strftime('%Y-%m-%dT%XZ')
                    else:
                            current_time = int (time.time() *100)
                            diff = current_time - old_time
                            if (diff > 30000):
                                status = 0
                                timestamp =old_timestamp
                                str_timestamp = '"'+timestamp+'"'
                                stringStatus = str(status)
                                match_key2 = str (int (time.time() *100))

                                # send message of Message Type and the corresponding payload layout that you defined in the IoT Services Cockpit
                                body='{"messageType":"4844e19192bb3536ddb2","mode":"sync","messages":[{"timestamp":'
                                body = body+str_timestamp
                                body = body +',"roomid":'+roomid
                                body = body +',"matchkey1":'+match_key1
                                body = body +',"status":'+stringStatus
                                body = body +',"ipaddress":'+str(ipaddress)
                                body = body +',"matchkey2":'+match_key2+'}]}'

                                print (body)

                                r = http.urlopen('POST', url, body=body, headers=headers)
                                print(r.status)
                                print(r.data)
                                print ("");

except KeyboardInterrupt:
    GPIO.cleanup()
