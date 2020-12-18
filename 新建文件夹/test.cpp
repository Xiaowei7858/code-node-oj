//leetcode
//21. �ϲ�������������
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //˼·1
        //˼·2����ͷ���--������
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = (ListNode*)malloc(sizeof(ListNode));
        ListNode* tail = head;
        ListNode* cur1 = l1, * cur2 = l2;

        //ȡСβ�� ��ֹcur->next = cur����ѭ��
        while (cur1 && cur2) {
            if (cur1->val > cur2->val) {
                tail->next = cur2;
                cur2 = cur2->next;
            }
            else {
                tail->next = cur1;
                cur1 = cur1->next;
            }
            tail = tail->next;
        }
        if (cur1) tail->next = cur1;
        if (cur2) tail->next = cur2;
        l1 = head->next;
        free(head);
        return l1;
    }
};
//��ָ Offer 22. �����е�����k���ڵ�
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head, * slow = head;
        while (k--) {
            if (!fast) return NULL;
            else fast = fast->next;
        }
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
//206. ��ת����
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //1.��ָ�뷨
        //�޽ڵ��һ���ڵ�
        /*
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while(cur){
            cur->next = prev;
            if(next){
                prev = cur;
                cur = next;
                next = next->next;
            }
            else{
                break;
            }
        }
        return cur;
        */
        //2.ͷ�巨
        if (head == NULL || head->next == NULL) return head;
        ListNode* cur = head;
        ListNode* next = cur->next;
        ListNode* newhead = NULL;
        while (cur != NULL) {
            cur->next = newhead;
            newhead = cur;
            cur = next;
            if (next != NULL)
                next = next->next;
        }
        return newhead;
    }
};
//ţ��
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* head1 = (ListNode*)malloc(sizeof(ListNode));
        ListNode* head2 = (ListNode*)malloc(sizeof(ListNode));
        ListNode* tail1 = head1, * tail2 = head2;
        ListNode* cur = pHead;
        while (cur) {
            if (cur->val < x) {
                tail1->next = cur;
                tail1 = cur;
            }
            else {
                tail2->next = cur;
                tail2 = cur;
            }
            cur = cur->next;
        }
        tail1->next = head2->next;
        tail2->next = NULL;
        pHead = head1->next;
        free(head1);
        free(head2);
        return pHead;
    }
};
//160. �ཻ����
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        ListNode* pa = headA, * pb = headB;
        //��ֹ������pa = pb = nulllptr
        while (pa != pb) {
            pa = pa ? pa->next : headB;
            pb = pb ? pb->next : headA;
        }
        return pb;
    }
};