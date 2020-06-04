//18BIS0157 - AFREEN AHMED

#include<iostream> 
#include<stdlib.h> 
using namespace std;
 
typedef struct node{                      //A structure called node is declared.
	int  seatno; 
	char firstname[20]; 
	char lastname[20];
	int age;
	char gender;                          //Passenger details are declared
	struct node* next;                    //Pointer next is assigned to store details in the next address 
}list,*ptr;
 
//Functions are declared.
void insert(ptr b);
void printseat(ptr temp); 
void del(ptr b); 
void print(ptr b);                       

//BOOKING TICKET 
void insert(ptr b){                     
	int input,Input; 
	ptr temp=NULL;                       //temp pointer declared which is initiated to null
	while(b->next!=NULL){                //When value in next to b is not equal to null, loop proceeds. 
		b=b->next;                       //b is given next pointer value 
	}
	if(b->seatno>80){                    //Max seats 80. If all nodes filled, display seats all booked.  
		cout<<"All seats booked. Try again later.\n"; 
		return ;
	}
	else if(b->seatno>50){               //Displays that waiting list is available. 
		cout<<b->seatno-50<<" seats available in waiting \n";
		cout<<"Enter 1 to exit or 0 to Continue \n";
		cin>>Input;
		if(Input==1){
			return;
		}
	}
	temp=(ptr)malloc(1*sizeof(list));    //temp is assigned details of passenger  
	temp->next=NULL;                     //Next temp pointer is given NULL
	cout<<"\nEnter your first name: ";
	cin>>temp->firstname;
	cout<<"Enter your surname: ";
	cin>>temp->lastname;
	cout<<"Enter your age: ";
	cin>>temp->age;
	cout<<"Enter your gender [M/F]: ";
	cin>>temp->gender; 
	temp->seatno=(b->seatno)+1;         //Seat number assigned is pushed to (b>seatno)+1 
	cout<<"\nEnter 1 to confirm ticket: "; 
	cin>>input;
	if(input==1){                       //Selecting 1 prints ticket
		printseat(temp);
	}
	b->next=temp; 
	return ;
}

//PRINT TICKET  
void printseat(ptr temp){
	if(temp->seatno>50){               //If seat number>50, displays waiting list
		cout<<"Waiting list number = "<<temp->seatno-50;
	}	
	else{                              //Displays details if no waiting list 
		cout<<"\n";
		cout<<"\tYour seat number = "<<temp->seatno<<"\n";
	}
	cout<<"\tName = "<<temp->lastname<<", "<<temp->firstname<<"\n";
	cout<<"\tAge = "<<temp->age<<"\n";
	cout<<"\tGender = "<<temp->gender<<"\n";
	cout<<"\n";
	return ;
}

//DELETE TICKET
void del(ptr b){
	int input;
	struct node *temp,*prev;           //Pointers temp and prev are initialised 
	temp = b;
	cout<<"\n";
	cout<<"Enter your seat number: "; 
	cin>>input;                          
	while(temp!=NULL&&(temp->seatno)!=input){
		prev=temp; 
		temp=temp->next;               //prev is assigned temp and temp is assigned next value  
	}
	if(temp==NULL){                    //If temp is equal to null, ticket cannot be deleted, since not booked.
		cout<<"Seat could not be deleted.\n";
		cout<<"\n"; 
		return ;
	}
	if(temp->seatno==input){           //If temp seat number is equal to null, seat is deleted
		prev->next=temp->next; 
		free(temp);                    //temp is made free
	}
	cout<<"Your ticket has been deleted.\n"; 
	cout<<"\n";
}

//SEATING CHART  
void print(ptr b){
	b=b->next;                          //Pointer b assigned next value  
	cout<<"\n";
	cout<<"SEATING CHART\n\n";
	while(b!=NULL){                   
		cout<<"\tSeat Number = "<<b->seatno<<"\n";
		cout<<"\t"<<b->lastname<<", "<<b->firstname<<"\t"<<b->age<<"\t"<<b->gender<<"\n";
		cout<<"\n";
		b=b->next;
	}
	return ;
}

int main(){
	struct node *b;                     //Pointer b is declared.   
	b=(ptr)malloc(1*sizeof(list));      //b is allocated a particular variable
	b->next=NULL;                       //The next pointer is assigned a null value.
	b->seatno=0;                        //Seat number is initialised to 0 and the do-while loop proceeds to booking
    int choice;
    do{
    	cout<<"THE RAILWAY BOOKING SYSTEM WELCOMES YOU\n";
    	cout<<"***************************************\n";
        cout<<"1. Book Ticket\n";
        cout<<"2. Delete Ticket\n";
        cout<<"3. Print Chart\n";
        cout<<"4. Exit\n";
        cout<<"***************************************\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: insert(b);
                    break;
            case 2: del(b);
                    break;
            case 3: print(b);
                    break;
            case 4: 
					cout<<"\nThank You! Have a safe journey\n";
					cout<<"***************************************\n";
					return 0;
            default: cout<<"Please enter valid choice\n";
        }
    }while(choice != 5);
    return 0;
}
  

