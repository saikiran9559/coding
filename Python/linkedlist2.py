class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SingleLinkedList:
    def __init__(self):
        self.head = None
        self.length=0
    
    def add_at_begin(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node
        self.length +=1

    def add_at_end(self, data):
        node = Node(data)
        temp = self.head
        if(temp == None):
            self.head = node
            self.length +=1
            return
        while(temp.next):
            temp = temp.next
        temp.next = node
        self.length +=1
    
    def add_after(self, data, after):
        temp = self.head
        if(after==-1):
            self.add_at_begin(data)
            return
        for i in range(after):
            temp = temp.next
        node = Node(data)
        nextone = temp.next
        node.next = nextone
        temp.next = node
        self.length+=1
    
    def delete_node(self, index):
        temp = self.head
        if(index==0):
            self.head = temp.next
            return
        for i in range(index-1):
            temp = temp.next
        temp.next = temp.next.next

    def get_len_recursive(self, node):
        if(not node):
            return 0
        else:
            node = node.next
            return 1+self.get_len_recursive(node)

    def get_count(self):
        return self.get_len_recursive(self.head)
    
    def swap_nodes(self, index1, index2):
        first_node = None
        temp = self.head
        if(index1>0):
            for i in range(index1-1): 
                temp = temp.next
            first_node = temp
            first_after_node = first_node.next
        for i in range(index2-index1-1):
            temp = temp.next
        last_node = temp
        after_node = last_node.next.next
        if(not first_node):
            temp = self.head
            self.head = last_node.next
            self.head.next = temp.next
            last_node.next = temp
            temp.next = after_node
            return
        first_node.next = last_node.next
        first_node.next.next = after_node
        last_node.next = first_after_node
        first_after_node = after_node.next
    
    def reverse_array(self):
        current = self.head
        prv = None
        nxt = None
        while(current):
            nxt = current.next
            current.next = prv
            prv = current
            current = nxt
        self.head = prv
    
    def merge_lists(temp):
        if(temp==None):
            print("empty array")

        while(temp):
            print(temp.data,end='->')
            temp = temp.next
        print("\n")


        
            

    def print_array(self):
        temp = self.head
        if(temp==None):
            print("empty array")

        while(temp):
            print(temp.data,end='->')
            temp = temp.next
        print("\n")


if __name__ == '__main__':
    head = SingleLinkedList()
    head.add_at_begin(4)
    head.add_at_begin(6)
    head.add_at_begin(9)
    head.add_at_begin(10)
    head.add_at_begin(22)
    head.print_array()
    head.reverse_array()
    SingleLinkedList.merge_lists(head)
    head.print_array()
    # while(1):
    #     print("1.print 2.add at begin 3.add at end 4.add after 5.add_before 6.delete node 7.get_len")
    #     ch = int(input("option :"))
    #     if(ch==1):
    #         head.print_array()
    #     elif(ch==2):
    #         head.add_at_begin(int(input("enter the number:")))
    #     elif ch==3:
    #         head.add_at_end(int(input("enter the number: ")))
    #     elif ch==4:
    #         after = int(input("after:"))
    #         if(after < 0 or after >= head.length):
    #             print("invalid index")
    #             continue
    #         head.add_after(int(input("enter num: ")), after)
    #     elif ch==5:
    #         before = int(input("before :"))
    #         if(before < 0 or before >= head.length):
    #             print("invalid index")
    #             continue
    #         head.add_after(int(input("enter num: ")), before-1)
    #     elif ch==6:
    #         index = int(input("index:"))
    #         if(index < 0 or index >= head.length):
    #             print("invalid index")
    #             continue
    #         head.delete_node(index)
    #     elif ch==7:
    #         print(head.get_count() , "is the length")
        
    #     elif ch==8:
    #         head.swap(nodes)
    #     else:
    #         print('invalid option')

