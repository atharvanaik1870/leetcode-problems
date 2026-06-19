class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans=0;

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        for(int i=1;i<n;i++)
        {
            leftMax[i] = std::max(leftMax[i-1], height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i] = std::max(rightMax[i+1], height[i]);
        }

        for(int i=0;i<n;i++)
        {
            ans = ans + (std::min(rightMax[i], leftMax[i]) - height[i]);
        }
        return ans;
    }
};
