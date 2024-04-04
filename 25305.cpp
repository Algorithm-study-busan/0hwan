#include <iostream>

void swap(int list[], int a, int b, int temp) { temp = list[a]; list[a] = list[b]; list[b] = temp;}

int partition(int list[], int left, int right);
void quick_sort(int list[], int left, int right);

int main() {
    int N; // 1 <= N <= 1000
    int k; // 1 <= k <= N

    std::cin >> N >> k; // 학생수, 커트라인 학생 수

    int* score = new int[N];

    for (int i = 0; i < N; i++) {
        std::cin >> score[i];
    }

    // 퀵정렬

    quick_sort(score, 0, N-1);

    // 결과 출력
    std::cout << score[N-k];

    delete[] score;

}

int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left;
    pivot = list[left];
    high = right + 1;

    do {
        do {
            low++;
        } while (low <= right && list[low] < pivot);

        do {
            high--;
        } while (high >= left && list[high] > pivot);

        if (low < high) swap(list, low, high, temp);

    } while (low < high);

    swap(list, left, high, temp);

    return high; // 피봇 위치 반환
}

void quick_sort(int list[], int left, int right) {

    if (left < right) {
        int q = partition(list, left, right);

        quick_sort(list, left, q-1); // 이전 피봇의 왼쪽 리스트를 정렬
        quick_sort(list, q+1, right);// 이전 피봇의 오른쪽 리스트 정렬
    }
}