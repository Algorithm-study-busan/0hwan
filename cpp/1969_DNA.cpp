#include <iostream>
#include <string>

int HammingDist(std::string A, std::string B);
void cntChar(std::string target, int** cnt);
std::string selectChar(int** cnt, int size);

int main() {

    int N, M; // DNA수, DNA 길이

    std::cin >> N >> M;

    std::string* dna = new std::string[N];

    int** cnt = new int*[M];

    for (int i = 0; i < N; i++) {
        std::cin >> dna[i];
    }

    for (int i = 0; i < M; i++) {
        cnt[i] = new int[4];
        cnt[i][0] = 0;
        cnt[i][1] = 0;
        cnt[i][2] = 0;
        cnt[i][3] = 0;
    }

    for (int i = 0; i < N; i++) {
        cntChar(dna[i], cnt);
    }

    std::string result = selectChar(cnt, M);

    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += HammingDist(result, dna[i]);
    }

    std::cout << result << '\n' << sum;

    for (int i = 0; i < M; i++) {
        delete [] cnt[i];
    }
    delete [] cnt;
    delete [] dna;

    return 0;
}

int HammingDist(std::string A, std::string B) {
    int cnt = 0;
    for (int i = 0; i < A.length(); i++) {
        if (A[i] != B[i]) cnt++;
    }
    return cnt;
}

void cntChar(std::string target, int** cnt) {
    for (int i = 0; i < target.length(); i++) {
        switch (target[i])
        {
        case 'A':
            cnt[i][0]++;
            break;
        case 'C':
            cnt[i][1]++;
            break;
        case 'G':
            cnt[i][2]++;
            break;
        case 'T':
            cnt[i][3]++;
            break;
        default:
            break;
        }
    }
}

std::string selectChar(int** cnt, int size) {
    int* current = new int[size];
    for (int i = 0; i < size; i++) {
        current[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 1; j < 4; j++) {
            if (cnt[i][current[i]] < cnt[i][j]) {
                current[i] = j;
            }
        }
    }

    std::string temp = "";

    for (int i = 0; i < size; i++) {
        switch (current[i])
        {
        case 0:
            temp.append("A");
            break;
        case 1:
            temp.append("C");
            break;
        case 2:
            temp.append("G");
            break;
        case 3:
            temp.append("T");
            break;
        default:
            break;
        }
    }

    delete [] current;

    return temp;
}