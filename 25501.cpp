#include <iostream>

using namespace std;

#include <stdio.h>
#include <string.h>

struct result
{
    int isP;
    int count;
};

result recursion(const char* s, int l, int r, int count) {
    if (l >= r) return { 1,count };
    else if (s[l] != s[r]) return { 0,count };
    else return recursion(s, l + 1, r - 1,++count);
}

result isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1,1);
}


int main()
{
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        result r = isPalindrome(a.c_str());
        cout << r.isP << ' ' << r.count<<endl;
    }
}