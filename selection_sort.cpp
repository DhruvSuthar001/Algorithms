#include<iostream>
using namespace std;

// main algorithm for selection sort ...
void selection_sort(int A[],int n )
{
    int i ,j,min,temp;

    for( i = 0 ; i <= n - 1 ; i++ )
    {
        min = i;
        for(j = i + 1 ; j < n ; j++ )
        {
            if(A[ j ] < A[ min ] )
            {
                min  = j;
            }
        }
        temp = A[ i ];
        A[ i ] = A[ min ];
        A[ min ] = temp;
    }
}
int main()
{
    int A[] = {2,5,8,9,4,1}; //each element stores 4 byes of memory do total is 24 bytes how??= 6 elements so 6*4=24.
    int n = sizeof( A ) / sizeof(A[ 0 ] );//comparing the size of array to the first element of the index value gives the total number of elements.

    selection_sort( A , n );

    cout<<"Sorted array :"<<endl;

    for(int i = 0; i < n ; i++ )
    {
        cout<< A[ i ]<<endl;
    }
    return 0;

}