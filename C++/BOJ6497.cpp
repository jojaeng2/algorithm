#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<pair<int,int>,int> piii;
typedef long long ll;
int n,m;
vector<piii> v;
ll result;
int visit[200001];
int find(int start){
    if(start==visit[start]) return start;
    visit[start] = find(visit[start]);
    return visit[start];
}

bool uni(int a,int b){
    int aa = find(a);
    int bb = find(b);
    if(aa==bb) return false;
    visit[bb] = visit[aa];
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        result = 0;
        memset(visit,0,sizeof(visit));
        v.clear();
        cin >> n >> m;
        if(n==0 && m==0){
            break;
        }
        for(int i=0;i<n;i++) visit[i] = i;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a  >> b >> c;
            v.push_back(make_pair(make_pair(c,a),b));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int cost = v[i].X.X;
            int x = v[i].X.Y;
            int y = v[i].Y;
            result += cost;
            if(uni(x,y)) result -= cost;
        }
        cout << result << '\n';
    }
}