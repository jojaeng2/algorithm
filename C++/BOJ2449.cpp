#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, DP[201][201];
vector<int> bulb;

int dfs(int s, int e) {
    if(DP[s][e] != -1) return DP[s][e];
    if(s==e) return DP[s][e] = 0;
    DP[s][e] = 1e9;
    for(int k=s; k<e; k++) {
        int p = 0;
        if(bulb[s] != bulb[k+1]) p=1;
        DP[s][e] = min(DP[s][e], dfs(s, k) + dfs(k+1, e) + p);
    }
    return DP[s][e];
} 

void init() {
    memset(DP, -1, sizeof(DP));
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(bulb.empty() || bulb.back() != x) bulb.push_back(x);
    }
}

int main() {
    init();
    cout << dfs(0, bulb.size()-1) << '\n';
    
}