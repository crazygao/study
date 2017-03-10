import json
import ConfigParser
import urllib3
from Data_Shared import Data,Data_Shared
from Singleton import Singleton

try:
    urllib3.disable_warnings()
except:
    print('urllib3.disable_warnings() failed \
    	- get a recent enough urllib3 version \
    	to avoid potential InsecureRequestWarning warnings! \
    	Can and will continue though.')

# use with or without proxy
http = urllib3.PoolManager()

# python3 type singleton
# python2 class Gen_Request()
#                 __metaclass__ = Singleton
class Gen_Request(metaclass=Singleton):
    """
    Class for make http request
    Singleton
    """
    self._basemessage = {
		"messageType": "4844e19192bb3536ddb2",
		"mode":"sync",
		"messages": [
			{
				"timestamp": "000000"
				"roomid": "000000" # Config
				"status": "1" # Config
				"ipaddress": "255.255.255.255"
				"matchkey1": "123456"
				"matchkey2": "0"
			}
		]
    }

    self._deviceID = '0c51daaa-e145-4f28-90d6-a8fa90bbf190'
    self._url = "https://iotmmsp1941731645trial.hanatrial.ondemand.com/com.sap.iotservices.mms/v1/api/http/data/" + self._deviceID
    
    self._headers = urllib3.util.make_headers()
	self._headers['Authorization'] = 'Bearer ' + '3e5d9eb25c40afe76fb9238c96d4b823'
	self._headers['Content-Type'] = 'application/json;charset=utf-8'

	self._last_timestamp = 0

    def __init__(self):
    	"""
    	Get Configuration from config file
    	Configure urllib3
    	"""

    	while (new_Data = Data_Shared().get())
    		self.DBMessage(new_Data)
    		self._last_timestamp = new_Data.timestamp



    def DBMessage(self, Data):
    	"""
    	Post message
    	"""
