import RPi.GPIO as GPIO
import ConfigParser
import threading

class Sensor_PIR(threading.Thread):
    """ Class for a PIR Sensor, it need a thread to make it run and loop.
    We perspect on every edge of PIR, however every pulse less than X seconds
    should not be treated as a valid pulse.

    Threading
    """
    def __self__(self, GPIO_PIR, pulse_length):
        """
        Initialize of PIR, start a PIR thread, should not be controlled.
        GPIO_PIR        - PIR port on the board
        pulse_length    - pulse length long enough to be recognized as a valid motion.
        """
        threading.Thread.__init__(self)
        self.threadID = "PIR"
        self._pulse_length = pulse_length
        GPIO.setup(GPIO_PIR, GPIO.IN)

    def run():
        """ This is a threaded entrance """
        pass

    def _onEdgeUp():
        """
        data to be transferred on edge up.
        """
        new Data
        pass

    def _onEdgeDown():
        """
        data to be transferred on edge down.
        """
        pass

    def _sendData():
        pass

