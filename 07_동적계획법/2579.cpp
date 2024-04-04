#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> &arr, vector<int> &dp) {
    dp[1] = arr[1];
    dp[2] = arr[2] + arr[1];
    dp[3] = arr[3] + max(arr[1], arr[2]);

    for (int i = 4; i <= n; i++) {
        // Sn은 두 가지 경우로 나눠진다.
        // an + Sn-2 (2번 뛰는 경우)
        // an + an-1 + Sn-3 (1+2번 뛰는 경우)
        // 2번 뛰는 경우를 기준으로 나눠진다.
        dp[i] = arr[i] + max(dp[i-2], arr[i-1] + dp[i-3]);
    }

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> arr(n+1, 0);
    vector<int> dp(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << solution(n, arr, dp);

    return 0;
}
