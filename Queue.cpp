
   // Implementation of  Queue using Linked List

#include<iostream>
#include<stdio.h>

using namespace std;

   // Node declaration
   
   struct node
    {
        int data;
        node *next;

    }*front = NULL,*rear = NULL,*p = NULL,*np = NULL;


   // Push function
   
    void push(int x)
    
    {
        np = new node;
        np->data = x;
        np->next = NULL;
        
        if(front == NULL)
        {
            front = rear = np;
            rear->next = NULL;

        }

        else
        {
            rear->next = np;
            rear = np;
            rear->next = NULL;

        }

    }

  // remove function
  
    int remove()
    {
        int x;
        if(front == NULL)
        {
            cout<<"empty queue";
            cout<<endl;
        }

        else
        {
            p = front;
            x = p->data;
            front = front->next;
            delete(p);
            return(x);

        }

    }

  // Driver Code 
  
    int main()

    {
        int n,c = 0,x;
        cout<<"Enter the number of values to be pushed into queue";
        cout<<endl;
        cin>>n;
        
        while (c < n)

        {
    	cout<<"Enter the value to be entered into queue";
    	cout<<endl;
    	cin>>x;
        push(x);
        c++;
        
        }

        cout<<"\n\nRemoved Values\n\n";
        while(true)

         {
            if (front != NULL)
                cout<<remove()<<endl;
                
            else
                break;

         }

       return 0;

    }
