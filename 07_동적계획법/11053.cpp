#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> &arr) {
    int cnt = 0;
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        // dp에는 각 인덱스마다의 최장 수열의 길이가 저장되어 있다
        for (int j = i-1; j >= 0; j--) {
            // arr[i]가 클 때만 증가
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        cnt = max(dp[i], cnt);
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solution(n, arr);

    return 0;
}
