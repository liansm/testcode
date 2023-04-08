# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None


#Function to return a list containing elements of left view of the binary tree.
def LeftView(root):
    
    node_list = []
    node_list.append(root)
    node_list.append(None)
    left_node_view = []
    left_node_view.append(root)
    while len(node_list) != 0:
        cur_node = node_list.pop(0)
        if cur_node == None:
            if len(node_list) > 0:
                node_list.append(None)
                left_node_view.append(node_list[0])
        else:
            if cur_node.left != None:
                node_list.append(cur_node.left)
        
            if cur_node.right != None:
                node_list.append(cur_node.right)
            
    return left_node_view        
    # code here


#{ 
 # Driver Code Starts
#Contributed by Sudarshan Sharma
from collections import deque
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root
    
    
if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        result = LeftView(root)
        for value in result:
            print(value,end=" ")
        print()

# } Driver Code Ends