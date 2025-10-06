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

class Compare{
    public:
    
    //priority(b) > priority(a), iff b.val < a.val
    bool operator()(const ListNode* a, const ListNode* b){
        return b-> val < a-> val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        //Add the first element of every list
        for(int i = 0; i < lists.size(); i++){
            ListNode *head = lists[i];
            if(head != NULL){
                pq.emplace(head);
            }
        }
        ListNode *res = NULL, *temp = NULL;
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            //Add element to res
            if(res == NULL){
                res = top;
                temp = res;
            }
            else{
                temp-> next = top;
                temp = temp-> next;
            }

            //Push the next element from that list in pq
            if(top-> next != NULL){
                pq.emplace(top-> next);
            }
        }
        return res;
    }
};
