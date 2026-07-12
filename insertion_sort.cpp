#include<iostream>
using namespace std;

void insertion_sort(int A[],int n)
{
    int i,j,key;

    for( i = 1 ; i < n ; i++)
    {
        key=A[i];
        j = i-1;
    
        while( j >= 0 && A[j] > key ) 
        {
            A[ j + 1 ] = A[ j ]; //element at j is shifted to right 
            j -= 1; //moving j to the left closer to the key[i] value 
        }
            A[ j + 1] = key; //the key value is at the position one left to the j value 
    }
}
int main()
{
    int A[]={2,5,8,9,4,1};
    int n =sizeof(A) / sizeof(A[ 0 ] );

    insertion_sort(A,n);
    cout<<"Sorted array"<<endl;

    for(int i = 0 ;i < n ; i++ )
    {
        cout<<A[i]<<" ";
    }
    return 0;

}