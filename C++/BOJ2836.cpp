#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> v;
ll n,m,result=0;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    result = m;
    for(int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        if(a>b) v.push_back(make_pair(b,a));
    }
    sort(v.begin(),v.end());

    ll start=0,end=0;
    for(int i=0;i<v.size();i++){
        ll x = v[i].X;
        ll y = v[i].Y;
        if(end<=x){
            result += (end-start)*2;
            start = x;
            end = y;
        } 
        else if(end<=y){
            end = y;
        }
    }
    result += (end-start)*2;

    cout << result << endl;
}