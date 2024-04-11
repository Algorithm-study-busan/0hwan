#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;

    cin >> N;

    vector<int> target(N);

    for (int i = 0; i < N; i++) cin >> target[i];

    stack<int> temp;
    string history = "";
    int current = 1;

    for (auto i : target) {
        if (current <= i) { // 어디까지 스택에 넣었는지 확인
            for (; current <= i; current++) {
                temp.push(current);
                history += '+';
            }
            temp.pop();
            history += '-';
        } else {
            if ( temp.top() == i) {
                temp.pop();
                history += '-';
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    for (char c : history) {
        cout << c << '\n';
    }

    return 0;
}