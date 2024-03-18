#include <iostream>

using namespace std;

// 킹과 돌을 움직이는 함수입니다.
// input에 따라 움직이는데, 한계점에 닿았을 경우 움직이지 않습니다.
string moves(string chess, string &input){
    string before_chess = chess;

    if (input == "R") {
        chess[0] += 1;
    } else if (input == "L") {
        chess[0] -= 1;
    } else if (input == "B") {
        chess[1] -= 1;
    } else if (input == "T") {
        chess[1] += 1;
    } else if (input == "RT") {
        chess[0] += 1;
        chess[1] += 1;
    } else if (input == "LT") {
        chess[0] -= 1;
        chess[1] += 1;
    } else if (input == "RB") {
        chess[0] += 1;
        chess[1] -= 1;
    } else if (input == "LB") {
        chess[0] -= 1;
        chess[1] -= 1;
    }

    if (chess[0] < 'A' || chess[0] > 'H' || chess[1] < '1' || chess[1] > '8') {
        return before_chess;
    }
    
    return chess;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    string king, stone;
    int n;
    cin >> king >> stone >> n;

    // 연산
    while (n--) {
        // 움직임의 전후 비교를 위해 변수를 여러개 선언했습니다.
        string input, king_before, king_after, stone_before, stone_after;
        cin >> input;

        // 먼저 킹과 돌의 전후를 각각 king, stone으로 초기화합니다.
        // 최종 움직임 결과는 king, stone에 저장됩니다.
        king_before = king_after = king;
        stone_before = stone_after = stone;

        // moves 함수를 이용해 king이 움직인 결과를 king_after에 저장합니다.
        king_after = king = moves(king, input);

        // 만약 킹과 돌의 위치가 겹치면, 돌을 움직입니다.
        if (stone_before == king_after) {
            stone_after = moves(stone, input);

            // 하지만 움직인 후에도 킹과 돌의 위치가 겹친다면, 킹의 움직임을 취소합니다.
            if (stone_after == king_after) {
                king = king_before;
            }
            else {
                king = king_after;
            }
            
            // stone에 stone_after 결과를 저장합니다.
            stone = stone_after;
        }
    }

    // 출력
    cout << king << '\n' << stone;
    return 0;
}