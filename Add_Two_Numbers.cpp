/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Subscribe to see which companies asked this question
*/

#include <iostream>
#include <math.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *root = new ListNode(0);
		ListNode *pNode = root;
		int a = 0;
		
		while (l1 != NULL || l2 != NULL) {
			int v1 = l1 == NULL ? 0 : l1->val;
			int v2 = l2 == NULL ? 0 : l2->val;
			ListNode *t = new ListNode((v1 + v2 + a)%10);
			a = (v1 + v2 + a) / 10;
			pNode->next = t;
			pNode = pNode->next;
			
			if (l1) {
				l1 = l1->next;
			}
			if (l2) {
				l2 = l2->next;
			}
		}
		
		if (a > 0) {
			ListNode *t = new ListNode(a);
			pNode->next = t;
		}
		return root->next;
    }
};

//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		long a = 0, b = 0;
//		int count = 0;
//		while (l1) {
//			a = a + l1->val * pow(10, count);
//			count++;
//			l1 = l1->next;
//		}
//		count = 0;
//		while (l2) {
//			b = b + l2->val * pow(10, count);
//			count++;
//			l2 = l2->next;
//		}
//		long c = a + b;
//		int t = 0;
//		ListNode *l3, *prev, *f;
//		prev = NULL;
//		if (c == 0) {
//			f = new ListNode(0);
//		}
//		while (c != 0) {
//			t = c % 10;
//			c = (c - t) / 10;
//			ListNode *tmp = new ListNode(t);
//			if (prev) {
//				prev->next = tmp;
//			} else {
//				f = tmp;
//			}
//			prev = tmp;
//		}
//		return f;
//    }
//};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	
	ListNode *a1 = new ListNode(9);
	ListNode *a2 = new ListNode(4);
	ListNode *a3 = new ListNode(3);
//	a1->next = a2;
//	a2->next = a3;
	
	ListNode *b1 = new ListNode(1);
	ListNode *b2 = new ListNode(9);
	ListNode *b3 = new ListNode(9);
	ListNode *b4 = new ListNode(9);
	ListNode *b5 = new ListNode(9);
	ListNode *b6 = new ListNode(9);
	ListNode *b7 = new ListNode(9);
	ListNode *b8 = new ListNode(9);
	ListNode *b9 = new ListNode(9);
	ListNode *b10 = new ListNode(9);
	b1->next = b2;
	b2->next = b3;
	b3->next = b4;
	b4->next = b5;
	b5->next = b6;
	b6->next = b7;
	b7->next = b8;
	b8->next = b9;
	b9->next = b10;
	
	ListNode *c1 = s->addTwoNumbers(a1, b1);
//	while (c1) {
//		cout << c1->val << endl;
//		c1 = c1->next;
//	}
}