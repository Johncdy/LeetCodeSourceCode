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
    int maxDepth(TreeNode *root) {
		if (root == NULL) {
			return 0;
		}
		
		vector<TreeNode*> vec;
		int depth = 0;
		vec.push_back(root);
		int cur = 0;
		int last = 1;
		while (cur < vec.size()) {
			last = vec.size();
			while (cur < last) {
				if (vec[cur]->left) {
					vec.push_back(vec[cur]->left);
				}
				if (vec[cur]->right) {
					vec.push_back(vec[cur]->right);
				}
				cur++;
			}
			depth++;
		}
		return depth;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	n1->left = n2;
	n2->left = n3;
	cout << s->maxDepth(NULL) << endl;
}