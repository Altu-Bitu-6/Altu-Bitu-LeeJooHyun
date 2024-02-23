#include <iostream>
#include <vector>
#include <algorithm>

#include <string>

using namespace std;

int sumOfDigit(string& s) {
    int len = s.size(), sum = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(s[i]) != 0)  sum += s[i] - '0';
    }
    
    return sum;
}

bool cmp(string& a, string& b) {
    int len_a = a.size(), len_b = b.size();
    if (len_a == len_b) {
        int sum_a = sumOfDigit(a), sum_b = sumOfDigit(b);
        if (sum_a == sum_b) return a < b;
        else return sum_a < sum_b;
    }

    return len_a < len_b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> serial_before(n);

    for (int i = 0; i < n; i++) {
        cin >> serial_before[i];
    }

    sort(serial_before.begin(), serial_before.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << serial_before[i] << endl;
    }

    return 0;

}