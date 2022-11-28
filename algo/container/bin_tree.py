
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

    def traverse(self, cur_node):
        if cur_node.right_child != None:
            self.traverse(cur_node.right_child)

        if cur_node != None:
            print(cur_node.key)

        if cur_node.left_child != None:
            self.traverse(cur_node.left_child)     

    def print(self):
        self.traverse(self.head_node)


def test_tree():  
    bin_tree = BinTree()          
    for idx in range(0, 20):
        key = random.randint(0, 1000)
        value = random.randint(10000, 20000)
        print(key)
        bin_tree.insert(key, value)

    print('-------------------------')
    bin_tree.print()

test_tree()
