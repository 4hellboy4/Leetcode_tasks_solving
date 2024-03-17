#include <iostream>
#include <vector>

using namespace std;

class Pair {
public:
    int element;
    int count;

    Pair(int element, int count) : element(element), count(count) {}
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<Pair> arr;

    int current_num = nums[0];
    int cnt = 1;
    int i = 1;

    while (i < nums.size()) {
        int current = nums[i];
        if (current_num != current) {
            Pair temp = Pair(current_num, cnt);
            arr.emplace_back(temp);

            current_num = nums[i];
            cnt = 1;
        } else {
            cnt += 1;
        }
        i++;
    }

    Pair temp = Pair(current_num, cnt);
    arr.emplace_back(temp);

    int answer = max(arr[0].element == 1 ? (arr[0].count) : 0,
                     arr[arr.size() - 1].element == 1
                     ? (arr[arr.size() - 1].count)
                     : -1);

    if (arr.size() == 1 && arr[0].element == 0) {
        answer = 0;
    } else if (arr.size() == 1 && arr[0].element == 1) {
        answer = answer - 1;
    }


    i = 0;

    while (i < arr.size() - 1) {
        if (arr[i].element == 1) {
            answer = max(answer, arr[i].count);
            if ( i + 2 < arr.size()) {
                answer = max(answer,
                             (arr[i + 1].count == 1 && arr[i + 2].element == 1)
                             ? (arr[i].count + arr[i + 2].count)
                             : 0);
            }
            answer = max(answer, arr[i + 1].element == 1
                                 ? arr[i].count + arr[i + 1].count - 1
                                 : 0);
        }
        i++;
    }

    cout << answer;

    return 0;
}