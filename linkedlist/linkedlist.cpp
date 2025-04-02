#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
// #define int long long

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) : data(data1), next(next1) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor - Frees memory
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Convert array to LinkedList
    void fromArray(const vector<int>& arr) {
        if (arr.empty()) return;
        
        head = new Node(arr[0]);
        Node* mover = head;

        for (size_t i = 1; i < arr.size(); i++) {
            mover->next = new Node(arr[i]);
            mover = mover->next;
        }
    }

    // Print the LinkedList
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Delete head node
    void deleteHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete tail node
    void deleteTail() {
        if (!head || !head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* mover = head;
        while (mover->next->next != nullptr) {
            mover = mover->next;
        }

        delete mover->next;
        mover->next = nullptr;
    }

    void deleteK(int k){
    	if(head == nullptr) return;

    	if(k == 1){
    		Node* temp = head;
    		head = head -> next;
    		delete temp;
    		return;
    	}
    	else{
    		Node* temp = head;
    		for(int i = 0; i < k - 1; i++){
    			temp = temp -> next;
    		}

    		Node* r = temp -> next;
    		temp -> next = r -> next;
    		delete r;
    	}

    }

    int find(int k){
    	int res = -1;
    	Node* temp = head;
    	int i = 0;
    	while(temp != nullptr){
    		if(temp -> data == k){
    			res = i;
    			break;
    		}
    		i++;
    		temp = temp -> next;
    	}

    	return res;
    }

    void insert(int k, int val){
    	
    	if(k == 0){
    		Node* temp = new Node(val, head);
    		head = temp;
    		return;
    	}
    	Node* mover = head;
    	for(int i = 1; i < k ; i++){
    		mover = mover-> next;
    	}

    	Node* temp = new Node(val, mover -> next);
    	mover -> next = temp;
    }
};

// Main function
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> arr = {2, 5, 6, 3, 5, 7, 5};
    
    // Create linked list
    LinkedList ll;
    ll.fromArray(arr);

    // Print initial linked list
    cout << "Linked List: ";
    ll.print();

    // Delete head and print
    ll.deleteHead();
    cout << "After deleting head: ";
    ll.print();

    // Delete tail and print
    ll.deleteTail();
    cout << "After deleting tail: ";
    ll.print();

    ll.deleteK(3);
    cout << "After deleting 3rd node: ";
    ll.print();

    cout << "Index of Node with value 3: " << ll.find(3) << endl;

    ll.insert(0, 9);
    cout << "After inserting 9 at 0th: ";
    ll.print();

    return 0;
}