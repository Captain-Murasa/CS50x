from jar import Jar


def test_init():
    jar = Jar()
    assert jar.capacity == 12
    jar = Jar(40)
    assert jar.capacity == 40
    assert jar.size == 0


def test_str():
    jar = Jar()
    assert str(jar) == ""
    jar.deposit(1)
    assert str(jar) == "🍪"
    jar.deposit(11)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪"


def test_deposit():
    jar = Jar()
    assert jar.size == 0
    jar.deposit(5)
    assert jar.size == 5
    jar.deposit(3)
    assert jar.size == 8


def test_withdraw():
    jar = Jar()
    jar.deposit(12)
    jar.withdraw(3)
    assert jar.size == 9
    jar.withdraw(7)
    assert jar.size == 2
    jar.withdraw(2)
    assert jar.size == 0