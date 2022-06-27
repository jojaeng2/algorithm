#include <iostream>
#include <algorithm>

int num[10001];
int coin[101];
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> coin[i];
    }
    sort(coin,coin+n);
    
    for(int i=0;i<10001;i++){
        num[i] = 10001;
    }
    num[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=coin[i];j<=m;j++){
            num[j] = min(num[j],num[j-coin[i]]+1);       
        }
    }
    
    if(num[m] == 10001){
        cout << -1 << endl;
    }
    else{
        cout << num[m] << '\n';
    }
}