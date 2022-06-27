#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
int solution(vector<int> food_times, ll k) {
    ll length = food_times.size();
    ll psum, cycle;
    ll left = 0, right = 1e8;
    while(left<=right) {
        ll mid = (left+right)/2;
        ll cnt = 0;
        for(int i=0; i<length; i++) {
            if(food_times[i] - mid < 0) cnt += abs(food_times[i] - mid);
        }
        if(mid*length - cnt <= k) {
            cycle = mid;
            left = mid+1;
        } 
        else right = mid-1;
    }
    psum = cycle * length;
    for(int i=0; i<length; i++) {
        if(food_times[i] - cycle < 0) psum += food_times[i]-cycle;
    }

    for(int i=0; i<length; i++) {
        int next = food_times[i];
        if(next - cycle <= 0) continue;
        if(k == psum) return i+1;
        psum++;
    }
    return -1;
}
