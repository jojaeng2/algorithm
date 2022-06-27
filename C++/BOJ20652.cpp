#include <iostream>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;
int a, b, c;
vector<int> v, li;


void init() {
	for(int i=0; i<7; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	a = v[0], b = v[1], c = v[6] - a - b;
	cout << a << " " << b << " " << c << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}