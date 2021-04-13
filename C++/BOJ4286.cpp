#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<float,float> pff;
vector<pff> star;
vector<int> line[101];
float visit[101];

void prim(){
    priority_queue<pair<float,int> >pq;
    pq.push(make_pair(0,1));
    visit[1] = 0;
    for(int i=0;i<line[1].size();i++){
        int next = line[1][i];
        float dist = sqrt(pow(star[1].first-star[next].first,2)+pow(star[1].second-star[next].second,2));
        pq.push(make_pair(-dist,next));
    }
    while(!pq.empty()){
        int now = pq.top().second;
        float dist = -pq.top().first;
        pq.pop();
        if(visit[now]!=-1)continue;
        visit[now] = dist;
        for(int i=0;i<line[now].size();i++){
            int next = line[now][i];
            float dist = sqrt(pow(star[now].first-star[next].first,2)+pow(star[now].second-star[next].second,2));
            pq.push(make_pair(-dist,next));
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    star.push_back(make_pair(0,0));
    for(int i=1;i<=n;i++){
        float a,b;
        cin >> a >> b;
        star.push_back(make_pair(a,b));
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            line[j].push_back(i);
        }
    }
    fill(visit,visit+101,-1);
    prim();
    float result = 0;
    for(int i=1;i<=n;i++){
        cout << visit[i] << endl;
        result += visit[i];
    }
    printf("%.2f",result);
}