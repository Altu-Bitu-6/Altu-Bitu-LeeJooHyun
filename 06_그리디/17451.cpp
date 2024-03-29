#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


ll solution(const int n, const vector<ll> &cost) {
    // 맨 뒤의 원소부터 거슬러 올라간다 (backtracking)
    ll ans = cost[n-1];
    for (int i = n-2; i >= 0; i--) {
        // 만약 ans가 속도의 배수라면 continue
        if (ans % cost[i] == 0) {
            continue;
        }
        // 만약 ans가 배수가 아니라면
        // ans는 cost[i]에 ans를 cost[i]로 나눈 값의 올림을 곱해 배수로 만들어 줌
        ans = cost[i] * (ans/cost[i]+1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 입력의 범위가 10^9이므로 long long 벡터 선언
    vector<ll> cost(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    cout << solution(n, cost);

    return 0;
}