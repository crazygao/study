# MAX_SIZE = 5000
# import queue
class LRUCache:
    def __init__(self, capacity: int):
        self._capacity = capacity
        self._cur_capacity = 0
        self.values = {} # key -> value
        self.sequence = [] # queue of key
    def get(self, key: int) -> int:
        value = self.values.get(key, -1)
        if value != -1:
            self._set_high_sequence(key)

    def _delete_lease_used(self) -> int:
        key = self.sequence[self._capacity]
        del self.values[key]
        del self.sequence[self._capacity]
        pass

    def _set_high_sequence(self, key: int) -> int:
        index = 0
        for index in range(0, self._capacity):
            if (self.sequence[index] == key):
                del self.sequence[index]
                break
        self.sequence = [key, *self.sequence]
    
    def put(self, key: int, value: int) -> None:
        # key not valid(bypass)
        # over capacity
        if self.values.get(key, -1) == -1 and self._cur_capacity >= self._capacity:
            self.values[key] == value
            self.sequence = [key, *self.sequence]
            # one item over delete it
            self._delete_lease_used()
        # set value, set sequence
        if self.values.get(key, -1) == -1 and self._cur_capacity < self._capacity:
            self.values[key] == value
            self.sequence = [key, *self.sequence]
            self._cur_capacity = self._cur_capacity + 1
        if self.values.get(key, -1) != -1:
            self.values[key] == value
            self._set_high_sequence(key)

if __name__ == "__main__":
    lruCache = LRUCache(2)
    lruCache.put(1, 1)
    lruCache.put(2, 2)
    lruCache.get(1)
    lruCache.put(3, 3)
    