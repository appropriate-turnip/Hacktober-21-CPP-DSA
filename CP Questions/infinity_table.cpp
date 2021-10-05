/*  Codeforces Problem: https://codeforces.com/contest/1560/problem/C
    Solution by: Ratan Raj Ojha
    Date: 4th Oct 2021
    */
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int num, r, c, temp;
		cin >> num;
		temp = floor(sqrt(num));
		if (temp == sqrt(num)) {
			r = sqrt(num);
			c = 1;
		}
		else {
			r = 1; c = temp + 1;
			for (int i = pow(temp, 2) + 1; i < num; i++) {
				if (r < (temp + 1)) {
					r++;
				}
				else {
					c--;
				}
			}
		}
		cout << r << ' ' << c << "\n";
	}
	return 0;
}
