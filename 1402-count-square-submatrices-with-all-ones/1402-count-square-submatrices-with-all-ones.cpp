class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
    int count = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 1) {
                count++;
                int maxSquareSize = min(row - i, col - j);
                for (int k = 1; k < maxSquareSize; k++) {
                    bool isSquare = true;
                    for (int p = 0; p <= k; ++p) {
                        if (matrix[i + k][j + p] == 0 || matrix[i + p][j + k] == 0) {
                            isSquare = false;
                            break;
                        }
                    }
                    if (isSquare)
                        count++;
                    else
                        break;
                }
            }
        }
    }
    return count;
    }
};