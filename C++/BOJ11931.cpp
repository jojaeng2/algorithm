
#include <iostream>
#include <algorithm>
using namespace std;
int num[1000000];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num,num+n,greater<int>());
    
    for(int i=0;i<n;i++){
        cout << num[i] << endl;
    }
}