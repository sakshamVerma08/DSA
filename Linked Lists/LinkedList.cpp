#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }


};


int main(){

    Node * node = new Node(1);
    cout << node->data;
    return 0;
}