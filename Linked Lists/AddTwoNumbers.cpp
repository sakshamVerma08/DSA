#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to convert an array to a linked list
Node* arrayToLinkedList(const int arr[], int size) {
    if (size == 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < size; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}



Node *addTwoNumbers(Node *num1, Node *num2)
{

    Node*t1= num1;
    Node*t2=num2;
    Node*dummyNode=new Node(-1);
    Node*curr=dummyNode;
    int carry=0;
    int sum;

    while (t1!=nullptr || t2!=nullptr){
        sum = carry;
        if(t1)
        sum+= t1->data;

        if(t2)
        sum+= t2->data;

        Node*node = new Node(sum%10);
        carry=sum/10;

        curr->next=node;
        curr=curr->next;

        if(t1)
        t1=t1->next;

        if(t2)
        t2=t2->next;

    }

    if(carry){
        Node*node=new Node(carry);
        curr->next=node;
        
    }

    return dummyNode->next;
    
}


int main(){
    int arr1[] = {5,3};
    int arr2[] = {9,7};

    Node*n1=arrayToLinkedList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    Node*n2= arrayToLinkedList(arr2, sizeof(arr2)/sizeof(arr2[0]));

    Node*ans= addTwoNumbers(n1,n2);
    printLinkedList(ans);
    return 0;
}