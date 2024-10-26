#include <iostream>
#include <chrono>

void selection_sort(int array[],int size,int start){
    if(size==start) return;

    int min=array[start];
    
    int m_index=start;

    for(int i=start;i<size;i++){
        if(array[i]<min){
          min=array[i];
          m_index=i;
        }
    }
    
    array[m_index]=array[start];
    array[start]=min;
    selection_sort(array,size,start+1);
}

void fill_array(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=rand()%100;
    }
}

void print_array(int array[],int size){
    int change_line=0;
    std::cout<<"\nthe array is:";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
        change_line++;
        if(change_line==15){
            change_line=0;
            std::cout<<"\n"<<"~";
        }
    }
}

int main(){
    int size=100000;
    int array[size];
    fill_array(array,size);
    print_array(array,size);
    auto start=std::chrono::high_resolution_clock::now();
    selection_sort(array,size,0);
    auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    print_array(array,size);
    std::cout<<"\nprogram took "<<duration.count()<<" microseconds to finish"<<std::endl;
    return 0;
}