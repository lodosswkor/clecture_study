#include <stdio.h>

/*
버블 정렬은 첫 번째 자료와 두 번째 자료를, 두 번째 자료와 세 번째 자료를, 세 번째와 네 번째를, … 
이런 식으로 (마지막-1)번째 자료와 마지막 자료를 비교하여 교환하면서 자료를 정렬한다.
1회전을 수행하고 나면 가장 큰 자료가 맨 뒤로 이동하므로 
2회전에서는 맨 끝에 있는 자료는 정렬에서 제외되고, 
2회전을 수행하고 나면 끝에서 두 번째 자료까지는 정렬에서 제외된다. 이렇게 정렬을
1회전 수행할 때마다 정렬에서 제외되는 데이터가 하나씩 늘어난다.

*/

int main() {

    int arr[] = { 10, 9, 11, 20, 1, 5, 3, 6, 7, 4 };
    int tmp = 0;
    int length = sizeof(arr) / sizeof(int);

    printf("정렬 전 : \n");

    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    //-- 

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    printf("정렬 후: \n");

    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}