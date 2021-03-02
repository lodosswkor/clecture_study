#include <stdio.h>

/*
제자리 정렬(in-place sorting) 알고리즘의 하나
입력 배열(정렬되지 않은 값들) 이외에 다른 추가 메모리를 요구하지 않는 정렬 방법
해당 순서에 원소를 넣을 위치는 이미 정해져 있고, 어떤 원소를 넣을지 선택하는 알고리즘
첫 번째 순서에는 첫 번째 위치에 가장 최솟값을 넣는다.
두 번째 순서에는 두 번째 위치에 남은 값 중에서의 최솟값을 넣는다.
…
과정 설명
주어진 배열 중에서 최솟값을 찾는다.
그 값을 맨 앞에 위치한 값과 교체한다(패스(pass)).
맨 처음 위치를 뺀 나머지 리스트를 같은 방법으로 교체한다.
하나의 원소만 남을 때까지 위의 1~3 과정을 반복한다.
https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html
*/

int main() {

    int arr[6] = { 3, 7, 2, 5, 1, 4 };
    int length = sizeof(arr) / sizeof(int);
    int max, tmp;

    printf("정렬 전 : ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < length - 1; i++) {
        max = i;

        // 1, 최소값을 탐색한다.
        for (int j = i + 1; j < length; j++) {
            if (arr[j] > arr[max])
                max = j;
        }

        // 최소값이 자기 자신이 아닐때, 교환
        if (i != max) {
            tmp = arr[i];
            arr[i] = arr[max];
            arr[max] = tmp;
        }
    }


    printf("\n정렬 후 : ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}