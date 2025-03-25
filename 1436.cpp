#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> num;
    int i = 666;
    while (num.size() < n) {
        if (to_string(i).find("666") != string::npos) {
            num.push_back(i);
        }
        i++;
    }

    sort(num.begin(), num.end());

    cout << num[n - 1] << endl;
    return 0;
}
















