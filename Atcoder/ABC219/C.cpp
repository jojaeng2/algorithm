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
#define NUM 200010
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int t;
map<char, int> m;
vector<string> v;

bool compare(string a, string b) {
	for(int i=0; i<min(a.size(), b.size()); i++) {
		if(a[i] == b[i]) continue;
		return m[a[i]] < m[b[i]];
	}
	return a.size() < b.size();
}

void init() {
	string a;
	cin >> a;
	for(int i=0; i<a.size(); i++) {
		m.insert({a[i], i});
	}
	cin >> t;
	for(int i=0; i<t; i++) {
		string b;
		cin >> b;
		v.push_back(b);
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << '\n';
	}
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
