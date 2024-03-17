#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string divide(long long num) {
    string temp;
    while (num != 0) {
        temp += to_string(num%10);
        num /= 10;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int compress(vector<char>& chars) {
    string s = "";
    if (!chars.empty()) {
        char current = chars[0];
        int cnt = 1;
        for (int i = 1; i < chars.size(); ++i) {
            if (current == chars[i]) {
                cnt += 1;
            } else {
                if (cnt == 1) {
                    s += current;
                } else {
                    s += current;
                    s += divide(cnt);
                }
                current = chars[i];
                cnt = 1;
            }
        }
        if (cnt == 1) {
            s += current;
        } else {
            s += current;
            s += divide(cnt);
        }
    }
    chars.clear();
    for (char sym : s) {
        chars.emplace_back(sym);
    }
    cout << s << endl;

    return (int) s.size();
}

int main() {
    int n;
    cin >> n;

    vector<char> chars(n);

    for (int i = 0; i < n; ++i) {
        cin >> chars[i];
    }

    cout << compress(chars) << endl;

    for (char sym : chars) {
        cout << sym << " ";
    }

    return 0;
}