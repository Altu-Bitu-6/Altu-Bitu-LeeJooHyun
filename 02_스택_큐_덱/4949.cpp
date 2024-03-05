#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input = "";

    while (true) {
        // 공백을 포함한 입력 받기
        getline(cin, input);

        // 종료 문자 입력 시 루프 종료
        if (input == ".") {
            break;
        }

        // 균형 검사를 위한 스택 정의
        stack<char> s;

        // 검사 결과 저장을 위한 bool 변수 정의
        bool result = true;

        for (int i = 0; i < 100; i++) {
            // 종료 문자 입력 시 스택이 비었는지 검사, 루프 종료
            // 스택에 남아 있는 문자가 있다면 결과는 false로 기록된다
            if (input[i] == '.') {
                if (!s.empty()) {
                    result = false;
                }
                break;
            }
            
            // 괄호를 여는 두 기호, '(' 이나 '['이 들어오면 push
            // 괄호를 여는 두 기호, ')' 이나 ']'이 들어오면 pop
            // 만약 루프가 끝날 때까지 짝이 지어지면 결과는 true로 유지된다
            // 만약 짝이 지어지지 않으면 for 루프는 종료되고 결과는 false로 기록된다
            if (input[i] == '(' || input[i] == '[') {
                s.push(input[i]);
            } else if (input[i] == ')') {
                if (s.empty() || s.top() != '(') {
                    result = false;
                    break;
                } else {
                    s.pop();
                }
            } else if (input[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    result = false;
                    break;
                } else {
                    s.pop();
                }
            }
        }

        if (result) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }

    }

    return 0;
}