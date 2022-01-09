//leetcode-125
class Solution {
public:
    bool isPalindrome(string s) {
        std::string::iterator itb = s.begin();
        std::string::iterator ite = s.end() - 1;
        while (itb < ite) {
            if (!isalnum(*itb)) {
                itb++;
                continue;
            }
            if (!isalnum(*ite)) {
                ite--;
                continue;
            }
            if (isdigit(*itb) && isdigit(*ite) && (*itb != *ite))
                return false;
            if ((isdigit(*itb) && !isdigit(*ite)) || (!isdigit(*itb) && isdigit(*ite)))
                return false;
            if ((*ite != *itb) && (abs(*ite - *itb) != 32))
                return false;
            itb++;
            ite--;
        }
        return true;
    }
};

//leetcode-541
class Solution {
public:
    string reverseStr(string s, int k) {
        std::string::iterator it1 = s.begin();
        std::string::iterator it2 = s.begin() + k;
        while (s.end() - it1 > 2 * k) {
            reverse(it1, it2);
            it1 += 2 * k;
            it2 = it1 + k;
        }
        if (s.end() - it1 >= k) {
            reverse(it1, it2);
        }
        else {
            reverse(it1, s.end());
        }

        return s;
    }
};

//leetcode-557
class Solution {
public:
    string reverseWords(string s) {
        std::string::iterator it1 = s.begin();
        std::string::iterator it2 = it1;
        char c = ' ';
        while (it2 < s.end()) {
            while (*it2 != c && it2 < s.end())
                it2++;
            reverse(it1, it2);
            it1 = it2 + 1;
            it2 = it1;
        }
        return s;
    }
};

//leetcode-43
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto& c : curr) {
                c += '0';
            }
            ans = addStrings(ans, curr);
        }
        return ans;
    }

    string addStrings(string& num1, string& num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto& c : ans) {
            c += '0';
        }
        return ans;
    }
};