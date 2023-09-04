#include <iostream>
using namespace std;
using std::cout;
using std::cin;

struct ListNode{
    string modelname;
    struct ListNode* link;
};

ListNode* createlink(){
    ListNode *temp;
    temp = new ListNode;
    temp->link = NULL;
    cout << "Please enter a Car Model: " <<endl;
    cin >> temp->modelname;
    return temp;
};

void Printlist(ListNode * head){
    ListNode *temp = head;
    //int NodeId = 1;
    if(temp == NULL) {
	   cout << "End of List " << endl;
    }
    while(temp != NULL){
        //cout << "The NodeId is: " << NodeId << endl;
		cout << "The carmodel is: " << temp->modelname << endl;
        temp = temp->link;
        //NodeId++;
	}
};

ListNode* Push(ListNode * head){
	ListNode *current;  				
    current = new ListNode;   				
	cout << "Please enter a Car Model: " << endl;
	cin >> current->modelname;
    current->link = head;		//assign link to old node link
	head = current;			// update head address to be new added node
	return head;				// return new head address
};

void CheckEmpty(ListNode *head){
	if(head == NULL)
		cout << "Stack is Empty" << endl;
	else
		cout << "Stack is not Empty" << endl;
};

ListNode* Pop(ListNode * head){
	ListNode *temp;
	temp = head->link;
	delete head;
	return temp;			//return address to next node
}

int main(){
    cout << "Sajed Atwa" << " FILE: " << __FILE__ << " DATE: " << __DATE__ << " CSC 21200 LM24126" << endl;
    ListNode* head = NULL;
    CheckEmpty(head);
    head = createlink();
    for(int i = 1; i <= 9;i++){
        head = Push(head); 
    }
    CheckEmpty(head);
    head = Pop(head);
    Printlist(head);
    return 0;
}