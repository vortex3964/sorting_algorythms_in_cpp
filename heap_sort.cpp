#include <iostream>
#include <chrono>

void print_array(int array[],int size){
    int changeline=0;
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<"\t";
        if(changeline==15){
            changeline=0;
            std::cout<<std::endl;
        }
    }
}

void fill_array(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=rand()%100;
    }
}

void swap(int& num1,int& num2){
    int temp;
    temp=num1;
    num1=num2;
    num2=temp;
}

void heapify(int array[],int size,int index){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<size && array[left]>array[largest]){
        largest=left;
    }   

    if(right<size && array[right]>array[largest]){
        largest=right;
    }

    if(largest!=index){
        swap(array[index],array[largest]);
        heapify(array,size,largest);
    }
}

void heap_sort(int array[],int size){
    for(int i=size/2-1;i>=0;i--){
        heapify(array,size,i);
    }

    for(int i=size-1;i>0;i--){
        swap(array[0],array[i]);
        heapify(array,i,0);
    }
}

int main(){
    int size=100000000;
    int*array=new int[size];
    fill_array(array,size);
    //print_array(array,size);
    auto start=std::chrono::high_resolution_clock::now();
    heap_sort(array,size);
    auto end=std::chrono::high_resolution_clock::now();
    auto duration=std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout<<"\n";
    //print_array(array,size);
    std::cout<<"\nprogram ended in "<<duration.count()<<" microseconds\n";
    return 0;
}