#include <iostream>
#include <algorithm>
using namespace std;
int n,m,result=0;
int visit[1001][1001];

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin >> a;
            if(a==2 || a==1){
                visit[i][j] = -1;
            }
            else if(a==0 && (i==0 || j==0)){
                visit[i][j] = 1;
            }
            else visit[i][j] = 0;
            result = max(result,visit[i][j]);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(visit[i][j]==-1) continue;
            int mini = min({visit[i-1][j-1],visit[i-1][j],visit[i][j-1]});
            if(mini==-1) visit[i][j] = 1;
            else{
                visit[i][j] = mini+1;
            }
            result = max(result,visit[i][j]);
        }
    }
    cout << result << endl;
}