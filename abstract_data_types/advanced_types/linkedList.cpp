#include <iostream>
using namespace std;

class Node {
public:
    int data[10] = {};
    Node* next = NULL;

    Node(int arr[]) {
        for (int i = 0; i < 10; ++i)
        {
            if (arr[i] != NULL)
            {
                this->data[i] = arr[i];
            }
        }
    }
    void print_list(){
        Node* n = this;
        while (n != NULL){
            for (int i = 0; i < 10; ++i)
            {
                if (n->data[i] != NULL)
                {
                    cout << n->data[i] << " ";
                }
            }

            n = n->next;
            cout << endl;
        }

    }
    void insertion(int arr[]) {
        Node* n = this;
        while (n->next != NULL) {
            n = n->next;
        }
        Node* newItem = new Node(arr);
        n->next = newItem;
        newItem->next = NULL;
    }

    bool compareArray(int arr_one[], int arr_two[]){
        for (int i = 0; i < 10; ++i)
        {
            if (arr_one[i] != arr_two[i])
            {
                return false;
            }
        }
        return true;
    }
    void deleteNode(int arr[]) {
        Node* n = this;
        while (n->next != NULL) {
            if (compareArray(n->next->data, arr)) {
                n->next = n->next->next;
            }
            else {
                n = n->next;
            }
        }
    }
    bool search(int arr[]){
        Node* n = this;
        if (n->next == NULL)
        {
           if(compareArray(n->data,arr)){
            return true;
        } else {
            n = n->next;
        }}else {
            while(n->next != NULL){
                if(compareArray(n->data,arr)){
                    return true;
                } else {
                    n = n->next;
                }
            }
        }

        return false;
    }
    void insertAfter(int pos_arr[], int arr[]) {
        Node* n = this;
        while (n->next != NULL) {
            if (compareArray(n->data,pos_arr)) {
                Node* newItem = new Node(arr);
                newItem->next = n->next;
                n->next = newItem;
                n = n->next;
            }
            else {
                n = n->next;
            }
        }
    }
    void prepend(int arr[]) {
        Node* n = this;
        if (n->next == NULL) {
            Node* newItem = new Node(n->data);
            for (int i = 0; i < 10; ++i)
            {
                n->data[i] = NULL;
            }
            for (int i = 0; i < 10; ++i)
            {
                if (arr[i] != NULL)
                {
                    n->data[i] = arr[i];
                }
            }
            n->next = newItem;
        }
        else {
            Node* newItem = new Node(n->data);
            Node* origin = n;
            newItem->next = origin->next;
            for (int i = 0; i < 10; ++i)
            {
                n->data[i] = NULL;
            }
            for (int i = 0; i < 10; ++i)
            {
                if (arr[i] != NULL)
                {
                    n->data[i] = arr[i];
                }
            }
            n->next = newItem;
        }
    }
};

int main() {
    int ar[10] = {5, 2, 3};
    Node* head = new Node(ar);
    int arr[10] = {5, 2, 4};
    head->insertion(arr);
    head->print_list();
    int arrx[10] = {2,5};
    head->insertAfter(ar, arrx);
    int arry[10] = {999, 999};
    head->prepend(arry);
    head->print_list();
    return 0;
}
