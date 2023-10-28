#include<iostream>
using namespace std;
void Tower_Of_Hanoi(int n, char source, char destination, char auxiliary)
{
    if(n>0)
    {
        Tower_Of_Hanoi(n-1, source, auxiliary, destination);
        cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
        Tower_Of_Hanoi(n-1, auxiliary, destination, source);
    }
}
int main()
{
    int n;
    cout<<"Enter the number of disks:\n";
    cin>>n;
    cout<<"Tower Of Hanoi for "<<n<<" Disk:\n";
    Tower_Of_Hanoi(n, 'A', 'C', 'B');
    return 0;
}
