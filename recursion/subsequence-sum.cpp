#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solution(int index, int arr[], vector<int> arr2, int sum, int n, int k){
    if(index >= n){
    	if(sum == k){
    		for(auto it: arr2){
    			cout<<it<<" ";
    		}
    		cout<<endl;

    	}
    	return;
    }

    arr2.push_back(arr[index]);
    sum+= arr[index];

    solution(index+1, arr, arr2, sum, n, k);

    arr2.pop_back();
    sum-= arr[index];
	solution(index+1, arr, arr2, sum, n, k);

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int arr[3] = {1,2,1};
    int n = 3;
    int k = 2;
    int sum = 0;
    vector<int> arr2;

    solution(0, arr, arr2, sum, n,k);

}