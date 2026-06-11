class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3)
            return nums[n - 1];
        set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        if (s.size() >= 3) {
            int third = s.size() - 3;
            auto t = std::next(s.begin(), third);
            return *t;
        } else {
            // using --s.end() to access the last element from the set. s.end()
            // points to the last elemnt in set
            return *--s.end();
        }
    }
};
