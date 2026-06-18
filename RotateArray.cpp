//Approach 1: using reverse logic
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
    }
};

//Approach 2: brute force, 1st move all the lement into the temp array from k to end of array and then move all elements from 0 to k

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        vector<int> ans;

        // Last k elements
        for (int i = n - k; i < n; i++)
            ans.push_back(nums[i]);

        // Remaining elements
        for (int i = 0; i < n - k; i++)
            ans.push_back(nums[i]);

        nums = ans;
    }
};
