#include <stdio.h>

int main() {

    int arr[6] = { 3, 7, 2, 5, 1, 4 };
    int i, j; // �ݺ����� ����� ����
    int temp; // �� ���� �ٲ� �� ����� ����
    int length = sizeof(arr) / sizeof(int);

    printf("���� �� : ");
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    for (i = 1; i < length; i++) {
        temp = arr[i];
        j = i - 1; // 2
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }

    printf("\n���� �� : ");

    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}