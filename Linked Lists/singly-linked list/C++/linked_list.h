#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Singly_Linked_List{

    private:
        Node* head = NULL;
        int length = 0;
    
    public:
        Singly_Linked_List(){
            cout<<"A singly-linked list is initialized"<<endl;
        }
        ~Singly_Linked_List(){
            cout<<"The singly-linked list is destroyed"<<endl;
        }

        void traverse(){
            if (this->head == NULL){
                cout<<"The singly-linked list has no element"<<endl;
                return;
            }
            cout<<"The singly-linked list's elements: "<<endl;
            Node* temp_head = this->head;
            while(temp_head != NULL){
                cout<<temp_head->data<<" ";
                temp_head = temp_head->next;
            }
            delete temp_head;
            temp_head = NULL;
            cout<<endl;
        }

        void push_back(int data){
            if (this->head == NULL){
                this->head = new Node();
                this->head->data = data;
                this->head->next = NULL;
                this->length++;
                return;
            }
            Node* temp_head = this->head;
            while (temp_head->next != NULL){
                temp_head = temp_head->next;
            }
            temp_head->next = new Node();
            temp_head->next->data=data;
            temp_head->next->next=NULL;
            this->length++;
        }

        void push_head(int data){
            if (this->head == NULL){
                this->head = new Node();
                this->head->data = data;
                this->head->next = NULL;
                this->length++;
                return;
            }
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = this->head;
            this->head = new_node;
            this->length++;
        }

        void insert_at(int data,int position){
            if (position<0 || position>= this->length+1){
                cout<<"Invalid position to insert, please select again !!!";
                return ;
            }

            if (position == 0){
                this->push_head(data);
                return;
            }

            if (position == this->length){
                this->push_back(data);
                return;
            }

            Node* temp_head = this->head;
            int i = 0;
            while(i != position-1){
                temp_head = temp_head->next;
                i++;
            }
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = temp_head->next;
            temp_head->next = new_node;
            this->length++;
        }

        void pop_back(){
            if(this->head == NULL){
                cout<<"There is no element for deleting"<<endl;
                return;
            }
            
            Node* pre_head = new Node();
            Node* temp_head = this->head;
            pre_head->next = temp_head;
            while(temp_head->next != NULL){
                pre_head = temp_head;
                temp_head = temp_head->next;
            }
            delete temp_head;
            temp_head = NULL;
            pre_head->next= NULL;
            this->length--;
        }

        void pop_head(){
            if(this->head == NULL){
                cout<<"There is no element for deleting"<<endl;
                return;
            }
            Node* temp_head = this->head;
            this->head = temp_head->next;
            delete temp_head;
            temp_head = NULL;
            this->length--;

        }

        void pop_at(int position){
            if(position <0 || position>=this->length){
                cout<<"Invalid position, cannot delete anything, please select again !!!"<<endl;
                return ;
            }
            if (this->head == NULL){
                cout<<"There is no element for deleting"<<endl;
                return ;
            }
            if(position ==0){
                this->pop_head();
                return ;
            }
            if(position == this->length-1){
                this->pop_back();
                return ;
            }
            Node *pre_head = new Node();
            Node *temp_head =this->head;
            int i = 0;
            while (i != position){
                pre_head = temp_head;
                temp_head = temp_head->next;
                i++;
            }
            pre_head->next = temp_head->next;
            delete temp_head;
            temp_head = NULL;
            this->length--;
        }

        int get_element_at(int position){
            if(position <0 || position >= this->length){
                cout<<"Invalid position, cannot get any element at here , please select again !!!"<<endl;
                return -1;
            }
            if(this->head == NULL){
                cout<<"There is no element for getting "<<endl;
                return -1;
            }
            int i = 0;
            Node* temp_head = this->head;
            while (i != position){
                i++;
                temp_head = temp_head->next;
            }
            return temp_head->data;
        }

        int get_length(){
            return this->length;
        }
};

#endif