#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void printSubsequence(int index, vector<int> &arr2, int arr[], int size){
    if(index >= size){
    	for(auto it: arr2){
    		cout << it << " ";
    	}
    	if(arr2.size() == 0){
    		cout << "{}";
    	}
    	cout<<endl;
    	return;
    }
    arr2.push_back(arr[index]);

    //pick the next element for subsequence
    printSubsequence(index + 1, arr2, arr, 3);
    arr2.pop_back();

    // not pick the next element
    printSubsequence(index + 1, arr2, arr, 3);

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int arr[3] = {3, 1, 2}; 
    int n = 3;

    vector<int> arr2;

    printSubsequence(0, arr2, arr, n);
}