#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll,int> >three;
vector<pair<ll,int> >five;

bool compare(pair<ll, int> a, pair<ll, int> b)
{
    return a.first > b.first;
}

int n,m;
ll mx = 0;

ll find(vector<pair<ll,int> >a, vector<pair<ll,int> >b,int x){
    for(int i=0;i<a.size();i++){
        ll sweet = a[i].first;
        int weight = a[i].second;
        if(m-weight >= x){
            int idx = ((m-weight)/x)-1;
            if(b.size() == 0){
                mx = sweet;
                continue;
            }
            if(idx >= b.size()){
                idx = b.size()-1;
            }
            if(mx < sweet + b[idx].first){
                mx = sweet + b[idx].first;
            }
        } else {
            if(mx < sweet && weight <= m){
                mx = sweet;
            }
        }
    }
    return mx;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a == 3){
            three.push_back({b,a});
        }
        else{
            five.push_back({b,a});
        }
    }
    sort(three.begin(),three.end(),compare);
    sort(five.begin(),five.end(),compare);
    
    for(int i=1;i<three.size();i++){
        three[i].first += three[i-1].first;
        three[i].second += three[i-1].second;
    }
    for(int i=1;i<five.size();i++){
        five[i].first += five[i-1].first;
        five[i].second += five[i-1].second;
    }

    ll result;
    result = find(three,five,5);
    result = find(five,three,3);
    cout << result << endl;

}