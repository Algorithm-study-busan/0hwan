#include <iostream>
#include <string>
#include <algorithm>

int main() {

    std::string S, T;

    std::cin >> S;

    std::cin >> T;

    // S -> T 로 만드는 것이 아닌
    // T -> S 로 만들기

    while (S.length() != T.length()) {
        if (T.back() == 'A') T.pop_back();
        else {
            T.pop_back();
            std::reverse(T.begin(), T.end());
        }
    }

    if (S == T) std::cout << '1';
    else std::cout << '0';

    return 0;
}