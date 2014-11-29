#define NAME "planaritycheck"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define pb push_back
#define mp make_pair
#define frs first
#define snd second

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <bool> vb;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

template <typename T>
T sqr (T a)
{
    return a * a;
}

const int N = 6;

int T;
string s;
char tmp [15];

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &T);

    while (T --> 0)
    {
        scanf ("%s", tmp);
        s = (const char*) tmp;
        int n = ceil (sqrt ((int) s.length () * 2));

        if (n == 0)
            n++;

        if (n < 5) {
            puts ("YES");
            continue;
        }
        
        char g [N + 1][N + 1];

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                g [i][j] = 0;

        int ind = 0;

        for (int j = 2; j <= n; j++)
            for (int i = 1; i < j; i++) 
            {
                g [i][j] = (int) (s [ind] - '0');
                g [j][i] = (int) (s [ind] - '0');
                ind++;
            }

        int a [7];
            
        for (int i = 1; i <= N; i++)
            a [i] = i;

        bool ok = 1;

        if (n == N)
        {
            while (1)
            {
                for (int i = 1; i <= N / 2; i++)
                    for (int j = N / 2 + 1; j <= N; j++)
                        if (!g [a [i]][a [j]])
                        {
                            ok = 0;
                            break;
                        }

                ok = !ok;

                if (!ok || !next_permutation (a + 1, a + N + 1))
                    break;
            }
        }

        if (!ok)
        {
            puts ("NO");
            continue;
        }

        if (n == N)
        {
            for (int v = 1; v <= N; v++)
            {
                for (int i = 1; i < N; i++)
                {
                    for (int j = i + 1; j <= N; j++)
                    {
                        if (i == v || j == v)
                            continue;

                        if (!g [i][v] || !g [j][v])
                            continue;

                        g [i][v] = 0;
                        g [v][i] = 0;
                        g [j][v] = 0;
                        g [v][j] = 0;
                        char was = 1;

                        if (!g [i][j])
                        {
                            g [i][j] = 1;
                            g [j][i] = 1;
                            was = 0;
                        }

                        for (int i1 = 1; i1 < N; i1++)
                            for (int j1 = i1 + 1; j1 <= N; j1++)
                            {
                                if (i1 == v || j1 == v)
                                    continue;

                                if (!g [i1][j1])
                                {
                                    ok = 0;
                                    break;
                                }
                            }

                        ok = !ok;

                        g [i][v] = 1;
                        g [v][i] = 1;
                        g [j][v] = 1;
                        g [v][j] = 1;

                        if (!was)
                        {
                            g [i][j] = 0;
                            g [j][i] = 0;
                        }

                        if (!ok)
                            break;
                    }

                    if (!ok)
                        break;
                }

                if (!ok)
                    break;
            }
        }

        if (!ok)
        {
            puts ("NO");
            continue;
        }

        while (1)
        {
            for (int i = 1; i < 5; i++)
                for (int j = i + 1; j < 6; j++)
                    if (!g [a [i]][a [j]])
                    {
                        ok = 0;
                        break;
                    }

            ok = !ok;

            if (!ok || !next_permutation (a + 1, a + N + 1))
                break;
        }

        puts (ok ? "YES" : "NO");
    }

    return 0;
}
