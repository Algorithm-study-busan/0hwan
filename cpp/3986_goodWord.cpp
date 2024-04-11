#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, cnt = 0;


    cin >> N;
    vector<string> temp(N);

    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    for (auto& str : temp) {
        stack<char> result;
        for (char c : str) {
            if (result.empty()) {
                result.push(c);
                continue;
            }

            if (c == 'A') {
                if (result.top() == 'A') {
                    result.pop();
                } else {
                    result.push(c);
                }
            } else {
                if (result.top() == 'B') {
                    result.pop();
                } else {
                    result.push(c);
                }
            }
        }
        if (result.empty()) {
            cnt++;
        }
    }

    cout << cnt;

}