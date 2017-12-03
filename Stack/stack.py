class Stack:

    def __init__(self):
        """ initializes a list """
        self.a = []


    def push(self, element):
        """ adds element in the stack """
        self.a.append(element)


    def __len__(self):
        """ gives length of stack """
        return len(self.a)

    def is_empty(self):
        """ checks if stack is empty """
        if(len(self.a)==0):
            return True
        else:
            return False


    def pop(self):
        """ Removes element from the stack """
        if not self.is_empty():
           return self.a.pop()
        else:
            print("Stack is empty.")


    def peek(self):
        """ returns the topmost element from the stack """
        if not self.is_empty():
            l = len(self.a)
            element = self.a[l-1]
            return element
        else: 
            print("Stack is empty")

   
s =Stack()
s.push(2)
s.push(14)
print("length is {}".format(s.__len__()))
print("element removed from stack is {}".format(s.pop()))
print("length after pop is {}".format(s.__len__()))
print("topmost element is {}".format(s.peek()))
print("element removed is {}".format(s.pop()))
print("topmost element is {}".format(s.peek()))
