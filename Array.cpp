/* Operations on Array */

#include<bits/stdc++.h>
using namespace std;

int formArray(int size,int arr[]);
int InsertAtFirst(int size,int arr[],int value);
int InsertAtLast(int size,int arr[],int value);
int Search(int size,int arr[],int v);
int DeleteAtFirst(int size,int arr[]);
int DeleteAtLast(int size,int arr[]);
int SortByInc(int size,int arr[]);
int SortByDec(int size,int arr[]);
int Display(int size,int arr[]);

int size,value;
int arr[10000];

/* formation of array */
int formArray(int size,int arr[])
{

cout<<"Enter elements :";
for(int i=0;i<size;i++)
cin>>arr[i];
return 0;

}

/* Inserting new value at index 0 */
int InsertAtFirst(int size,int arr[],int value)
{
size++;
for(int i=size-1;i>0;i--)
{
arr[i]=arr[i-1];
}

arr[0]=value;
return size;

}

/* Inserting new value at index size-1 */
int InsertAtLast(int size,int arr[],int value)
{
size++;
arr[size-1]=value;
return size;

}

/* Searching value in array */
int Search(int size,int arr[],int value)
{

for(int i=0;i<size;i++)
{

if(arr[i]==value)
{
 cout<<value<<" found at index "<<i<<endl;
 return 0;
}

}
cout<<"Not Found "<<endl;
return 0;
}

/* Delete  first element */
int DeleteAtFirst(int size,int arr[])
{

for(int i=0;i<size-1;i++)
{
arr[i]=arr[i+1];
}

size--;
return size;
}

/* Delete  last element */
int DeleteAtLast(int size,int arr[])
{

size--;
return size;
}

/* Sort element by Increasing Order */
int SortByInc(int size,int arr[])
{

sort(arr,arr+size);
return 0;
}

/* Sort element by Decreasing Order */
int SortByDec(int size,int arr[])
{

sort(arr, arr+size, greater<int>()); 
return 0;
}

/* Printing elements */
int Display(int size,int arr[])
{

for(int i=0;i<size;i++)
cout<<arr[i]<<" ";
cout<<endl;
cout<<endl;
return 0;

}



int main()
{
cout<<" Forming Array is must "<<endl;

do
{
cout<<endl;
cout<<"1. Form array "<<endl;
cout<<"2. Insert element at begining "<<endl;
cout<<"3. Insert element at end "<<endl;
cout<<"4. Search an element "<<endl;
cout<<"5. Delete element from starting "<<endl;
cout<<"6. Delete element from end "<<endl;
cout<<"7. Sort element in Increasing order "<<endl;
cout<<"8. Sort element in Decreasing order "<<endl;
cout<<"9. Display array "<<endl;
cout<<"10. Exit "<<endl;

int choice;
cout<<"Enter your choice :"<<endl;
cin>>choice;

switch(choice)
{
case 1:

cout<<"Enter array size :";
cin>>size;

//int arr[size];
formArray(size,arr);
break;

case 2:
//int value;
//size++;
cout<<"Enter element you want to Insert :";
cin>>value;

size=InsertAtFirst(size,arr,value);
break;

case 3:
//int value;
//size++;
cout<<"Enter element you want to Insert :";
cin>>value;

size=InsertAtLast(size,arr,value);
break;

case 4:
cout<<"Enter element you want to search :";
cin>>value;

Search(size,arr,value);
break;

case 5:
size=DeleteAtFirst(size,arr);
break;

case 6:
size=DeleteAtLast(size,arr);
break;

case 7:
SortByInc(size,arr);
break;

case 8:
SortByDec(size,arr);
break;

case 9:
Display(size,arr);
break;

case 10:
return 0;
break;

default:
cout<<"Enter valid choice "<<endl;
break;

}

}while(1);


return 0;
}









