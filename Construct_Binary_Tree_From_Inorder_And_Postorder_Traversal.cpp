#include <iostream>
#include <vector>

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
   		if (inorder.size() > 0) {
			return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
		} else {
			return NULL;
		}
    }

	TreeNode *build(vector<int> &inorder, vector<int> &postorder,
		int in_s, int in_e, int post_s, int post_e) {		if (in_s > in_e) {
			return NULL;
		}
		
		int rootVal = postorder[post_e];
		TreeNode *rootNode = new TreeNode(rootVal);
		
		int rootIndex = -1;
		for (int i = in_s; i <= in_e; i++) {
			if (inorder[i] == rootVal) {
				rootIndex = i;
				break;
			}
		}
		
		TreeNode *lTree = build(inorder, postorder, in_s, rootIndex-1, post_s, post_s +rootIndex-in_s-1);
		TreeNode *rTree = build(inorder, postorder, rootIndex+1, in_e, post_s+rootIndex-in_s, post_e-1);
		rootNode->left = lTree;
		rootNode->right = rTree;
		
		return rootNode;
	}
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<int> v1;
	v1.push_back();
	vector<int> v2;
	v2.push_back(-1);
	s->buildTree(v1, v2);
}