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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for (ListNode* temp : lists) {
            while (temp) {
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        std::sort(ans.begin(), ans.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        for (int x : ans) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return dummy->next;
    }
};
