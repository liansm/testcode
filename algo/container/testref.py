

class TestStruct:
    def __init__(self, val) -> None:
        self.val = val

    def add(self, delta):
        self.val += delta

    def getVal(self):
        return self.val

def TestFunc(val):
    val.add(30)


ts = TestStruct(30)
print(ts.getVal())

ts2 = TestStruct(70)

TestFunc(ts)
print(ts.getVal())
print(ts2.getVal())


ts = ts2
print(ts.getVal())


