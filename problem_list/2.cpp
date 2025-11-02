#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {

    }
    ListNode(int x) : val(x), next(nullptr) {

    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
        
    }
};

ListNode* build(vector<int> v){
    ListNode *h = new ListNode();
    ListNode *t = h;
    for( int i = 0; i < v.size(); i++){
        ListNode *novo = new ListNode(v[i]);
        t->next = novo;
        t = novo;
    }
    return h;
}

void imprimir(ListNode* h){
    while(h != nullptr){
        cout << h->val << endl;
        h = h->next;
    }
}
 
class Solution {
public:
    vector<int> final;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tam_l1 = 0, tam_l2 = 0;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* aux = h1;
        while(aux != nullptr){
            tam_l1++;
            aux = aux->next;
        }
        aux = h2;
        while (aux != nullptr){
            tam_l2++;
            aux = aux->next;
        }

        if(tam_l1 < tam_l2){
            swap(h1, h2);
            swap(tam_l1, tam_l2);
        }
        aux = h2;
        while(aux->next != nullptr) aux = aux->next;
        while(tam_l2 != tam_l1){
            ListNode *novo = new ListNode();
            novo->val = 0;
            aux->next = novo;
            aux = aux->next;
            tam_l2++;
        }
        
        final.resize(tam_l1+1);
        for(int i = 0; i < tam_l1; i++){
            int val = h1->val + h2->val;
            int p = 0, d = 0;
            val+=final[i];
            p = val/10;
            d = val % 10;
            final[i] = d;
            final[i+1] += p;
            h1 = h1->next;
            h2 = h2->next;
        }
        while(final.size()>=2 and final.back()==0) final.pop_back();
        ListNode* m = build(final);
        m = m->next;
        return m;
    }
};



int main(){
    Solution s;
    vector<int>valores_1 = {0};
    vector<int>valores_2 = {0};
    ListNode* hd = build(valores_1);
    ListNode* o = build(valores_2);
    hd = hd->next;
    o = o->next;
    ListNode* r;
    
    r = s.addTwoNumbers(hd, o);
    imprimir(r);
    return 0;
}