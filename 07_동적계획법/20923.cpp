#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void merge(deque<int> &deck, deque<int> &my_ground, deque<int> &op_ground) {
    while (!op_ground.empty()) {
        deck.push_front(op_ground.front());
        op_ground.pop_front();
    }

    while (!my_ground.empty()) {
        deck.push_front(my_ground.front());
        my_ground.pop_front();
    }
}

string solution(int n, int m, deque<int> &do_deck, deque<int> &su_deck) {
    deque<int> do_ground;
    deque<int> su_ground;
    
    int do_card, su_card;

    // 게임 중
    for (int i = 0; i < m; i++) {
        // 도도 차례
        if (i%2 == 0) {
            do_card = do_deck.back();
            do_deck.pop_back();
            do_ground.push_back(do_card);
        }
        // 수연 차례
        else {
            su_card = su_deck.back();
            su_deck.pop_back();
            su_ground.push_back(su_card);
        }

        // 게임 중 승패가 정해지는 경우
        // 도도 덱이 비는 경우
        if (do_deck.empty()) {
            return "su";
        }
        // 수연 덱이 비는 경우
        else if (su_deck.empty()) {
            return "do";
        }

        // 도도가 종치는 경우: 각 그라운드가 비는 경우는 패스
        if (!do_ground.empty() && do_card == 5 || !su_ground.empty() && su_card == 5) {
            merge(do_deck, do_ground, su_ground);
        }
        // 수연이 종 치는 경우: 도도와 수연 그라운드가 비는 경우는 패스
        else if (!do_ground.empty() && !su_ground.empty() && do_card + su_card == 5) {
            merge(su_deck, su_ground, do_ground);
        }
    }
    
    // 게임 완료 후
    if (do_deck.size() > su_deck.size()) {
        return "do";
    } else if (do_deck.size() < su_deck.size()) {
        return "su";
    }
    // 두 덱의 개수가 같아 비긴 경우
    return "dosu";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    deque<int> do_deck;
    deque<int> su_deck;

    int do_in, su_in;

    for (int i = 0; i < n; i++) {
        cin >> do_in >> su_in;
        do_deck.push_back(do_in);
        su_deck.push_back(su_in);
    }

    cout << solution(n, m, do_deck, su_deck);

    return 0;
}
