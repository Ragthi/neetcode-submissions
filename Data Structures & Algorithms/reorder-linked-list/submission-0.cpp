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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        int cnt =0;
        ListNode* temp = head;
        while(temp!=nullptr){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0;i<cnt/2;i++){
            st.push(temp);
            temp = temp->next;
        }
        if(cnt&1) temp = temp->next;

        bool phela = true;
        while(!st.empty()){
            ListNode* first = st.top();
            st.pop();
            ListNode* mid = temp;
            temp = temp->next;
            ListNode* last = first->next;
            first->next = mid;
            mid->next = last;
            if(phela) {last->next = nullptr;phela = false;}
        }

    }
};
