//Approach 1: use count to count occurences of any number (brute force but better)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == nums[i + 1]) {
                count++;
            } else if (nums[i] != nums[i + 1] && count == 0) {
                return nums[i];
            } else if (nums[i] != nums[i + 1] && count != 0) {
                count = 0;
                ;
            }
        }
        return nums[n - 1];
    }
};

//Approach 2: Use hasmap
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for( auto x: m)
        {
            if(x.second == 1)
            return x.first;
        }
        return 0;
    }
};
