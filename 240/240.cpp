/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty())
        {
            return false;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = rows - 1;
        int col = 0;
        // 从左下角出发，向右变大，向上变小
        while(col < cols && row >= 0)
        {
            if (target == matrix[row][col])
            {
                return true;
            }
            else if (target > matrix[row][col])
            {
                col++;
            }
            else
            {
                row--;
            }
            
        }

        return false;

    }
};
// @lc code=end

