class MyClass:
    
    def __init__(self, data):
        self.value = data
        
        
    def MyPrint(self):
        print("my data : ", self.value)
        
t = MyClass([1,2,3])

t.MyPrint()