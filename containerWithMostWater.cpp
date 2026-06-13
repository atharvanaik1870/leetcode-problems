class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while (left < right) {
            int width = right - left;
            int height1 = std::min(height[left], height[right]);
            int currWater = width * height1; // something like area of rectangle

            if (height[left] < height[right]) {
                left++;
            } else
                right--;

            ans = std::max(currWater, ans);
        }
        return ans;
    }
};
