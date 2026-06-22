//Approach1: using extra arrays to mark rows and cols which contain atleast one 0 and then 
//lastly if that row/col has any zeros which wehave marked earlier then we set all the elements in that row/col as zero
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> r1(rows, 0);
        vector<int> c1(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == 0) {
                    r1[i] = 1;
                    c1[j] = 1;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (r1[i] == 1 || c1[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
