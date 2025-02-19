#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int fib(int n){
    if(n == 1){
    	return 0;
    }
    else if(n == 2){
    	return 1;
    }

    return fib(n-1) + fib(n-2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;

    cout<<fib(n);
}