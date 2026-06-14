//use freq array and not map, map can be used but its easy this way

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        vector<int> freq(nums.size() + 1, 0);

        for (int& i : nums) {
            freq[i]++;

            if (freq[i] == 2)
                ans.push_back(i);
        }
        for (int i = 1; i <= nums.size(); i++) {

            if (freq[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
