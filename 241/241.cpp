/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
	vector<int> vec = {};

	for (int i = 0; i < input.length(); i++) {
		char c = input.at(i);
		
		if (c == '-' || c == '+' || c == '*') {//对于每个运算符号采取分治
			vector<int> left = diffWaysToCompute(input.substr(0, i));
			vector<int> right = diffWaysToCompute(input.substr(i + 1));
			for (int l : left){
				for (int r : right) {
					switch (c)
					{
					case '+':
						vec.push_back(l + r);
						break;
					case '-':
						vec.push_back(l - r);
						break;
					case '*':
						vec.push_back(l * r);
						break;
					default:
						break;
					}
				}
			}
		}
	}
	if (vec.size() == 0) {//input没有符号 则为数字
	/*	stringstream ss;
		int0<< input;
		ss >> a;*/
		vec.push_back(stoi(input));
	}
	return vec;
    }
};
// @lc code=end

