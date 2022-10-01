// equal strings
#include <iostream>

using namespace std;

int main()
{
    string s1, s2, answer;
    cin >> s1 >> s2;
   
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == '#')
        {
            cnt1++;
        }
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] == '#')
        {
            cnt2++;
        }
    }
    if (s1.length() != s2.length())
    {
        if(cnt1 == 0 && s2.length() - 2 * cnt2 == s1.length()){
            answer = "Yes";
        }else if(cnt2 == 0 && s1.length() - 2 * cnt1 == s2.length()){
            answer = "Yes";
        }else{
            answer = "No";
        }
    }
    else
    {
        if (cnt1 != cnt2)
        {
            answer = "No";
        }
        else
        {
            answer = "Yes";
        }
    }
    cout << answer << endl;

    return 0;
}