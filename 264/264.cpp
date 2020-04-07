/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if (1 == n)
        {
            return 1;
        }
        
        vector<int> res(n, 1);
        res[0] = 1;

        // dp
        int min2 = 0, min3 = 0, min5 = 0;
        for (int i = 1; i < n; i++)
        {
            int minval = min(min(res[min2] * 2, res[min3] * 3), 
                res[min5] * 5);
            if (minval == res[min2] * 2)
            {
                min2++;
            }
            if (minval == res[min3] * 3)
            {
                min3++;
            }
            if (minval == res[min5] * 5)
            {   
                min5++;
            }
            res[i] = minval;
        }

        /*每次取最小
        (1) 1×2, 2×2, 3×2, 4×2, 5×2, …
        (2) 1×3, 2×3, 3×3, 4×3, 5×3, …
        (3) 1×5, 2×5, 3×5, 4×5, 5×5, …
        */

        return res[n-1];
    }
};
// @lc code=end

