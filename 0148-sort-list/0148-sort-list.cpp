class Solution {
public:

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1 != NULL)
            temp->next = list1;

        if (list2 != NULL)
            temp->next = list2;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Divide into two halves
        prev->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge sorted halves
        return merge(left, right);
    }
};