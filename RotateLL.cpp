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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }

        if (k % len == 0)
            return head;

        k = k % len;
        temp->next = head;
        ListNode* newlast = findKthNode(head, len - k);
        head = newlast->next;
        newlast->next = NULL;
        return head;
    }
    ListNode* findKthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp) {
            if (cnt == k)
                return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
};
