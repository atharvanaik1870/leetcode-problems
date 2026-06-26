//Note: this seems easy but is really complex problem to understand. pay great attention to the logic
class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int count = 0;

        int n = nums.size();
        while (r < n - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = std::max(i + nums[i], farthest);
            }
            l = r + 1;
            r = farthest;
            count++;
        }
        return count;
    }
};
