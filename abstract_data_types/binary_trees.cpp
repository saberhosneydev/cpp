// Example program
#include <iostream>

using namespace std;

class Node {
  public:
    Node * left = NULL;
  Node * right = NULL;
  int data;
  Node(int data) {
    this - > data = data;
  }
  void insert(int value) {
    if (value <= data) {
      if (left == NULL) {
        left = new Node(value);
      } else {
        left - > insert(value);
      }
    } else {
      if (right == NULL) {
        right = new Node(value);
      } else {
        right - > insert(value);
      }
    }
  }
  bool findNode(int value) {
    if (data == value) {
      return true;
    } else if (value < data) {
      if (left == NULL) {
        return false;
      } else {
        return left - > findNode(value);
      }
    } else {
      if (right == NULL) {
        return false;
      } else {
        return right - > findNode(value);
      }
    }
  }
  void showCurrentNodeValue() {
    cout << data << endl;
  }

  void printTreeInOrder() {
    if (left != NULL) {
      left - > printTreeInOrder();
    }
    cout << data << endl;
    if (right != NULL) {
      right - > printTreeInOrder();
    }
  }
};

int main() {
  Node * root = new Node(5);

  root - > insert(55);
  root - > insert(54);
  root - > insert(2);
  root - > insert(3);
  root - > showCurrentNodeValue();
  root - > right - > showCurrentNodeValue();
  root - > right - > left - > showCurrentNodeValue();
  cout << root - > findNode(5);
}