class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        int len = nums.size();
        vector<vector<int>> threesum;
        int start = 0, middle = 1, end = len - 1;
        //记录保存二维数组的新数组的一维变量
        int k = 0, flag = 1, prev = 0;
        while (end >= 2) {
            int twosum = nums[start] + nums[end];
            while (end - start >= 1) {
                for (int i = middle; i < end; ++i) {
                    if (twosum + nums[i] == 0) {
                        threesum.push_back({ nums[start],nums[middle],nums[end] });
                    }
                }
            }
        }
        return threesum;
    }
};