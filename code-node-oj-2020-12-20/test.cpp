//leetcode
//83. 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                ListNode* temp = cur->next->next;
                delete cur->next;
                cur->next = temp;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};
//142. 环形链表 II
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
    ListNode* detectCycle(ListNode* head) {
        //快慢指针
        //F：a + n(b + c) + b    S：a + b
        ListNode* fast = head, * slow = head;
        ListNode* ptr;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ptr = head;
                while (ptr != slow) {
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
//141. 环形链表
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
    bool hasCycle(ListNode* head) {
        //快慢指针
        //若存在环，快指针会追上慢指针
        ListNode* fast = head, * slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
//牛客：删除链表中重复的结点
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* newhead = new ListNode(-1);
        newhead->next = pHead;
        ListNode* prev = newhead;
        ListNode* cur = pHead;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
                while (cur->next && cur->val == cur->next->val)
                    cur = cur->next;
                cur = cur->next;
                prev->next = cur;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return newhead->next;
    }
};