/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> present;
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode* curr = head;
        while(curr != nullptr){
            auto i = ranges::find(present , curr);
            if(i != present.end()){
                return true;
                break;
            }
            present.push_back(curr);
            curr = curr->next;
        }
        return false;
    }
};