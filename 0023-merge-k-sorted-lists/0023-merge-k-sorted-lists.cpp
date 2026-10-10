/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
    if(!l2) return l1;
    if(!l1) return l2;
    if(l1->val<=l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
    return NULL;
}
ListNode* partitionAndMerge(int start,int end,vector<ListNode*> &lists){
    if(start>end) return NULL;
    if(start==end) return lists[start];
    int mid = start+(end-start)/2;
    ListNode* l1 = partitionAndMerge(start,mid,lists);
    ListNode* l2 = partitionAndMerge(mid+1,end,lists);
    return mergeTwoLists(l1,l2);
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // vector<int>arr;
        // for(int i=0;i<lists.size();i++){
        //     ListNode* temp = lists[i];
        //     while(temp !=NULL){
        //         arr.push_back(temp->val);
        //         temp=temp->next;
        //     }
        // }
        // sort(arr.begin(),arr.end());
        // if(arr.empty()) return NULL;
        // ListNode* head = new ListNode(arr[0]);
        // ListNode* ans = head;
        // for(int i=1;i<arr.size();i++){
        //     ListNode* temp = new ListNode(arr[i]);
        //     head->next = temp;
        //     head = head->next;
        // }
        // return ans;


        int k = lists.size();
        if(k==0) return NULL;
        return partitionAndMerge(0,k-1,lists);
    }
};