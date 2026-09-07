//concept is easy revise it more https://youtu.be/NwBvene4Imo?si=WjllpKvShDH0nbSp

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            //remove elements outside window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            //remove smaller elements
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);

            //window is complete and add the max element which will be at the end of queue that is front element
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
