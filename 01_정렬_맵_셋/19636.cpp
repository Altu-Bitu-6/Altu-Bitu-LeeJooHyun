#include <iostream>
#include <cmath>

using namespace std;

void calculateDiet(int w, int b, int diet_in, int t, int d, int a) {
    int w1, w2;
    int b1, b2;
    int result1, result2;

    w1 = w; w2 = w;
    b1 = b; b2 = b;
    result1 = 0; result2 = 0;

    for (int i = 0; i < d; i++) {
        int b_change1, b_change2;

        w1 += diet_in - b1 - a;
        w2 += diet_in - b2 - a;

        int b1_change, b2_change, abs_b_change;

        b1_change = 0;
        b2_change = diet_in - b2 - a;

        if (abs(b2_change) > t) b2 += floor(b2_change) / 2;
        
        if (w1 <= 0 || b1 <= 0) result1 = -1;
        if (w2 <= 0 || b2 <= 0) result2 = -1;
    }

    if (result1 == -1) cout << "Danger Diet" << endl;
    else cout << w1 << ' ' << b1 << endl;

    if (result2 == -1) cout << "Danger Diet";
    else {
        cout << w2 << ' ' << b2;
        if (b - b2 > 0) cout << ' ' << "YOYO";
        else cout << ' ' << "NO";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int w, b, t = 0;
    int d, diet_in, a = 0;

    cin >> w >> b >> t;
    cin >> d >> diet_in >> a;

    calculateDiet(w, b, diet_in, t, d, a);

    return 0;
}