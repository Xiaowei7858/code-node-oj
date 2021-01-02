class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //贪心策略：若当前元素之和<0,则丢弃之前的元素
        //思考？为什么之前和>0才可以加呢，因为只有之前和大于0，才能说明有希望成为更大的数字，要加当前数字
        //若前面之和小于0，如果相加，不是在阻碍变大吗

        int prevsum = nums[0];
        int maxsum = prevsum;
        for (int i = 1; i < nums.size(); ++i)
        {
            prevsum = max(nums[i], prevsum + nums[i]);
            maxsum = max(prevsum, maxsum);
        }
        //动态规划：若前一个元素>0,则将其加到当前元素上
        return maxsum;
    }
};