#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(){
    }
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};


LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    LinkedListNode<int> *start=new LinkedListNode<int>(100);
    //cout<<"check1"<<endl;
    start->next = head;
    //cout<<"check2"<<start->next->data<<endl;
    LinkedListNode<int> *temp= start, *kthnode=start;


    for(int i=1;i<=K;i++) temp=temp->next;

    while(temp->next != NULL){
        temp = temp->next;
        kthnode = kthnode->next;
    }

    kthnode->next = kthnode->next->next;

    return start->next;
}
int main(){
    vector<int> v{1,2,5,7,9};
    LinkedListNode<int> *head =NULL;
    for(auto i:v){
        LinkedListNode<int> *n = new LinkedListNode<int>(i);
        if(!head){
            head = n;
            continue;
        }
        n->next = head;
        head = n;
    }
    LinkedListNode<int> *temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp  = temp->next;
    }
    cout<<endl;
    temp = removeKthNode(head,3);
    if(!temp){
        cout<<"empty";
    }
    while(temp){
        cout<<temp->data<<"->";
        temp  = temp->next;
    }
    return 0;
}
