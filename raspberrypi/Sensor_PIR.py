import RPi.GPIO as GPIO
import ConfigParser
import threading
from Data_Shared import Data,Data_Shared
from Singleton import get_time

class Sensor_PIR(threading.Thread):
    """ Class for a PIR Sensor, it need a thread to make it run and loop.
    We perspect on every edge of PIR, however every pulse less than X seconds
    should not be treated as a valid pulse.

    Threading
    """
    _status = 0

    def __init__(self, GPIO_PIR):
        """
        Initialize of PIR, start a PIR thread, should not be controlled.
        GPIO_PIR        - PIR port on the board
        pulse_length    - pulse length long enough to be recognized as a valid motion. in seconds
        """
        threading.Thread.__init__(self)
        self.threadID = "PIR"
        GPIO.setup(GPIO_PIR, GPIO.IN)

    def run():
        """ This is a threaded entrance
        Old Polling method"""
        while True:
            cur_PIR = GPIO.input(GPIO_PIR)
            if self._status != cur_PIR:
                self._status = cur_PIR
                data = new Data_Shared.Data(
                    timestamp = get_time('Asia/Shanghai'),
                    status = PIR)
                Data_Shared().put(data)
            time.sleep(3)
        pass

    def _onChange():
        data = new Data_Shared.Data(
            timestamp = get_time('Asia/Shanghai'),
            status = PIR)
        Data_Shared().put(data)

    def _onEdgeUp():
        """
        data to be transferred on edge up.
        """
        _onChange()
        pass

    def _onEdgeDown():
        """
        data to be transferred on edge down.
        """
        _onChange()
        pass


