#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class ListNode{


public:

	int val;
	ListNode* next;


	ListNode(int val){
		this->val = val;
		next = nullptr;

	}


	ListNode(int val, ListNode* next){

		this->val = val;
		this->next = next;

	}

};


ListNode* mergeLL(ListNode* l1, ListNode *l2){


	ListNode* t1 = l1, *t2 = l2;
	ListNode* dummy = new ListNode(-10000-1);
	ListNode* tail = dummy;

	while(t1 && t2){
		
		if(t1->val <= t2->val){
			tail->next = t1;
			t1 = t1->next;
			tail = tail->next;

		}

		else{
			tail->next = t2;
			t2 = t2->next;
			tail = tail->next;
		}
	
	}



	if(!t2){
		
	while(t1){
		tail->next = t1;
		t1 = t1->next;
		tail = tail->next;
	}


	}


	if(!t1){


		while(t2){
			tail->next = t2;
			t2 = t2->next;
			tail = tail->next;
		}

	}



	return dummy->next;

}

ListNode* mergeKLists(vector<ListNode*> &lists){

	ListNode* newHead = lists[0];

	for(int i = 1; i < lists.size(); i++){

		newHead = mergeLL(newHead,lists[i]);
	}	


	return newHead;

}



int main(){

    // List 1: 1 -> 4 -> 7
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);

    // List 2: 2 -> 5 -> 8
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(8);

    // List 3: 3 -> 6 -> 9
    ListNode* l3 = new ListNode(3);
    l3->next = new ListNode(6);
    l3->next->next = new ListNode(9);

    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* result = mergeKLists(lists);

    // Print result
    while(result){
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}


