#ifndef __SORT_H__
#define __SORT_H__

#include<iostream>
#include<time.h>
#include "config.h"

using namespace std;

class Sort{
    
    private:
        double runtime=0;
        bool isSorted=false;

    protected:
        int arr[NUM];

    public:
        void readArray(int arr[NUM]){
            copy(arr,arr+NUM,this->arr);
        }

        void showArray(){
            for(int i=0;i<NUM;i++){
                if(i==NUM-1){
                    cout<<this->arr[i];
                }
                if(this->arr[i]>this->arr[i+1]){
                    cout<<this->arr[i]<<" ";
                    this->isSorted=false;
                }
            }
            cout<<endl;
            this->isSorted=true;
        }

        void swap(int *p1, int *p2){
            int temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }
        
        void sort(){
            clock_t start,end;
            start = clock();
            implement();
            end = clock();
            this->runtime = double(end-start)/double(CLOCKS_PER_SEC);
        }

        double getRuntime(){
            return this->runtime;
        }

        void showRuntime(){
            cout<<"Runtime : "<<this->runtime<<endl;
            if (this->isSorted){cout<<"Array has been sorted !!!"<<endl;}
            else cout<<"Array has not been sorted , let's check again !!!"<<endl;
        }

        virtual void implement()=0; // implement each sorting type (children class will implement this)
    
};

class SelectionSort: public Sort{

    public:
        SelectionSort(){
            cout<<"SelectionSort:"<<endl;
        }
        
        ~SelectionSort(){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }
        
        void implement() override{
            /* implement selection sort */
            for(int i=0;i<NUM;i++){
                for(int j=i+1;j<NUM;j++){
                    if (this->arr[i] > this->arr[j]){
                        swap(&this->arr[i],&this->arr[j]);
                    }
                }
            }

        }
};

class BubbleSort: public Sort{

    public:
        BubbleSort(){
            cout<<"BubbleSort:";
        }

        ~BubbleSort(){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }

        void implement(){
            /* implement bubble sort */
            
        }
};

class InsertionSort: public Sort{

    public:
        InsertionSort(){
            cout<<"InsertionSort:";
        }

        ~InsertionSort(){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }
};

#endif