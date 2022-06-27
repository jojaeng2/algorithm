#include <iostream>

using namespace std;

int li[100001] = {0};
long long psum[100001] = {0};
int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> li[i];
    }
    long long mx =0;
    for(int i=0;i<m;i++){
        mx += li[i];
    }
    psum[m-1] = mx;
    for(int i=m;i<n;i++){
        psum[i] = psum[i-1]+li[i]-li[i-m];        
    }
    for(int i=0;i<n;i++){
        if(psum[i] > mx){
            mx = psum[i];
        }
    }
    cout << mx << endl;

}