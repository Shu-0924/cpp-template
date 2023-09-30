#include <iostream>
using namespace std;

struct Node {
	int value = 0;
	int left_descendant = 1;
	int appear = 1;
	Node* parent = nullptr;
	Node* left_child = nullptr;
	Node* right_child = nullptr;
};
Node BIT[500005];
Node* root = nullptr;
int full = 0;

void LL(Node* pivot) {
	Node* new_pivot = pivot->left_child;
	Node* temp_node = new_pivot->right_child;
	pivot->left_descendant -= new_pivot->left_descendant;
	if (temp_node == nullptr) {
		pivot->left_height = 0;
	}
	else {
		pivot->left_height = max(temp_node->left_height, temp_node->right_height) + 1;
	}
	new_pivot->right_height = max(pivot->left_height, pivot->right_height) + 1;
	new_pivot->right_child = pivot;
	pivot->left_child = temp_node;
	if (temp_node != nullptr) {
		temp_node->parent = pivot;
	}
	if (pivot == root) {
		root = new_pivot;
		new_pivot->parent = nullptr;
		pivot->parent = new_pivot;
	}
	else {
		if (pivot->parent->left_child == pivot) {
			pivot->parent->left_child = new_pivot;
		}
		else {
			pivot->parent->right_child = new_pivot;
		}
		new_pivot->parent = pivot->parent;
		pivot->parent = new_pivot;
	}
}
void RR(Node* pivot) {
	Node* new_pivot = pivot->right_child;
	Node* temp_node = new_pivot->left_child;
	new_pivot->left_descendant += pivot->left_descendant;
	if (temp_node == nullptr) {
		pivot->right_height = 0;
	}
	else {
		pivot->right_height = max(temp_node->left_height, temp_node->right_height) + 1;
	}
	new_pivot->left_height = max(pivot->left_height, pivot->right_height) + 1;
	new_pivot->left_child = pivot;
	pivot->right_child = temp_node;
	if (temp_node != nullptr) {
		temp_node->parent = pivot;
	}
	if (pivot == root) {
		root = new_pivot;
		new_pivot->parent = nullptr;
		pivot->parent = new_pivot;
	}
	else {
		if (pivot->parent->left_child == pivot) {
			pivot->parent->left_child = new_pivot;
		}
		else {
			pivot->parent->right_child = new_pivot;
		}
		new_pivot->parent = pivot->parent;
		pivot->parent = new_pivot;
	}
}
void LR(Node* pivot) {
	RR(pivot->left_child);
	LL(pivot);
}
void RL(Node* pivot) {
	LL(pivot->right_child);
	RR(pivot);
}


void Insert(int num) {
	if (root == nullptr) {
		full = 0;
		root = &BIT[full];
		BIT[full++].value = num;
		return;
	}

	bool change = 0;
	Node* now = root;
	Node* parent = nullptr;
	while (now != nullptr) {
		if (num < now->value) {
			now->left_descendant++;
			parent = now;
			now = now->left_child;
			if (now == nullptr) {
				BIT[full].value = num;
				BIT[full].parent = parent;
				if (parent->left_child == nullptr && parent->right_child == nullptr) {
					change = 1;
				}
				now = &BIT[full++];
				parent->left_child = now;
				break;
			}
		}
		else if (num > now->value) {
			parent = now;
			now = now->right_child;
			if (now == nullptr) {
				BIT[full].value = num;
				BIT[full].parent = parent;
				if (parent->left_child == nullptr && parent->right_child == nullptr) {
					change = 1;
				}
				now = &BIT[full++];
				parent->right_child = now;
				break;
			}
		}
		else {
			now->left_descendant++;
			now->appear++;
			break;
		}
	}
	if (change == 1) {
		Node* pivot = nullptr;
		while (now != root) {
			if (now->parent->left_child == now) {
				now->parent->left_height++;
				now = now->parent;
				if (now->left_height == now->right_height) {
					break;
				}
				else if (now->left_height - now->right_height > 1) {
					pivot = now;
					break;
				}
			}
			else {
				now->parent->right_height++;
				now = now->parent;
				if (now->left_height == now->right_height) {
					break;
				}
				else if (now->left_height - now->right_height < -1) {
					pivot = now;
					break;
				}
			}
		}
		if (pivot != nullptr) {
			if (pivot->left_height > pivot->right_height) {
				if (pivot->left_child->left_height > pivot->left_child->right_height) {
					LL(pivot);
				}
				else {
					LR(pivot);
				}
			}
			else {
				if (pivot->right_child->left_height > pivot->right_child->right_height) {
					RL(pivot);
				}
				else {
					RR(pivot);
				}
			}
		}
	}
	else {
		if (now == root) {
			return;
		}
		if (now->parent->left_child == now) {
			now->parent->left_height++;
		}
		else {
			now->parent->right_height++;
		}
	}
}

int Find_number(int index) {
	index++;
	int accumulate = 0;
	Node* now = root;
	while (now != nullptr) {
		if (index <= now->left_descendant + accumulate - now->appear) {
			now = now->left_child;
		}
		else if (index > now->left_descendant + accumulate) {
			accumulate += now->left_descendant;
			now = now->right_child;
		}
		else {
			return now->value;
		}
	}
	return -1;
}

int The_number_of_node_smaller_than_or_equal_to(int num) {
	Node* now = root;
	int counting = 0;
	while (now != nullptr) {
		if (num < now->value) {
			now = now->left_child;
		}
		else if (num > now->value) {
			counting += now->left_descendant;
			now = now->right_child;
		}
		else {
			counting += now->left_descendant;
			break;
		}
	}
	return counting;
}