// C++ program for implementation of KMP pattern searching
// algorithm
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computeLPSArray(string pat, int M, int *lps);

// Prints occurrences of txt[] in pat[]
bool KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            return true;
            // printf("Found pattern at index %d ", i - j);
            // j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(string pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver program to test above function
int main()
{
    string s, t;
    cin >> s >> t;

    int cnt = 0;

    while (7)
    {
        if (KMPSearch(s, t))
        {
            cout << cnt << "\n";
            return 0;
        }
        t.push_back(t[0]);
        t.erase(t.begin());
        cnt++;
        if (cnt >= t.size())
        {
            cout << -1 << "\n";
            break;
        }
    }
    return 0;
}
