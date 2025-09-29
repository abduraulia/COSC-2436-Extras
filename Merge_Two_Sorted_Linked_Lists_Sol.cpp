//Merge Two Sorted Linked Lists LeetCode

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (list1 != nullptr || list2 != nullptr)
        {
            int val;
            if (list1 != nullptr && list2 != nullptr)
            {
                if (list1->val < list2->val)
                {
                    val = list1->val;
                    list1 = list1->next;
                }
                else if (list1->val > list2->val)
                {
                    val = list2->val;
                    list2 = list2->next;
                }
                else
                {
                    val = list1->val;
                    list1 = list1->next;
                }
            }
            else if (list1 != nullptr)
            {
                val = list1->val;
                list1 = list1->next;
            }
            else
            {
                val = list2->val;
                list2 = list2->next;
            }

            ListNode* newNode = new ListNode(val);

            if (!head)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }
};