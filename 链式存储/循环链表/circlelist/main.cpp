#include <iostream>

using namespace std;

class element{
public:
    int scor = 0;

    element(int n){
        scor = n;
    }

    element(){};

    bool operator==(element b){
        return(b.scor==scor);
    }
};

class node{
public:
    element data;
    node* next=nullptr;

    node(element b){
        data=b;
    }

    node(){};
};

class mylooplist{
public:
    node* tail;

    mylooplist(){
        tail = new node;
        tail->next = tail;
    }

    bool IsEmpty(){
        if(tail->next==tail) return true;
        else return false;
    }

    void mypush_back(element b){
        node* head = tail->next;
        tail->next = new node(b);
        tail = tail->next;
        tail->next = head;
    }

    void myempty(){
        node* p=tail->next->next;//point to first node

        while(p!=tail){
            node* b=p;
            p=p->next;
            delete b;
        }

        tail=tail->next;
        tail->next=tail;
        delete p;
    }

    int mycount(){
        node* p=tail->next;//point to head
        int cout=0;

        while(p!=tail){
            p = p->next;
            cout++;
        }

        return cout;
    }

    void myprt(){
        node* p = tail->next;//point to head

        while(p!=tail){
            p=p->next;
            cout<<p->data.scor<<" ";
        }
        cout<<endl;
    }

    int mysearch(element b){
        node* p=tail->next;//point to head
        int num=0;

        do{
            num++;
            p = p->next;//first node then go on
            if(p->data==b) return num;
        }while(p!=tail);

        return 0;

    }

    //insert after specific node
    void myinsert(int n, element b){
        node* p=tail->next;//point to head

        //point to n node
        for(int i=0; i<n; i++){
            p=p->next;
        }

        node* mynext=p->next;
        p->next = new node(b);

        p->next->next = mynext;

    }

    void mydelete(int n){
        node* p=tail->next;//point to head

        //point to n-1 node
        for(int i=0; i<n-1; i++){
            p=p->next;
        }

        node* mynext = p->next->next;

        delete p->next;

        p->next = mynext;

    }

};

int main()
{
    mylooplist a,b;

    a.mypush_back(element(10));
    a.mypush_back(element(100));
    a.mypush_back(element(999));

    //a.myempty();

    cout<<a.mycount()<<endl;
    cout<<a.mysearch(element(99))<<endl;

    a.myinsert(1,element(50));
    a.mydelete(2);

    a.myprt();


    return 0;
}
