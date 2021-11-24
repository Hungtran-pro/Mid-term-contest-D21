#include<bits/stdc++.h>
using namespace std;
#define fasten() ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
#define ll long long

int route_min(int arr[], int n){
    if(n == 1) return 0;
    else{
        int value_route[n] = {0};
        value_route[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            value_route[i] = n;
            for(int j = 1; j <= arr[i] && i + j < n; j++){
                if(value_route[j + i] + 1 < value_route[i]){
                    value_route[i] = value_route[i + j] + 1;
                }
            }
        }
        return value_route[0];
    }
}

int BA(int nums[], int n, int target){
    if(n == 0) {
        return -1;
    }
    for(int i = 0; i < n; i++){
        if(nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int BS(int nums[], int n, int target){
    if(n == 0) {
        return -1;
    }
    int low = 0, high = n - 1;
    int first = nums[0];
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int value = nums[mid];
        if(value == target) {
            return mid;
        }
        bool am_big = value >= first;
        bool target_big = target >= first;
        if(am_big == target_big) {
            if(value < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        else {
            if(am_big) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

void solve(){
    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << route_min(arr, n) << endl;
}

int main(){
    fasten();
    int test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}
//Cactus <3
