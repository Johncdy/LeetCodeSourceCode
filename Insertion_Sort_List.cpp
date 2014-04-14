#include <iostream>

using namespace std;

template<typename T>
void InsertSort(T array[], int len) {
	int i = 0, j = 0;
	int k = -1, temp = -1;
	
	for (i = 1; i < len; i++) {
		k = i;
		temp = array[k];
		for (j = i-1; (j >= 0) && (array[j] > temp); j--) {
			array[j+1] = array[j];
			k = j;
		}
		array[k] = temp;
	}
}

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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) {
			return NULL;
		}
		
		ListNode *temp = new ListNode(0);
		ListNode *pre = temp;
		ListNode *cur = head;
		while (cur != NULL) {
			ListNode *next = cur->next;
			pre = temp;
			while (pre->next != NULL && pre->next->val < cur->val) {
				pre = pre->next;
			}
			
			cur->next = pre->next;
			pre->next = cur;
			cur = next;
		}
		
		return temp->next;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	ListNode *p1 = new ListNode(3);
	ListNode *p2 = new ListNode(4);
	ListNode *p3 = new ListNode(1);
	p1->next = p2;
	p2->next = p3;
	ListNode *p = s->insertionSortList(p1);
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
}