#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
vector<pii> v[301];
int dp[301][301];
int n,m,k;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a>=b) continue;
        v[a].push_back(make_pair(b,c));
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            int score = v[i][j].second;
            int next = v[i][j].first;
            if(i==1) dp[2][next] = max(dp[2][next],score);
            for(int p=2;p<m;p++){
                if(dp[p][i]==0) continue;
                dp[p+1][next] = max(dp[p+1][next],dp[p][i]+score);
            }
        }
    }
    
    int result =0;
    for(int i=2;i<=m;i++){
        result = max(result,dp[i][n]);
    }
    cout << result << endl;
}