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
    ListNode* reverseList(ListNode* head) {
        // traverse and put on stack
        vector<int> st;
        while(head != nullptr)
        {   st.push_back(head->val);
            head = head->next;
        }
        ListNode* root = nullptr;
        ListNode* curr = nullptr;
        reverse(st.begin(), st.end());
        // pop and create 
        for(auto val: st)
        {
            ListNode* newNode = new ListNode(val);
            if (root == nullptr)
            {   root = newNode;
                curr = newNode;
            }
            else
            {
                curr->next = newNode;
                curr = newNode;
            }
        }
        return root;
    }
};
