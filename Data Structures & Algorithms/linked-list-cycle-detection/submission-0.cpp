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

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // use two pointers, advance one by 1 and second by 2
        bool cycle = false;
        if(head == nullptr)
            return cycle;
        ListNode* first = head;
        if(first->next == nullptr)
            return cycle;
        ListNode* second = first->next;
        while(first != nullptr and second != nullptr){
            if(first == second)
            {   return true;
            }
            first = first->next;
            second = second->next;
            if(second == nullptr)
            {   return false;
            }
            second = second->next;
        }
        return cycle;
    }
};
