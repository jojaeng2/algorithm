#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define X first
#define Y second
using namespace std;
int n, num[110], answer = 0;

void init() {
	memset(num, 0, sizeof(num));
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> num[i];
		num[i] += num[i-1];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if((num[j]-num[i-1])%(j-i+1) != 0) continue;
			for(int k=i; k<=j; k++) {
				if(num[k]-num[k-1] == ((num[j]-num[i-1]))/(j-i+1)) {
					answer++;
					break;
				}
			}
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