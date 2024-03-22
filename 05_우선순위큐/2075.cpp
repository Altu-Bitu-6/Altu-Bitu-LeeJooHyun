#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 숫자 입력
    int n, input;
    cin >> n;

    // max_heap 입력
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input;
            min_heap.push(input);

            // 입력 받으며 min_heap의 size를 초과하는 경우 pop 한다
            // min_heap이므로 size를 n으로 유지하면 top에 저장되는 수가 답이 된다
            // 이 과정 없이 입력을 다 저장하면 메모리 초과가 발생
            if (min_heap.size() > n) min_heap.pop();
        }
    }

    // 출력
    cout << min_heap.top();

    return 0;
}
