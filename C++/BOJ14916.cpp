#include <iostream>

using namespace std;
int num[100001] ={0};
int main(){
    for(int i=1;i<100001;i++){
        if(i%2==0){
            num[i] = i/2;
        }
    }
    num[5] = 1;
    for(int i=6;i<100001;i++){
        if(num[i-5] != 0){
            num[i] = num[i-5] + 1;
        }
    }
    int n;
    cin >> n;
    cout << num[n] << '\n';
}