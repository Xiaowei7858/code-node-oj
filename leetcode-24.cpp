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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur = head, * next = cur->next, * nnext = nullptr;
        int flag = 1;
        while (next) {
            //保存下次循环的位置
            nnext = next->next;
            next->next = cur;
            if (nnext && nnext->next)
                cur->next = nnext->next;
            else
                cur->next = nnext;
            //保存头节点
            if (flag) {
                head = next;
                flag = 0;
            }
            cur = nnext;
            cur == nullptr ? next = nullptr : next = cur->next;
        }
        return head;
    }
};