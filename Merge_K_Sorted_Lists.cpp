//Merge K Sorted Lists LeetCode

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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode head;
        ListNode* temp = &head;

        vector<int> list;
        for (int i=0; i<lists.size(); i++)
        {
            while (lists[i] != nullptr)
            {
                list.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        int sizeList = list.size();

        
        for (int i=0; i<sizeList-1; i++)
        {
            for (int j=0; j<sizeList-i-1; j++)
            {
                if (list[j] > list[j+1])
                {
                    int temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
                }  
            } 
        }

        for (int i=0; i<sizeList; i++)
        {
            temp->next = new ListNode(list[i]);
            temp = temp->next;
        }
        return head.next;
    }
};