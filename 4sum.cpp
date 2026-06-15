//pretty much similar to 3sum here we use 4 pointers and keep 2 constatnt and 2 running.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // just so that we dont pick duplicates move until next element is
            // not same as previous
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                // just so that we dont pick duplicates move until next element
                // is not same as previous
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = nums[i];
                      sum = sum +  nums[j];
                      sum = sum +  nums[k];
                      sum = sum +  nums[l];
                    if (sum > target) {
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);

                        k++;
                        l--;
                        // just so that we dont pick duplicates move until next
                        // element is not same as previous
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }
        return ans;
    }
};
