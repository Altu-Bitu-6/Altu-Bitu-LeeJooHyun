#include <iostream>
#include <vector>

using namespace std;

// 연산자 가짓수
int OPR = 4;

// 입력과 출력에 직접 관여하는 변수들
int n;
vector<int> num;
vector<int> oper;

// 각 최소 최대를 -10억, 10억으로 초기화
int max_num = -1000000000;
int min_num = 1000000000;

void backtracking(int idx, int now_num) {
    if (idx == n) {
        // 최대값 업데이트
        if (max_num < now_num) {
            max_num = now_num;
        }

        // 최소값 업데이트
        if (min_num > now_num) {
            min_num = now_num;
        }
    }
    else {
        for (int i = 0; i < OPR; i++) {
            // 연산자가 없으면 스킵
            if (oper[i] == 0) {
                continue;
            }
            // 지금 숫자 임시로 저장
            int tmp = now_num;
            // 연산처리
            if (i == 0) {
                now_num += num[idx];
            } else if (i == 1) {
                now_num -= num[idx];
            } else if (i == 2) {
                now_num *= num[idx];
            } else {
                now_num /= num[idx];
            }
            // 연산자 사용
            oper[i]--;
            // 백트래킹
            backtracking(idx+1, now_num);
            // 연산자 사용 사실 복구
            oper[i]++;
            // 지금 숫자 복구
            now_num = tmp;
        }
    }
}

int main() {
    // 입력
    cin >> n;
    num.assign(n, 0);
    oper.assign(OPR, 0);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < OPR; i++) {
        cin >> oper[i];
    }

    // 백트래킹
    backtracking(1, num[0]);

    // 출력
    cout << max_num << '\n' << min_num << '\n';

    return 0;
}
