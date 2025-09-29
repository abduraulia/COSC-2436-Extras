//Remove Nth Node From End LeetCode

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        
        if (n == length) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;  
            return head;
        }

        
        curr = head;
        for (int i = 1; i < length - n; i++) {
            curr = curr->next;
        }

        
        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;  

        return head;
    }
};