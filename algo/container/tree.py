import random

class Node:
    def __init__(self, number) :
        self.left_node = None
        self.right_node = None
        self.number = number

class Tree:
    def __init__(self) :
        self.head_node = None

    def insert(self, number):
        new_node = Node(number)       
        if self.head_node == None:
            self.head_node = new_node
            return

        node_list = []
        node_list.append(self.head_node)
        while len(node_list) != 0:
            cur_node = node_list.pop(0)
            if cur_node.left_node == None:
               cur_node.left_node = new_node
               return
            else:
                node_list.append(cur_node.left_node)

            if cur_node.right_node == None:
                cur_node.right_node = new_node
                return
            else:
                node_list.append(cur_node.right_node)

    def print_tree(self):
        if self.head_node == None:
            return

        node_list = []
        node_list.append(self.head_node)

        while len(node_list) != 0:
            cur_node = node_list.pop(0)
            print(cur_node.number)
            if cur_node.left_node != None:
                node_list.append(cur_node.left_node)
            if cur_node.right_node != None:
                node_list.append(cur_node.right_node)


def test_tree():  
    my_tree = Tree()          
    for idx in range(0, 20):
        val = random.randint(0, 1000)
        print(val)
        my_tree.insert(val)

    print('-------------------------')
    my_tree.print_tree()

test_tree()

