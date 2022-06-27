#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
ll x=1e9, y=1e9, z=1e9, num[10], n, answer = 0, psum = 0;
vector<int> v;

void init() {
	cin >> n;
	for(int i=0; i<6; i++) {
		cin >> num[i];
		x = min(x, num[i]);
		v.push_back(num[i]);
		psum += num[i];
	}
	for(int i=1; i<5; i++) {
		y = min(y, num[0]+num[i]);
		y = min(y, num[5]+num[i]);
		for(int j=1; j<5; j++) {
			if(i == j) continue;
			if(i == 1 && (j == 2 || j == 3)) y = min(y, num[i]+num[j]);
			if(i == 2 && (j == 1 || j == 4)) y = min(y, num[i]+num[j]);
			if(i == 3 && (j == 1 || j == 4)) y = min(y, num[i]+num[j]);
		}
	}
	for(int i=1; i<5; i++) {
		for(int j=i+1; j<5; j++) {
			if((i == 1 && j == 4) || (i==2 && j==3)) continue;
			z = min(z, num[0]+num[i]+num[j]);
			z = min(z, num[5]+num[i]+num[j]);
		}
	}
	if(n == 1) {
		sort(v.begin(), v.end());
		cout << psum - v[5] << '\n';
	}
	else {
		answer += (pow(n-2, 2) + (4*(n-2)*(n-1))) *x;
		answer += (8*n-12)*y;
		answer += 4*z;
		cout << answer << '\n';
	}
}

int main() {
	init();
}