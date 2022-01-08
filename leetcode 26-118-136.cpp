//leetcode-136
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::vector<int>::iterator itb = nums.begin();
        std::vector<int>::iterator ite = nums.end();
        int sn = 0;
        while (itb != ite) {
            sn = sn ^ *itb;
            itb++;
        }
        return sn;
    }
};

//leetcode-118
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> gen(numRows);
        for (int i = 0; i < numRows; ++i) {
            gen[i].resize(i + 1);
            gen[i][i] = gen[i][0] = 1;
            for (int j = 1; j < i; ++j) {
                gen[i][j] = gen[i - 1][j] + gen[i - 1][j - 1];
            }
        }
        return gen;
    }
};

//leetcode-26
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int slow = 1, fast = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            fast++;
        }
        return slow;
    }
};