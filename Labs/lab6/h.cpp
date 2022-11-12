#include <iostream>
using namespace std;

int n;
char letters[26];

void quicksort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int h = r;
    while (l < h)
    {
        if (letters[l] > letters[r])
        {
            while (l < h)
            {
                if (letters[h] <= letters[r])
                    swap(letters[l], letters[h]);
                break;
            }
            h--;
        }
        l++;
    }
    quicksort(0, l - 1);
    quicksort(l, r);
}

char find(char w, int l, int r)
{
    char answer = ' ';
    while (l <= r)
    {
        int m = (l + r) / 2;
        if(letters[m] <= w){
            l = m + 1;
        }
        if(letters[m] > w){
            r = m - 1;
            answer = letters[m];
        }
    }
    if(answer == ' '){
        answer = letters[0];
    }
    return answer;
}

void print()
{
    for (char s : letters)
    {
        cout << s << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i(0); i < n; i++)
    {
        cin >> letters[i];
    }

    char w;
    cin >> w;

    // quicksort(0, n - 1);
    // print();

    if(letters[n - 1] <= w || letters[0] > w){
        cout << letters[0] << "\n";
        return 0;
    }
    cout << find(w, 0, n - 1) << "\n";

    return 0;
}