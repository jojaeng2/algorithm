#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define X first
#define Y second
#define NUM 1000010
using namespace std;
int n;
typedef pair<int, int> pii;
typedef long long ll;
ll answer = 0, maxi = 0;
vector<pii> v;

void init() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	for(int i=0; i<n-1; i++) {
		int x = v[i].X, y = v[i].Y, nx = v[i+1].X, ny = v[i+1].Y;
		answer += abs(x-nx) + abs(y-ny);
	}
	for(int i=0; i<n-2; i++) {
		int x = v[i].X, y = v[i].Y, nx = v[i+1].X, ny = v[i+1].Y, nnx = v[i+2].X, nny = v[i+2].Y;
		maxi = max(maxi, abs(x-nx)+(ll)(abs(y-ny)+abs(nx-nnx)+abs(ny-nny) - abs(x-nnx)-abs(y-nny)));
	}
	cout << answer - maxi << '\n';
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}