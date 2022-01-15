//leetcode-215
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //构建最大堆
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
    //向下调整
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }
    //建立最大堆
    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }
};

//niuke-JZ31
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;
        int i = 0, j = 0;
        st.push(pushV[j]);
        while (i < popV.size()) {
            if (!st.empty() && st.top() == popV[i]) {
                i++;
                st.pop();
            }
            else {
                j++;
                if (j < pushV.size())
                    st.push(pushV[j]);
                else
                    break;
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};