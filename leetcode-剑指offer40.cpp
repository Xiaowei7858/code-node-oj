/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void AdJustDown(int* a, int n, int root) {
    int parent = root;
    int child = root * 2 + 1;
    while (child < n) {
        if (child + 1 < n && a[child + 1] > a[child]) {
            ++child;
        }
        if (a[child] > a[parent]) {
            int temp = a[parent];
            a[parent] = a[child];
            a[child] = temp;

            parent = child;
            child = parent * 2 + 1;
        }
        else {
            break;
        }
    }
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
    //建立大堆解决
    *returnSize = k;
    if (k == 0)
        return NULL;
    int* retArr = (int*)malloc(sizeof(int) * k);

    for (int i = 0; i < k; ++i) {
        retArr[i] = arr[i];
    }
    //建堆
    for (int i = (k - 1 - 1) / 2; i >= 0; --i) {
        AdJustDown(retArr, k, i);
    }

    //比较
    for (int j = k; j < arrSize; ++j) {
        if (arr[j] < retArr[0]) {
            retArr[0] = arr[j];
            AdJustDown(retArr, k, 0);
        }
    }
    return retArr;
}
