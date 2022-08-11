class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None
    
    def insert(self, data):
        if(not self.root):
            self.root = Node(data)
            return
        q=[]
        q.append(self.root)
        index = 0
        while(1):
            temp = q[index]
            index+=1
            if(not temp.left):
                temp.left = Node(data)
                break
            else:
                q.append(temp.left)
            
            if not temp.right:
                temp.right = Node(data)
                break
            else:
                q.append(temp.right)
        
    def inorder_traverse(self, node):
        if(node):
            self.inorder_traverse(node.left)
            print(node.data,end=',')
            self.inorder_traverse(node.right)


    def inorder(self):
        self.inorder_traverse(self.root)
    

    def postorder_traverse(self, node):
        if(node):
            self.postorder_traverse(node.left)
            self.postorder_traverse(node.right)
            print(node.data,end=',')
    
    def postorder(self):
        self.postorder_traverse(self.root)

    def preorder_traverse(self, node):
        if(node):
            print(node.data,end=',')
            self.preorder_traverse(node.left)
            self.preorder_traverse(node.right)
    
    def preorder(self):
        self.preorder_traverse(self.root)

  
    # function to delete element in binary tree
    def deletion(self,root, key):
        if root == None :
            return None
        if root.left == None and root.right == None:
            if root.key == key :
                return None
            else :
                return root
        key_node = None
        q = []
        q.append(root)
        temp = None
        parent = None
        while(len(q)):
            temp = q.pop(0)
            if temp.data == key:
                key_node = temp
            if temp.left:
                parent = temp
                q.append(temp.left)
            if temp.right:
                parent = temp
                q.append(temp.right)
        if key_node :
            x = temp.data
            if parent.right:
                parent.right = None
            else:
                parent.left = None
            key_node.data = x
        return root

    def delete(self,key):
        self.deletion(self.root, key)
  





if __name__ == '__main__':
    root = BinaryTree()
    data = [1,2,3,4,5,6]
    for i in data:
        root.insert(i)
    root.inorder()
    # print("\n")
    # root.postorder()
    # print("\n")
    # root.preorder()
    root.delete(2)
    print('\n')
    root.inorder()





