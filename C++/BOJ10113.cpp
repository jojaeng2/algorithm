#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
int n, num[200], maxi = 0;
bool flag = false;

void init() {
	memset(num, 0, sizeof(num));
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		if(!x) continue;
		num[x]++;
	}
	for(int i=1; i<=n; i++) {
		if(num[maxi] < num[i]) {
			flag = true;
			maxi = i;
		}
		else if(num[maxi] == num[i]) {
			flag = false;
		}
	}
	if(flag) cout << maxi << '\n';
	else cout << "skipped" << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
