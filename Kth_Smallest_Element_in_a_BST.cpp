/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int tree_size(TreeNode* root)
	{
		if (root){
			return tree_size(root->left) + tree_size(root->right) + 1;
		} else {
			return 0;	
		}
	}

    int kthSmallest(TreeNode* root, int k) {
        if (tree_size(root->left) + 1 == k) {
			return root->val;
		} else if (tree_size(root->left) + 1 > k) {
			return kthSmallest(root->left, k);
		} else {
			return kthSmallest(root->right, k-(tree_size(root->left)+1));
		}
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution();
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(4);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(5);
	TreeNode *node5 = new TreeNode(8);
	TreeNode *node6 = new TreeNode(7);
	TreeNode *node7 = new TreeNode(9);
	TreeNode *node8 = new TreeNode(6);
	node3->left = node1;
	node3->right = node2;
	node4->left = node3;
	node4->right = node5;
	node5->left = node6;
	node5->right = node7;
	node6->left = node8;
	cout << s->kthSmallest(node4, 5) << endl;
//	cout << s->tree_size(node1) << endl;
	return 0;
}