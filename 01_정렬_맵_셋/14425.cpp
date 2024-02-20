#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    set<string> set_n;
    int count = 0;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        set_n.insert(str);
    }

    set<string>::iterator iter;

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;

        if (set_n.find(str) != set_n.end()) count++;
    }

    cout << count;

    return 0;

}