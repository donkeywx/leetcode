/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        vector<int> res(size, 1);
        
        int mul = 1;
        for (int i = 1; i < size; i++)
        {
            mul *= nums[i-1];
            res[i] = mul;
        }

        mul = 1;
        for (int i = size - 2; i >= 0; i--)
        {
            mul *= nums[i+1];
            res[i] *= mul;
        }

        return res;
    }
};
// @lc code=end

