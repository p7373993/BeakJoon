#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str;
    vector<char> vec;

    while (1)
    {
        bool fi = false;
        getline(cin, str);
        if (str == ".") break;
        for (auto s : str)
        {
            if (s == '(' || s == '[' || s == ')' || s == ']')
            {
                vec.emplace_back(s);
            }
            else if (s == '.')
            {
                fi = true;
                break;
            }
        }

        if (fi)
        {
            bool nok = true;
            vector<char> vec2(vec.size());
            int index = 0;
            if (vec.size() == 0) nok = false;
            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i] == '(' || vec[i] == '[')
                {
                    vec2[index] = vec[i];
                    ++index;
                }
                else
                {
                    if (vec[i] == ')')
                    {
                        if (index <= 0) break;
                        if (vec2[index - 1] == '(') --index;
                        else
                        {
                            break;
                        }
                    }
                    else if (vec[i] == ']')
                    {
                        if (index <= 0) break;
                        if (vec2[index - 1] == '[') --index;
                        else
                        {
                            break;
                        }
                    }
                }

                if (i == vec.size() - 1 && index == 0) nok = false;
            }

            if (nok)
            {
                cout << "no\n";
            }
            else cout << "yes\n";

            vec.clear();
            vec2.clear();
        }
    }
}