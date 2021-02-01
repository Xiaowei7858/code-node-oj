#include<stdio.h>
#include<string.h>

//¿ìÅÅ
void Swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
int qsort(char* a, int begin, int end) {
    int index = end;

    while (begin < end) {
        while (begin < end && a[begin] <= a[index]) {
            begin++;
        }
        while (begin < end && a[end] >= a[index]) {
            end--;
        }
        Swap(&a[begin], &a[end]);
    }
    Swap(&a[begin], &a[index]);
    return begin;
}
void quicksort(char* a, int left, int right) {
    if (left >= right)
        return;

    int div = qsort(a, left, right);
    quicksort(a, left, div - 1);
    quicksort(a, div + 1, right);
}

int main() {

    char a[20];
    printf("ÇëÊäÈë×Ö·û´®:\n");
    gets(a);
    int len = strlen(a);
    quicksort(a, 0, len - 1);
    for (int i = 0; i < len; i++) {
        printf("%c", a[i]);
    }
    return 0;
}