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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr and list2 == nullptr)
            return nullptr;        
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        ListNode* root = nullptr;
        ListNode* head = nullptr;
        while(list1 != nullptr and list2 != nullptr)
        {   ListNode* node = nullptr;
            // check which node is smaller
            if(list1->val < list2->val)
            {// create new node with same value as smaller node
                node = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                node = new ListNode(list2->val);
                list2 = list2->next;
            }
            // append node to root
            if(root == nullptr)
            {
                root = node;
                head = node;
            }
            else
            {
                root->next = node;
                root = root->next;
            }
        }
        // append remaining list1
        while(list1 != nullptr)
        {   ListNode* node = new ListNode(list1->val);
            list1 = list1->next;
            // append node to root
            if(root == nullptr)
            {
                root = node;
                head = node;
            }
            else
            {
                root->next = node;
                root = root->next;
            }
        }
        // append remaining list1
        while(list2 != nullptr)
        {   ListNode* node = new ListNode(list2->val);
            list2 = list2->next;
            // append node to root
            if(root == nullptr)
            {
                root = node;
                head = node;
            }
            else
            {
                root->next = node;
                root = root->next;
            }
        }
        return head;
    }
};
