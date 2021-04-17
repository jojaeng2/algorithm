#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
int num[1020];
int dp[1020];
vector<int> graph[1020];

int dfs(int start){
    if(dp[start]!=-1){
        return dp[start];
    }
    dp[start] = num[start];
    int ans = 0;
    for(int i=0;i<graph[start].size();i++){
        ans = max(ans,dfs(graph[start][i]));
    }
    dp[start] = 
    return dp[start]+=ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        for(int i=0;i<1020;i++){
            graph[i].clear();
        }
        memset(dp,-1,sizeof(dp));
        memset(num,0,sizeof(num));
        
        int n,k,destination;
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            cin >> num[i];
        }
        for(int i=0;i<k;i++){
            int a,b;
            cin >> a >> b;
            graph[b].push_back(a);
        }
        
        cin >> destination;
        
        cout << dfs(destination) << '\n';
    }
}