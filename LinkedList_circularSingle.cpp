// C++ Program to Implement Circular Linked List 

    #include<iostream>
    #include<cstdio>
    #include<cstdlib>

    using namespace std;

    struct node									// Declaration   Node   
    {
        int info;
        struct node *next;
    }*last;


    class circular_llist
    {
        public:
            void create_node(int value);
            void add_begin(int value);						//functions
            void add_after(int value, int position);
            void delete_element(int value);
            void search_element(int value);
            void display_list();
            void update();
            void sort();
            circular_llist()
            {
                last = NULL;           
            }

    };

     
    int main()

    {
        int choice, element, position;
        circular_llist cl;
        while (1)
        {
            cout<<endl<<"Circular singly linked list\n"<<endl;
            
            cout<<"1.Create Node"<<endl;
            cout<<"2.Add at beginning"<<endl;					//operations
            cout<<"3.Add after"<<endl;
            cout<<"4.Delete"<<endl;
            cout<<"5.Search"<<endl;
            cout<<"6.Display"<<endl;
            cout<<"7.Update"<<endl;
            cout<<"8.Sort"<<endl;
            cout<<"9.Quit"<<endl;
            
            cout<<"Enter your choice : ";
            cin>>choice; 
            switch(choice)
            {
            case 1:
                cout<<"Enter the element: ";
                cin>>element;
                cl.create_node(element);
                cout<<endl;
                break;
            case 2:
                cout<<"Enter the element: ";
                cin>>element;
                cl.add_begin(element);
                cout<<endl;
                break;
            case 3:
                cout<<"Enter the element: ";
                cin>>element;
                cout<<"Insert element after position: ";
                cin>>position;
                cl.add_after(element, position);
                cout<<endl;
                break;
            case 4:
                if (last == NULL)
                {
                    cout<<"List is empty, nothing to delete"<<endl;
                    break;
                }
                cout<<"Enter the element for deletion: ";
                cin>>element;
                cl.delete_element(element);
                cout<<endl;
                break;
            case 5:
                if (last == NULL)
                {
                    cout<<"List Empty!! Can't search"<<endl;
                    break;
                }
                cout<<"Enter the element to be searched: ";
                cin>>element;
                cl.search_element(element);
                cout<<endl;
                break;
            case 6:
                cl.display_list();
                break;
            case 7:
                cl.update();
                break;
            case 8:
                cl.sort();
                break;                      
            case 9:
                exit(1);
                break;
                
            default:
                cout<<"Wrong choice: Please enter correct option."<<endl;

            }

        }
        return 0;

    }


    void circular_llist::create_node(int value)
    {
        struct node *temp;
        temp = new(struct node);				//Allocating memory for Node
        temp->info = value;
        if (last == NULL)
        {
            last = temp;
            temp->next = last;   
        }
        else
        {
            temp->next = last->next; 
            last->next = temp;
            last = temp;
        }
    }


    void circular_llist::add_begin(int value)
    {
        if (last == NULL)
        {
            cout<<"First Create the list."<<endl;		// Insert node at starting.
            return;
        }
        struct node *temp;
        temp = new(struct node);
        temp->info = value;
        temp->next = last->next;
        last->next = temp;

    }

    void circular_llist::add_after(int value, int pos)
    {
        if (last == NULL)
        {
            cout<<"First Create the list."<<endl;
            return;
        }								// Insert node at given position
        struct node *temp, *s;
        s = last->next;
        for (int i = 0;i < pos-1;i++)
        {
            s = s->next;
            if (s == last->next)
            {
                cout<<"There are less than ";
                cout<<pos<<" in the list"<<endl;
                return;
            }
        }
        temp = new(struct node);
        temp->next = s->next;
        temp->info = value;
        s->next = temp;
      
        if (s == last)
        { 
            last=temp;
        }

    }


    void circular_llist::delete_element(int value)
    {
        struct node *temp, *s;
        s = last->next;
      

        if (last->next == last && last->info == value)       // If List has only one element
        {
            temp = last;
            last = NULL;
            free(temp);
            return;
        }
        if (s->info == value) 				 /*First Element Deletion*/
        {
            temp = s;
            last->next = s->next;
            free(temp);
            return;
        }
        while (s->next != last)
        {
            if (s->next->info == value)    
            {
                temp = s->next;				  /*Deletion of Element in between*/
                s->next = temp->next;
                free(temp);
                cout<<"Element "<<value;
                cout<<" deleted from the list"<<endl;
                return;
            }
            s = s->next;
        }

        if (s->next->info == value)    			  /*Deletion of last element*/
        {
            temp = s->next;
            s->next = last->next;
            free(temp);		
            last = s;
            return;
        }
        cout<<"Element "<<value<<" not found in the list"<<endl;
    }



    void circular_llist::search_element(int value)
    {
        struct node *s;
        int counter = 0;
        s = last->next;
        while (s != last)
        {
            counter++;
            if (s->info == value)    
            {
                cout<<"Element "<<value; 
                cout<<" found at position "<<counter<<endl;
                return;
            }
            s = s->next;
        }
        if (s->info == value)    
        {
            counter++;             
            cout<<"Element "<<value;
            cout<<" found at position "<<counter<<endl;
            return;
        }
        cout<<"Element "<<value<<" not found in the list"<<endl;
    }
     

    void circular_llist::display_list()
    {
        struct node *s;
        if (last == NULL)						//display list
        {
            cout<<"List is empty, nothing to display"<<endl;
            return;
        }
        s = last->next;
        cout<<"Circular Link List: "<<endl;
        while (s != last)
        {
            cout<<s->info<<"->";
            s = s->next;
        }
        cout<<s->info<<endl;

    }


    void circular_llist::update()
    {
        int value, pos, i;
        if (last == NULL)
        {									//update value of a node 
            cout<<"List is empty, nothing to update"<<endl;
            return;
        }
        cout<<"Enter the node position to be updated: ";
        cin>>pos;
        cout<<"Enter the new value: ";
        cin>>value;
        struct node *s;
        s = last->next;
        for (i = 0;i < pos - 1;i++)
        {
            if (s == last)
            {
                cout<<"There are less than "<<pos<<" elements.";
                cout<<endl;
                return;
            }
            s = s->next;
        }
        s->info = value;  
        cout<<"Node Updated"<<endl;
    } 


    void circular_llist::sort()
    {									//sort the list
        struct node *s, *ptr;
        int temp;
        if (last == NULL) 
        {
            cout<<"List is empty, nothing to sort"<<endl;
            return;
        }
        s = last->next;
        while (s != last)
        {
            ptr = s->next;
            while (ptr != last->next)
            {
                if (ptr != last->next)
                {
                    if (s->info > ptr->info)
                    {
                        temp = s->info;
                        s->info = ptr->info;
                        ptr->info = temp;
                    }
                }
                else
                {
                    break;
                }
                ptr = ptr->next;    
            }
            s = s->next;         
        }
    }
