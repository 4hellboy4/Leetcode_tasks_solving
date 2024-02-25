#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

set<string> my_set;
queue<string> q;
vector<string> l1;
vector<string> l2;
vector<string> l3;

int count_symbol(string& str, char& c) {
    int cnt = 0;
    for (int i = 0; i < str.size(); ++i) {
        cnt += (str.at(i) == c ? 1 : 0);
    }
    return cnt;
}

bool isL1(string& str, vector<char>& symbols) {
    bool flag = true;
    for (char symbol : symbols) {
        int cnt = count_symbol(str, symbol);
        if (cnt % 2 != 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

bool isL2(string& str, vector<char>& symbols) {
    bool flag = true;
    for (char symbol : symbols) {
        int cnt = count_symbol(str, symbol);
        if (cnt < 1) {
            flag = false;
            break;
        }
    }
    return flag;
}

bool isL3(string& str, vector<char>& symbols) {
    int flag = 0;
    for (char symbol : symbols) {
        int cnt = count_symbol(str, symbol);
        if (cnt < 1) {
            flag += 1;
        }
    }
    return flag == 1;
}

void permutations(int l1_size, int l2_size, int l3_size, vector<char>& symbols) {
    int cnt1 = 1;
    int cnt2 = 0;
    int cnt3 = 0;
    while ( (cnt1 <= l1_size || cnt2 <= l2_size || cnt3 <= l3_size)) {
        string temp = q.front();
        q.pop();
        if (isL1(temp, symbols)) {
            l1.emplace_back(temp);
            cnt1++;
        }
        if (isL2(temp, symbols)) {
            l2.emplace_back(temp);
            cnt2++;
        }
        if (isL3(temp, symbols)) {
            l3.emplace_back(temp);
            cnt3++;
        }
        for (char symbol : symbols) {
            string new_string = temp + string(1, symbol);
            q.push(new_string);
        }
    }
}


int main() {
    int n;
    cin >> n;

    vector<char> symbols(n);
    vector<int> lengths(3);

    for (int i = 0; i < n; ++i) {
        cin >> symbols.at(i);
    }

    for (int i = 0; i < 3; ++i) {
        cin >> lengths.at(i);
    }

    for (char symbol : symbols) {
        q.push(string(1, symbol));
    }

    permutations(lengths[0], lengths[1], lengths[2], symbols);

    cout << "_" << " ";
    for (int i = 0; i < lengths[0] - 1; ++i) {
        cout << l1.at(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < lengths[1]; ++i) {
        cout << l2.at(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < lengths[2]; ++i) {
        cout << l3.at(i) << " ";
    }

}
