#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,result=0;
int dat[51][10],people[10];
bool visit[10],ground[4];;

void game(){
    int idx=1,score=0;
    for(int i=1;i<=n;i++){
        fill(ground,ground+4,false);
        int out = 0;
        while(out<3){
            if(idx==10) idx=1;
            int now = people[idx];
            idx++;
            if(dat[i][now]==0){
                out++;
            }
            else if(dat[i][now]==1){
                if(ground[3]){
                    score++;
                    ground[3]=false;
                }
                if(ground[2]){
                    ground[3]=true;
                    ground[2]=false;
                }
                if(ground[1]){
                    ground[2]=true;
                }
                ground[1]=true;
            }
            else if(dat[i][now]==2){
                if(ground[3]){
                    score++;
                    ground[3]=false;
                }
                if(ground[2]){
                    score++;
                }
                if(ground[1]){
                    ground[1]=false;
                    ground[3]=true;
                }
                ground[2]=true;
            }
            else if(dat[i][now]==3){
                if(ground[3]){
                    score++;
                }
                if(ground[2]){
                    score++;
                    ground[2]=false;
                }
                if(ground[1]){
                    score++;
                    ground[1]=false;
                }
                ground[3]=true;
            }
            else if(dat[i][now]==4){
                if(ground[3]){
                    score++;
                    ground[3]=false;
                }
                if(ground[2]){
                    score++;
                    ground[2]=false;
                }
                if(ground[1]){
                    score++;
                    ground[1]=false;
                }
                score++;
            }
        }
    }
    result = max(result,score);
}
void dfs(int cnt){
    if(cnt==10){
        game();
        return;
    }
    if(cnt==4){
        people[4] = 1;
        dfs(cnt+1);
    }
    else{
        for(int i=2;i<=9;i++){
            if(visit[i]) continue;
            visit[i] = true;
            people[cnt] = i;
            dfs(cnt+1);
            people[cnt] = 0;
            visit[i] = false;
        }
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=9;j++) cin >> dat[i][j];
    visit[1]=true;
    dfs(1);
    cout << result << endl;
}