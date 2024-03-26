// https://www.acmicpc.net/problem/15662

#include <iostream>
#include <vector>
#include <string> ////substr 함수 사용
using namespace std;

vector<string> li; ////톱니바퀴 정보 벡터
vector<pair<int, int> > stack; ////회전 정보 벡터
vector<int> visited; ////순회했는지 여부를 검사하는 벡터

void check_rotation(int current_num, int current_dir) {
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0) { ////왼쪽으로 돌릴 때 만약 왼쪽 톱니 인덱스가 범위 벗어나거나, 왼쪽 톱니를 이미 순회한 경우 필터
        if (li[current_num][6] != li[current_num - 1][2]) { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num - 1, current_dir * -1)); ////회전 정보 벡터에 왼쪽 톱니 회전 정보 저장
            visited[current_num - 1] = 1; ////톱니 순회했음 여부 저장
            check_rotation(current_num - 1, current_dir * -1); ////재귀적으로 왼쪽 톱니 호출
        }
    }
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0) { ////오른쪽으로 돌릴 때 만약 오른쪽 톱니 인덱스가 범위 벗어나거나, 오른쪽 톱니를 이미 순회한 경우 필터
        if (li[current_num][2] != li[current_num + 1][6]) { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num + 1, current_dir * -1)); ////회전 정보 벡터에 오른쪽 톱니 회전 정보 저장
            visited[current_num + 1] = 1; ////톱니 순회했음 여부 저장
            check_rotation(current_num + 1, current_dir * -1); ////재귀적으로 오른쪽 톱니 호출
        }
    }
}

int main() {
    int t; ////톱니바퀴의 개수 T
    int k; ////회전 횟수 K

    cin >> t; //톱니바퀴의 개수 T 입력

    li.resize(t); //톱니바퀴 개수만큼 resize
    for (int i = 0; i < t; ++i)
        cin >> li[i]; //톱니바퀴 상태 입력

    cin >> k; // 회전 횟수 K 입력
    for (int i = 0; i < k; ++i) { //k번 돌면서 회전할 수 있는지에 대해 체크
        int num, direction; ////회전시킨 톱니바퀴의 번호 num, 방향 direction
        cin >> num >> direction; //방향 입력 (1이면 시계 방항, -1이면 반시계 방향)
        stack.clear(); ////전역변수 회전 정보 벡터 비움
        stack.push_back(make_pair(num - 1, direction)); ////회전 정보 벡터에 새로 입력된 정보들 저장
        visited.assign(t, 0); //t개만큼 0을 초기화
        visited[num - 1] = 1; ////i번째 회전에서 visited의 시작 인데스(num-1)는 1로 지정해 회전 시작
        check_rotation(num - 1, direction); ////회전 가능 여부 검사하고 가능하면 회전하는 함수 호출

        while (!stack.empty()) { ////회전 정보 벡터가 비었으면 회전할 필요 없음
            pair<int, int> top = stack.back(); ////회전 정보 벡터 맨 마지막에 있는 요소 저장
            stack.pop_back(); ////저장한 요소는 pop
            int tmp_num = top.first; //돌려야 할 톱니바퀴의 인덱스
            int tmp_dir = top.second; //돌릴 방향
            if (tmp_dir == 1) { //시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7); ////시계방향으로 돌릴 땐 0번째에 맨 뒤의 숫자가 자리함, 나머지 0번째부터 6번째까지의 숫자들은 같으므로 복사
            } else { //반시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0]; ////반시계방향으로 돌릴 땐 1번째부터 7번째까지의 숫자들은 같으므로 복사, 맨 뒤에 0번째 숫자가 자리함
            }
        }
    }

    int cnt = 0; ////cnt 0으로 초기화
    for (int i = 0; i < t; ++i) {
        if (li[i][0] == '1') { ////만약 12시 방향의 자석이 s라면
            cnt++; ////cnt 증가
        }
    }

    cout << cnt << endl; ////결과로 cnt 출력

    return 0;
}