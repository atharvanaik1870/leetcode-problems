class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> m1;

        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                m1[nums2[i]] = -1;
            } else {
                m1[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        // this time we will go through nums1 as it is a subset of nums2 and
        // hecne it will have all the lelemnts from nums2 and we have to return
        // the ans in nums1 order.
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(m1[nums1[i]]);
        }

        return ans;
    }
};
