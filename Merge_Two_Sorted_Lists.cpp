#include <iostream>

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *temp = new ListNode(0);
		ListNode *p = temp;
		
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			
			p = p->next;
		}
		
		if (!l1) {
			p->next = l2;
		} else {
			p->next = l1;
		}
		
		p = temp->next;
		temp->next = NULL;
		delete temp;
		return p;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(5);
	ListNode *p3 = new ListNode(6);
	p1->next = p2;
	p2->next = p3;
	
	ListNode *d1 = new ListNode(2);
	ListNode *d2 = new ListNode(3);
	ListNode *d3 = new ListNode(4);
	d1->next = d2;
	d2->next = d3;
	
	ListNode *p = s->mergeTwoLists(p1, d1);
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
}