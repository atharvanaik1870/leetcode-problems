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
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode * temp = head;

        while(temp)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }

        std::sort(ans.begin(), ans.end());

        //conver array to string again
        ListNode * dummy = new ListNode(-1);
        temp=dummy;

        for(int arr:ans)
        {
            temp->next = new ListNode(arr);
            temp=temp->next;
        }
        return dummy->next;
    }
};

//Approach 2: using merge sort
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
    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        ListNode* left = head;
        middle->next = NULL;

        ListNode* l1 = sortList(left);
        ListNode* l2 = sortList(right);

        return MergeList(l1, l2);
    }
    ListNode* MergeList(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                curr = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                curr = l2;
                l2 = l2->next;
            }
        }

        if (l1) {
            curr->next = l1;
        } else if (l2) {
            curr->next = l2;
        }

        return dummy->next;
    }
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
