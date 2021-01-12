/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void AdJustDown(int* array, int k, int root) {
    int parent = root;
    int child = root * 2 + 1;
    while (child < k) {
        if (child + 1 < k && array[child + 1] > array[child]) {
            child++;
        }
        if (array[child] > array[parent]) {
            int temp = array[parent];
            array[parent] = array[child];
            array[child] = temp;
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
    if (!k) return NULL;
    int* array = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; ++i) {
        array[i] = arr[i];
    }
    //建堆
    for (int i = (k - 1 - 1) / 2; i >= 0; --i) {
        AdJustDown(array, k, i);
    }

    //比较
    for (int j = k; j < arrSize; ++j) {
        if (arr[j] < array[0]) {
            array[0] = array[j];
            AdJustDown(array, k, 0);
        }
    }
    *returnSize = k;
    return array;
}