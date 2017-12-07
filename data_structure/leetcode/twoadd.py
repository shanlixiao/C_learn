class Node():
    def __init__(self,x):
        self.val = x
        self.next = None
    def getNext(self):
        return self.next
    def getVal(self):
        return self.val
    def setVal(self,newval):
        self.val = newval
    def setNext(self,newnext):
        self.next = newnext
# class Solution():
#     def addTwoNumbers(self,l1,l2):
#         while(l1)




class List():
    def __init__(self):
        self.head = None
        self.length = 0
    def isempty(self):
        return self.length == 0
    #逆序在链表头部插入
    def add(self,item):
        temp = Node(item)
        temp.next = self.head;
        self.head = temp
        self.length += 1
    def append(self,item):
        if self.length == 0:
            self.head = Node(item)
            current = self.head
            current.next = None
            self.length += 1
        else:
            current = self.head
            while current.next != None:
                current = current.next
            current.next = Node(item)
            self.length += 1
            current = current.next
            current.next = None
    def show(self):
        current = self.head
        while current != None:
            print("current.val = %d" % current.val)
            current = current.getNext()

List1 = List()
# List1.add(1)
for i in range(10):
    List1.add(i)
for i in range(10):
    List1.append(i)
List1.show()
