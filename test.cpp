// 求根到叶子节点数字之和
void helper(TreeNode* root, vector<int>& res, int curVal)
{
    if (nullptr == root)
    {
        res.push_back(curVal);
    }

    curVal = curVal * 10 + root->val;
    helper(root->left, res, curVal);
    helper(root->right, res, curVal);
}
int sumNumbers(TreeNode* root, int curVal)
{
    vector<int> res;
    helper(root, 0, res);

    int sum = 0;
    for (int i = 0; i < res.size(); i++)
    {
        sum += res[i];
    }

    return sum;
}
// 填充每个节点的下一个右侧节点指针二
void helper(Node* root)
{
    if (nullptr == root || (!root->left && !root->right))
    {
        return;
    }
    if (root->left && root->right)
    {
        root->left->next = root->right;
    }

    Node* cur = root->right ? root->right : root->left;
    Node* tmp = root->next;
    while(tmp)
    {
        if (tmp->left)
        {
            cur->next = tmp->left;
        }
        else if (tmp->right)
        {
            cut->next = tmp->right;
        }

        tmp = tmp->next;
    }


    helper(root->right);
    helper(root->left);
}

void helper(Node* root)
{
    if  (nullptr == root)
    {
        return nullptr;
    }

    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        int size = qu.size();

        for (int i = 0; i < size; i++)
        {
            Node* cur = qu.top();
            qu.pop();
            if (i < size - 1)
            {
                cut->next = qu.top();
            }

            if (cur->left)
            {
                qu.push(cur->left);
            }
            else
            {
                qu.push(cur->right);
            }
        }
    }
}
Node* connect(Node* root)
{
    helper(root);

    return root;
}

// 填充每个节点的下一个右侧节点指针
void helper(Node* root)
{
    if (nullptr == root)
    {
        return;
    }

    if (root->left && root->right)
    {
        root->left->next = root->right;
    }
    if (root->next && root->right)
    {
        root->right->next = root->next->left;
    }

    helper(root->left);
    helper(root->right);
}
Node* connect(Node* root)
{
    helper(root);

    return root;
}

// BiNode
TreeNode* helper(TreeNode* root, TreeNode* pre)
{
    if (nullptr == root)
    {
        return root;
    }

    helper(root->left, pre);
    pre->right = root;
    root->left = nullptr;
    pre = root;
    helper(root->right, pre);
}
TreeNode* convertBiNode(TreeNode* root)
{
    if (nullptr == root)
    {
        return nullptr;
    }

    TreeNode* head = new TreeNode(-1);
    head->right = nullptr;
    helper(root, head);

    return head->right;
}

// 二叉树展开为链表
TreeNode* helper(TreeNode* root)
{
    if (nullptr == root)
    {
        return nullptr;
    }

    TreeNode* leftEnd = helper(root->left);
    TreeNode* rightEnd = helper(root->right);

    if (leftEnd)
    {
        leftEnd->right = root->right;
        root->right = leftEnd;
        root->left = nullptr;
    }

    if (rightEnd)
    {
        return rightEnd;
    }

    if (leftEnd)
    {
        return leftEnd;
    }

    return root;
}
void flatten(TreeNode* root)
{

}

// 路径总和二
void helper(vector<vector<int> >& res, vector<int> tmp, TreeNode* root, int sum)
{
    if (nullptr == root && 0 == sum)
    {
        res.push_back(tmp);
    }

    if (nullptr == root)
    {
        return;
    }

    tmp.push_back(root->val);
    helper(res, tmp, root->left, sum - root->val);
    helper(res, tmp, root->right, sum - root->val);
}

vector<vector<int> > pathSum(TreeNode* root, int sum)
{
    vector<vector<int> >res;
    vector<int> tmp;
    helper(res, tmp, root, sum);

    return res;
}

// 路径总和
bool helper(TreeNode* root, int sum)
{
    if (nullptr == root && 0 == sum)
    {
        return true;
    }

    if (nullptr == root)
    {
        return false;
    }

    return  helper(root->left, sum - root->val)
        || helper(root->right, sum - root-val);
}

bool hasPathSum(TreeNode* root, int sum)
{
    return helper(root, sum);
}

// 二叉树的最小深度
int minDepth(TreeNode* root)
{
    if (nullptr == root)
    {
        return 0;
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    return (left > right ? right : left) + 1;
}

// 将有序数组转换为二叉搜索树
TreeNode* helper(vector<int>& nums, int l, int r)
{
    if (l > r)
    {
        return nullptr;
    }

    int mid = (r - l) / 2 + l;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, l, mid - 1);
    root->right = helper(nums, mid + 1, r);

    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums)
{
    TreeNode* root = helper(nums, 0, nums.size());

    return root;
}

// 实现strStr()
int* getNext(string needle)
{
    int* next = new int[needle.size()];
    next[0] = -1;
    next[1] = 0;
    int i = 0;
    int j = -1;
    while (i < needle.size())
    {
        if (-1 == j || needle[i] == needle[j])
        {
            next[++i] = ++j;
        }
        else
        {
            j = next[j];
        }
    }
    return next;
}
int strStr(string haystack, string needle)
{
    int len1 = haystack.size();
    int len2 = needle.size();

    int i = 0;
    int j = 0;

    int* next = getNext(needle);
    while(i < len1 && j < len2)
    {
        if (0 == j || haystack[i] == needle[j])
        {
            i++;
            j++;
            if (j == len2)
            {
                return --i;
            }
        }
        else
        {
            j = next[j];
        }
    }

    // if (len2 == j)
    // {
    //     return j;
    // }

    return -1;
}
// 括号生成
void helper(vector<string>& res, string tmp, int left, int right)
{
    if (left > right)
    {
        return;
    }
    if (0 == left && 0 == right)
    {
        res.push_back(tmp);
    }
    if (left > 0 )
    {
        tmp.push_back('(');
        helper(res, tmp, left-1,  right);
        tmp.pop();
    }

    if (right > 0)
    {
        tmp.push_back(')');
        helper(res, tmp, left, right - 1);
        tmp.pop();
    }
}
vector<string> generateParenthesis(int n)
{

}

// 电话号码的字母组合

void helper(vector<string>& res, string tmp, string digits, int index, vector<string>& dict)
{
    if (index >= digits.size())
    {
        return;
    }

    int num = digits[index] - '0';
    for (int i = 0; i < dict[num].size(); i++)
    {
        tmp.push_back(dict[num][i]);
        helper(res, tmp, digits, ++index, dict);
        
        --index;
        tmp.pop();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
    {
        return {};
    }
    vector<string> dict{"abc"};

    vector<string> res;
    string tmp "";
    helper(res, tmp, digits, 0, dict)
}

// 字符串转数字
int string2Int(string str)
{
    int res = 0;
    int size = str.size();

    int index = 0;
    while(index < size && ' ' == str[index])
    {
        index++;
    }
    int flag = '-' == str[index++] ? 0 : 1;
    for (int i = 0; i < size; i++)
    {
        if ((res > INT_MAX / 10)
            || (INT_MAX / 10 == res && str[i] > '7'))
        {
            return 0 == flag ? INT_MAX : INT_MIN;
        }
        res += res * 10 + str[i] - '0';
    }

    return 0 == flag ? res : -res;
}

// 数字转罗马
string intToRoman(int num)
{
    string res = "";
    int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++)
    {
        while(num >= nums[i])
        {
            res += roman[i];
            num -= nums[i];
        }
    }
    return res;
}

// 罗马转数字
int romanToInt(string s)
{
    int res = 0;
    unordered_map<char, int> map{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 100}
    };
    for (int i = 0; i < s.size(); i++)
    {
        int tmp = map[s[i]];
        if (s.size() - 1 == i || map[s[i+1]] < map[s[i]])
        {
            res += tmp;
        }
        else
        {
            res -= tmp;
        }
    }

    return res;
}

// 无重复字符的最长子串
int lengthOfLongestSubstring(string s)
{
    int res = 0;
    unordered_map<char, int> map;
    int size = s.size();

    int left = 0;
    for (int i = 0; i < size; i++)
    {
        if (!map.count(s[i]))
        {
            map[s[i]] = i;
            res = max(res, i - left + 1);
        }
        else
        {
            int tmp = map[s[i]];
            while(left <= tmp)
            {
                map.erase(s[left]);
                left++;
            }
            map[s[i]] = i;
        }
    }

    return res;
}

// 最长回文子串
string longestPalindrome(string s)
{
    int size = s.size();
    int dp[size][size] {0};
    int len = 0;
    int start = 0;
    for (int j = 0; j < size; j++)
    {
        dp[j][j] = 1;   // 00 11 01 22
        for (int i = 0; i < j; i++)
        {
            dp[i][j] = (s[i] == s[j]) && (j - i < 2 || dp[i+1][j-1]);
            if (j - i + 1 > len)
            {
                len = j - i + 1;
                start = i;
            }
        }
    }

    return s.substr(start, len);
}

// int helper(vector<int>& nums, int index, bool isUp)
// {
//     int maxcount = 0;
//     for (int i = index + 1; i < nums.size(); i++)
//     {
//         if ((isUp && nums[index] < nums[i]) 
//             || (!isUp && nums[index] > nums[i]))
//         {
//             maxcount = max(maxcount, 1 + helper(nums, i, !isUp));
//         }
//     }

//     return maxcount;
// }

// int wiggleMaxLength(vector<int>& nums)
// {
//     if (nums.size() < 2)
//     {
//         return nums.size();
//     }

//     return 1 + max(helper(nums, 0, true), helper(nums, 0, false));
// }

// // 动态规划
// int wiggleMaxLength(vector<int>& nums)
// {
//     if (nums.size() < 2)
//     {
//         return nums.size();
//     }

//     vector<int> up(0, nums.size());
//     vector<int> down(0, nums.size());

//     for (int i = 1; i < nums.size(); i++)
//     {
//         for (int j = 0; j < i; i++)
//         {
//             if (nums[j] < nums[i])
//             {
//                 up[i] = max(up[i], down[j] + 1);
//             }
//             else
//             {
//                 down[i] = max(down[i], up[j] + 1);
//             }
            
//         }
//     }
//     return 1 + max(down[nums.size() - 1], up[nums.size() - 1]);
// }

// // 贪心
// int wiggleMaxLength(vector<int>& nums)
// {
//     if (nums.size() < 2)
//     {
//         return nums.size();
//     }

// }

// string removeKdigits(string num, int k)
// {
//     stack<char> st;
//     for (int i = 0; i < num.size(); i++)
//     {
//         // 左边的数字大于右边的就需要弹出
//         while(st.size() > 0 && k > 0 && st.top() > num[i])
//         {
//             st.pop();
//             k--;
//         }

//         st.push(num[i]);
//     }

//     // 剩下的都是左边比较小的，直接弹出就可以
//     for (int i = 0; i < k)
//     {
//         st.pop();
//     }

//     string res = "";
//     bool leadingzero = true;
//     for (int i = 0; i < st.size(); i++)
//     {
//         if  (leadingzero && st.top() == '0')
//         {
//             st.pop();
//             continue;
//         }
//         leadingzero = false;
//         res.push_back(st.top());
//         st.pop();
//     }

//     reverse(res.begin(), res.end());
//     if (res.empty())
//     {
//         return "0";
//     }

//     return res;
// }


// vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
// {

// }

// int maxProfit(vector<int>& prices)
// {
//     int res = 0;
//     int size = prices.size();
//     int min = prices[0];
//     for (int i = 1; i < size; i++)
//     {
//         if (min < prices[i])
//         {
//             min = prices[i];
//         }
//         else
//         {
//             res += prices[i] - min;
//             min = prices[i];
//         }
//     }    

//     return res;
// }