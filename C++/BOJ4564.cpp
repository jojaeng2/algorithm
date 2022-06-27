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
#define NUM 1010
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
string n;

void init() {
	while(true) {
		cin >> n;
		if(n == "0") break;

		cout << n << " ";
		while(n.size() > 1) {
			int num = 1;
			for(int i=0; i<n.size(); i++) {
				num *= n[i]-'0';
			}
			n = to_string(num);

			cout << n << " ";
		} 
		cout << '\n';
	}

}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}