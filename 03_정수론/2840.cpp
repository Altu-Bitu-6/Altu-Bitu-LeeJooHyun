#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

// wheel을 추론하고, wheel이 존재하지 않으면 false 반환
bool luckyWheel(vector<char> &wheel, vector<pair<int, char>> &arrow, int n, int k) {
    // arrow에 입력된 정보를 입력해서 wheel을 추론
    // 이때, 가장 마지막에 입력된 글자가 맨 첫 번째에 오도록 함

    // 중복된 글자가 존재하는지 검사하기 위해 set과 map을 사용
    // set에 key 값을 저장하고 map으로 글자 개수를 센다
    set<char> s;
    map<char, int> m;
    
    int idx = 0;
    
    for (int i = 0; i < k; i++) {
        // 비어 있다면 채운다
        // set과 map도 채운다
        if (wheel[idx] == '?') {
            wheel[idx] = arrow[k-1-i].second;
            m[wheel[idx]]++;
            s.insert(wheel[idx]);
        }
        // 비어 있지 않다면 바퀴가 성립하는지 검사한다
        else {
            if (wheel[idx] != arrow[k-1-i].second) {
                return false;
            }
        }

        idx += arrow[k-1-i].first;
        idx %= n;
    }

    // map에 저장된 개수가 2개를 초과하면 false 반환
    for (auto count = s.begin(); count != s.end(); count++) {
        if (s.find(*count) != s.end()) {
            if (m[*count] > 1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<char> wheel(n);
    vector<pair<int, char>> arrow(k);
    
    // wheel 벡터의 원소를 '?'로 초기화
    for (int i = 0; i < n; i++) {
        wheel[i] = '?';
    }

    // arrow 벡터에 {s, letter} 형태로 입력을 저장해 딕셔너리 구현
    for (int i = 0; i < k; i++) {
        int s;
        char letter;
        pair<int, char> p;
        
        cin >> s >> letter;

        p.first = s;
        p.second = letter;

        arrow[i] = p;
    }
    
    // luchyWheel 함수의 결과를 check에 저장
    bool check = luckyWheel(wheel, arrow, n, k);
    
    if (check) {
        for (int i = 0; i < n; i++) {
            cout << wheel[i];
        }
    } else {
        cout << '!';
    }

    return 0;

}