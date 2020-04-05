/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        if (citations.empty())
        {
            return 0;
        }

        int left = 0;
        int size = citations.size();
        int right = citations.size() - 1;

        while (left + 1 < right)
        {
            int mid = (right - left) / 2 + left;

            // 题目给的例子，太难懂，
            // citations的值要大于等于 (大于等于citations值的个数)
            // 最小citations的值。
            if (citations[mid] >= size - mid)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
            
        }

        if (size - left <= citations[left])
        {
            return size-left;
        }

        if (size - right <= citations[right])
        {
            return size-right;
        }

        return 0;
        
    }
};
// @lc code=end

