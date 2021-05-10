#include <iostream>
#include <cstring>
using namespace std;
int n, maxi[3], mini[3];

int main() {
	memset(maxi, 0, sizeof(maxi));
	memset(mini, 0, sizeof(mini));
	
	cin >> n;
	for(int i=0;i<n;i++) {
		ios_base :: sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int a, b, c, aa, bb, cc;
		cin >> a >> b >> c;
		aa = a, bb = b, cc = c;
		a += max(maxi[0], maxi[1]);
		b += max({maxi[0], maxi[1], maxi[2]});
		c += max(maxi[1], maxi[2]);
		maxi[0] = a, maxi[1] = b, maxi[2] = c;

		aa += min(mini[0], mini[1]);
		bb += min({mini[0], mini[1], mini[2]});
		cc += min(mini[1], mini[2]);
		mini[0] = aa, mini[1] = bb, mini[2] = cc;
	}
	
	cout << max({maxi[0], maxi[1], maxi[2]}) << " " << min({mini[0], mini[1], mini[2]}) << '\n';
}