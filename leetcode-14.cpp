class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //∫·œÚ…®√Ë
        if (!strs.size()) return "";
        int len = strs.size();
        string Prefix = strs[0];
        for (int n = 1; n < len; ++n) {
            Prefix = longestCommonPrefix(Prefix, strs[n]);
            if (!Prefix.size()) break;
        }
        return Prefix;
    }

    string longestCommonPrefix(const string& s1, const string& s2) {
        int len = s1.size() > s2.size() ? s2.size() : s1.size();
        int index = 0;
        while (len-- && s1[index] == s2[index]) {
            index++;
        }
        return s1.substr(0, index);
    }
};