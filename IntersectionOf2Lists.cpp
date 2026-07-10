//Approach 1: using hasmap but this has O(n) as SC and TC is also 
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_map<ListNode*, int> m1;
        ListNode* temp = headA;
        while (temp) {
            m1[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while (temp) {
            if (m1.find(temp) != m1.end())
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
};
//Approach 2: using O(1)SC
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *t1 = headA;
        ListNode *t2 = headB;

        if (t1 == NULL || t2 == NULL)
            return NULL;
      //we compare t1 !=t2 coz when 2 lists are equal that means head of 1st LL is intersection point obviously.
        while (t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;

            if (t1 == t2)
                return t1;

            if (t1 == NULL)
                t1 = headB;
            if (t2 == NULL)
                t2 = headA;
        }
        return t1;
    }
};
