#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n,k;
vector<pii> jew;
vector<int>bag;
priority_queue<int>pq;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        jew.push_back(make_pair(a,b));
    }
    for(int i=0;i<k;i++){
        int a;
        cin >> a;
        bag.push_back(a);
    }
    sort(jew.begin(),jew.end());
    sort(bag.begin(),bag.end());

    ll result = 0;
    int idx = 0;
    for(int i=0;i<k;i++){
        while(idx<n){
            int weight = jew[idx].first;
            int money = jew[idx].second;
            if(weight<=bag[i]){
                pq.push(money);
                idx++;
            }
            else break;
        }
        if(!pq.empty()){

            result += pq.top();
            pq.pop();
        }
    }
    cout << result << endl;
}