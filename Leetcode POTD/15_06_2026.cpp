#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
Solution(){

}
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp=temp->next;
        }
        
        if(n==1)
            return nullptr;
            
        temp=head;

        int mid_idx = n/2;

        int i = 0;
        while(temp && i < mid_idx-1){
            i++;
            temp=temp->next;
        }

        

        ListNode* forward = temp->next->next;
        ListNode* del = temp->next;
        del->next=nullptr;
        temp->next=forward;
        delete del;
        return head;

    }
};

int main(){


}