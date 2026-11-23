
#include <iostream>
using namespace std;

const int SIZE=10;

class Node {
public:
    string tag;
    int count;
    Node* next;

    Node(string t) {
        tag=t;
        count=1;
        next=NULL;
    }
};

class HashTable {
    Node* table[SIZE];

public:
    HashTable() {
        for(int i=0;i<SIZE;i++) {
            table[i]=NULL;
        }
    }

    int hashFunction(string tag) {
        int sum=0;

        for(int i=0;i<tag.length();i++) {
            sum=sum+tag[i];
        }

        return sum%SIZE;
    }

    void insert(string tag) {
        int index=hashFunction(tag);
        Node* temp=table[index];

        while(temp!=NULL) {
            if(temp->tag==tag) {
                temp->count++;
                return;
            }

            temp=temp->next;
        }

        Node* newNode=new Node(tag);
        newNode->next=table[index];
        table[index]=newNode;
    }

    void search(string tag) {
        int index=hashFunction(tag);
        Node* temp=table[index];

        while(temp!=NULL) {
            if(temp->tag==tag) {
                cout<<tag<<" used "<<temp->count<<" times"<<endl;
                return;
            }

            temp=temp->next;
        }

        cout<<"Tag not found"<<endl;
    }

    void remove(string tag) {
        int index=hashFunction(tag);
        Node* temp=table[index];
        Node* prev=NULL;

        while(temp!=NULL) {
            if(temp->tag==tag) {
                if(prev==NULL) {
                    table[index]=temp->next;
                }
                else {
                    prev->next=temp->next;
                }

                delete temp;
                cout<<"Tag removed"<<endl;
                return;
            }

            prev=temp;
            temp=temp->next;
        }

        cout<<"Tag not found"<<endl;
    }

    void longestChain() {
        int longest=0;

        for(int i=0;i<SIZE;i++) {
            int count=0;
            Node* temp=table[i];

            while(temp!=NULL) {
                count++;
                temp=temp->next;
            }

            if(count>longest) {
                longest=count;
            }
        }

        cout<<"Longest chain: "<<longest<<endl;

        if(longest>5) {
            cout<<"System Overload"<<endl;
        }
    }

    void display() {
        for(int i=0;i<SIZE;i++) {
            cout<<i<<": ";

            Node* temp=table[i];

            while(temp!=NULL) {
                cout<<temp->tag<<"("<<temp->count<<") -> ";
                temp=temp->next;
            }

            cout<<"NULL"<<endl;
        }
    }
};

int main() {
    HashTable h;

    h.insert("#cats");
    h.insert("#dogs");
    h.insert("#cats");
    h.insert("#food");
    h.insert("#music");
    h.insert("#travel");
    h.insert("#sports");

    h.display();

    h.search("#cats");

    h.remove("#dogs");

    h.longestChain();

    return 0;
}
