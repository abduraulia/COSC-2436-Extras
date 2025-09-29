// Detect a Cycle in Linked List HackerRank

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;
    
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) { return true; }
    }
    return false;
}

