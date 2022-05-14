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
        int c = 0;
        ListNode* output = new ListNode((l1->val + l2->val) % 10);
        ListNode* cur_ptr = output;
        c = (l1->val + l2->val) / 10;
        while(l1->next != nullptr || l2->next != nullptr)
        {
            ListNode* temp;
            if(l1->next == nullptr)
            {
                l2 = l2->next;
                temp = new ListNode((l2->val + c) % 10);
                cur_ptr->next = temp;
                c = (l2->val + c) / 10;
            }
            else if(l2->next == nullptr)
            {
                l1 = l1->next;
                temp = new ListNode((l1->val + c) % 10);
                cur_ptr->next = temp;
                c = (l1->val + c) / 10;
            }
            else
            {
                l1 = l1->next;
                l2 = l2->next;
                temp = new ListNode((l2->val + l1->val + c) % 10);
                cur_ptr->next = temp;
                c = (l2->val + l1->val + c) / 10;
            }
            cur_ptr = temp;
        }
        if(c != 0)
        {
            ListNode* temp = new ListNode(c);
            cur_ptr->next = temp;
        }
        return output;
    }
};
