#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;

tuple<int, int, int> calculateDiet(int w, int b, int diet_in, int t, int d, int a) {
    int w1, w2;
    int b1, b2;

    w1 = w; w2 = w;
    b1 = b; b2 = b;

    for (int i = 0; i < d; i++) {
        int b_change1, b_change2;

        w1 += diet_in - b1 - a;
        w2 += diet_in - b2 - a;

        int b1_change, b2_change, abs_b_change;

        b1_change = 0;
        b2_change = diet_in - b2 - a;

        if (abs(b2_change) > t) b2 += floor(b2_change) / 2;
    }

    return {w1, w2, b2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int w, b, t = 0;
    int d, diet_in, a = 0;

    cin >> w >> b >> t;
    cin >> d >> diet_in >> a;

    tuple<int, int, int> result;

    int w1 = get<0>(result), b1 = b;
    int w2 = get<1>(result), b2 = get<2>(result);

    if (w1 <= 0) cout << "Danger Diet" << '\n';
    else cout << w1 << ' ' << b1 << ' ' << '\n';

    if (w1 <= 0 || b2 <= 0) cout << "Danger Diet" << '\n';
    else {
        cout << w2 << ' ' << b2 << ' ';
        if (b2 < b) cout << "YOYO";
        else cout << "NO";
    }

    return 0;
}