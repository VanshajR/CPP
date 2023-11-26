#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;

    node(int value) {
        data = value;
        next = nullptr;
    }
};

class CLinkL {
private:
    node* head;

public:
    CLinkL() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        node* nn = new node(value);

        if (head == nullptr) {
            head = nn;
            nn->next = head;
        } else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = nn;
            nn->next = head;
        }
    }

    void insertAtBeginning(int value) {
        node* nn = new node(value);

        if (head == nullptr) {
            head = nn;
            nn->next = head;
        } else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = nn;
            nn->next = head;
            head = nn;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        while(temp->next!=head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<temp->next->data<<" ";
    }
    void check()
    {
        int flag=0;
        node* temp=head;
        while(temp!=NULL)
        {
            if(temp->next==head)
            {
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if (flag==1)
        {
            cout<<"Circular Linked List";
        }
        else if (flag==0)
        {
            cout<<"Not a Circular Linked List";
        }
    }
};

int main() {
    CLinkL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    list.display();

    list.insertAtBeginning(5);
    cout << endl;
    list.display();
    cout<<endl;
    list.check();

    return 0;
}
