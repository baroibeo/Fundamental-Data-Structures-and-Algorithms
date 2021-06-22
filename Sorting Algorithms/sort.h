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
                    break;
                }
                if(this->arr[i]>this->arr[i+1]){
                    this->isSorted=false;
                    return;
                }
                else{
                    cout<<this->arr[i]<<" ";
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
            cout<<"BubbleSort:"<<endl;
        }

        ~BubbleSort(){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }

        void implement(){
            for(int i = 0 ;i<NUM;i++){
                for(int j=NUM-1;j>i;j--){
                    if (this->arr[j]<this->arr[j-1]){
                        swap(&this->arr[j],&this->arr[j-1]);
                    }

                }
            }
            
        }
};

class InsertionSort: public Sort{

    public:
        InsertionSort(){
            cout<<"InsertionSort:"<<endl;
        }

        ~InsertionSort(){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }

        void implement(){
            for(int i =1 ; i<NUM;i++){
                int temp=this->arr[i];
                while(i>0 && temp<this->arr[i-1]){
                    this->arr[i]=this->arr[i-1];
                    i--;
                }
                this->arr[i]=temp;
            }
        }
};

class MergeSort: public Sort{

    public:
        MergeSort(){
            cout<<"MergeSort:"<<endl;
        }
        ~MergeSort(){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }

        void implement(){
            mergeSort(0,NUM-1);
        }

        //Partition array 
        void mergeSort(int left,int right){
            if(left < right){
                int mid = left + (right-left)/2;
                mergeSort(left,mid); //Mergesort left sub array
                mergeSort(mid+1,right); // Mergesort right sub array
                this->merge(left,mid,right); //Combine
            }
        }

        //Combination left and right array
        void merge(int left,int mid,int right){
            int numLeft = mid-left+1; //number of number of left sub array
            int numRight = right-mid; //number of number of right sub array
            int arrLeft[numLeft]; //temp array to store left sub array's elements
            int arrRight[numRight]; // temp array to store right sub array's elements

            //Copy
            for (int i=0;i<numLeft;i++){
                arrLeft[i] = this->arr[left+i];
            }
            for(int i=0;i<numRight;i++){
                arrRight[i] = this->arr[mid+1+i];
            }

            int i = 0, j=0;
            int k = left;
            
            while (i<numLeft && j<numRight){
                if (arrLeft[i] < arrRight[j]){
                    this->arr[k]=arrLeft[i];
                    k++;
                    i++;
                }
                else{
                    this->arr[k] = arrRight[j];
                    k++;
                    j++;
                }
            }

            //Add rest elements in left / right sub array to the main array
            while (i<numLeft){
                this->arr[k]=arrLeft[i];
                i++;
                k++;
            }
            while (j<numRight){
                this->arr[k]=arrRight[j];
                k++;
                j++;
            }
        }
};

class QuickSort: public Sort{

    public:
        QuickSort(){
            cout<<"QuickSort:"<<endl;
        }
        ~QuickSort(){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }

        void implement(){

        }

};

class HeapSort: public Sort{

    public:
        HeapSort(){
            cout<<"HeapSort:"<<endl;
        }
        ~HeapSort(){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }
};

class CountingSort: public Sort{
    public:
        CountingSort(){
            cout<<"CoutingSort:"<<endl;
        }
        ~CountingSort(){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }

        void implement(){

        }
};

#endif