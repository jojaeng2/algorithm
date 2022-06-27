#include <iostream>
using namespace std;
int n, m, x, y, t;

int main() {
	cin >> n >> m >> x >> y >> t;
	x += t, y += t;
	if((x/n)%2 == 0) {
		cout << x%n << " ";
	}
	else {
		cout << n - x%n << " ";
	}
	if((y/m)%2 == 0) {
		cout << y%m << "\n";
	}
	else {
		cout << m - y%m << "\n";
	}
	
}