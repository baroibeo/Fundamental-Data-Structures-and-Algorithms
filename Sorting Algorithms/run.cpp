#include<iostream>
#include<string>
#include<fstream>
#include "config.h"
#include "sort.h"

using namespace std;

void sort(Sort *sort_type,int arr[NUM]){
    sort_type->readArray(arr);
    sort_type->sort();
    sort_type->showArray();
    sort_type->showRuntime();
}

int main(){
    freopen("data.txt","r",stdin);

    //Read data from file and assign it to an array
    int arr[NUM];
    for(int i =0 ;i<NUM;i++){
        cin>>arr[i];
    }

    SelectionSort selection_sort;
    sort(&selection_sort,arr);

    BubbleSort bubble_sort;
    sort(&bubble_sort,arr);

    InsertionSort insertion_sort;
    sort(&insertion_sort,arr);

    MergeSort merge_sort;
    sort(&merge_sort,arr);

}