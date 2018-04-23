//  main.cpp
//  link list
//  Created by ardavan on 4/22/18.
//  Copyright © 2018 Apple Inc. All rights reserved.

#include<iostream>
#include<cstdlib>
using namespace std;
class node {
public:
    int data;
    node *link;
};
class list {
public:
    node *head;
    list (){
        head=0;
    }
    void AddToFirst(void){
        node *pn=head;
        head=new node;
        head->link=pn;
        cout<<"Enter your number for add to first : ";
        cin>>head->data;
    }
    void removeFromFirst(void){
        cout<<"-----------------------\n";
        node *pn=head;
        int i;
        for(i=0;pn->link;pn=pn->link,i++);
        if(i==1){
            head=0;
        }
        else{
            head=head->link;
        }
            }
    void AddToEnd(void){//append
        node *pn=head;
        for(;pn->link;pn=pn->link);
        pn->link=new node;
        pn->link->link=0;
        cout<<"Enter your number for add to end : ";
        cin>>pn->link->data;
    }
    void AddToMiddle(int a){//insert
        node *pn=head;
        int i;
        for(i=0;i<a&&pn->link;pn=pn->link,i++);
        if(a==i){
            cout<<"Enter your insert number in part "<<a<<" : ";
            cin>>pn->data;
        }
        else{
            cout<<"There is no such a data!"<<endl;
        }
    }
    void printLinkList (void){
        node *pn;
        pn=head;
        for(int i=0;pn;pn=pn->link,i++){
            cout<<"a["<<i<<"] : "<<pn->data<<endl;
        }
    }
    void removeLinkList(int a){
        node *pn=head,*pv=head->link;
        a=a-1;
        int i;
        for(i=0;i<a&&pv&&pn;pv=pv->link,pn=pn->link,i++);
        if(a==i){
            pn->link=pv->link;
            delete pv;
        }
        else{
            cout<<"There is no such a data!"<<endl;
        }
    }
};
int main () {
    list l1;
    l1.AddToFirst();
    l1.printLinkList();
    l1.AddToEnd();
    l1.printLinkList();
    l1.AddToFirst();
    l1.printLinkList();
    l1.AddToEnd();
    l1.printLinkList();
    l1.AddToEnd();
    l1.printLinkList();
    l1.AddToEnd();
    l1.printLinkList();
    l1.AddToEnd();
    l1.printLinkList();
    int a;
    cout<<"Enter the number of part for insert function :";
    cin>>a;
    l1.AddToMiddle(a);
    l1.printLinkList();
    cout<<"Do you want to REMOVE something? ";
    cin>>a;
    l1.removeLinkList(a);
    l1.printLinkList();
    l1.removeFromFirst();
    l1.printLinkList();
    l1.removeFromFirst();
    l1.printLinkList();
    l1.removeFromFirst();
    l1.printLinkList();
    return 0;
}
