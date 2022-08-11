class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
  
    def add_at_begin(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node
    
    def add_at_end(self,data):
        temp = self.head
        if(temp is None):
            self.head = Node(data)
            return
        while(temp.next):
            temp = temp.next
        temp.next = Node(data)

    def print_list(self):
        temp = self.head
        while(temp):
            print(temp.data,end=',')
            temp = temp.next


if __name__=='__main__':
    n = int(input("enter the length:"))
    llist = LinkedList()
    for i in range(n):
        llist.add_at_end(int(input("enter the num: ")))
    
    llist.print_list()
