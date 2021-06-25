#include<iostream>
#include "linked_list.h"
using namespace std;

int main(){
    Singly_Linked_List sll;
    for(int i = 1 ; i<10;i++){
        sll.push_back(i);
    }
    sll.push_head(0);
    sll.push_head(0);
    sll.insert_at(100,1);
    sll.insert_at(50,11);
    sll.insert_at(200,13);
    sll.pop_back();
    sll.pop_at(3);
    sll.pop_head();
    sll.traverse();
    cout<<"Element at index 5 : "<<sll.get_element_at(5)<<endl;
    cout<<"Element at index 0 : "<<sll.get_element_at(0)<<endl;
}