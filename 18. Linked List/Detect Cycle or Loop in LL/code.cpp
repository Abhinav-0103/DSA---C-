#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

class List {
    public :
        Node* head;
        Node* tail;

        List() {
            head = NULL;
            tail = NULL;
        }
        
        void push_front(int val) {
            Node* newNode = new Node(val);
            // Node* newNode(val); Static Allocation -> Deleted after function termination

            if(head == NULL) {
                head = tail = newNode;
                return;
            }

            newNode->next = head;
            head = newNode;

        }

        void push_back(int val) {
            Node* newNode = new Node(val);

            if(head == NULL) {
                head = tail = newNode;
                return;
            }

            tail->next = newNode;
            tail = newNode;
        }

        void pop_front() {
            if(head == NULL) {
                cout << "The List is Empty" << endl;
                return;
            }

            Node* temp = head;

            head = head->next;

            temp->next = NULL;
            delete temp;
        }

        void pop_back() {
            if(head == NULL) {
                cout << "The List is Empty" << endl;
                return;
            }

            if(head->next == NULL) {
                delete head;
                return;
            }

            Node* temp = head;

            while(temp->next->next != NULL) {
                temp = temp->next;
            }

            Node* delNode = temp->next;
            temp->next = NULL;

            delete delNode;
            tail = temp;
        }

        bool isCycle() {
            if(head == NULL || head->next == NULL) {
                return false;
            }   

            Node* slow = head;
            Node* fast = slow;

            while(fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast) {
                    return true;
                }
            }

            return false;
        }

        void print() {
            if(head == NULL) {
                cout << "NULL" << endl;
                return;
            }

            Node* temp = head;

            while(temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
};

int main() {
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);

    // ll.tail->next = ll.head;

    cout << ll.isCycle() << endl;

    return 0;
}