#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solution(){
	int x = 20;
    if(x & 1){
    	cout << "odd";
    }
    else {
    	cout << "even";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solution();
}