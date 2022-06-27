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

void init() {
	string a, b, c, t, s = "";
	cin >> a >> b >> c >> t;
	for(int i=0; i<t.size(); i++) {
		if(t[i] == '1') s += a;
		if(t[i] == '2') s += b;
		if(t[i] == '3') s += c;
	}
	cout << s << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
