class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                int up = (i == 0) ? -1 : mat[i - 1][j];
                int down = (i == rows - 1) ? -1 : mat[i + 1][j];
                int left = (j == 0) ? -1 : mat[i][j - 1];
                int right = (j == cols - 1) ? -1 : mat[i][j + 1];

                if (mat[i][j] > up &&
                    mat[i][j] > down &&
                    mat[i][j] > left &&
                    mat[i][j] > right) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};