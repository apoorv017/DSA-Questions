#include <bits/stdc++.h>
using namespace std;
//node creation
class Node{
    public:
        int data;
        Node* next;
        //constructor
        Node(int data){
            this-> data = data;
            this->next = nullptr;
        }
};
//linked list creation
class Linkedlist {
    Node* head;
    public:
    //constructor
        Linkedlist(){
            head = nullptr;
        }
        //insert at end
        void insert(int data){
            Node *newNode = new Node(data);

            if(head == nullptr){
                head = newNode;
                return;
            }
            newNode->next = this->head;
            this->head = newNode;
        }
        //display
        void print(){
            Node *temp = head;

            if(head == nullptr){
                cout << "List Empty" << endl;
                return;
            }

            while(temp != nullptr){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "null";
        }
        // recursive function
        Node* reverseRec(Node* node) {
            //base case
            if (node == nullptr || node->next == nullptr)return node;
            Node* rev = reverseRec(node->next); //recursive call
            node->next->next = node;
            node->next = nullptr; //pointer moving
            return rev;
        }

        // Wrapper function
        void reverse() {
            head = reverseRec(head); //function call 
        }

};


int main() {
    Linkedlist list;
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    cout << "Element before reversal: ";

    list.print();
    cout << endl;
    list.reverse(); // function call
    cout << "Element after reversal: ";
    list.print();
    
    return 0;
}