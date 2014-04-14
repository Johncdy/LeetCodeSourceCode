#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
		vector<int> vec;
		TreeNode *node = root;
		while (node || !s.empty()) {
			if (node != NULL) {
				s.push(node);
				node = node->left;
			} else {
				node = s.top();
				s.pop();
				vec.push_back(node->val);
				node = node->right;
			}
		}
		return vec;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	n1->left = n2;
	n1->right = n3;
	vector<int> v = s->inorderTraversal(n1);
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << " ";
//	}
}