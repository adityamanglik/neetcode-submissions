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
    void reorderList(ListNode* head) {
        ListNode* first = nullptr; 
        ListNode* last = nullptr;
        ListNode* newHead = nullptr;
        ListNode* newRoot = nullptr;
        first = head;
        // store last in stack for fast access
        stack<ListNode*> reverse;
        int listSize = 0;
        while(first != nullptr){
            reverse.push(first);
            first = first->next;
            listSize++;
        }
        first = head; 
        int counter = 0;
        // insert first element
        newRoot = head;
        first = first->next;
        newHead = newRoot;
        counter++;
        while(first != nullptr and reverse.size() != 0){
            if(counter%2){// odd element = reverse
                ListNode* element = reverse.top();
                reverse.pop();
                element->next = nullptr;
                newHead->next = element;
                newHead = newHead->next;
            }
            else {// even element
                newHead->next = first;
                newHead = newHead->next;
                ListNode* temp = first;
                first = first->next;
                temp->next = nullptr;
            }
            counter++;
            if(counter == listSize)
                break;
        }
        head = newRoot;
    }
};
