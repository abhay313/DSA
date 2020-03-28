/*Insertion Sort Using C++ */
 
#include <stdio.h>
#include<iostream>
using namespace std;

#define MAX 1000
 
int main()
{
    int arr[MAX],limit;
    int i,j,temp;
     
    printf("Enter total number of elements: ");
   cin>>limit;
     
    /*Reading array*/
    
    printf("Enter array elements: \n");
    for(i=0; i<limit; i++)
    {
        printf("Enter element %3d: ",i+1);
        cin>>arr[i];
    }
     
    /*sort elements in Ascending Order*/
    for(i=1; i<(limit); i++)
    {
        j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
             
            j--;
        }
    }
 
    printf("Array elements in Ascending Order:\n");
    for(i=0; i<limit; i++)
        cout<<arr[i]<<" ";
     
    cout<<endl;
         
    /*sort elements in Descending Order*/
    for(i=1; i<(limit); i++)
    {
        j=i;
        while(j>0 && arr[j]>arr[j-1])
        {
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
             
            j--;
        }
    }
 
    printf("Array elements in Descending Order:\n");
    for(i=0; i<limit; i++)
        cout<<arr[i]<<" ";
         
   cout<<endl;
     
    return 0;
}

