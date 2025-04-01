#include <iostream>
using namespace std;
#define endl '\n'
#define int long long

class Node{
	public:
	int data;
	Node* next;

	public:
	Node(int data1, Node* next1){
		data = data1;
		next = next1;
	}

	Node(int data1){
		data = data1;
		next = nullptr;
	}
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* y = new Node(2);
    cout << y -> data;
    
}