#include <iostream>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, x;
    cin >> m;
    
    // 비트마스크 사용
    ll b = 0LL;
    
    string input;

    while (m--) {
        cin >> input;

        if (input == "add") {
            cin >> x;
            // x-1 bit만큼 1 이동 후 | 연산으로 포함
            b |= (1 << (x-1));
        }
        
        else if (input == "remove") {
            cin >> x;
            // x-1 bit를 반전시켜 x bit 자리만 0으로 처리 후 & 연산으로 반영
            b &= ~(1 << (x-1));
        }
        
        else if (input == "check") {
            cin >> x;
            // x-1 bit 자리에 1이 있는지 체크하고 그에 따라 답을 줌
            if (b & (1 << (x-1))) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
        
        else if (input == "toggle") {
            cin >> x;
            // x-1 bit 자리의 숫자와 xor 연산
            b ^= (1 << (x-1));
        }
        
        else if (input == "all") {
            // 20번째 비트까지 shift 연산하고 1을 빼면 나머지 자리 모두 1로 채워짐
            b = (1 << (21-1)) - 1;
        }
        
        else if (input == "empty") {
            // 0으로 초기화
            b = 0;
        }
    }
    return 0;
}