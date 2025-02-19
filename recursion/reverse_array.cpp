#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void reverse(int arr[], int l, int r){
    if(r <= l){
    	return;
    }

    swap(arr[l], arr[r]);

    reverse(arr, l+1, r-1);
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

    int arr[n];

    for (int i = 0; i < n; ++i)
    {
    	cin>>arr[i];
    }

    reverse(arr, 0, n-1);

    for (int i = 0; i < n; ++i)
    {
    	cout<<arr[i]<<" ";
    }
}