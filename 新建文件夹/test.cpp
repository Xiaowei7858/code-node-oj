//leetcode
//21. 合并两个有序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //思路1
        //思路2，带头结点--虚拟结点
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = (ListNode*)malloc(sizeof(ListNode));
        ListNode* tail = head;
        ListNode* cur1 = l1, * cur2 = l2;

        //取小尾插 防止cur->next = cur；死循环
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
//剑指 Offer 22. 链表中倒数第k个节点
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
//206. 反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //1.三指针法
        //无节点或一个节点
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
        //2.头插法
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
//牛客
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
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
//160. 相交链表
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        ListNode* pa = headA, * pb = headB;
        //终止条件，pa = pb = nulllptr
        while (pa != pb) {
            pa = pa ? pa->next : headB;
            pb = pb ? pb->next : headA;
        }
        return pb;
    }
};