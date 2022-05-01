#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 10000000000000
#define X first
#define Y second
using namespace std;
int n, a = 1, b = 0, na, nb;

void init() {
    cin >> n;
    while(n--) {
        nb = a;
        na = b;
        nb += b;
        a = na, b = nb;
        na = 0, nb = 0;
    }
    cout << a << " " << b << '\n';
}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}


