/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size =  nums.size();
        vector<int> res;
        unordered_map<int, int> map;
        for (int i = 0; i < size; i++)
        {
            map[nums[i]] ++;
        }

        auto it = map.begin();
        for (; it != map.end(); it++)
        {
            if (1 == it->second)
            {
                res.push_back(it->first);
            }
        }

        return res;

        //         vector<int> v(2);
        
        // int xor_result = 0;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     xor_result ^= nums.at(i);
        // }

        // int separator = xor_result & (-xor_result); //以separator的二进制表示的位 划分两个单次(奇数次)数的到不同数组

        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     if ((nums.at(i) & separator) == 0) //在separator的二进制表示的位上为0
        //     {
        //         v.at(0) ^= nums.at(i);
        //     }
        //     else //在separator的二进制表示的位上为1
        //     {
        //         v.at(1) ^= nums.at(i);
        //     }
        // }

        // return v;

    }
};
// @lc code=end

