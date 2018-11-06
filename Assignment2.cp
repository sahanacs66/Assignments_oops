//
//  main.cpp
//  Assignment2
//
//  Created by sahana cs on 2/8/18.
//  Copyright © 2018 sahana cs. All rights reserved.
//

#include <iostream>
using namespace std;

class node{
    public :
    int value;
    node * next;
    node * previous;
    node() { next = previous = nullptr; }
    node(int k) { value = k; next = previous = nullptr; }
    
};

class linked_list{
    public :
    node * head;
    node * tail;
    linked_list() { head = tail = nullptr; }
    void make_random_list(int k , int m);
    void print_forward();
    void print_reverse();
    void reverse();
    void sort();
    void insert(int k);
    void remove_all(int k);
    
};

void linked_list::make_random_list(int k, int m){
    node *p;
    for(int i=0;i<k;i++){
        p = new node(rand() % m);
        p->next = head;
        if(head == nullptr){
            tail = p;
            head = p;
            
        }
        else{
            head->previous = p;
            head = p;
        }
    }
}

void linked_list::print_forward(){
    node * p = head;
    cout << endl;
    while( p != nullptr){
        cout << p->value << " ";
        p = p->next;
    }
    
}

void linked_list::print_reverse(){
    node * p = tail;
    cout<<endl;
    while (p != nullptr){
        cout << p->value << " ";
        p = p->previous;
    }
}


void linked_list::reverse(){
    
    node *q , *r;
    if(tail != nullptr){
    
    q = tail;
    r = tail->previous;

    while(true){
        
        r = q->previous;
        q->previous = q->next;
        q->next = r;
        
       if(q->next == nullptr)
       {
           node * t = tail;
           tail = head ;
           head = t;
           return;
       }
        q = q->next;
        
    }
    }
    else
        return;
}


void linked_list::sort(){
    
    node * p, * q , *r , *min;
    if(head !=nullptr){
    p = head->next;
    r = head;
    min = head;
    
    if(head->next == nullptr){
        return;
    }
    
    
    while( r != nullptr){
        bool flag = false;
        while(p != nullptr ){
            if(min->value > p->value ){
                min = p;
                p = p->next;
                flag = true;
                
            }
            else
                p = p->next;
            
        }
        
        if(min!= head && flag){
        
        min->previous->next = min->next;
        
        if(min->next != nullptr)
        min->next->previous = min->previous;
        else
            tail = min->previous;
        
        min ->next = r;
        min ->previous = r->previous;
        
        if(r->previous != nullptr)
            r->previous->next = min;
        
        r->previous = min;
        
        if(r == head)
        head = min;
    }
        
        r = min->next;
        
        if(r == tail)
            return;
            
        min = r;
        p = r->next;
        
    }
    }
    else
        return;
    
}



void linked_list::insert(int k){
    
    node * add = new node(k);
    node * p = head ;
    
    
    while(p != nullptr){
        
            if(p->value >= add->value){
            
                if(p == head){
                    add->next = head;
                    add ->previous = head->previous;
                    head->previous = add;
                    head = add;
                    return;
                }
            p->previous->next = add;
            add->next = p;
            add->previous = p->previous;
            p->previous = add;
            return;
            
        }
        
        if(p->next!=nullptr)
        p = p->next;
        else{
            
            add->next = p->next;
            p->next = add;
            add->previous = p;
            tail = add;
            return;
            
        }
        
    }
    if( p == nullptr){
        head = add;
        tail = add;
        return;
        
    }
}


void linked_list::remove_all(int k){
    
    node * p = head;
    
    while( p != nullptr)
    {
        if(p->value == k && p == head){
            
            head = p->next;
            delete head->previous;
            head->previous = nullptr;
        }
        else if(p->value == k && p !=head && p != tail){
            p->previous->next = p->next;
            p->next->previous = p->previous;
            
        }
        else if(p->value == k && p == tail){
            tail = p->previous;
            delete tail->next;
            tail->next = nullptr;
            
            
        }
        
        p = p->next;
        
    }
}



int main(){
    linked_list L1;
    L1.make_random_list(60, 15);
    L1.print_forward();
    L1.print_reverse();
    L1.reverse();
    L1.print_forward();
    L1.print_reverse();
    L1.remove_all(11);
    L1.print_forward();
    L1.print_reverse();
    L1.sort();
    L1.print_forward();
    L1.print_reverse();
    L1.insert(0);
    L1.insert(10);
    L1.insert(16);
    L1.print_forward();
    L1.print_reverse();
    getchar();
    getchar();
    return 0;
    
    
    
}























