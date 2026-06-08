// Approach taken: use prefix to track from start and suffic to track from right(end) and then we try to find the max product all these 2 and since we can havbe -ve values we use prefix and suffix.
//https://www.youtube.com/watch?v=hnswaLJvr6g
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        int maxi = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix=1;
            if (suffix == 0) suffix=1;
            
            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];
            maxi = std::max(std::max(prefix, suffix), maxi);
        }
        return maxi;
    }
};
