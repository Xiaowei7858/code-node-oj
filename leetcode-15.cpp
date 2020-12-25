class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        int len = nums.size();
        vector<vector<int>> threesum;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] > 0) return threesum;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = len - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > -nums[i]) right--;
                else if (nums[left] + nums[right] < -nums[i]) left++;
                else
                {
                    threesum.push_back({ nums[i],nums[left],nums[right] });
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return threesum;
    }
};