#include <iostream>
using namespace std;
using std::cout;
using std::cin;

int nodeid = 1;
int donkey[27] = {7500,8000,8500,9000,9500,10000,10500,11000,11500,12000,12500,13000,13500,14000,14500,15000,15500,16000,16500,17000,17500,18000,18500,19000,19500,20000,20500};  //global array for histogram

struct ListNode{    //creates the list
    string modelname;
    string ownername;
    int price;
    struct ListNode* link;
};

ListNode* createlink(){    //creates the first node of the list and fills it in
    ListNode *temp;
    temp = new ListNode;
    temp->link = NULL;
    cout << "Node ID: " << nodeid << endl;
    cout << "Please enter a Car Model(BMW,Cadillac,Toyota): " <<endl;
    cin >> temp->modelname;
    cout << "Please the name of the car owner: " <<endl;
    cin >> temp->ownername;
    cout << "Please enter a Car Price(between 7500 - 20500): " <<endl;
    cin >> temp->price;
    return temp;

};

ListNode* Addlink(ListNode *head){   //adds a new node to the list everytime it is called
    ListNode *temp;
    temp = new ListNode;
    nodeid++;
    cout << "Node id: " << nodeid <<endl;
    cout << "Please enter a Car Model(BMW,Cadillac,Toyota): " <<endl;
    cin >> temp->modelname;
    cout << "Please the name of the car owner: " <<endl;
    cin >> temp->ownername;
    cout << "Please enter a Car Price(between 7500 - 20500): " <<endl;
    cin >> temp->price;
    temp->link = head;
    head = temp;
    return head;
};

void deleteLink(ListNode * head, int Link){ //this will delete specified nodes
    ListNode *temp = head;		
    ListNode *out = head;		
    ListNode *prev = head;		
    int NodeId = 1;
    while(temp != NULL){
	    prev = temp;
		if(NodeId == Link - 1){
            out = temp->link;           
            temp = temp->link;         
            prev->link = temp->link;			
		    delete out;				
		    break;
        }
        NodeId++;
        temp = temp->link;        		
    }
};

void Print(ListNode * head){  //prints out the entire list
    ListNode *temp = head;
    int NodeId = 1;
    if(temp == NULL) {
	   cout << "End of List " << endl;
    }
    while(temp != NULL){
        cout << "The NodeId is: " << NodeId << endl;
		cout << "The carmodel is: " << temp->modelname << endl;
		cout << "The name of the car owner is: " << temp->ownername<< endl;
        cout << "The price of the car is: " << temp->price << endl;
		temp = temp->link;
        NodeId++;
	}
};

void findList(ListNode * head){          //finds the nodes of the list where it is less than 7500 dollars.
    ListNode *temp = head;			//start at front
    int NodeId = 1;		
    while(temp != NULL){
        if(temp->price < 7500){
			cout << "Car with a price of less than $7500 found at Node #: " << NodeId << endl;
			cout << "The Car model is: " << temp->modelname << endl;
			cout << "The Owner of the car is = " << temp->ownername<< endl;
	    }
	    NodeId++;
	    temp = temp->link;			//move to next node
    }
};

int ListAverage(ListNode * head){   //Calculates the average of the prices of the list
    int total=0;
    int ave;
    ListNode * temp = head;			
    int NodeId = 1;	
    while(temp != NULL){
        total += temp->price; 
	    NodeId++;
	    temp = temp->link;			//move to next node
    }
    ave = total/NodeId;
	return ave;			
};

void Avemore(ListNode * head, int ave){   
    ListNode * temp = head;			//start at front of list
    int NodeId = 1;		//initializes NodeId
    while(temp != NULL){
        if(temp->price > ave){   //checks if the price of the nodes is greater than the average and prints their info if they are
			cout << "Car with a price of more than average found at Node #: " << NodeId << endl;
			cout << "The Car model is: " << temp->modelname << endl;
			cout << "The Owner of the car is: " << temp->ownername<< endl;
            cout << "The Price of the car is: " << temp->price <<endl;
	    }
	    NodeId++;
	    temp = temp->link;			//move to next node
    }
};

void noderemover(ListNode * head){     //checks which nodes have a price which is less than 8000 dollars and deletes them.
    ListNode * temp = head;			//start at front
    int NodeId = 1;
    cout << "Any car below the price of 8000 will be removed " <<endl;	
    while(temp != NULL){
        if(temp->price < 8000){
			deleteLink(head, NodeId);
            cout << "The Removed node: " << NodeId <<endl;
	    }
	    NodeId++;
	    temp = temp->link;			
    }
};     		

int main(){
    cout << "Sajed Atwa" << " FILE: " << __FILE__ << " DATE: " << __DATE__ << " CSC 21200 LM24126" << endl;
    int average;
    ListNode* head = NULL;  //creates the linked list
    head = createlink();                                        //function calls
    for(int i = 0; i <= 10; i++){
        head = Addlink(head);
    }
    cout << "--------------------------------------" << endl;
    Print(head);
    cout << "--------------------------------------" << endl;
    findList(head);
    cout << "--------------------------------------" << endl;
    average = ListAverage(head);
    cout << "The Average Price is: " << average<< endl;
    cout << "---------------------------------------" << endl;
    Avemore(head,average);
    cout << "---------------------------------------" << endl;
    noderemover(head);
    cout << "---------------------------------------" << endl;
    cout << "The updated list is: " <<endl;
    Print(head);
    cout << "---------------------------------------" << endl;
    return 0;
}