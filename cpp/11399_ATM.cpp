#include <iostream>
#include <algorithm>

int main() {
    // 문제 설명
    // 총 N명의 사람이 돈을 인출
    // 줄을 선 사람마다 걸리는 시간이 존재
    // 5명이 있다고 할 때, 각걸리는 시간이 순서대로
    // 3, 1, 4, 3, 2 가 걸린다고 하면
    // 순서대로 돈을 인출하는 경우, 3, 3+1, 3+1+4, ... 3+1+4+3+2 가 걸리며
    // 총 3+4+8+11+13 = 39분이 걸림
    // 이 시간이 최소가 되도록해야함

    int N;

    std::cin >> N;

    int* time = new int[N];
    int* sum = new int[N];

    for (int i = 0; i < N; i++) {
        std::cin >> time[i];
    }

    // 오름차순으로 정렬
    std::sort(time, time+N);

    sum[0] = time[0];

    int result = sum[0];

    // sum에 각 사람마다 걸리는 시간 저장후, 결과에 더하기
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i-1] + time[i];
        result += sum[i];
    }

    std::cout << result;

    delete[] time;
    delete[] sum;

    return 0;
}