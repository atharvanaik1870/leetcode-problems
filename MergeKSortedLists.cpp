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
//Approach 2: using minimum heap
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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            if (p.second->next) {
                pq.push({p.second->next->val, p.second->next});
            }
            //why second?? -> cox first has the value and 2ns is node
            temp->next = p.second;
            temp = temp->next;
        }
        return dummy->next;
    }
};
