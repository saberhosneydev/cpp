#include <iostream>
using namespace std;

class unrolledNode {
public:
    int unrolledArray[10] = {};
    unrolledNode* next = NULL;

    unrolledNode(int givenArray[]) {
        for (int arrKey = 0; arrKey < 10; ++arrKey)
        {
            if (givenArray[arrKey] != NULL)
            {
                this->unrolledArray[arrKey] = givenArray[arrKey];
            }
        }
    }
    void print_unrolled_list(){
        unrolledNode* current_unrolledNode = this;
        while (current_unrolledNode != NULL){
            for (int arrKey = 0; arrKey < 10; ++arrKey)
            {
                if (current_unrolledNode->unrolledArray[arrKey] != NULL)
                {
                    cout << current_unrolledNode->unrolledArray[arrKey] << " ";
                }
            }

            current_unrolledNode = current_unrolledNode->next;
            cout << endl;
        }

    }
    void insert_at_end(int givenArray[]) {
        unrolledNode* current_unrolledNode = this;
        while (current_unrolledNode->next != NULL) {
            current_unrolledNode = current_unrolledNode->next;
        }
        unrolledNode* newItem = new unrolledNode(givenArray);
        current_unrolledNode->next = newItem;
        newItem->next = NULL;
    }

    bool compareArray(int arr_one[], int arr_two[]){
        for (int arrKey = 0; arrKey < 10; ++arrKey)
        {
            if (arr_one[arrKey] != arr_two[arrKey])
            {
                return false;
            }
        }
        return true;
    }
    void delete_unrolledNode(int givenArray[]) {
        unrolledNode* current_unrolledNode = this;
        while (current_unrolledNode->next != NULL) {
            if (compareArray(current_unrolledNode->next->unrolledArray, givenArray)) {
                current_unrolledNode->next = current_unrolledNode->next->next;
            }
            else {
                current_unrolledNode = current_unrolledNode->next;
            }
        }
    }
    bool search(int givenArray[]){
        unrolledNode* current_unrolledNode = this;
        if (current_unrolledNode->next == NULL)
        {
           if(compareArray(current_unrolledNode->unrolledArray,givenArray)){
            return true;
        } else {
            current_unrolledNode = current_unrolledNode->next;
        }}else {
            while(current_unrolledNode->next != NULL){
                if(compareArray(current_unrolledNode->unrolledArray,givenArray)){
                    return true;
                } else {
                    current_unrolledNode = current_unrolledNode->next;
                }
            }
        }

        return false;
    }
    void insert_at_position(int pos_arr[], int givenArray[]) {
        unrolledNode* current_unrolledNode = this;
        while (current_unrolledNode->next != NULL) {
            if (compareArray(current_unrolledNode->unrolledArray,pos_arr)) {
                unrolledNode* newItem = new unrolledNode(givenArray);
                newItem->next = current_unrolledNode->next;
                current_unrolledNode->next = newItem;
                current_unrolledNode = current_unrolledNode->next;
            }
            else {
                current_unrolledNode = current_unrolledNode->next;
            }
        }
    }
    void insert_at_beginning(int givenArray[]) {
        unrolledNode* current_unrolledNode = this;
        if (current_unrolledNode->next == NULL) {
            unrolledNode* newItem = new unrolledNode(current_unrolledNode->unrolledArray);
            for (int arrKey = 0; arrKey < 10; ++arrKey)
            {
                current_unrolledNode->unrolledArray[arrKey] = NULL;
            }
            for (int arrKey = 0; arrKey < 10; ++arrKey)
            {
                if (givenArray[arrKey] != NULL)
                {
                    current_unrolledNode->unrolledArray[arrKey] = givenArray[arrKey];
                }
            }
            current_unrolledNode->next = newItem;
        }
        else {
            unrolledNode* newItem = new unrolledNode(current_unrolledNode->unrolledArray);
            unrolledNode* origin = current_unrolledNode;
            newItem->next = origin->next;
            for (int arrKey = 0; arrKey < 10; ++arrKey)
            {
                current_unrolledNode->unrolledArray[arrKey] = NULL;
            }
            for (int arrKey = 0; arrKey < 10; ++arrKey)
            {
                if (givenArray[arrKey] != NULL)
                {
                    current_unrolledNode->unrolledArray[arrKey] = givenArray[arrKey];
                }
            }
            current_unrolledNode->next = newItem;
        }
    }
};

int main() {
    cout << "Unrolled Linked List!" << endl;
    cout << "Insert 10 Records:";
    int arr0[10] = {5, 2, 3};
    unrolledNode* head = new unrolledNode(arr0);
    int arr1[10] = {5, 2, 4, 21, 423, 91774, 21312, 0, 021};
    head->insert_at_end(arr1);
    int arr2[10] = {2, 5, 321321, 9876, 2112, 698};
    head->insert_at_position(arr0, arr2);
    int arr3[10] = {412, 20, 98, 56416, 10};
    head->insert_at_end(arr3);
    head->print_unrolled_list();
    cout << "\n\n\nUpdate 1!" << endl;
    int arr4[10] = {023 };
    head->insert_at_beginning(arr4);
    int arr5[10] = {945, 1235, 874, 0356, 8132};
    head->insert_at_end(arr5);
    int arr6[10] = {321, 76, 425, 1320};
    head->insert_at_end(arr6);
    int arr7[10] = {0, 874, 6510, 52, 58, 4110, 18, 185, 10};
    head->insert_at_end(arr7);
    int arr8[10] = {0, 10, 2, 51, 68, 181, 31, 201};
    head->insert_at_position(arr3, arr8);
    int arr9[10] = {87, 012, 415, 987, 11, 012, 12, 56, 31, 012};
    head->insert_at_beginning(arr9);
    head->print_unrolled_list();
    cout << "\n\n\nUpdate 2!" << endl;
    head->delete_unrolledNode(arr4);
    head->delete_unrolledNode(arr7);
    head->print_unrolled_list();
    cout << "\n\n\nSearch!" << endl;
    cout << "Search for (0, 10, 2, 51, 68, 181, 31, 201):" << endl;
    int searchArray[10] = { 0, 10, 2, 51, 68, 181, 31, 201 };
    if (head->search(searchArray)) {
        cout << "Found! :D";
    }
    else "Not Found! :( , Better luck next time!";
    cout << "\nSearch for (1, 2, 3, 4, 5):" << endl;
    int searchArray1[10] = {1, 2, 3, 4, 5};
    if (head->search(searchArray1)) {
        cout << "Found! :D";
    }
    else "Not Found! :( , Better luck next time!";

    return 0;
}
