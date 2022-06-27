#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 10000000000000
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, root = 1;
ll k;
pii node[200010];

void init() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        node[i] = {x, y};
    }
    cin >> k;
    while(true) {
        if(node[root].X == -1 && node[root].Y == -1) break;
        else if(node[root].X == -1) root = node[root].Y;
        else if(node[root].Y == -1) root = node[root].X;
        else if(k%2) {
            root = node[root].X;
            k /= 2;
            k++;
        }
        else {
            root = node[root].Y;
            k /= 2;
        }
    }
    cout << root << '\n';
}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}


