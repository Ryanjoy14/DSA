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

Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return NULL;
    }
    if (head->link == head) { // Only one node
        delete head;
        cout << "Last node deleted. List is now empty." << endl;
        return NULL;
    }
    Node *temp = head;
    while (temp->link->link != head) {
        temp = temp->link;
    }
    delete temp->link;
    temp->link = head;
    cout << "A node has been deleted from the end." << endl;
    return head;
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return NULL;
    }
    if (head->link == head) { // Only one node
        delete head;
        cout << "The only node has been deleted. List is now empty." << endl;
        return NULL;
    }
    Node *temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }
    Node *toDelete = head;
    head = head->link;
    temp->link = head;
    delete toDelete;
    cout << "A node has been deleted from the beginning." << endl;
    return head;
}

Node* deleteFromGivenNode(string givenNode, Node* head) {
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return NULL;
    }
    if (head->songName == givenNode) {
        head = deleteFromBeginning(head);
        cout << "The Node " << givenNode << " has been deleted." << endl;
        return head;
    }
    Node *temp = head;
    Node *next = head->link;

    while (next != head && next->songName != givenNode) {
        temp = next;
        next = next->link;
    }
    if (next == head) {
        cout << "No such node exists." << endl;
        return head;
    }
    temp->link = next->link;
    delete next;
    cout << "The Node " << givenNode << " has been deleted." << endl;
    return head;
}

int main() {
    Node *head = createNode("Sanctuary", "by Joji");

    head = insertAtEnd("Sunday Morning", "by Maroon 5", head);
    traverse(head);
    head = insertAtEnd("Sweet Dreams", "by Beyonce", head);
    traverse(head);
    head = insertAtEnd("Church", "by Chase Atlantic", head);
    traverse(head);

    head = insertAtBeginning("Est ce que tu m' aimes", "by Maitre Gims", head);
    traverse(head);
    head = insertAtBeginning("I wanna be yours", "by Arctic Monkeys", head);
    traverse(head);
    head = insertAtBeginning("The Night We Met", "by Lord Huron", head);
    traverse(head);
    head = insertAtBeginning("Enchanted", "by Taylor Swift", head);
    traverse(head);

    cout << insertAtAfter("Church", "Swim", "by Chase Atlantic", head) << endl;
    traverse(head);
    cout << insertAtAfter("Enchanted", "All too well", "by Taylor Swift", head) << endl;
    traverse(head);
    cout << insertAtAfter("I wanna be yours", "505", "by Arctic Monkeys", head) << endl;
    traverse(head);

    head = deleteAtEnd(head);
    traverse(head);
    head = deleteFromBeginning(head);
    traverse(head);
    head = deleteFromGivenNode("Enchanted", head);
    traverse(head);

    return 0;
}
