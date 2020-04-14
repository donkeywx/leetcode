/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    bool isIncluded(vector<int>& tmp, int target)
    {
        for (int i = 0; i < tmp.size(); i++)
        {
            if (target == tmp[i])
            {
                return true;
            }
        }

        return false;
    }

    void helper(vector<vector<int> >&res, vector<int> tmp, int start, int k, int n)
    {
        if (0 == k && 0 == n)
        {
            res.push_back(tmp);
            return;
        }
        else if (n < 0 || 0 == k)
        {
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            // if (isIncluded(tmp, i))
            // {
            //     continue;
            // }
            tmp.push_back(i);
            helper(res, tmp, i+1, k-1, n-i);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> tmp;
        helper(res, tmp, 1, k, n);

        return res;
    }
};
// @lc code=end

