//
// Created by John on 2022/3/13.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* m1 = head;
        ListNode* m2 = head;
        int len = 0;
        while (head != nullptr)
        {
            len++;
            if (len % 2 == 0)
            {
                m2 = m2->next;
            } else {
                if (m1 != head) m1 = m1->next;
            }
            head = head->next;
        }
        if (len % 2 == 0) return m2;
        else return m1;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution;
    ListNode lnodes[] = { ListNode(1), ListNode(2), ListNode(3), ListNode(4)};
    for (int i = 0; i < 3; i++) {
        lnodes[i].next = &lnodes[i+1];
    }
    cout << s->middleNode(&lnodes[0])->val << endl;
}