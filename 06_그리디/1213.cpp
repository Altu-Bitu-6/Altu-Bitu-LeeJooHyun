#include <iostream>
#include <vector>
#include <algorithm>

#define ALPHABET 26

using namespace std;

string getPalindrome(vector<int> &count) {
    string start = "", middle = "", end = "";
    int start_idx = (int)'A';

    for (int i = start_idx; i < start_idx + ALPHABET; i++) {
        char char_iter = (char)i;
        
        // 만약 해당 알파벳 개수가 홀수면
        if (count[i] % 2 == 1) {
            // palindrome 성립 검사
            if (!middle.empty()) {
                return "I'm Sorry Hansoo";
            }
            middle = char_iter;
        }

        // 전반부와 후반부에 나눠서 할당
        // 이떄 count[i]가 홀수면 2의 몫에 포함되지 않아 자동으로 제외
        for (int j = 0; j < count[i] / 2; j++) {
            start += char_iter;
            end = char_iter + end;
        }
    }

    return start + middle + end;
}

// 각 알파벳이 input에 몇 개 있는지 세는 함수
vector<int> countAlphabet(string input) {
    // 벡터 0으로 초기화
    vector<int> count(ALPHABET, 0);
    for (int i = 0; i < input.size(); i++) {
        count[input[i]]++;
    }
    return count;
}

string solution(string input) {
    vector<int> count = countAlphabet(input);
    return getPalindrome(count);
}

int main() {
    string input;
    cin >> input;

    cout << solution(input);

    return 0;
}