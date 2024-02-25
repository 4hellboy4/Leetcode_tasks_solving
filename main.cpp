#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

//vector<str> solution1() {
//    vector<str> temp;
//    temp.emplace_back("_");
//
//}

set<string> my_set;
vector<string> sorted_array;

int count_symbol(string& str, char& c) {
    int cnt = 0;
    for (int i = 0; i < str.size(); ++i) {
        cnt += (str.at(i) == c ? 1 : 0);
    }
    return cnt;
}

void alphabet1(vector<char>& symbols, int& num) {
    int counter = 0;
    for (string word : sorted_array) {
        if (counter == num) {
            break;
        }
        bool flag = true;
        for (char s : symbols) {
            int cnt = count_symbol(word, s);
            if (cnt % 2 != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << (word == "" ? "_" : word) << " ";
            counter += 1;
        }
    }
}

void alphabet2(vector<char>& symbols, int& num) {
    int counter = 0;
    for (string word : sorted_array) {
        if (counter == num) {
            break;
        }
        bool flag = true;
        for (char s : symbols) {
            int cnt = count_symbol(word, s);
            if (cnt < 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << word << " ";
            counter += 1;
        }
    }
}

void alphabet3(vector<char>& symbols, int& num) {
    int counter = 0;
    for (string word : sorted_array) {
        if (counter == num) {
            break;
        }
        int flag = 0;
        for (char s : symbols) {
            int cnt = count_symbol(word, s);
            if (cnt == 0) {
                flag += 1;
            }
        }
        if (flag == 1) {
            cout << word << " ";
            counter += 1;
        }
    }
}



bool myPredicate(const std::string& str1, const std::string& str2) {
    if (str1.size() < str2.size()) {
        return true;
    } else if (str1.size() == str2.size()) {
        return str1 < str2;
    }
    return false;
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

    for (string word : my_set) {
        sorted_array.emplace_back(word);
    }

    std::sort(sorted_array.begin(), sorted_array.end(), myPredicate);

//    for (string s : sorted_array) {
//        cout << s << endl;
//    }

//    cout << "_" << " ";
    alphabet1(symbols, lengths[0]);
    cout << endl;
    alphabet2(symbols, lengths[1]);
    cout << endl;
    alphabet3(symbols, lengths[2]);

}
