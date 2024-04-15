#include <iostream>
#include <vector>

using namespace std;

int n, a, b, m; //// 입력 전역변수 선언
vector<vector<int>> li; // 그래프를 나타내는 인접 리스트
vector<bool> visited; // 방문 여부를 체크하는 벡터
int ans = -1; // 최종 촌수 저장, 기본값은 -1(친척 관계 없음)

void dfs(int v, int num) {
    visited[v] = true; // 현재 노드 방문 처리

    if (v == b) { // 촌수를 구한 경우
        ans = num; //// 촌수 반환
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (li[v][i] == 1 && !visited[i]) { // 인접하고 아직 방문하지 않은 것에 대해 dfs 실행 
            dfs(i, num + 1); //// dfs 부를 때 다음 촌수로 재귀
        }
    }
}

int main() {
    cin >> n; //// 전체 사람의 수 입력
    cin >> a >> b; //// 촌수 계산을 위한 두 사람의 번호 수 입력
    cin >> m; //// 부모 자식들 간의 관계 개수 입력

    li.assign(n + 1, vector<int>(n + 1, 0)); //// 인접 리스트 0으로 초기화
    visited.assign(n + 1, false); //// 방문 벡터 false로 초기화

    for (int i = 0; i < m; i++) { //// 부모 자식들 간의 관계 개수만큼 반복
        int c, d; //// 입력 지역변수 선언
        cin >> c >> d; //// 부모 자식 간의 관계를 나타내는 두 번호
        li[c][d] = li[d][c] = 1; // 양방향 그래프로 구성
    }

    dfs(a, 0); //// 두 사람 중 한 사람부터 시작, 자기 자신의 촌수는 0

    if (ans == -1) {
        cout << -1 << "\n"; // 경로가 없는 경우
    } else {
        cout << ans << "\n"; // 최소 거리 출력
    }

    return 0;
}