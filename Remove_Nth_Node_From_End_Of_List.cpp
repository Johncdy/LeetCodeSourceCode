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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (head == NULL || n <= 0) {
			return head;
		}
		
        ListNode *fast = head;
		ListNode *slow = head;
		
		int i = 0;
		while (fast != NULL && i < n) {
			fast = fast->next;
			i++;
		}
		if (i < n) {
			return head;
		}
		if (fast == NULL) {
			return head->next;
		}
		while (fast->next != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return head;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	ListNode *l5 = new ListNode(5);
//	l1->next = l2;
//	l2->next = l3;
//	l3->next = l4;
//	l4->next = l5;
	ListNode *tmp = s->removeNthFromEnd(l1, 1);
	while (tmp != NULL) {
		cout << tmp->val << endl;
		tmp = tmp->next;
	}
}