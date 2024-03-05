#include <iostream>
#include <vector>

using namespace std;

vector<bool> getPrimes(int &n) {
    vector<bool> primes(n + 1, false);

    primes[0] = true;
    primes[1] = true;
    
    for(int i = 2; i * i <= n; i++) {
        if(primes[i] != false) {
            continue;
        }
        
        for(int j = i * i; j <= n; j += i) {
            primes[j] = true;
        }
    }
    
    return primes;
}

bool goldbach(int &n, int &a, int &b) {
    vector<bool> primes = getPrimes(n);

    for (int i = 3; i < n+1; i += 2) {
        if (!primes[i] && !primes[n-i]) {
            a = primes[i];
            b = primes[n-i];
            return true;
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int input;
        cin >> input;
        
        if (input == 0) {
            break;
        }

        int n, a, b;

        bool check = goldbach(n, a, b);

        if (check) {
            cout << n << " = " << a << " + " << b << '\n';
        } else {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0; 
}