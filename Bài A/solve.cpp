#include <bits/stdc++.h>
using namespace std;
#define ll long long
main(){
	int a, b;
    scanf ( "%d%d", &a, &b );
    long long ans = 1;
    for ( long long i = 1; i <= min( a, b ); i++ )
    	ans *= i;
    printf ( "%lld\n", ans );
	
	
}
//@author: Tran Thu Hoai
