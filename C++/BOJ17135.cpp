#include <iostream>
#include <vector>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

int n,m,d,result,page,ans;
int graph[16][16],cgraph[16][16],visit[16][16];
bool bow[16];
vector<pii> v,dat;

void count(){
    for(int i=0;i<3;i++){
        memset(visit,0,sizeof(visit));
        int x = v[i].X;
        int y = v[i].Y;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                if(cgraph[j][p]==1) visit[j][p] = abs(x-j)+abs(y-p)-page;
            }
        }
        int row=0,column=0;
        visit[row][column]=987654;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                if(visit[j][p]>0 && visit[j][p]<= d){
                    if(visit[j][p]<visit[row][column]){
                        row = j;
                        column = p;
                    }
                    else if(visit[j][p]==visit[row][column]){
                        if(p<column){
                            row=j;
                            column=p;
                        }
                    }
                }
            }
        }
        dat.push_back(make_pair(row,column));
    }
    while(!dat.empty()){
        int nx = dat.back().X;
        int ny = dat.back().Y;
        dat.pop_back();
        if(cgraph[nx][ny]==1){
            ans++;
            cgraph[nx][ny]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cgraph[n-page][i]=0;
    }
    return;
}

void dfs(int cnt){
    if(cnt==3){
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cgraph[i][j] = graph[i][j];
        page = 0;
        while(page<=n){
            count();
            page++;
        }
        result = max(result,ans);
        ans=0;
        return;
    }
    for(int i=1;i<=m;i++){
        if(bow[i]) continue;
        bow[i] = true;
        v.push_back(make_pair(n+1,i));
        dfs(cnt+1);
        v.pop_back();
        for(int j=i+1;j<=m;j++) bow[j]=false;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> d;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> graph[i][j];
    dfs(0);
    cout << result << endl;
}