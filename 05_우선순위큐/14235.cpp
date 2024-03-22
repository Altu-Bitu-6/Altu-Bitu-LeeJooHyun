#include <iostream>
#include <queue>

using namespace std;

// 선물의 가치를 출력한다
// 만약 줄 선물이 없다면 -1 반환
int price(priority_queue<int> &gift) {
    int price = -1;
    
    if (!gift.empty()) {
        price = gift.top();
        gift.pop();
    }

    return price;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, a, input;
    priority_queue<int> gift;
    cin >> n;

    while (n--) {
        cin >> a;

        // a가 0이면 선물 전달
        if (a == 0){
            cout << price(gift) << '\n';
        }
        // a가 0이 아니면 선물 충전 
        else {
            for (int i = 0; i < a; i++) {
                cin >> input;
                gift.push(input);
            }
        }
    }

    return 0;
}
