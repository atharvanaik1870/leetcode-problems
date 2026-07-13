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
    ListNode* middleNode(ListNode* head) {
        ListNode * temp = head;
        ListNode * dummy = new ListNode(-1);
        int n =0;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        
        int median = 0;
        if(n % 2 == 0)
        {
            median = (n/2) +1;
        }
        else
        {
            median = (n+1)/2;
        }
        std::cout<<median;
        dummy->next = head;
        temp = dummy;
        temp->next=dummy->next;
        while(median)
        {
            temp = temp->next;
            median--;
        }
        return temp;
    }
};
