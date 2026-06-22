class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0;
        int bottom = row - 1;
        int right = col - 1;
        int left = 0;
        vector<int> ans;

        while (left <= right && top <= bottom) {
            // 1st left to right and top is constant
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            // now go from top to bottom and right stays constant as we dont
            // want to move in horizotal direc.
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                // now go from right to left and bottom stays constant as we
                // dont want to move in vertical direc.
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                // now go from bottom to top and left stays constant as we dont
                // want to move in horizontal direc.
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
