#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string str;
	vector<char> vec;
	bool fi = false;
	while (1)
	{
		cin >> str;
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
			vector<char> vec2(vec.size());
			int index = 0;
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
						if (vec2[index-1] == '(') --index;
						else 
						{
							break;
						}
						
					}
					else if(vec[i] == ']')
					{
						if (vec2[index - 1] == ']') --index;
						else
						{
							break;
						}
					}
				}
				if (index < 0) break;
			}
		}
	}

	
}