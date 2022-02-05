#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0, l = 1, r = 1e9;
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    while(l <= r) {
        int mid = (l+r)/2;
        vector<int> v;
        v.push_back(0);
        for(int rock : rocks) {
            if(rock - v.back() >= mid) {
                v.push_back(rock);
            }
        }        
        if(v.size()-1 >= rocks.size()-n) {
            answer = mid;
            l = mid+1;
        }
        else r = mid-1;
    }    
    return answer;
}