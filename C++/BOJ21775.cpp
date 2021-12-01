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
#define NUM 10000
#define INF 987654321
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, t, pi[500010], ii[500010];
queue<int> tt, q;
string is[500010];
set<int> st;

void init() {
	cin >> n >> t;
	for(int i=0; i<t; i++) {
		int x;
		cin >> x;
		tt.push(x);
	}
	for(int i=0; i<t; i++) {
		int x, y;
		string s;
		cin >> x >> s;
		is[x] = s;
		q.push(x);
		if(s == "acquire") {
			cin >> y;
			ii[x] = y;
		}
		if(s == "release") {
			cin >> y;
			ii[x] = y;
		}
	}
	while(!tt.empty()) {
		int curr = tt.front();
		tt.pop();
		if(!pi[curr]) {
			int cnum = q.front(), num = ii[cnum];
			string s = is[cnum];
			q.pop();
			cout << cnum << '\n';
			if(s == "next") continue;
			if(s == "acquire") {
				if(st.find(num) == st.end()) st.insert(num);
				else pi[curr] = cnum;
			}
			if(s == "release") st.erase(num);
		}
		else {
			cout << pi[curr] << '\n';
			if(st.find(ii[pi[curr]]) == st.end()) {
				st.insert(ii[pi[curr]]);
				pi[curr] = 0;	
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}