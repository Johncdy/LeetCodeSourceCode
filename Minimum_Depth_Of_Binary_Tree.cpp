#include <iostream>
#include <queue>

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
    int minDepth(TreeNode *root) {
		if (root == NULL) {
			return 0;
		} else if (root->left == NULL) {
			return minDepth(root->right)+1;
		} else if (root->right == NULL) {
			return minDepth(root->left)+1;
		} else {
			return min(minDepth(root->left), minDepth(root->right)) + 1;	
		}
    }
};

int main(int argc, char *argv[]) {
	
}