class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //̰�Ĳ��ԣ�����ǰԪ��֮��<0,����֮ǰ��Ԫ��
        //˼����Ϊʲô֮ǰ��>0�ſ��Լ��أ���Ϊֻ��֮ǰ�ʹ���0������˵����ϣ����Ϊ��������֣�Ҫ�ӵ�ǰ����
        //��ǰ��֮��С��0�������ӣ��������谭�����

        int prevsum = nums[0];
        int maxsum = prevsum;
        for (int i = 1; i < nums.size(); ++i)
        {
            prevsum = max(nums[i], prevsum + nums[i]);
            maxsum = max(prevsum, maxsum);
        }
        //��̬�滮����ǰһ��Ԫ��>0,����ӵ���ǰԪ����
        return maxsum;
    }
};