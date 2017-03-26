#include<iostream>
#include<vector>
using namespace std;
class TreeNode
{
	int m_value;
public:
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode(int value, TreeNode* left, TreeNode* right) : m_value(value), m_left(left), m_right(right)
	{
	}

	TreeNode(int value) : m_value(value), m_left(NULL), m_right(NULL)
	{
	}

	bool operator==(const TreeNode& rhs) const
	{
		return this->m_value == rhs.m_value;
	}
	static TreeNode* arrayToTree(std::vector<int> arr)
	{
		if (arr.size() <= 0) {
			return NULL;
		}
		vector<TreeNode*>currentLine;
		TreeNode* nodeBegin = new TreeNode(arr[0]);
		if (arr.size()==1) {
			return nodeBegin;
		}
		currentLine.push_back(nodeBegin);
		long current = 0;
		int count = 1;
		while (current < arr.size()) {
			int c = 0;
			int max = currentLine.size();
			while (c < max) {
				currentLine[0]->m_left = new TreeNode(arr[count++]);
				if (count >= arr.size()) {
					current = count;
					break;
				}
				currentLine[0]->m_right = new TreeNode(arr[count++]);
				if (count >= arr.size()) {
					current = count;
					break;
				}
				currentLine.push_back(currentLine[0]->m_left);
				currentLine.push_back(currentLine[0]->m_right);
				currentLine.erase(currentLine.begin());
				c++;
			}
			current = count;
		}
		return nodeBegin;
	}
};
int main() {
	vector<int> arr = { 17 };
	TreeNode::arrayToTree(arr);
	return 0;
}