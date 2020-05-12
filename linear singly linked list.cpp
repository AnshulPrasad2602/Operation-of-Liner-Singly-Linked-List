//Code of Operation of linear singly linked list using class

#include <iostream>
using namespace std;

class node	//class node that contain data value and link to the next node
{
	public:
		int data;
		node *next;
};

class list : public node //class list -> child class of node
{
	public:
		node *lstptr;	//pointer that points to the 1st node
		node *temp;		//pointer that points to the last node and hold temporary value of the node
		list ()	//default constructor
		{
			lstptr = NULL;	//initialising lstptr and temp to NULL
			temp = NULL;
		}
		
		void create_node()	//function to create node
		{
			cout << "\n\n\tCREATE NODE OF LINKED LIST\n\n";
			
			node *newnode = new node();	//node pointer to create new node (dynamically memory allocated)
			int value;	//variable from which user will enter data
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;	//storing value to the data section of node
			newnode->next = NULL;	//next is assigned to NULL because it points to nothing
			if (lstptr == NULL)		//checking condition for empty
			{
				lstptr = temp = newnode;	//pointing lstpr and temp to 1st node
				cout << "Node created successfully";
			}
			else
			{
				for (temp = lstptr; temp->next != NULL; temp = temp->next);
				temp->next = newnode;	//creating link between the nodes
				temp = temp->next;	//temp pointing to newly linked node
				cout << "Node created successfully";
			}
		}
		
		void print_lnkdlst()	//function to print whole linked list
		{
			cout << "\n\n\tPRINT WHOLE LINKED LIST\n\n";
			
			node *temp1;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				cout << "Elements in the linked list : ";
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					cout << temp1->data << " ";		//printing each value of linked list
				}
			}
		}
		
		void length_lnkdlst()	//function to print length of linked list
		{
			cout << "\n\n\tLENGTH OF LINKED LIST\n\n";
			
			int count = 0; 	//variable to count the node in linked list
			node *temp1;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "Linked list is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					count++;	//incremeting the counter
				}
				cout << "Length of the linked list is " << count;
			}
		}
		
		void insert_begnn()	//function to insert node at beginning
		{
			cout << "\n\n\tINSERT NODE AT BEGINNING\n\n";
			
			node *temp1;
			node *newnode = new node();
			int value;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = NULL;
				cout << "List was empty, new node created.";
			}
			else
			{
				newnode->next = lstptr;
				lstptr = newnode;
				cout << "Node added successfully.";
			}
		}
		
		void insert_pos()	//function to insert at specified position
		{
			cout << "\n\n\tINSERT NODE AT SPECIFIED POSITION\n\n";
			
			node *newnode = new node();
			node *temp1;
			int pos;	//variable for position
			int count = 0;
			int value;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			cout << "Enter the position : ";
			cin >> pos;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = NULL;
				cout << "List was empty, new node created.";
			}
			else
			{
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					count++;	//incremeting the counter to count whole liked list
				}
				if (pos > count)
				{
					cout << "Can't create the node.";
					delete newnode;
					return;
				}
				else
				{
					temp1 = lstptr;
					for (int i = 1; i < pos-1; i++)
					{
						temp1 = temp1->next;
					}
					newnode->next = temp1->next;
					temp1->next = newnode;
					cout << "Node added successfully";
				}
			}
		}

		void insert_end()	//function for insert at end
		{
			cout << "\n\n\tINSERT NODE AT END\n\n";
			
			int value;
			node *newnode = new node();
			node *temp1;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = NULL;
				cout << "List was empty, new node created.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != NULL; temp1 = temp1->next);	//traversing till last node
				temp1->next = newnode;	//creating link between newnode and last node
				newnode->next = NULL;
				cout << "Node added successfully";
			}
		}
		
		void delete_node_front()
		{
			cout << "\n\n\tDELETE NODE FROM FRONT\n\n";
			
			node *temp1;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				temp1 = lstptr;
				lstptr = lstptr->next;	//pointing lstptr to next node
				cout << "Deleted node had : " << temp1->data;
				delete temp1;
			}
		}
		
		void delete_node_end()
		{
			cout << "\n\n\tDELETE NODE FROM END\n\n";
			
			node *temp1, *temp2;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; (temp1->next)->next != NULL; temp1 = temp1->next);	//temp1 will traverse to the second last node
				temp2 = temp1->next;
				temp1->next = NULL;
				cout << "Deleted node had : " << temp2->data;
				delete temp2;
			}
		}
		
		void delete_node_position()
		{
			cout << "\n\n\tDELETE NODE AT SPECIFIED POSITION\n\n";
			
			node *temp1, *temp2;
			int node_pos;	//variable for storing node position
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				cout << "Enter the node position to be deleted : ";
				cin >> node_pos;
				temp1 = lstptr;
				for (int i = 1; i < node_pos-1; i++)
				{
					temp1 = temp1->next;
				}
				temp2 = temp1->next;
				temp1->next = temp2->next;
				cout << "Deleted node had : " << temp2->data;
				delete temp2;
			}
		}
		
		void delete_by_searched_value()
		{
			cout << "\n\n\tDELETE BY SEARCHED VALUE\n\n";
			
			node *temp1, *temp2;
			int search_value;	//to store the search value entered by the user
			int pos = 0; 		//to determine the position of searched value
			int stat = 0;	//if searched element not found then stat will remain 0
			
			cout << "Enter the data value of the node to be deleted : ";
			cin >> search_value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					pos++;
					if (temp1->data == search_value)
					{
						stat++;
						temp2 = lstptr;
						for (int i = 1; i < pos-1; i++)
						{
							temp2 = temp2->next;
						}
						temp2->next = temp1->next;
						delete temp1;
						cout << pos << " st/nd/rd/th node is deleted.";
						break;
					}
				}
				if (stat == 0)
				{
					cout << "No node contain " << search_value << ".";
				}
			}
		}
		
		void reverse_list ()	//function to reverse the list
		{
			cout << "\n\n\tREVERSE OF LINK LIST\n\n";
			
			node *back, *curr, *fwd;	//pointers to point to the previous, current and forward node
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				back = NULL;
				curr = fwd = lstptr;
				fwd = fwd->next;
				curr->next = back;	//reversing the first two nodes
				while (fwd != NULL)
				{
					back = curr;
					curr = fwd;
					fwd = fwd->next;
					curr->next = back;	//reversing the remaining list
				}
				lstptr = curr;	//making last node as first node
				cout << "Reverse of list successfull";
			}
		}
		
		void search_node()	//function for searching data in a node
		{
			cout << "\n\n\tSEARCH DATA OF THE NODE\n\n";
			
			int search, pos = 0;	//search variable to store search value, pos variable to determine position of node
			int count = 0;	//if remained 0 then element not found
			node *temp1;
			
			cout << "Enter the search element : ";
			cin >> search;
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					pos++;
					if (temp1->data == search)
					{
						count++;
						cout << "Search element found at node " << pos <<".";
						break;
					}
				}
				if (count == 0)
				{
					cout << "Element not found.";
				}
			}
		}
		
		void concat_list_end()	//function for concatinating two list
		{
			cout << "\n\n\tCONCATINATION OF TWO LIST\n\n";
			
			list lst1;	//object to create new linked list
			node *temp1, *temp2;
			int data;	//to store new data of the nodes
			char ch;	//variable to continue
			
			cout << "Enter the new list.";
			do 
			{
				node *newnode = new node();
				cout << "\nEnter the data : ";
				cin >> data;
				newnode->data = data;
				newnode->next = NULL;
				if (lst1.lstptr == NULL)	//condition for empty
				{
					lst1.lstptr = temp2 = newnode;
					cout << "Node added successfully.";
				}
				else
				{
					temp2->next = newnode;	//linking nodes to previous nodes
					temp2 = temp2->next;
					cout << "Node added successfully.";
				}
				cout << "\nDo you want to add new node? Y/N\nEnter your choice : ";
				fflush (stdin);
				cin >> ch;
				fflush (stdin);
			}while (ch == 'y' || ch == 'Y');
			if (lstptr == NULL)
			{
				lstptr = lst1.lstptr;
				cout << "\nMain list was absent, new list was created.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != NULL; temp1 = temp1->next);	//traversing in the main list
				temp1->next = lst1.lstptr;	//concatinating to main list
				cout << "\nConcatination successfull.";
			}
		}
		
};

void choice(list lst)	//function for user choice
{
	int ch;	//choice variable for user
	
	cout << "\n\n\nChoose one of the following:\n1. Create a node\n2. Insert node at begining\n3. Insert node at end\n4. Insert node at specified position\n5. Print linked list\n6. Length of linked list\n7. Delete node from front\n8. Delete node from end\n9. Delete node from node position\n10. Delete node by searched value\n11. Reverse of linked list\n12. Search of node\n13. Concatination of two list\n14. Exit\nEnter your choice : ";
	cin >> ch;
	switch(ch)
	{
		case 1 :
			lst.create_node();
			choice(lst);
			break;
			
		case 2 :
			lst.insert_begnn();
			choice(lst);
			break;
			
		case 3 :
			lst.insert_end();
			choice(lst);
			break;
			
		case 4 :
			lst.insert_pos();
			choice(lst);
			break;
			
		case 5 :
			lst.print_lnkdlst();
			choice(lst);
			break;
			
		case 6 :
			lst.length_lnkdlst();
			choice(lst);
			break;
			
		case 7 :
			lst.delete_node_front();
			choice(lst);
			break;
			
		case 8 :
			lst.delete_node_end();
			choice(lst);
			break;
		
		case 9 :
			lst.delete_node_position();
			choice(lst);
			break;
			
		case 10 :
			lst.delete_by_searched_value();
			choice(lst);
			break;
			
		case 11 :
			lst.reverse_list();
			choice(lst);
			break;
			
		case 12 :
			lst.search_node();
			choice(lst);
			break;
			
		case 13 :
			lst.concat_list_end();
			choice(lst);
			break;
			
		case 14 :
			cout << "\n\nProgram ended!!";
			exit (0);
			break;
			
		default :
			cout << "\nChoice not valid.";
			choice (lst);
	}
}

main ()
{
	list lst;
	choice(lst);
}
