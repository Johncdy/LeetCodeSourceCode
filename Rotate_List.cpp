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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
			return head;
		}
		
		ListNode *ptr = head, *tail = head;
		int length = 0;
		while (ptr != NULL) {
			tail = ptr;
			ptr = ptr->next;
			length++;
		}
		
		k %= length;
		ptr = head;
		for (int i = 0; i < length-k-1; i++) {
			ptr = ptr->next;
		}
		tail->next = head;
		head = ptr->next;
		ptr->next = NULL;
		
		return head;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	n1->next = n2;
//	ListNode *t = s->rotateRight(n1, 1);
//	cout << "t " << t->val << endl;
//	cout << t->next->val << endl;
//	cout << t->val << endl;
//	cout << t->next->val << endl;
	while (n1 != NULL) {
		cout << n1->val << " ";
//		cout 
		n1 = n1->next;
	}
}