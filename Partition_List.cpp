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
    ListNode *partition(ListNode *head, int x) {
		if (head == NULL) {
			return NULL;
		}
		
	    ListNode *smailer = new ListNode(-1);
		ListNode *shead = smailer;
		ListNode *bigger = new ListNode(-1);
		ListNode *bhead = bigger;
		
		while (head != NULL) {
			if (head->val < x) {
				shead->next = head;
				shead = head;
			} else {
				bhead->next = head;
				bhead = head;
			}
			
			head = head->next;
		}
		
		bhead->next = NULL;
		shead->next = bigger->next;
		
		return smailer->next;
    }
};

int main(int argc, char *argv[]) {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(4);
	ListNode *n3 = new ListNode(2);
	n1->next = n2;
	n2->next = n3;
	Solution *s = new Solution;
	ListNode *t = s->partition(n1, 3);
	while (t != NULL) {
		cout << t->val << endl;
		t = t->next;
	}
}