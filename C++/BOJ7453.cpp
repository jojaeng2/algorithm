#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
vector<ll> v[5];
vector<ll> pa,pb;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        v[1].push_back(a);
        v[2].push_back(b);
        v[3].push_back(c);
        v[4].push_back(d);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pa.push_back(v[1][i]+v[2][j]);
            pb.push_back(v[3][i]+v[4][j]);
        }
    }
    sort(pa.begin(),pa.end());
    sort(pb.begin(),pb.end());

    ll cnt = 0;
    ll start=0,end=pb.size()-1;

    while(start<pa.size() && end >= 0){
        if(pa[start]+pb[end]>0) end--;
        else if(pa[start]+pb[end]<0) start++;
        else{
            ll a=1,b=1;
            while(start!=pa.size()-1 && pa[start+1]==pa[start]){
                start++;
                a++;
            }
            while(end!=0 && pb[end-1]==pb[end]){
                end--;
                b++;
            }
            start++;
            cnt += a*b;
        }
    }
    cout << cnt << endl;
}