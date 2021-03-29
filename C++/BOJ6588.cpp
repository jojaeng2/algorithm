#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool era(int n){
    int k = (int)sqrt(n);
    for(int i=2;i<=k;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

vector<int>v;
bool visit[1000001]={false};
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base :: sync_with_stdio(false);
    for(int i=3;i<1000001;i++){
        if(era(i)){
            v.push_back(i);
            visit[i] = true;
        }
    }
    while(1){
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        for(int i=0;i<v.size();i++){
            if(visit[n-v[i]] == true){
                cout << n << " = " << v[i] << " + " << n-v[i] << '\n';
                break;
            }
        }
    }
}