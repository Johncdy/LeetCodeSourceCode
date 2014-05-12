/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means?
OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*/

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
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<TreeNode*> container;
    	vector<vector<int> > vec;
    	if (root == NULL) {
    		return vec;
    	}
    	
    	vector<int> v;
    	v.push_back(root->val);
    	vec.push_back(v);
    	container.push_back(root);
    	
        int cur = 0, last = 1;
        while (cur < container.size()) {
        	last = container.size();
        	vector<int> tmp;
        	while(cur < last) {
        		TreeNode *node = container[cur];
        		if (node->left) {
        			container.push_back(node->left);
        			tmp.push_back(node->left->val);
        		}
        		if (node->right) {
        			container.push_back(node->right);
        			tmp.push_back(node->right->val);
        		}
        		cur++;
        	}
        	if (tmp.size() > 0) {
        		vec.push_back(tmp);	
        	}
        }
        return vec;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	TreeNode *a = new TreeNode(3);
	TreeNode *b = new TreeNode(9);
	TreeNode *c = new TreeNode(20);
	TreeNode *d = new TreeNode(15);
	TreeNode *e = new TreeNode(7);
	a->left = b;
	a->right = c;
	c->left = d;
	c->right = e;
	vector<vector<int> > v = s.levelOrder(a);
//	cout << "Complete" << endl;
//	for (int i = 0; i < v.size(); i++) {
//		for (int j = 0; j < v[i].size(); j++) {
//			cout << v[i][j] << " "; 
//		}
//		cout << endl;
//	}
	return 0;
} 
