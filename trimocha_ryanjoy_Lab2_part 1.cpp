#include <iostream>
 #include <string>
 using namespace std;
 
 typedef struct Node {
     string songName;
     string artistName;
     Node* link;
 } Node;
 
 Node* createNode(string data, string artist) {
     Node* newNode = new Node;
     newNode->songName = data;
     newNode->artistName = artist;
     newNode->link = newNode;
     return newNode;
 }
 
 void traverse(Node *head) {
     if (head == NULL) {
         cout << "Playlist is empty." << endl;
         return;
     }
     Node *temp = head;
     cout << "\n My Playlist" << endl;
     do {
         cout << temp->songName << "  " << temp->artistName << endl;
         temp = temp->link;
     } while (temp != head);
 }
 
 Node* insertAtEnd(string data, string artist, Node* head) {
     if (head == NULL) {
         return createNode(data, artist);
     }
     Node *temp = head;
     while (temp->link != head) {
         temp = temp->link;
     }
     Node *newNode = createNode(data, artist);
     temp->link = newNode;
     newNode->link = head;
     cout << "A new node has been inserted at the end." << endl;
     return head;
 }
 
 Node* insertAtBeginning(string data, string artist, Node* head) {
     if (head == NULL) {
         return createNode(data, artist);
     }
     Node *temp = head;
     while (temp->link != head) {
         temp = temp->link;
     }
     Node *newNode = createNode(data, artist);
     newNode->link = head;
     temp->link = newNode;
     cout << "A new node has been inserted at the beginning." << endl;
     return newNode;
 }
 
 string insertAtAfter(string after, string data, string artist, Node* head) {
     if (head == NULL) {
         return "List is empty. Cannot insert.";
     }
     Node *temp = head;
     do {
         if (temp->songName == after) {
             Node *newNode = createNode(data, artist);
             newNode->link = temp->link;
             temp->link = newNode;
             return "A new node has been added after " + after + ".";
         }
         temp = temp->link;
     } while (temp != head);
     return "No such song exists, please try again.";
 }
 
