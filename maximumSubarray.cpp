//This is Kedane's algo woth O(n) time complexity.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }
        return maxSum;
    }
};

// Approach 2: Brute force with O(n^2) time complexity maybe not best solution but still works
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int currSum = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                currSum = currSum + nums[j];
                if (currSum > maxSum) {
                    maxSum = currSum;
                }
            }
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
        return maxSum;
    }
};
