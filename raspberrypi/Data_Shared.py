import Queue

class Data:
    """
    Formal data scheme transferred between
    sensor thread to HTTP thread.
    """
    def __self__(self, **kwargs):
        self._timestamp = kwargs["timestamp"]
        self._status = kwargs["status"]
    pass

class Data_Shared:
    """
    Queue in python: https://docs.python.org/2/library/queue.html
    Use it for a thread-safe data structrue for sensor data
    """
    def __self__(self):
        self._queue = Queue()

    def put(self, data_obj, *args):
        """
        Same put method in queue

        Example 1, for non-blocking put
        data_shared.put(data, False)
        Example 2, for block but timeout put
        data_shared.put(data, True, 1)
        Example 3, for ever-block put
        data_shared.put(data, True)
        """
        if isinstance(data_obj, Data):
            try:
                self._queue.put(data_obj, *args)
                return true
            except Queue.Full:
                # Error Log here
                return false
        else
            # Error Log or Log
            return false

    def get(self):
        """
        Blocking Get, return a item
        """
        return self._queue.get(True)

    def dump(self):
        """
        Dump the queue to output or somewhere else?
        """
        pass

    pass
