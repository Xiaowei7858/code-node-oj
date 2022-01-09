//leetcode-137
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto [num, occ] : freq) {
            if (occ == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};

//leetcode-260
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        vector<int> ans;
        for (auto [num, acc] : freq) {
            if (acc == 1) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};