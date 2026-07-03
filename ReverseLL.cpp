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
    ListNode* reverseList(ListNode* head) {
        // we take 3 pointers temp, prev, front

        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* front = nullptr;

        while (temp != NULL) {
        front = temp->next;   // Save next node
        temp->next = prev;    // Reverse the link
        prev = temp;          // Move prev forward
        temp = front;         // Move current forward
    }
        return prev;
    }
};
