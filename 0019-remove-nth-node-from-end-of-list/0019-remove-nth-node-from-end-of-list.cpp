class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Find the length of the list
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        ListNode* dummy = new ListNode(0, head);
        curr = dummy;

        for (int i = 0; i < length - n; i++) {
            curr = curr->next;
        }

        ListNode* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete; 

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};