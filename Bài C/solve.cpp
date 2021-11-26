#include<bits/stdc++.h>
using namespace std;
#define fasten() ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
#define ll long long

int sell_stock(int arr[], int n){
    int maxProfit = 0;
    for(int i = 1; i < n; i++) 
        maxProfit += max(arr[i] - arr[i-1], 0);
    return maxProfit;
}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int interest = sell_stock(arr, n);
    if(interest > 0) cout << interest << endl;
    else cout << "Khong dau tu duoc roi!" << endl;
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
