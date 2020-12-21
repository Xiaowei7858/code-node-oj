//leetcode
//2. 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode(-1);
        ListNode* tail = newhead;
        int carry = 0;//进位
        while (l1 || l2 || carry) {
            int l1val = l1 == nullptr ? 0 : l1->val;
            int l2val = l2 == nullptr ? 0 : l2->val;
            int sum = l1val + l2val + carry;
            ListNode* node = new ListNode(sum % 10);
            tail->next = node;
            tail = node;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            carry = sum / 10;
        }
        return newhead->next;
    }
};