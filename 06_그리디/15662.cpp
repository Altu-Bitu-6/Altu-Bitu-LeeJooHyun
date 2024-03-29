#include <iostream>
#include <vector>

#define SIZE 8
using namespace std;

void spinWheel(int t, vector<vector<int>> &wheel, int wheel_idx, int direction) {
    // 톱니 회전
    vector<int> tmp(SIZE, 0);
    // 시계 방향
    if (direction == 1) {
        for (int i = 0; i < SIZE-1; i++) {
            tmp[i+1] = wheel[wheel_idx][i];
        }
        tmp[0] = wheel[wheel_idx][SIZE-1];
    }
    // 반시계 방향
    else {
        for (int i = 1; i < SIZE; i++) {
            tmp[i-1] = wheel[wheel_idx][i];
        }
        tmp[SIZE-1] = wheel[wheel_idx][0];
    }

    wheel[wheel_idx] = tmp;

    return;
}

void calculateSpin(int t, vector<vector<int>> &wheel, int wheel_idx, int direction) {
    // 왼쪽으로 회전 번짐
    int left_idx = wheel_idx-1, left_direction = direction*(-1);
    while (left_idx >= 0) {
        if (wheel[wheel_idx][6] ^ wheel[left_idx][2]) {
            spinWheel(t, wheel, left_idx, left_direction);
            left_idx--;
            left_direction *= -1;
        } else {
            break;
        }
    }

    // 오른쪽으로 회전 번짐
    int right_idx = wheel_idx+1, right_direction = direction*(-1);
    while (right_idx < SIZE) {
        if (wheel[wheel_idx][2] ^ wheel[right_idx][6]) {
            spinWheel(t, wheel, right_idx, right_direction);
            right_idx++;
            right_direction *= -1;
        } else {
            break;
        }
    }

    return;
}

int solution(int t, vector<vector<int>> &wheel, int k, vector<pair<int, int>> &spin) {
    int ans = 0;

    for (int i = 0; i < k; i++) {
        calculateSpin(t, wheel, spin[i].first, spin[i].second);
    }

    for (int i = 0; i < t; i++) {
        if (wheel[i][0]) {
            ans++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 톱니바퀴 입력
    int t;
    cin >> t;

    vector<vector<int>> wheel;
    wheel.assign(t, vector<int>(SIZE, 0));
    string input;

    for (int i = 0; i < t; i++) {
        cin >> input;
        for (int j = 0; j < SIZE; j++) {
            wheel[i][j] = input[j] - '0';
        }
    }

    // 회전 입력
    int k;
    cin >> k;

    vector<pair<int, int>> spin;
    spin.assign(k, {0, 0});

    for (int i = 0; i < k; i++) {
        cin >> spin[i].first >> spin[i].second;
        spin[i].first--;
    }

    cout << solution(t, wheel, k, spin);

    return 0;
}
