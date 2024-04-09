#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

int n, m, ans;
vector<vector<int>> li;
vector<bool> visited_dfs;

void dfs(int index, int ans) {
    visited_dfs[index] = true;
    ans++;

    for (int i = 1; i <= n; i++) {
        if (li[index][i] == 1 && !visited_dfs[i]) {
            dfs(i, ans);
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
    ans = 0;
    dfs(1, ans);
    return ans;
}

int main() {
    cin >> n >> m;

    cout << solution(n, m);

}