#include <iostream>
using namespace std;
int n;

void init() {
	cin >> n;
	long long cnt = 1;
	for(int i=1; i<=n; i++) {
		cout << cnt << '\n';
		cnt *= i;
		cnt %= 1000000;
		while(cnt%10 == 0) {
			cnt /= 10;
		}
	}
	cout << cnt%10 << '\n';
}

int main() {
	init();
}