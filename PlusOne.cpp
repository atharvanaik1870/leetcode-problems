class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // we folloow the carry approach
        int carry = 1;
        int i = digits.size() - 1;
        vector<int> ans(digits.size());
        int digit = 0;

        while (i >= 0) {
            int sum = digits[i] + carry;
            carry = sum / 10;
            ans[i] = sum % 10;
            i--;
        }

        if (carry != 0) {
            ans.insert(ans.begin(), carry);
        }
        return ans;
    }
};
