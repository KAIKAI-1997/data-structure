#include <iostream>

using namespace std;


class element{
private:
    int cont=0;

public:
    int getcont(){
        return cont;
    }

    void setcont(int n){
        cont=n;
    }
};

class Myarray{
private:
    element* PElem=nullptr;//动态分配，这样没有分配内存，只分配了起始点，需要new内存
    //element PElem[100];//静态分配
    int length=0;

public:
    Myarray(int n){
        PElem = new element[n];//一共有多少个元素
        length = n;
    }

    Myarray(){
        PElem = new element[100];
        length = 100;
    }

    ~Myarray(){
        delete[] PElem;
    }

    void Clear(){
        length=0;
    }

    int GetLength(){
        return length;
    }

    int IsEmpty(){
        if(length == 0) return 1;
        else return 0;
    }

    element get(int x){
        if(x>length) exit (-1);
        return *(PElem+x-1);
    }

    void setval(int x, int n){
        if(x>length) exit (-1);
        (PElem+x-1)->setcont(n);

    }

    int Find(int b){
        for(int i=0;i<length;i++){
            if((PElem+i)->getcont() == b) return i+1;
        }
        return 0;
    }

    //last element will disappear
    void Insert(int x, int n){
        if(x>=length) exit (-1);
        else if(x<length){


        }
    }

    void Delete(int x){
        if(x>=length || x<1) exit(-1);
        for(int i=x;i<length;i++){
            (PElem+i-1)->setcont((PElem+i)->getcont());
        }
    }

};

int main(){
    Myarray a(100);
    a.setval(10,100);
    a.setval(5,10);
    a.Delete(5);
    cout<<a.get(5).getcont()<<endl;
    cout<<a.get(10).getcont()<<endl;
        cout<<a.get(9).getcont()<<endl;
    cout<<a.Find(100);

    return 0;

}


