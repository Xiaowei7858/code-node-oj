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
