#include <iostream>
#include <algorithm>

using namespace std;

// 재귀를 이용해 최대공약수를 구한다
int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a_numerator, a_denominator, b_numerator, b_denominator;
    cin >> a_numerator >> a_denominator >> b_numerator >> b_denominator;
    
    // 기약분수가 아닌 형태의 분자와 분모를 구한다
    int numerator, denominator;
    numerator = a_numerator*b_denominator + b_numerator*a_denominator;
    denominator = a_denominator * b_denominator;
    
    // 최대공약수를 구한다
    int gcd = getGcd(max(numerator, denominator), min(numerator, denominator));
    
    // 최대공약수로 나눠 기약분수로 만들어 준다
    numerator /= gcd;
    denominator /= gcd;
    
    cout << numerator << ' ' << denominator;
    
    return 0;
}
