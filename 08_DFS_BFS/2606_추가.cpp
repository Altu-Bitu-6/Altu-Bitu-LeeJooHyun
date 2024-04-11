#include <iostream>
#include <vector>

using namespace std;

int N, M; //// 컴퓨터 수와 컴퓨터 쌍의 수 입력을 위한 변수 
vector<vector<int>> li; // 그래프를 나타내는 인접 리스트
vector<bool> visited; // 방문 여부를 체크하는 벡터

void dfs(int num) { //// dfs 알고리즘 구현
    for (int i = 1; i <= N; i++) { //// 1부터 인덱싱
        if (li[num][i] == 1 && !visited[i]) { //// 만약 DFS 다음 노드가 1이고, 방문 전이라면
            visited[i] = true; // 방문 처리
            dfs(i); // DFS 진행
        }
    }
}

int main() {
    cin >> N >> M; //// 컴퓨터 수와 컴퓨터 쌍의 수 입력
    li.assign(N + 1, vector<int>(N + 1, 0)); //// 인접 리스트 할당 (1부터 인덱싱), 0으로 초기화
    visited.assign(N + 1, false); //// 방문 벡터는 인접 리스트와 같은 크기로 할당, false 초기화

    for (int i = 0; i < M; i++) { 
        int a, b; //// 컴퓨터쌍 입력을 위한 변수
        cin >> a >> b; //// 차례 대로 입력
        li[a][b] = li[b][a] = 1; // 양방향 그래프 구성
    }

    visited[1] = true; //// 1번이 바이러스에 걸렸기 때문에 1을 true로 바꿈
    dfs(1); //// 1번부터 시작

    int count = 0; //// 바이러스에 걸리게 되는 컴퓨터의 수를 위한 변수
    for (int i = 2; i <= N; i++) {
        if (visited[i]) //// 만약 방문을 했다면
            count++; // 연결된 노드 수 계산
    }
    
    cout << count << "\n"; //// 출력

    return 0;
}