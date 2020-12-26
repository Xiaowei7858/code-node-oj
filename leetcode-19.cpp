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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr, * cur = head, * next = head;
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        prev = newhead;
        while (next) {
            while (next && n) {
                next = next->next;
                n--;
            }
            if (!next) break;
            prev = cur;
            cur = cur->next;
            next = next->next;
        }
        prev->next = cur->next;
        delete cur;
        head = newhead->next;
        delete newhead;
        return head;
    }
};