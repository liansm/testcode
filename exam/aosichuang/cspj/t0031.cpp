#include <iostream>

class Node
{
public:
	int index;
	Node* left_node;
	Node* right_node;


	Node() {
		index = 0;
		left_node = nullptr;
		right_node = nullptr;
	}
};


void preorder_travel(Node* cur_node)
{
	if (cur_node == nullptr) {
		return;
	}

	std::cout << cur_node->index << " ";
	preorder_travel(cur_node->left_node);
	preorder_travel(cur_node->right_node);
}

void middleorder_travel(Node* cur_node)
{
	if (cur_node == nullptr) {
		return;
	}

	if(cur_node->left_node != nullptr){
		middleorder_travel(cur_node->left_node);
	}

	std::cout << cur_node->index << " ";

	if(cur_node->right_node != nullptr){
		middleorder_travel(cur_node->right_node);
	}
}

void postorder_travel(Node* cur_node)
{
	if (cur_node == nullptr) {
		return;
	}

	if (cur_node->left_node != nullptr) {
		postorder_travel(cur_node->left_node);
	}

	if (cur_node->right_node != nullptr) {
		postorder_travel(cur_node->right_node);
	}

	std::cout << cur_node->index << " ";
}

int main()
{
	int n;
	std::cin >> n;

	Node* pNodeList = new Node[n];
	for (int i = 0; i < n; ++i) {
		pNodeList[i].index = i+1;
	}

	for (int i = 0; i < n; ++i) {
		int left_index, right_index;
		std::cin >> left_index >> right_index;

		if (left_index != 0) {
			pNodeList[i].left_node = &(pNodeList[left_index - 1]);
		}

		if (right_index != 0) {
			pNodeList[i].right_node = &(pNodeList[right_index - 1]);
		}
	}

	Node * root_node = nullptr;
	if (n > 0) {
		root_node = &(pNodeList[0]);
	}

	preorder_travel(root_node);
	std::cout << std::endl;

	middleorder_travel(root_node);
	std::cout << std::endl;

	postorder_travel(root_node);
	std::cout << std::endl;

}
