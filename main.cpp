#include <iostream>
#include <vector>
#include <set>
using namespace std;

//vector<str> solution1() {
//    vector<str> temp;
//    temp.emplace_back("_");
//
//}

set<string> my_set;

void permutations(int& n, vector<string>& array, string str) {
    if ((str.size() > 2*n) || my_set.find(str) != my_set.end())
        return;
    array.emplace_back(str);
    my_set.insert(str);
    for (int i = 0; i < array.size(); ++i) {
        string temp = array.at(i);
        for (string& s : array) {
            temp.append(s);
            permutations(n, array, temp);
        }
    }
}


int main() {
    int n;

    cin >> n;

    vector<string> symbols(n);
    vector<int> lengths(3);

    for (int i = 0; i < n; ++i) {
        cin >> symbols.at(i);
    }

    for (int i = 0; i < 3; ++i) {
        cin >> lengths.at(i);
    }

//    vector<string> strings;
    vector<string> strings;
    for (string s : symbols) {
        strings.emplace_back(s);
        my_set.insert(s);
    }

    permutations(n, strings, "");

    for (string s : strings) {
        cout << s << endl;
    }


}
