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
#define NUM 100100
#define INF 1000000000
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, answer;
vector<string> v;

void init() {
	cin >> n;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(s);
	}
	for(int i=0; i<v[0].size(); i++) {
		set<string> st;
		for(int j=0; j<v.size(); j++) {
			st.insert(v[j].substr(0, i+1));
		}
		if(st.size() == n) {
			cout << i+1 << '\n';
			break;
		}
	}
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}