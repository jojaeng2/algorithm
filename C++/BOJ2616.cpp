#include <iostream>
#include <vector>

using namespace std;
int train[50001];
int dp[4][50001];
int result,m,n;
void ha(){
    for(int i=1;i<=3;i++){
        for(int j=i*m;j<=n;j++){
            if(i==1){
                dp[1][j] = max(dp[1][j-1],train[j]-train[j-m]);
            }
            else {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j-m] + train[j]-train[j-m]);
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        train[i] = train[i-1] + a;
    }
    cin >> m;
    ha();
    cout << dp[3][n] << endl;
}