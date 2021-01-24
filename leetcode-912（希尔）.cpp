class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		int gap = nums.size();

		while (gap > 1) {
			gap = gap / 3 + 1;//保证最后一次为1
			for (int i = 0; i < nums.size() - gap; ++i) {
				//多组并排
				int end = i;
				int temp = nums[end + gap];
				while (end >= 0) {
					if (nums[end] > temp) {
						nums[end + gap] = nums[end];
						end -= gap;
					}
					else {
						break;
					}
				}
				nums[end + gap] = temp;
			}
		}
		return nums;
	}
};