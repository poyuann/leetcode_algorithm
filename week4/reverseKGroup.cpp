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
        ListNode* reverseKGroup(ListNode* head, int k) {
            int counts = 0;
            ListNode *dummy = new ListNode(-1, head), *lastSegment = dummy, *previous, *now = dummy, *next = head, *buffer;
            do {
                previous = now; now = next; next = now->next; now->next = previous;
                if ((++counts) == k) {
                    buffer = lastSegment->next; lastSegment->next = now;
                    lastSegment = buffer; lastSegment->next = next;
                    counts = 0;
                }
            } while (next);
            if (counts) {
                buffer = lastSegment->next; lastSegment->next = now;
                buffer->next = nullptr;
                next = now->next;
                while (next) {
                    previous = now; now = next; next = now->next; now->next = previous;
                }
                lastSegment->next->next = nullptr;
                lastSegment->next = buffer;
            }
            return dummy->next;
        }
    };