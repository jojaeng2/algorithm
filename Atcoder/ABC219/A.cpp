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
int t, a = 40, b = 70, c = 90;

void init() {
	cin >> t;
	if(t < 40) cout << a-t << '\n';
	else if(t<70) cout << b-t << '\n';
	else if(t<90) cout << c-t << '\n';
	else cout << "expert" << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
