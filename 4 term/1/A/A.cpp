#define NAME "search1"

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#define pb push_back

using namespace std;

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    string s, t;
    cin >> s;
    cin >> t;
    int n = (int) s.length ();
    int m = (int) t.length ();
    vector <int> ans;

    for (int i = 0; i < m - n + 1; i++)
    {
        char bad = 0;

        for (int j = 0; j < n; j++)
            if (s [j] != t [i + j])
            {
                bad = 1;
                break;
            }

        if (!bad)
            ans.pb (i + 1);
    }

    cout << ans.size () << endl;

    if (ans.size () == 0)
        return 0;

    for (int i = 0; i < (int) ans.size (); i++)
        cout << ans [i] << " ";

    cout << endl;

    return 0;
}
