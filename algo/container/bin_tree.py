
import random

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left_child = None
        self.right_child = None

    
class BinTree:
    def __init__(self):
        self.head_node = None

    def insert(self, key, value):
        new_node = Node(key, value)
        if self.head_node == None:
            self.head_node = new_node
            return

        cur_node = self.head_node
        while True :
            if cur_node.key > key:
                if cur_node.right_child != None:
                    cur_node = cur_node.right_child
                elif cur_node.right_child == None:
                    cur_node.right_child = new_node
                    return

            elif cur_node.key < key:
                if cur_node.left_child != None:
                    cur_node = cur_node.left_child
                elif cur_node.left_child == None:
                    cur_node.left_child = new_node
                    return    

            elif cur_node.key == key:
                return
    
    def find(self, key):
        cur_node = self.head_node
        while True:
            if cur_node.key > key:
                if cur_node.right_child == None:
                    return None
                cur_node = cur_node.right_child
            elif cur_node.key < key:
                if cur_node.left_child == None:
                    return None
                cur_node = cur_node.left_child
            elif cur_node.key == key:
                    return cur_node.value
    
    def print(self):
        self.traverse(self.head_node)

    def traverse(self, cur_node):
        if cur_node.right_child != None:
            self.traverse(cur_node.right_child)

        if cur_node != None:
            print(cur_node.key)

        if cur_node.left_child != None:
            self.traverse(cur_node.left_child)     

    def find_rightest_node(self, cur_node):
        rightest_node_parent = None
        while cur_node.right_child != None:
            rightest_node_parent = cur_node
            cur_node = cur_node.right_child
        return cur_node, rightest_node_parent

    def find_leftest_node(self, cur_node):
        leftest_node_parent = None
        while cur_node.left_child != None:
            leftest_node_parent = cur_node
            cur_node = cur_node.left_child
        return cur_node, leftest_node_parent       

    def adjust(self, parent_node, cur_node, new_node):
        if parent_node != None and parent_node.left_child == cur_node:
            parent_node.left_child = new_node
        elif parent_node != None and parent_node.right_child == cur_node:
            parent_node.right_child = new_node

        new_node.left_child = cur_node.left_child
        new_node.right_child = cur_node.right_child
        cur_node.left_child = None
        cur_node.right_child = None


    def remove(self, key):
        cur_node = self.head_node
        parent_node = None
        while True:
            if cur_node.key > key:
                if cur_node.right_child == None:
                    return None
                parent_node = cur_node
                cur_node = cur_node.right_child
            elif cur_node.key < key:
                if cur_node.left_child == None:
                    return None
                parent_node = cur_node
                cur_node = cur_node.left_child
            elif cur_node.key == key:
                if cur_node.left_child == None and cur_node.right_child == None:
                    if cur_node == self.head_node:
                        self.head_node = None

                    if parent_node.left_child == cur_node:
                        parent_node.left_child = None
                        return
                    elif parent_node.right_child == cur_node:
                        parent_node.right_child = None
                        return
                elif cur_node.left_child != None:
                    if cur_node.left_child.right_child == None:
                       self.adjust(parent_node, cur_node, cur_node.left_child)   
                       return                  
                    rightest_node, rightest_node_parent = self.find_rightest_node(cur_node.left_child)   
                    rightest_node_parent.left_child = rightest_node.right_child
                    self.adjust(parent_node, cur_node, rightest_node)     
                    if cur_node == self.head_node:
                        self.head_node = rightest_node
                    return    

                elif cur_node.right_child != None:
                    if cur_node.right_child.left_child == None:
                        self.adjust(parent_node, cur_node, cur_node.right_child)
                        return
                    
                    leftest_node, leftest_node_parent = self.find_leftest_node(cur_node.right_child)   
                    leftest_node_parent.right_child = leftest_node.left_child
                    self.adjust(parent_node, cur_node, leftest_node)    
                    if cur_node == self.head_node:
                        self.head_node = leftest_node_parent  
                    return           


def test_tree():  
    bin_tree = BinTree()          
    for idx in range(0, 20):
        key = random.randint(0, 1000)
        value = random.randint(10000, 20000)
        print(key , value)
        bin_tree.insert(key, value)

    print('-------------------------')
    bin_tree.print()

    s_val = int(input("input the val:"))
    print("the answer is" , bin_tree.find(s_val))

test_tree()
