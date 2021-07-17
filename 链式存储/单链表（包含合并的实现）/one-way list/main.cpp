#include <iostream>

using namespace std;

class element{
public:
    int scor=0;

    element(int a){
        scor=a;
    }

    element(){};

    //const means cannot change element here
    bool operator==(const element b){
        return(b.scor==scor);
    }

    bool operator>(const element b){
        return(scor>b.scor);
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

class mylist{
public:
    node* head = new node;
    //head node, store some information with the list

    int Isempty(){
        if(!head->next)return 1;
        else return 0;
    }

    //destroy every node without head node
    void empty(){
        node* e, *d;
        e = head->next;
        while(e){
            d = e;
            e = e->next;
            delete d;
        }
        //head's next need be null;
        head->next = nullptr;
    }

    //destroy the list include head node
    void destroy(){
        while(head){
            node* b=head;
            head=head->next;
            delete b;
        }
    }

    void push_back(element b){
        node* p = head->next;
        node* pri=head;
        while(p){
            pri = p;
            p=p->next;
        }

        pri->next = new node(b);
    }

    int count(){
        node* c=head->next;
        int cou=0;
        while(c){
            cou++;
            c=c->next;
        }
        return cou;

    }

    void prt(){
        node* p = head->next;
        while(p){
            cout<<p->data.scor<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    element get(int n){
        node* p=head->next;

        if(n<=0) exit(-1);

        for(int i=1;i<n;i++){
            p = p->next;
            if(!p) exit(-1);
        }

        return p->data;
    }

    int mysearch(element b){
        node* p=head->next;
        int coun = 1;

        while(p){
            if(p->data==b) return coun;
            p=p->next;
        }

        return 0;
    }

    void myinsert(int n, element b){
        node* p = head;//point to i node

        for(int i=0;i<n;i++){
            p=p->next;
        }

        node* s = new node(b);

        s->next = p->next;
        p->next=s;
    }

    void mydelete(int n){
        node* p = head;//point to i-1 node

        for(int i=1;i<n;i++){//与上面不一样，上面在node后插入，这里需要指向node前
            p=p->next;
        }

        node* inode=p->next;
        p->next=p->next->next;
        delete inode;
    }
};

mylist myunion(mylist a, mylist b){
    for(int i=0; i<b.count(); i++){
        element x = b.get(i+1);
        if(a.mysearch(x)) continue;
        else a.push_back(x);
    }

    return a;
}

mylist sequence_merge(mylist a, mylist b){
    mylist c;
    node* p = c.head;
    node* pa = a.head->next;
    node* pb = b.head->next;

    while(pa&&pb){
        if(pa->data > pb->data) {
            p->next=pb;
            pb=pb->next;
            p=p->next;
        }
        else{
            p->next=pa;
            pa=pa->next;
            p=p->next;
        }
    }

    if(pa) p->next=pa;//if(pa) means some other node after pa
    else if(pb) p->next=pb;

    return c;
}


int main()
{
    mylist a,b,c,d;
    a=b;

    a.push_back(element(10));
    a.push_back(element(20));
    a.push_back(element(25));
    a.prt();

    b.push_back(element(15));
    b.push_back(element(30));
    b.push_back(element(30));
    b.prt();


    d=sequence_merge(a,b);
    //c=myunion(a,b);

    c.prt();
    d.prt();


    return 0;
}
