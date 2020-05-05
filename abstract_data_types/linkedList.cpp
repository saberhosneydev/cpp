#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next = NULL;

    Node(int data) {
        this->data = data;
    }
};

void print_list(Node *n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

void prepend(Node *head, int newData) {
    if (head->next == NULL) {
        Node *newItem = new Node(head->data);
        head->data = newData;
        head->next = newItem;
    } else {
        Node *newItem = new Node(head->data);
        Node *origin = head;
        newItem->next = origin->next;
        head->data = newData;
        head->next = newItem;
    }
}

void append(Node *head, int newData) {
    while (head->next != NULL) {
        head = head->next;
    }
    Node *newItem = new Node(newData);
    head->next = newItem;
    newItem->next = NULL;
}

void deleteNode(Node *currentNode, int data) {
    while (currentNode->next != NULL) {
        if (currentNode->next->data == data) {
            currentNode->next = currentNode->next->next;
        } else {
            currentNode = currentNode->next;
        }
    }
}

void insertAfter(Node *nodes, int pos, int newData){
    while (nodes->next != NULL) {
        if (nodes->data == pos){
            Node *newItem = new Node(newData);
            newItem->next = nodes->next;
            nodes->next = newItem;
        }else {
            nodes = nodes->next;
        }
    }
}
int main() {
    Node *head = new Node(1);
    prepend(head, 5);
    append(head, 15);
    append(head, 16);
    append(head, 18);
    deleteNode(head, 15);
    insertAfter(head, 16, 17);
    append(head, 14);
    print_list(head);
}