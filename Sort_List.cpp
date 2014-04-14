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
    ListNode *sortList(ListNode *head) {
		return mergeSort(head);
    }

private:
	ListNode *mergeSort(ListNode *head) {
		if (!head || !head->next) {
			return head;
		}
		
		ListNode *slow = head, *fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		
		ListNode *head1 = head;
		ListNode *head2 = slow->next;
		slow->next = NULL;
		head1 = mergeSort(head1);
		head2 = mergeSort(head2);
		
		return merge(head1, head2);
	}
	
	ListNode *merge(ListNode *lh, ListNode *rh) {
		ListNode *temp = new ListNode(0);
		ListNode *p = temp;
		while (lh && rh) {
			if (lh->val < rh->val) {
				p->next = lh;
				lh = lh->next;
			} else {
				p->next = rh;
				rh = rh->next;
			}
			
			p = p->next;
		}
		
		if (!lh) {
			p->next = rh;
		} else {
			p->next = lh;
		}
		
		p = temp->next;
		temp->next = NULL;
		delete temp;
		
		return p;
	}
};

int main(int argc, char *argv[]) {
	ListNode *p1 = new ListNode(2);
	ListNode *p2 = new ListNode(1);
	p1->next = p2;
	Solution* s = new Solution;
	s->sortList(p1);
}