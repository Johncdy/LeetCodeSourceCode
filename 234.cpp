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
    bool isPalindrome(ListNode* head) {
        int nums[100000];
        int i = 0;
        do
        {
            nums[i] = head->val;
            i++;
            head = head->next;
        } while (head != nullptr);
        int a = 0, b = i-1;
        while (a < b)
        {
            if (nums[a] == nums[b]) { a++; b--; } else return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution;
    ListNode lnodes[] = { ListNode(1), ListNode(2), ListNode(2), ListNode(1)};
    for (int i = 0; i < 3; i++) {
        lnodes[i].next = &lnodes[i+1];
    }
    cout << s->isPalindrome(&lnodes[0]) << endl;
}