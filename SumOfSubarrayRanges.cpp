class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int mod = (int)(1e9 + 7);

        long long maxSum = subnumsayMaxs(nums);
        long long minSum = subnumsayMins(nums);

        long long ans = (maxSum - minSum) % mod;

        if (ans < 0)
            ans += mod;

        return ans;
    }

    long long subnumsayMins(vector<int>& nums) {
        int n = nums.size();
        int mod = (int)(1e9 + 7);

        vector<int> nse = getNSE(nums, n);
        vector<int> pse = getPSE(nums, n);

        long long sum = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long total = (left * right) % mod;

            sum = (sum + (total * nums[i]) % mod) % mod;
        }

        return sum;
    }

    long long subnumsayMaxs(vector<int>& nums) {
        int n = nums.size();
        int mod = (int)(1e9 + 7);

        vector<int> nge = getNGE(nums, n);
        vector<int> pge = getPGE(nums, n);

        long long sum = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pge[i];
            long long right = nge[i] - i;

            long long total = (left * right) % mod;

            sum = (sum + (total * nums[i]) % mod) % mod;
        }

        return sum;
    }

    vector<int> getNSE(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> ans(n);

        // RIGHT -> LEFT
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() &&
                   nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> getPSE(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> ans(n);

        // LEFT -> RIGHT
        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> getNGE(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> ans(n);

        // RIGHT -> LEFT
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() &&
                   nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> getPGE(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> ans(n);

        // LEFT -> RIGHT
        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }
};
