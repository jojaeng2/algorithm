#include <iostream>

#define INF 987654321
using namespace std;
typedef long long ll;
int home[1001][4];
ll copyh[1001][4];
ll result = INF;
int n;
void dp(int num){
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            copyh[i][j] = home[i][j];
        }
    }
    
    copyh[n-1][num]=INF;
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0) copyh[i][0] += min(copyh[i-1][1],copyh[i-1][2]);
            else if(j==1) copyh[i][1] += min(copyh[i-1][0],copyh[i-1][2]);
            else copyh[i][2] += min(copyh[i-1][0],copyh[i-1][1]);
        }
    }
    for(int i=0;i<3;i++){
        if(i==num) continue;
        result = min(result,copyh[n-1][i]);
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> home[i][0] >> home[i][1] >> home[i][2];
    }
    dp(0);
    dp(1);
    dp(2);
    cout << result << '\n';
}