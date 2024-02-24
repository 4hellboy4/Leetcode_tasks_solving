#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//vector<str> solution1() {
//    vector<str> temp;
//    temp.emplace_back("_");
//
//}

set<string> my_set;

int count_symbol(string& str, char& c) {
    int cnt = 0;
    for (int i = 0; i < str.size(); ++i) {
        cnt += (str.at(i) == c ? 1 : 0);
    }
    return cnt;
}

void alphabet1(vector<char>& symbols, int& num) {
    vector<string> temp;
    for (string word : my_set) {
        bool flag = true;
        for (char s : symbols) {
            int cnt = count_symbol(word, s);
            if (cnt % 2 != 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            temp.emplace_back(word);
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < num - 1; ++i) {
        cout << temp[i] << " ";
    }
}



void permutations(int& n, vector<char>& array, string str) {
    if ((str.size() > 2*n) || my_set.find(str) != my_set.end())
        return;
    my_set.insert(str);
    for (char s : array) {
        permutations(n, array, str + s);
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

    for (char s : symbols) {
        permutations(n, symbols, "");
    }

//    for (string word : my_set) {
//        cout << word << endl;
//    }

    cout << "_" << " ";
    alphabet1(symbols, lengths[0]);

}
