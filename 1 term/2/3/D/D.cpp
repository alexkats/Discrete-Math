#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "nextsetpartition"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int n, k;
vector <int> a [200];
string s;
int b;

void solve (vector <int> a [])
{
	bool fl = false;
	int l = k - 1;
	vector <int> removed;	

	repd0(i, k)
	{
		rep0(j, (int) (removed.size ()))
			if (removed [j] > a [i][a [i].size () - 1])
			{ 
				a [i].pb (removed [j]);
				swap (removed [j], removed [removed.size () - 1]);
				fl = true;
				break;
			}

		if (fl)
		{
			removed.pop_back ();
			break;                                                                                      
		}
			
		repd0(j, (int) (a [i].size ())) 
		{
			if (j > 0)
				rep0(p, (int) (removed.size ()))
					if (removed [p] > a [i][j])                                            
					{
						swap (removed [p], a [i][j]);
						fl = true;
						break;                                                                          
					}

			removed.pb (a [i][j]);
			                                                                                            
			if (fl)
			{
				removed.pop_back ();                                                        
				break;
			}

			a [i].pop_back ();	

			sort (removed.begin (), removed.end ());	
		}

		if (fl)
			break;

		l--;	
	}

	sort (removed.begin (), removed.end ());

	cout << n << " " << l + removed.size () + 1 << endl;

	rep0(i, l + 1)
	{
		rep0(j, (int) (a [i].size ()))
			cout << a [i][j] << " ";

		cout << endl;
	}

	rep0(i, (int) (removed.size ()))
		cout << removed [i] << endl;

	cout << endl;	
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> n >> k;
	getline (cin, s);

	while (1)
	{
		if (n == 0 && k == 0)
			break;
			                             
		rep0(i, k)
		{
			getline (cin, s);
			int m = s.length ();

			rep0(j, m)
			{
				if (s [j] == ' ')
				{
					a [i].pb (b);
					b = 0;
				}	
				else
					b = b * 10 + (int) (s [j]) - 48;
			}

			a [i].pb (b);
			b = 0;
		}

		getline (cin, s);
		
/*		rep0(i, k)
		{
			rep0(j, (int) (a [i].size ()))
				cout << a [i][j];

			cout << endl;
		}*/

		solve (a);

		rep0(i, 200)
			a [i].clear ();

		cin >> n >> k;
		getline (cin, s);	
	}	

	return 0;
}	