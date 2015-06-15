#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
 
using namespace std;
 
int n, k, kol = 0;
vector <int> a[15];                  
 
void gen(vector <int> a[], int p)
{                    
        if (kol > k || p > n)
                return;
        if (kol == k && p == n)
        {
                for(int i = 1; i <= k; i++)
                        for(int j = 0; j < (int) (a [i].size ()); j++)
                                if (j < (int) (a [i].size ()) - 1)
                                        cout << a[i][j] << " ";
                                else
                                        cout << a[i][j] << endl;
                cout << endl;
                return;
        }
        for(int i = 1; i <= kol; i++)
        {
                a[i].push_back(p + 1);
                gen(a, p + 1);
                a[i].pop_back();
        }
        kol++;
        a[kol].push_back(p + 1);
        gen(a, p + 1);
        a[kol].pop_back();     
        kol--;
 
}
 
 
int main()
{
        freopen("part2sets.in", "r", stdin);
        freopen("part2sets.out", "w", stdout);
        cin >> n >> k;
        gen(a, 0);
        return 0;
}