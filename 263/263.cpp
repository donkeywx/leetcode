/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        
        if (num <= 0)
        {
            return false;
        }
        if (1 == num)
        {
            return true;
        }

        bool res = false;
        while(true)
        {
            if (1 == num || 2 == num 
                || 3 == num || 5 == num)
            {
                res = true;
                break;
            }
            else if (num % 2 == 0)
            {
                num /= 2;
            }
            else if (num % 3 == 0)
            {
                num /= 3;
            }
            else if (num % 5 == 0)
            {
                num /= 5;
            }
            else
            {
                res = false;
                break;
            }
            
        }

        return res;
    }
};
// @lc code=end

