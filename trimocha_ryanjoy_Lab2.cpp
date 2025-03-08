

#include <iostream>

 using namespace std;

//Create structure for the node
typedef struct Node{
    string songName;
    Node *link;
}Node;


//Create new node
Node *createNode(string data){
    Node *newNode = new Node; // create new node instance
    newNode->songName = data; //assign data
    newNode->link = NULL; //assign link

    return newNode;
 } 

//Traverse linked list
 void traverse(Node *head){
    Node *temp = new Node; // create temporary node
    temp = head; // assign temporary node as head

    cout << "My Playlist" <<endl; 
    while(temp != NULL){ //Loop through the nodes
        cout << temp->songName<< "->"<<endl; // print data
        if(temp->link == NULL){ // if tail is reached
            cout << "NULL"<<endl; // print NULL after
        }
        
        temp = temp->link;
    }    
} 

//Insert at the end
Node *insertAtEnd(string data, Node *head){
    if(head == NULL){ // if the linked list is empty
        Node *newNode = createNode(data); //create node
        head = newNode; // assign new node has been inserted at the end \n" << endl; // print out message
        return head;
    }
    Node *temp = new Node; //create a temporary node
    temp = head; // assign temporary node as head
    
    while(temp->link != NULL){ // traverse until end is found ie. link == NULL
        temp = temp->link;
    }
    
    Node *newNode = createNode(data); // create new node
    temp->link = newNode; // link the new node to the last element

    cout << "A new node has been Inserted at the end \n" << endl;
    return head;
}

//Insert at the beginning
Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data); //create new node
    newNode->link = newNode; //set new node as head


    cout << "A new node has been inserted at the beginning \n" <<endl; //Output confirmation

    return head;
}

//Insert at the after a given node 
string insertAfter(string after, string data, Node *head){
    Node *temp = new Node; // create temporary node
    temp = head; // assign temporary node as head

    while(temp->songName.compare(after) !=0){ // search for the node
        if(temp == NULL){ // if no such  node exist, please try again later.";
            return "No such song exist, please try again later.";
        }

        temp = temp->link;
    }
    Node *newNode = createNode(data); //create new node
    newNode->link = temp->link; // assign the link of the node after the given node
    temp->link = newNode; //link new node to the given node
    
    return "An new node has been added after " + after + "\n"; // return confirmation message
}    
        
 int main(){
    cout << insert your three(3) most played songs at the end
    Node *head = createNode("Santurary by Joji");
  
    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    traverse(head);

    return 0;
 }   

 