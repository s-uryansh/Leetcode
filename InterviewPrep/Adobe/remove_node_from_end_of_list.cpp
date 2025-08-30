#include<iostream>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        ListNode dHead = ListNode(-1,head);
        ListNode* fastPtr = &dHead;
        ListNode* slowPtr = &dHead;
        int k = 1;
        int i = 0;
        while(i <= k+1){
            fastPtr = fastPtr->next;
            i++;
        }
        while(fastPtr != NULL){
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;;
        }
        ListNode* delNode = slowPtr->next;
        slowPtr->next = delNode->next;
        delete delNode;

        return dHead.next;    
    }
};
int main(){

}