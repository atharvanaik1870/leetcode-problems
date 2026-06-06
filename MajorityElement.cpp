//using hashMap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        // to check if element occurs more thne n/2 times we updatd the value of
        // n
        n = n / 2;

        for (auto x : m) {
            if (x.second > n)
                return x.first;
        }
        return 0;
    }
};

//Approach 2: using simple sorting technique
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //when we sort the element which is more then n/2 in the array will occur at middle position
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }
};
