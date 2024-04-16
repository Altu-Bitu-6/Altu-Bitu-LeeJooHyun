#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 10000;

int n, m;
vector<int> input;
vector<int> sequence;


void printSequence() {
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void backtrack(int cnt) {
    // 만약 고른 자연수 숫자가 m이면 종료
    if (cnt == m) {
        printSequence();
        return;
    }

    // 중복된 숫자 저장을 위한 변수
    int dup = -1;

    for (int i = 1; i <= n; i++) {
        // 만약 중복 숫자라면 넘어감
        if (input[i] == dup) {
            continue;
        }
        // 중복 아닌 숫자라면 중복 숫자 변수에 저장
        dup = input[i];

        sequence.push_back(input[i]);
        backtrack(cnt + 1);
        sequence.pop_back();        
    }
}

int main() {
    // 입력
    cin >> n >> m;
    input.assign(n+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    // 백트래킹
    backtrack(0);

    return 0;
}