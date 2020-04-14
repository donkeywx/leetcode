/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        map<long long, int> map;
        int size = nums.size();
        int start = 0;
        for (int i = 0; i < size; i++)
        {
            if (i - start > k)
            {
                map.erase(nums[start++]);
            }
            auto a = map.lower_bound((long long)nums[i] - t);
            if (map.end() != a && abs(a->first - nums[i]) <= t)
            {
                return true;
            }

            map[nums[i]] = i;
        }

        return false;
    }
};
// @lc code=end

