class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = (int)(1e9 + 7);

        vector<int> NSE = gettNSE(arr, n);
        vector<int> PSE = gettPSE(arr, n);

        typedef long long ll;
        ll sum = 0;

        for (int i = 0; i < n; i++) {
            ll left = i - PSE[i];
            ll right = NSE[i] - i;

            ll total = (left * right) % mod;

            sum = (sum + (total * arr[i]) % mod) % mod;
        }
        return sum;
    }
    vector<int> gettPSE(vector<int> arr, int n) {
        stack<int> st;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }
    vector<int> gettNSE(vector<int> arr, int n) {
        stack<int> st;
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }
};
