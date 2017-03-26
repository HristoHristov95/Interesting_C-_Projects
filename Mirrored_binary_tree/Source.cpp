#include<iostream>
using namespace std;
class BinaryTree {
public:
	BinaryTree* left;
	BinaryTree* right;
	BinaryTree* root;
	int mValue;
};
bool isMirored(BinaryTree* left, BinaryTree* right) {
	return (left && right) ? (left->mValue == right->mValue && isMirored(left->left, right->right) && isMirored(left->right, right->left)) : (left == right);
}
bool isMirroredTree(BinaryTree* root) {
	if (!root) {
		return true;
	}
	isMirored(root->left, root->right);
}