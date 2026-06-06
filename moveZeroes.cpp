//using two pointer approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int right =0; right < nums.size(); right++)
        {
            if(nums[right] != 0)
            {
                std::swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};

//Approach 2: using count to get num of 0s and then erase all and add the 0s at the end till count becomes 0
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i : nums)
        {
            if (i == 0)
                cnt++;
        }
        std::erase(nums, 0);
        while(cnt != 0)
        {
            nums.push_back(0);
            cnt--;
        }
    }
};
