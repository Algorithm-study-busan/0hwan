#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool isBombElement(char c, string bomb, int* seq);
void clearStack(vector<char>* result, stack<char>* temp);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string target;
    string bomb;
    vector<char> result;
    stack<char> temp;

    cin >> target >> bomb;

    for (char c : target) {
        int seq = 0;

        if (!isBombElement(c, bomb, &seq)) { // 폭탄 요소가 아닌경우
            if (!temp.empty()) {
                clearStack(&result, &temp);
            }
            result.push_back(c);
            continue;
        }

        if (!temp.empty()) {
            if (seq == 0) { // 첫번째 글자인경우 삽입
                temp.push(c);
            } else {
                // 폭탄의 이어지는 글자인 경우
                if (temp.top() == bomb[seq-1]) { 
                    temp.push(c);
                    // 폭탄이 완성된 경우
                    if (seq+1 == bomb.size()) {
                        for (char k : bomb) {
                            temp.pop();
                        }
                    }
                } else {
                    temp.push(c);
                    clearStack(&result, &temp);
                }
            }
        } else {
            if (bomb.size() == 1) continue; // 폭탄 사이즈가 1인경우
            if (seq == 0) temp.push(c);
            else result.push_back(c);
        }
    }

    // 스택에 남은거 모두 저장
    clearStack(&result, &temp);

    if (result.empty()) cout << "FRULA";
    else {
        for (char c : result) {
            cout << c;
        }
    }

    return 0;
}

bool isBombElement(char c, string bomb, int* seq) {
    for (int i = 0; i < bomb.size(); i++) {
        if (c == bomb[i]) {
            *seq = i; // bomb의 몇번째 요소인지 저장
            return true;
        }
    }
    return false;
}

void clearStack(vector<char>* result, stack<char>* temp) {
    vector<char> str;
    while (!temp->empty()) {
        str.push_back(temp->top());
        temp->pop();
    }
    reverse(str.begin(), str.end());
    result->insert(result->end(), str.begin(), str.end());
}