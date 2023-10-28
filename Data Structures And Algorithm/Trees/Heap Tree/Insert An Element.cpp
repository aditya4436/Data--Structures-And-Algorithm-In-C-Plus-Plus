#include<iostream>
using namespace std;
void Heapify_An_Array(int heap_array[], int size, int index)
{
    int parent_node=(index-1)/2;
    if(heap_array[parent_node]>0)
    {
        if(heap_array[parent_node]<heap_array[index])
        {
            swap(heap_array[parent_node], heap_array[index]);
            Heapify_An_Array(heap_array, size, parent_node);
        }
    }
}
void Insert_A_Node_In_Heap_Array(int array[], int &size, int data_to_be_inserted)
{
    size=size+1;
    array[size-1]=data_to_be_inserted;
    Heapify_An_Array(array, size, size-1);
}
void Print_Heap_Array(int array[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<"  ";
    }
}
int main()
{
    int array[]={10, 5, 3, 2, 4};
    int size=sizeof(array)/sizeof(array[0]);
    int data_to_be_inserted=15;
    Insert_A_Node_In_Heap_Array(array, size, data_to_be_inserted);
    Print_Heap_Array(array, size);
    return 0;
}
