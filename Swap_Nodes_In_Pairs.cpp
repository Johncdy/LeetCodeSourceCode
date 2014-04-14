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
    ListNode *swapPairs(ListNode *head) {
  		ListNode *temp = new ListNode(0);
		temp->next = head;
		ListNode *pre = temp;
		ListNode *cur = head;
		
		while (cur != NULL && cur->next != NULL) {
			pre->next = cur->next;
			cur->next = cur->next->next;
			pre->next->next = cur;
			pre = pre->next->next;
			cur = cur->next;
		}
		
		return temp->next;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	ListNode *p = s->swapPairs(p1);
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
}