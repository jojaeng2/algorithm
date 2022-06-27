#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin >> a;
            if(q.size() < n){
                q.push(a);
            }
            else{
                int x = q.top();
                if(a > x){
                    q.pop();
                    q.push(a);
                }
            }

        }
    }
    cout << q.top() << '\n';
}