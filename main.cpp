#include <iostream>
#include <string>
#include <cctype>


using namespace std;

bool isPalindrome(string s) {
    string temp = "";
    for (int i = 0; i < s.size(); ++i) {
        char sym = s.at(i);
        if (isalpha(sym)) {
            temp += tolower(sym);
        } else if (isdigit(sym)) {
            temp += sym;
        }
    }

    for (int i = 0; i < ((int) temp.size()/2); ++i) {
        if (temp[i] != temp[temp.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s;

    getline(cin, s);

    cout << (isPalindrome(s) ? "true" : "false") << endl;

    return 0;
}