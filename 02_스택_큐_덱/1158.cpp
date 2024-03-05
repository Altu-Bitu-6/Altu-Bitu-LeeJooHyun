#include <iostream>
#include <queue>

using namespace std;

// 해당 함수는 요세푸스 순열을 이루는 큐를 반환한다.
queue<int> josephus(queue<int> &arr, int n, int k) {
    queue<int> tmp;

    // tmp 큐가 다 채워질 때까지 루프 반복
    while (tmp.size() != n) {
        // 큐는 인덱스 지정을 할 수 없기 때문에 k-1만큼 넣었다 빼는 작업을 반복해야 한다
        for (int i = 1; i < k; i++) {
            int num = arr.front();
            arr.pop();
            arr.push(num);
        }

        // k번째에 제거할 숫자를 tmp에 저장하고 arr에서 뺀다.
        tmp.push(arr.front());
        arr.pop();
    }

    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    // 원형 순회를 위한 큐 선언
    queue<int> arr;

    for (int i = 0; i < n; i++) {
        arr.push(i+1);
    }

    // 요세푸스 순열
    arr = josephus(arr, n, k);

    // 결과 출력
    cout << '<';
    
    for (int i = 0; i < n-1; i++) {
        cout << arr.front() << ", ";
        arr.pop();
    }

    cout << arr.front() << '>';

    return 0;
}