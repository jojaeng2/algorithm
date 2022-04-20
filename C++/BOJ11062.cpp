#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 10000000000000
#define X first
#define Y second
using namespace std;
typedef long long ll;
int t, n, DP[2][1010][1010];

int dfs(vector<int> &v, int left, int right, int curr, int psum) {
    if(left > right) return 0; 
    int &res = DP[curr][left][right];
    if(res != 0) return res;
    res = 0;
    int x = v[left++];
    res = max(res, psum - dfs(v, left, right, ((curr == 0) ? 1 : 0), psum - x));
    left--;
    if(v.empty()) return res;
    x = v[right--];
    res = max(res, psum - dfs(v, left, right, ((curr == 0) ? 1 : 0), psum - x));
    right++;
    return res;
}


void init() {
    cin >> t;
    while(t--) {
        memset(DP, 0, sizeof(DP));
        cin >> n;
        vector<int> v;
        int psum = 0;
        v.clear();
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            psum += x;
            v.push_back(x);
        }
        cout << dfs(v, 0, n-1, 0, psum) << '\n';
    }
}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}


