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
            ListNode *res=head;
            while(head!=nullptr&&head->next!=nullptr)
            {
                int a=head->val;
                int b=head->next->val;
                head->val=b;
                head->next->val=a;
                head=head->next->next;
            }
            return res;
        }
    };