/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
        {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int> > dp(rows, vector<int>(cols, 0));
        
        int res = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if ('0' == matrix[i][j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0)
                    {
                        dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));

                    }

                    res = max(res, dp[i][j]);
                }
                
            }
        }

        return res*res;
    }
};
// @lc code=end

