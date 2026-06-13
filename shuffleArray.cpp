class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int count = n;
        for(int i=0;i<n*2;i++)
        {
            if(i%2 == 0)
                ans.push_back(nums[i/2]);
            else
                ans.push_back(nums[n+i/2]);
        }
        return ans;
    }
};
