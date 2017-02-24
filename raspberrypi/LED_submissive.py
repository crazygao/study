#import configparser

class LED_submissive:
    """ LED is an indicator for your room status,
    mainly for debugging """
    def __self__(self, GPIO_LED):
        """ read LED configure from file """
        # GPIO.setup()
        # if error raise exception "Device Not Ready"
        self.status = false
        return self.status

    def turn_on(self):
        """ turn on LED """
        # GPIO.output
        # if error raise exception
        self.status = true
        return self.status

    def turn_off(self):
        """ turn off LED """
        # GPIO.output
        self.status = false
        return self.status

    def status(self):
        """ return current status of LED"""
        return self.status
