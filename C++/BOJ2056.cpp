#include <iostream>
#include <vector>

using namespace std;

int dat[10001];
int dp[10001];
vector<int> v[10001];
int n,result=0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        dat[i] = a;
        for(int j=0;j<b;j++){
            int c;
            cin >> c;
            v[i].push_back(c);
        } 
    }

    for(int i=1;i<=n;i++){
        dp[i] = dat[i];
        result = max(dp[i],result);
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            int before = v[i][j];
            dp[i] = max(dp[i], dat[i]+dp[before]);
            result = max(result, dp[i]);
        }
    }
    cout << result << endl;
}