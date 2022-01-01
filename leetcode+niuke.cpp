#include<iostream>
#include<string>
using namespace std;

//string to int
class Solution {
public:
    int StrToInt(string str) {
        if (!str.size()) return 0;
        long long res = 0L;
        int s = 1;
        if (str[0] == '-') s = -1;
        for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
            i < str.size(); i++) {
            if (!isdigit(str[i])) return 0;
            res = res * 10 + (str[i] - '0');
        }
        return res * s;
    }
};

//leetcode-415
class Solution {
public:
    string addStrings(string num1, string num2) {
        string str;
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            str.push_back(result % 10 + '0');
            add = result / 10;
            i--;
            j--;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

//leetcode-344
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

//leetcode-387
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> frequency;
        for (char ch : s) {
            ++frequency[ch];
        }
        for (int i = 0; i < s.length(); i++) {
            if (frequency[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

//HJ1 字符串最后一个单词的长度
#include<iostream>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int len = 0;
    string::reverse_iterator rit = str.rbegin();
    while (*rit != ' ' && rit != str.rend()) {
        len++;
        rit++;
    }
    cout << len << endl;
    return 0;
}