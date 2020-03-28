/* C++ Program - Linear Search 
 Time complexity: Best O(1)
 Time complexity: Worst O(n) */	

#include<iostream>
using namespace std;

int main()
{
	
	int  i, num, n, c=0, pos;
	cout<<"Enter the array size : ";
	cin>>n;
	int arr[n];
	cout<<"Enter Array Elements : ";
	
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the number to be search : ";
	cin>>num;
	
	for(i=0; i<n; i++)
	{
		if(arr[i]==num)
		{
			c=1;
			pos=i+1;
			break;
		}
	}
	if(c==0)
	{
		cout<<"Number not found..!!";
	}
	else
	{
		cout<<num<<" found at position "<<pos<<endl;
	}
	return 0;	
}
