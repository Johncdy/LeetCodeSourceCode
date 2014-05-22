/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

#include <iostream>
#include <vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	if (lists.size() == 0) {
    		return NULL;
    	}
    	return mergeFunc(lists, 0, lists.size()-1);
    }
    
    ListNode *mergeFunc(vector<ListNode *> &lists, int l, int h) {
    	if (l < h) {
    		int m = (l+h)/2;
    		return mergeTwoLists(mergeFunc(lists, l, m), mergeFunc(lists, m+1, h));	
    	}
    	return lists[l];
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	ListNode *head = new ListNode(0);
    	ListNode *p = head;
    	
    	while(l1 && l2) {
    		if (l1->val > l2->val) {
    			p->next = l2;
    			l2 = l2->next;
    		} else {
    			p->next = l1;
    			l1 = l1->next; 
    		}
    		p = p->next;
    	}
    	
    	if (l1) {
    		p->next = l1;
    	} else {
    		p->next = l2;
    	}
    	
    	if (p == head) {
    		p = p->next;
    	}
    	p = head->next;
    	head->next = NULL;
    	delete head;
    	return p;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(5);
	ListNode *p3 = new ListNode(6);
	p1->next = p2;
	p2->next = p3;
	
	ListNode *d1 = new ListNode(2);
	ListNode *d2 = new ListNode(3);
	ListNode *d3 = new ListNode(8);
	d1->next = d2;
	d2->next = d3;
	
	ListNode *e1 = new ListNode(4);
	ListNode *e2 = new ListNode(7);
	ListNode *e3 = new ListNode(9);
	e1->next = e2;
	e2->next = e3;
	
	ListNode *tmp = NULL; 
	vector<ListNode *> vec;
	vec.push_back(tmp);
	vec.push_back(p3);
//	vec.push_back(d1);
//	vec.push_back(e1);
	ListNode *p = s.mergeKLists(vec);
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
	
	return 0;
}

