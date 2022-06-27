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
#define NUM 500010
#define INF 2000000000
#define MOD 1000000007
#define LOG 22
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<piii, int> piiii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int n, bc = 0, rc = 0;
bool bisit[500010], risit[500010];
string s;

void init() {
	memset(bisit, false, sizeof(bisit));
	memset(risit, false, sizeof(risit));
	cin >> n >> s;
	for(int i=0; i<s.size(); i++) {
		if(bisit[i] || s[i] == 'R') continue;
		for(int j=i; j<s.size(); j++) {
			if(s[j] == 'R') {
				bc++;
				break;
			}
			bisit[j] = true;
		}
	}
	for(int i=0; i<s.size(); i++) {
		if(risit[i] || s[i] == 'B') continue;
		for(int j=i; j<s.size(); j++) {
			if(s[j] == 'B') {
				rc++;
				break;
			}
			risit[j] = true;
		}
	}
	if(s.back() == 'B') bc++;
	else rc++;
	cout << min(bc + 1, rc + 1) << '\n';
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}