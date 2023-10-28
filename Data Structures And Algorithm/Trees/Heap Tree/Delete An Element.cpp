#include<iostream>
using namespace std;
void Heapify_An_Array(int heap_array[], int size, int index)
{
    int largest_element=index;
    int left_child=(2*index)+1;
    int right_child=(2*index)+2;
    if(left_child<size && heap_array[left_child]>heap_array[largest_element])
    {
        largest_element=left_child;
    }
    if(right_child<size && heap_array[right_child]>heap_array[largest_element])
    {
        largest_element=right_child;
    }
    if(largest_element!=index)
    {
        swap(heap_array[index], heap_array[largest_element]);
        Heapify_An_Array(heap_array, size, largest_element);
    }
}
void Delete_An_Element_From_Heap_Array(int array[], int &size)
{
    int last_element=array[size-1];
    array[0]=last_element;
    size=size-1;
    Heapify_An_Array(array, size, 0);
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
    int n=sizeof(array)/sizeof(array[0]);
    Delete_An_Element_From_Heap_Array(array, n);
    Print_Heap_Array(array, n);
    return 0;
}
