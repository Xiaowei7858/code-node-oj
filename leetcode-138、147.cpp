//147
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* sorthead = head;
        ListNode* tail = sorthead;
        ListNode* cur = head->next;
        tail->next = nullptr;
        while (cur)
        {
            ListNode* next = cur->next;
            //ͷ��
            if (cur->val <= sorthead->val)
            {
                cur->next = sorthead;
                sorthead = cur;
            }
            else
            {
                //β��
                if (cur->val > tail->val)
                {
                    tail->next = cur;
                    tail = cur;
                    tail->next = nullptr;
                }
                //�м����
                else
                {
                    ListNode* sortcur = sorthead;
                    while (sortcur)
                    {
                        if (sortcur->val < cur->val && sortcur->next->val >= cur->val)
                        {
                            ListNode* sortnext = sortcur->next;
                            sortcur->next = cur;
                            cur->next = sortnext;
                            break;
                        }
                        sortcur = sortcur->next;
                    }
                }
            }
            cur = next;
            if (next)
                next = next->next;
        }
        return sorthead;
    }
};
//138
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        //���ƽ�㣬������ԭ������
        Node* cur = head;
        while (cur) {
            Node* newNode = new Node(0);
            newNode->next = nullptr;
            newNode->random = nullptr;
            newNode->val = cur->val;

            Node* next = cur->next;
            /* newNode->next = next;
             cur->next = newNode;
             cur = next;
             if(!next)
             next = next->next;*/
            cur->next = newNode;
            newNode->next = next;

            cur = next;

        }

        //����������random
        cur = head;
        while (cur) {
            Node* newNode = cur->next;
            if (cur->random) {
                newNode->random = cur->random->next;
            }
            else {
                newNode->random = nullptr;
            }
            cur = cur->next->next;
        }

        //������������
        cur = head;
        Node* newhead = cur->next;
        while (cur) {
            Node* newNode = cur->next;
            Node* next = newNode->next;
            cur->next = next;
            if (next) {
                newNode->next = next->next;
            }
            else {
                newNode->next = nullptr;
            }
            cur = next;
        }

        return newhead;
    }
};