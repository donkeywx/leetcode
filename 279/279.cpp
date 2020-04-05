/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isSquare(int n)
    {
        int tmp = sqrt(n);
        return tmp*tmp == n;
    }
    int numSquares(int n) {
        if(n <= 0) return 0;
        if(isSquare(n)) return 1;
        
        vector<int> dp(n+1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (isSquare(i))
            {
                dp[i] = 1;
                continue;
            }

            int minRes = n;
            for (int j = 1; j * j < i; j++)
            {
                // dp[i]=min(dp[i],dp[i-j*j]+1)这种也是可以的
                minRes = min(minRes, dp[i - j*j] + dp[j*j]);
            }
            dp[i] = minRes;
        }

        return dp[n];
    }

    //https://blog.csdn.net/qq_41855420/article/details/88248959
    // 没看懂bfs和dfs的区别。为什么dfs会超时
};
// @lc code=end

