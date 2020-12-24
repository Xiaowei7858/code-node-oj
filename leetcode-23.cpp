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
    ListNode* mergetwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newhead = new ListNode(-1);
        ListNode* tail = newhead;
        ListNode* next = nullptr;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                next = list2->next;
                tail->next = list2;
                list2 = next;
            }
            else {
                next = list1->next;
                tail->next = list1;
                list1 = next;
            }
            tail = tail->next;
        }
        tail->next = list1 == nullptr ? list2 : list1;
        ListNode* head = newhead->next;
        delete newhead;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        ListNode* head = nullptr;
        for (int i = 0; i < len; ++i) {
            head = mergetwoLists(head, lists[i]);
        }
        return head;
    }
};