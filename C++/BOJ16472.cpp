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
#define NUM 130
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
int n, l = 0, r = 0, answer = 0, cnt = 0;
string s;
bool flag = false;
map<char, int> mp;

void init() {
	cin >> n >> s;
	while(l <= r && r < s.size()) {
		if(!flag) {	
			if(mp[s[r]] == 0) cnt++;
			mp[s[r]]++;
		}
		if(cnt <= n) {
			answer = max(answer, r-l+1);
			r++;
			flag = false;
		}
		else {
			if(mp[s[l]] == 1) cnt--;
			mp[s[l]]--;
			l++;
			flag = true;
		}
	}
	cout << answer << '\n';
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}