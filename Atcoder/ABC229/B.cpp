#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <deque>
#include <list>
#define X first
#define Y second
#define NUM 100010
#define INF 987654321
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, double> piib;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
string a, b;
bool flag = true;

void init() {
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int j=0; j<min(a.size(), b.size()); j++) {
		for(ll i=1; i<=18; i++) {
			ll d = pow(10, i), r = pow(10, i-1);
			if(((a[j]-'0')%d)/r + ((b[j]-'0')%d)/r >= 10) flag = false;
		}
	}
	if(flag) cout << "Easy" << '\n';
	else cout << "Hard" << '\n';

}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}