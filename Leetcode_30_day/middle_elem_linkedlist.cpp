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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr){
            fast = fast->next;
            if(fast == nullptr){
                return slow;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};