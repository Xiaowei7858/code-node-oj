//leetcode,ţ�� �������
class PalindromeList {
public:
    ListNode* Fast = NULL;
    ListNode* reverse(ListNode* start, ListNode* end) {
        //1.��ָ�뷨
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
        //����ָ��
        //��Ϊż����㣬���ص�һ�����
        ListNode* Slow = head;
        Fast = head;
        while (Fast->next != NULL && Fast->next->next != NULL) {
            Slow = Slow->next;
            Fast = Fast->next->next;
        }
        return Slow;
    }
    bool chkPalindrome(ListNode* A) {
        //�ҵ��е�
        //����תǰ�벿��
        //�ҵ��е�
        //��ͷ���е㿪ʼ�����Ƚ�
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
//206.��ת����
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //1.��ָ�뷨
        //�޽ڵ��һ���ڵ�
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
//876.������м���
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