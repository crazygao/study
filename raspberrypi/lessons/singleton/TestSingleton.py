from Singleton import Singleton

class Test(metaclass=Singleton):
    def setit(self, value):
        self._value = value

    def getit(self):
        return self._value

a = Test()
a.setit(2)
b = Test()
print("Instance Value is {0}".format(b.getit()))
