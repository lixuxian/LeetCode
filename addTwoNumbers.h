//
// Created by 李旭贤 on 2018/8/16.
//

#ifndef LEETCODE_ADDTWONUMBERS_H
#define LEETCODE_ADDTWONUMBERS_H
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

 struct ListNode{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class addTwoNumbersSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 循环
        // 如果都不为null，相加，存结果和进位
        // 若一个为null，则另一个加到结尾
        // 若两个都为null，结束
        ListNode* result = new ListNode(0);
        ListNode* cut_ptr = new ListNode(0);
        int value, res, carry;
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        else if (l1 != NULL && l2 != NULL)
        {
            value = l1->val + l2->val;
            res = value % 10;
            carry = value / 10;
            result->val = res;
            result->next = NULL; // head ptr
            cut_ptr = result;
            l1 = l1->next;
            l2 = l2->next;

            while (l1 != NULL && l2 != NULL)
            {
                value = l1->val + l2->val + carry;
                res = value % 10;
                carry = value / 10;
                ListNode* temp = new ListNode(0);
                temp->val = res;
                temp->next = NULL;
                cut_ptr->next = temp;
                cut_ptr = cut_ptr->next;

                l1 = l1->next;
                l2 = l2->next;
            }
            if (l1 == NULL && l2 == NULL)
            {
                // return result;
            }
            else if (l1 == NULL)
            {
                while(l2 != NULL)
                {
                    value = l2->val + carry;
                    res = value % 10;
                    carry = value / 10;
                    ListNode* temp = new ListNode(0);
                    temp->val = res;
                    temp->next = NULL;
                    cut_ptr->next = temp;
                    cut_ptr = cut_ptr->next;

                    l2 = l2->next;
                }
            }
            else if (l2 == NULL)
            {
                while (l1 != NULL)
                {
                    value = l1->val + carry;
                    res = value % 10;
                    carry = value / 10;
                    ListNode* temp = new ListNode(0);
                    temp->val = res;
                    temp->next = NULL;
                    cut_ptr->next = temp;
                    cut_ptr = cut_ptr->next;

                    l1 = l1->next;
                }
            }

            if (carry != 0)
            {
                ListNode* temp = new ListNode(carry);
                cut_ptr->next = temp;
                cut_ptr = cut_ptr->next;
            }
            return result;
        }
        else if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }

    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* cut_ptr = result;
        int value = 0, res = 0, carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int x = (l1 == NULL) ? 0 : l1->val;
            int y = (l2 == NULL) ? 0 : l2->val;
            value = x + y + carry;
            res = value % 10;
            carry = value / 10;
            cut_ptr->next = new ListNode(res);
            cut_ptr = cut_ptr->next;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        if (carry > 0)
        {
            cut_ptr->next = new ListNode(carry);
        }
        return result->next;
    }
    void printList(ListNode *head)
    {
        while(head)
        {
            cout << head->val << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }

    ListNode* createList(int nums[], int len)
    {
        ListNode* head = new ListNode(nums[0]);
        ListNode* ptr = head;
        for (int i = 1; i < len; i++)
        {
            ListNode* temp = new ListNode(nums[i]);
            ptr->next = temp;
            ptr = ptr->next;
        }
        return head;
    }

    void test()
    {
        int ls1[] = {2, 4, 6};
        ListNode *l1 = createList(ls1, 3);
        int ls2[] = {2, 8, 9};
        ListNode *l2 = createList(ls2, 3);
        ListNode *res = addTwoNumbers2(l1, l2);
        printList(res);
    }
};
#endif //LEETCODE_ADDTWONUMBERS_H
