//leetcode,牛客 链表回文
class PalindromeList {
public:
    ListNode* Fast = NULL;
    ListNode* reverse(ListNode* start, ListNode* end) {
        //1.三指针法
        ListNode* prev = end->next;
        ListNode* cur = start;
        ListNode* next = cur->next;
        ListNode* finish = prev;
        while (cur != finish) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        return prev;
    }
    ListNode* middleNode(ListNode* head) {
        //快慢指针
        //若为偶数结点，返回第一个结点
        ListNode* Slow = head;
        Fast = head;
        while (Fast->next != NULL && Fast->next->next != NULL) {
            Slow = Slow->next;
            Fast = Fast->next->next;
        }
        return Slow;
    }
    bool chkPalindrome(ListNode* A) {
        //找到中点
        //链表反转前半部分
        //找到中点
        //从头及中点开始遍历比较
        if (A == NULL || A->next == NULL) return true;
        ListNode* start = A;
        ListNode* end = NULL;
        end = middleNode(A);
        start = reverse(start, end);
        end = middleNode(start);
        end = end->next;
        if (Fast->next == NULL) {
            start = start->next;
        }
        while (end) {
            if (start->val == end->val) {
                start = start->next;
                end = end->next;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
//206.反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //1.三指针法
        //无节点或一个节点
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while (cur) {
            cur->next = prev;
            if (next) {
                prev = cur;
                cur = next;
                next = next->next;
            }
            else {
                break;
            }
        }
        return cur;
    }
};
//876.链表的中间结点
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* Slow = head;
        ListNode* Fast = head;
        while (Fast != NULL && Fast->next != NULL) {
            Slow = Slow->next;
            Fast = Fast->next->next;
        }
        return Slow;
    }
};