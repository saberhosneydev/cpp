#include <iostream>
using namespace std;

class unrolledNode {
public:
    int unrolledArray[10] = {};
    unrolledNode* next = NULL;

    unrolledNode(int givenArray[]) {
        for (int iterator = 0; iterator < 10; ++iterator)
        {
            if (givenArray[iterator] != NULL)
            {
                this->unrolledArray[iterator] = givenArray[iterator];
            }
        }
    }
    void print_unrolled_list(){
        unrolledNode* current_unrolledNode = this;
        while (current_unrolledNode != NULL){
            for (int iterator = 0; iterator < 10; ++iterator)
            {
                if (current_unrolledNode->unrolledArray[iterator] != NULL)
                {
                    cout << current_unrolledNode->unrolledArray[iterator] << " ";
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
        for (int iterator = 0; iterator < 10; ++iterator)
        {
            if (arr_one[iterator] != arr_two[iterator])
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
            for (int iterator = 0; iterator < 10; ++iterator)
            {
                current_unrolledNode->unrolledArray[iterator] = NULL;
            }
            for (int iterator = 0; iterator < 10; ++iterator)
            {
                if (givenArray[iterator] != NULL)
                {
                    current_unrolledNode->unrolledArray[iterator] = givenArray[iterator];
                }
            }
            current_unrolledNode->next = newItem;
        }
        else {
            unrolledNode* newItem = new unrolledNode(current_unrolledNode->unrolledArray);
            unrolledNode* origin = current_unrolledNode;
            newItem->next = origin->next;
            for (int iterator = 0; iterator < 10; ++iterator)
            {
                current_unrolledNode->unrolledArray[iterator] = NULL;
            }
            for (int iterator = 0; iterator < 10; ++iterator)
            {
                if (givenArray[iterator] != NULL)
                {
                    current_unrolledNode->unrolledArray[iterator] = givenArray[iterator];
                }
            }
            current_unrolledNode->next = newItem;
        }
    }
};

int main() {
    int ar[10] = {5, 2, 3};
    unrolledNode* head = new unrolledNode(ar);
    int arr[10] = {5, 2, 4};
    head->insert_at_end(arr);
    head->print_unrolled_list();
    int arrx[10] = {2,5};
    head->insert_at_position(ar, arrx);
    int arry[10] = {999, 999};
    head->insert_at_beginning(arry);
    head->print_unrolled_list();
    return 0;
}
