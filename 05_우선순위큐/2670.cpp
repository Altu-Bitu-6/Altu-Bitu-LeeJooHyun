#include <iostream>
#include <vector>

#define ALPHABET 26
using namespace std;

// 알파벳 배열을 만들어 각 알파벳이 몇 개가 쓰였는지 각 알파벳 사용 개수를 저장한다
vector<int> getAlphaVec(string word) {
    vector<int> alpha_vec(ALPHABET, 0);

    for (int i = 0; i < word.size(); i++) {
        alpha_vec[word[i]-'A']++;
    }

    return alpha_vec;
}

// 비슷한 단어인지 검사한다
bool check(string &input_word, vector<int> &first_alpha_vec) {
    vector<int> input_alpha_vec = getAlphaVec(input_word);
    int more_alpha = 0, less_alpha = 0;
    
    for (int i = 0; i < ALPHABET; i++) {
        if (input_alpha_vec[i] != first_alpha_vec[i]) {
            if (input_alpha_vec[i] > first_alpha_vec[i]) {
                more_alpha += abs(input_alpha_vec[i] - first_alpha_vec[i]);
            } else {
                less_alpha += abs(input_alpha_vec[i] - first_alpha_vec[i]);
            }
        }
    }

    if (more_alpha <= 1 && less_alpha <= 1) {
        return true;
    }

    return false;
}

// 비슷한 단어가 감지되면 cnt 수를 늘려 최종적으로 비슷한 단어 수를 반환한다
int solution(vector<string> &v, string &first_word) {
    int cnt = 0;

    vector<int> first_alpha_vec = getAlphaVec(first_word);
    
    for (int i = 0; i < v.size(); i++) {
        if (check(v[i], first_alpha_vec)) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 숫자 입력
    int n = 0;
    cin >> n;

    // 단어 입력
    vector<string> v;
    string input_word, first_word;

    // 첫번째 단어 입력
    cin >> first_word;

    for (int i = 0; i < n-1; i++) {
        cin >> input_word;
        v.push_back(input_word);
    }

    // 출력
    cout << solution(v, first_word);

    return 0;
}
