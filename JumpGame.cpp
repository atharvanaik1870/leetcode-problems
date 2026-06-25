class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIndex)
                return false; // this measn we have a 0

            maxIndex = std::max(maxIndex, i + nums[i]);
        }
        return true;
    }
};
// Note: this is Greedy algorithm - think of it as max amount of something u can do greedily
