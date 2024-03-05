#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define MAX_SIZE 100000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a, b;
    queue<int> a_q, b_q;
    vector<int> result;

    cin >> a >> b;

    // string으로 입력 받은 문자열을 큐에 숫자로 push
    for (int i = 0; i < a.size(); i++) {
        a_q.push(a[a.size()-i-1] - '0');
    }

    for (int i = 0; i < b.size(); i++) {
        b_q.push(b[b.size()-i-1] - '0');
    }

    // a와 b의 합이 10 이상인 경우 이를 저장할 변수가 필요함
    int carry = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        // 만약 a_q와 b_q가 비었다면 루프 종료
        // 이때 carry에 수가 남아 있다면 끝에 더해 줌
        if (a_q.empty() && b_q.empty()) {
            if (carry == 1) {
                result.push_back(carry);
            }

            break;
        }

        int num_a, num_b, sum;

        // num_a에 a_q를 pop 해서 나온 숫자 저장
        if (!a_q.empty()) {
            num_a = a_q.front();
            a_q.pop();
        } else {
            num_a = 0;
        }

        // num_b에 b_q를 pop 해서 나온 숫자 저장
        if (!b_q.empty()) {
            num_b = b_q.front();
            b_q.pop();
        } else {
            num_b = 0;
        }

        // sum에 두 숫자와 carry까지 더해 줌
        sum = num_a + num_b + carry;

        // 다음 자리 연산을 위해 carry는 sum을 10의 몫으로 지정
        // sum은 10의 나머지로 지정
        carry = floor(sum / 10);
        sum %= 10;

        result.push_back(sum);

    }

    // 출력할 때는 뒤에서 앞으로 한다
    for (int i = 0; i < result.size(); i++) {
        cout << result[result.size()-i-1];
    }

    return 0;
}