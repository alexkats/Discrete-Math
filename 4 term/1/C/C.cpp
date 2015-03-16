#define NAME "prefix"

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

typedef vector <int> vi;

char tmp [1000005];
string s;
int n;

vi calc ()
{
    vi p (n);
    p [0] = 0;

    for (int i = 1; i < n; i++)
    {
        int k = p [i - 1];

        while (k > 0 && s [i] != s [k])
            k = p [k - 1];

        if (s [i] == s [k])
            k++;

        p [i] = k;
    }

    return p;
}

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%s\n", tmp);
    s = (const char*) tmp;
    n = (int) s.length ();
    vi ans = calc ();

    for (int i = 0; i < n; i++)
        printf ("%d%c", ans [i], " \n" [i == n - 1]);

    return 0;
}
