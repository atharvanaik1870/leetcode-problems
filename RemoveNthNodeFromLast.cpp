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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        while (fast->next != NULL) {
            //why till fast->next = null coz this ,eans fast has reached the last  node and bybthe time fast raches the last node slow will be at the previous node of the target node
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;
        return head;
    }
};
//Approach 2: brute force 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;

        while (temp) {
            cnt++;
            temp = temp->next;
        }

        // Delete head
        if (cnt == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        temp = head;
        int res = cnt - n;

        for (int i = 1; i < res; i++) {
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        return head;
    }
};
