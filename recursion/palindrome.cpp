#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

bool solution(string s, int l, int r){
    if(l >= r){
    	return true;
    }
    else if(s[l] != s[r]){
    	return false;
    }

    return solution(s, l+1, r-1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin>>s;

    cout<<solution(s, 0, s.length() - 1);
}