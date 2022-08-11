
    def convertToInt(self,node):
        str1 =""
        while(node):
            str1 = str(node.data)+str1
        return int(str1)
    
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        value = self.convertToInt(l1)+self.convertToInt(l2)
        strval = str(value)
        root = None
        for i in strval:
            if root==None:
                root=ListNode(int(i))
                continue
            temp = ListNode(int(i))
            temp.next = root
            root = temp
        return root

if __name__=='__main__':
    n = int(input("enter the length:"))
    llist = LinkedList()
    for i in range(n):
        llist.add_at_end(int(input("enter the num: ")))
    
    llist.print_list()
