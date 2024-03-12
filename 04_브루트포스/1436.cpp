#include <iostream>

using namespace std;

// 브루트포스 알고리즘을 사용해 연속한 666의 숫자가 나오는 경우를 센다.
int bruteforce(int &n) {
    int count = 0;
    for (int i = 666; true; i++) {
        int num;
        int tmp = i;
        while (tmp) {
            // num으로 666인지 검사
            num = tmp % 1000;
            tmp /= 10;
            
            if (num == 666) {
                count++;
                if (count == n) {
                    return i;
                }
                // 6666, 66666 등 중복되는 경우를 피하기 위해 break
                break;
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    // 출력
    cout << bruteforce(n);

    return 0;
}