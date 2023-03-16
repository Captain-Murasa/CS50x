class Jar:
    def __init__(self, capacity=12):
        if type(capacity) != int or capacity < 0:
            raise ValueError("Invalid number.")
        self._capacity = capacity
        self.cookies = 0

    def __str__(self):
        return '🍪' * self.cookies

    def deposit(self, n):
        if type(n) != int or n < 0 or n + self.cookies > self.capacity:
            raise ValueError("Invalid number.")
        self.cookies += n

    def withdraw(self, n):
        if type(n) != int or n < 0 or self.cookies < n:
            raise ValueError("Invalid number.")
        self.cookies -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self.cookies