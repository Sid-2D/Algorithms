// Link: https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main() 
{
	int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        string s;
        string close = ")]}";
        string ans = "YES\n";
        map<char, char> p;
        p[')'] = '(';
        p[']'] = '[';
        p['}'] = '{';
        cin >> s;
        vector<char> vec;
        vec.push_back(s[0]);
        for (int i = 1; i < s.length(); i++) 
        {
            if (close.find(s[i]) < INT_MAX) 
            {
                if (p[s[i]] == vec.back()) 
                {
                    vec.pop_back();
                    continue;
                } else 
                {
                    ans = "NO\n";
                    break;
                }
            }
            vec.push_back(s[i]);
        }
        if (vec.size() > 0) 
        {
        	ans = "NO\n";
        }
        cout << ans;
    }
	return 0;
}