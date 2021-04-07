#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll dat[10];
ll now[10];
vector<ll>v;

int main(){
    fill(dat,dat+10,1);
    v.push_back(0);
    v.push_back(9);
    for(int i=2;i<101;i++){
        for(int j=0;j<10;j++){
            if(j==0){
                now[0] = dat[1];
            }
            else if(j==9){
                now[9] = dat[8];
            } else {
                now[j] = (dat[j-1] + dat[j+1])%1000000000;
            }
        }
        ll sum = 0;
        for(int j=1;j<10;j++){
            sum += now[j];
        }
        v.push_back(sum%1000000000);
        for(int j=0;j<10;j++){
            dat[j] = now[j];
        }
    }
    int n;
    cin >> n;
    cout << v[n] << endl;
}