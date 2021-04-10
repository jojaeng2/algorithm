#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;

vector<pil>v;
priority_queue<ll>ramen;

ll result = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        ll b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        int deadline = v[i].first;
        ramen.push(-v[i].second);
        while(ramen.size()>deadline) ramen.pop();
    }
    while(!ramen.empty()){
        ll cnt = ramen.top();
        ramen.pop();
        result += -cnt;
    }

    cout << result << "\n";
}