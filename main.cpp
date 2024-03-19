#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>

using namespace std;

bool isOneEditDistance(string &s, string &t) {
    int cnt = 0;
    int i = 0;
    int j = 0;

    if (abs((int) (s.size() - t.size())) > 1) {
        return false;
    }

    while (i < s.size() && j < t.size()) {
        if (cnt > 1) return false;
        if (s.at(i) == t.at(j)) {
            i += 1;
            j += 1;
        } else if (i + 1 < s.size() && s.at(i + 1) == t.at(j)) {
            i += 1;
            cnt += 1;
        } else if (j + 1 < t.size() && s.at(i) == t.at(j + 1)) {
            j += 1;
            cnt += 1;
        } else if (i + 1 < s.size() && j + 1 < t.size() && s.at(i + 1) == t.at(j + 1)) {
            i += 1;
            j += 1;
            cnt += 1;
        } else {
            i += 1;
            j += 1;
        }
    }
    if (cnt == 0 && abs((int) (s.size() - t.size())) == 1)
        cnt += 1;
    return cnt == 1;
}

// qwerty
// qwery


int main() {
    string s, t;
    cin >> s >> t;

    cout << (isOneEditDistance(s, t) ? "true" : "false") << endl;

    return 0;
}