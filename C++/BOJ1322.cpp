#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#define X first
#define Y second
#define INF 1e9
#define NUM 1010
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll x, k;

string trans(ll now) {
	string s="";
	for(ll i=1; now>0; i*=10) {
		int b = now%2;
		if(b == 0) s += '0';
		else s += '1';
		now /= 2;
	}
	return s;
}


void init() {
	cin >> x >> k;
	string xs = trans(x), ks = trans(k), ans = "";
	int idx = 0;
	for(int i=0; i<xs.size(); i++) {
		if(xs[i] == '1') ans += '0';
		else {
			ans += ks[idx];
			idx++;
		}
		if(idx>=ks.size()) break;		
	}
	for(int i=idx; i<ks.size(); i++) ans += ks[i];
	ll answer = 0;
	for(ll i=0; i<ans.size(); i++) {
		if(ans[i] == '0') continue;
		answer += ((ll)1<<i);
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}