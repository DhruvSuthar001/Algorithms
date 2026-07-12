#include<iostream>
using namespace std;

void bubble_sort(int A[],int n)
{
    int i,j,temp;

    for(i = 0;i < n - 1;i++)
    {
        for(j = 0;j < n- i;j++)
        {
            if( A[ j ] > A[ j + 1 ] )
            {
                temp = A[ j ];
                A[ j ] = A[ j + 1 ];
                A[ j + 1 ] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {2,5,8,9,4,1};
    int n = sizeof( A ) / sizeof ( A [ 0 ] );

    bubble_sort(A,n);

    cout<<"Sorted array"<<endl;
    
    for(int i = 0 ; i < n; i++)
    {
        cout<<A[ i ] << " ";
    }
    return 0;
}