#include <iostream>

using namespace std;

class Element{
public:
    int scor=0;

    Element(int n){
        scor=n;
    };

    Element(){};

};

class Node{
public:
    Element data;
    Node* pri = nullptr;
    Node* next = nullptr;

    Node(Element b){
        data = b;
    };

    Node(){};
};

class mylist{
public:
    Node* head = new Node;

    mylist(){
        head->next = head;
        head->pri = head;
    };

    mylist(Element b){
        Node* p = new Node(b);
        head->next = p;
        head->pri = p;
        p->next = head;
        p->pri = head;
    };

    void mypush_back(Element b){
        Node* p = head;

        //point to last node
        while(p->next!=head){
            p=p->next;
        }

        //push_back node;
        p->next = new Node(b);
        p->next->pri=p;
        p->next->next=head;

        head->pri=p->next;
    }

    void myprt(){
        Node* p = head->next;//point to first node or head

        while(p!=head){
            cout<<p->data.scor<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    void myinsert(int n, Element b){
        Node* p = head;

        //point to n node
        for(int i=0; i<n; i++){
            p=p->next;
        }

        /*
        Node* mynext = p->next;
        p->next = new Node(b);
        p->next->pri=p;
        p->next->next=mynext;
        mynext->pri=p;
        */

        Node* s = new Node(b);
        s->pri = p;
        s->next = p->next;
        p->next->pri=s;
        p->next=s;


    }

    void mydelete(int n){
        Node* p = head;

        //point to n node
        for(int i=0; i<n; i++){
            p=p->next;
        }

        p->pri->next = p->next;
        p->next->pri = p->pri;

        delete p;
    }
};

int main()
{
    mylist a(Element(10));
    a.mypush_back(Element(20));
    a.mypush_back(Element(30));

    a.mydelete(2);

    a.myinsert(1, Element(40));

    a.myprt();

    return 0;
}
