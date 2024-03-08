#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 소수 여부 반환 함수: 에라토스테네스의 체 이용
// 
vector<bool> getPrimes(int n) {
    // 입력 값만큼의 크기를 갖는 벡터를 선언한다. 이때 0부터 n까지이므로 크기는 n+1이다.
    vector<bool> is_prime(n + 1, true);
    // 소수는 1이 아닌 양수들이라는 전제에 따라 0번째 1번째는 false
    is_prime[0] = is_prime[1] = false;
    // 2부터 n까지 선회하며 검사한다
    for (int i = 2; i * i <= n; i++) {
        // 만약 is_prime 벡터의 i번째가 false 지나간다. 즉, i가 소수라면 아래 이중 for문으로 진입한다.
        if (!is_prime[i]) {
            continue;
        }
        // for문을 통해 i부터 n까지 i만큼 증가하며 선회한다. 소수의 특성을 사용했다.
        // i=2부터 선회하고 is_prime 벡터는 0과 1을 제외하면 배열의 모든 원소 true인 상태이다. 소수가 아닌 것들을 찾아내는 루프.
        for (int j = i * i; j <= n; j += i) {

            is_prime[j] = false;
        }
    }
    // 결과 배열을 반환한다.
    return is_prime;
}

// n = a + b를 만족시키는 a 반환
int goldbach(int n, vector<bool> &is_prime) {
    for (int a = 3; a <= n / 2; a+= 2) {
        // 2보다 큰 짝수 소수는 존재하지 않으므로
        // a = 3부터 탐색해도 a와 b 모두 홀수여야 한다는 조건 만족
        // a가 2만큼 증가하므로 더 빠르게 선회할 수 있다

        // n = a + (n-a) 라는 관계를 이용해 if문 검사
        if (is_prime[a] && is_prime[n - a]) {
            return a;
        }
    }
    // n = a + b를 만족시키는 홀수 소수 a, b가 없으면 0 반환
    return 0;
}

/* [백준 6588: 골드바흐의 추측]
 * 1. 3보다 크거나 같고 n / 2보다 작거나 같은 소수 a를 오름차순으로 탐색한다.
 * 2. 1에서 찾은 a에 대하여 n - a(=b)도 소수이면 골드바흐의 추측이 성립한다.
 * 3. 골드바흐의 추측이 성립하면 a를, 성립하지 않으면 0을 반환한다.
 */

int main() {
    // 입력
    // 입력을 저장할 정수형 벡터
    vector<int> arr;
    // 입력되는 수
    int input;
    // while 반복문
    while(1) {
        // iostream으로 input에 입력되는 수 저장
        cin >> input;
        // 만약 입력이 0이면 입력 반복문에서 탈출
        if (input == 0) {
            break;
        }
        // 입력된 정수를 arr 벡터에 저장
        arr.push_back(input);
    }

    // 연산
    // max_num에 arr 벡터의 가장 큰 수를 저장
    int max_num = *max_element(arr.begin(), arr.end());
    // getPrimes 함수를 호출해 max_num의 소수 정보를 알려 주는 bool 형식의 배열을 반환 받는다
    vector<bool> is_prime = getPrimes(max_num);

    // for문을 사용해 arr 벡터에 저장된 각 입력들에 골드바흐 추측이 맞는지 틀린지 검사하고 맞으면 두 소수의 합으로 나타낸다
    for (int i = 0; i < arr.size(); i++) {
        // a가 0이면 골드바흐의 추측이 틀린 것임
        int a = goldbach(arr[i], is_prime);

        // 출력
        if (a != 0) { // n = a + b를 만족하는 a, b가 존재하면
            // n = a + b 출력
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n";
        } else {      // 존재하지 않으면
            // Goldbach's conjecture is wrong.\n 출력
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    // 함수 종료 선언
    return 0;
}