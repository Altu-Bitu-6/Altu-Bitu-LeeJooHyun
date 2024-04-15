#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

int n, m, ans = 0;;
vector<vector<int>> li;
vector<bool> visited_dfs;

void dfs(int index) {
    for (int i = 1; i <= n; i++) {
        if (li[index][i] == 1 && !visited_dfs[i]) {
            // 방문했을 때 true로 바뀌도록 수정!
            visited_dfs[i] = true;
            // 그리고 방문 즉시 ans++
            ans++;
            dfs(i);
        }
    }
}

int solution(int n, int m) {
    li.assign(MAX+1, vector<int>(MAX+1));
    visited_dfs.assign(MAX+1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        li[a][b] = li[b][a] = 1;
    }
    visited_dfs[1] = true;
    dfs(1);
    return ans;
}

int main() {
    cin >> n >> m;
    cout << solution(n, m);
}