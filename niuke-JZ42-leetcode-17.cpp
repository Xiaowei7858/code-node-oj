//牛客-JZ42
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int size = array.size();
        vector<int> dp(size + 1, 1);
        dp[0] = 0;
        int ret = array[0];
        for (int i = 1; i <= size; ++i) {
            //相当于如果dp[i-1]小于0，就选择array[i-1]
            dp[i] = max(array[i - 1], dp[i - 1] + array[i - 1]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

//leetcode-17
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.length() == 0)
            return combinations;
        unordered_map<char, string> PhoneMap = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        string combination;
        backtrack(digits, PhoneMap, 0, combinations, combination);
        return combinations;
    }
    void backtrack(const string& digits, const unordered_map<char, string>& PhoneMap, int index, vector<string>& combinations, string& combination) {
        if (combination.length() == digits.length()) {
            combinations.push_back(combination);
        }
        else {
            char digit = digits[index];
            const string& letters = PhoneMap.at(digit);
            for (const char& letter : letters) {
                combination.push_back(letter);
                backtrack(digits, PhoneMap, index + 1, combinations, combination);
                combination.pop_back();
            }
        }
    }
};