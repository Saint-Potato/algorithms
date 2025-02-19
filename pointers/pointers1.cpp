#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

void solution(){
    int a = 8;
    int *p;

    p = &a;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<p+1<<endl;
    cout<<*p<<endl;
    *p = 10;
    cout<<a<<endl;

    cout<<"\n"<<sizeof(int)<<endl;

    int arr[4];

    arr[0] = 1;
    arr[1] = 2;

    int *pa = &arr[0];

    cout<<*pa<<endl;
    cout<<*pa+1<<endl;



    // string s = "hello";
    // p = &s;
    // cout<<*p;


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