#include <iostream>

long long stock(const int cnt);

int main() {

    int N;

    std::cin >> N;

    long long* result = new long long[N];


    int cnt;
    for (int i = 0; i < N; i++) {
        std::cin >> cnt;
        result[i] = stock(cnt);
    }

    for (int i = 0; i < N; i++) {
        std::cout << result[i] << '\n';
    }

    // free memory
    delete [] result;

    return 0;
}

long long stock(const int cnt) {
    // 주식으로 이익을 못받는 경우
    if (cnt <= 1) return 0;

    int* test_case = new int[cnt];

    // input data
    for (int i = 0; i < cnt; i++) {
        std::cin >> test_case[i];
    }

    long long benefit = 0;

    int temp = test_case[cnt-1];

    // 뒤에서부터 이익계산
    for (int i = cnt-2; i >= 0; i--) {
        if (temp >= test_case[i]) {
            benefit += temp - test_case[i];
        } else {
            temp = test_case[i];
        }
    }

    delete [] test_case;

    return benefit;
}