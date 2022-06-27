#include <iostream>
#include <algorithm>
#include <vector>

int one[1000001];
int two[1000001];
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int j=0;j<n;j++){            
            cin >> v[j];
        }
        sort(v.begin(),v.end());
        int m;
        cin >> m;
        vector<int> arr(n);
        for(int j=0;j<m;j++){
            cin >> arr[j];
        }
        for(int j=0;j<m;j++){
            int start=0,end=n-1;
            while(1){
                if(start>end){
                    cout << 0 << '\n';
                    break;
                }
                int mid = (start + end)/2;
                if(v[mid] == arr[j]){
                    cout << 1 << '\n';
                    break;
                }
                else if(v[mid] > arr[j]){
                    end = mid-1;
                }else{
                    start = mid + 1;
                }
            }
        }
    }
}