
#include <iostream>
using namespace std;

const int SIZE=11;

class HashTable {
    int table[SIZE];
    bool occupied[SIZE];
    int count;

public:
    HashTable() {
        count=0;

        for(int i=0;i<SIZE;i++) {
            occupied[i]=false;
        }
    }

    float loadFactor() {
        return (float)count/SIZE;
    }

    void insert(int key) {
        if(loadFactor()>0.5) {
            cout<<"Rehash needed. New bookings stopped"<<endl;
            return;
        }

        int index=key%SIZE;

        for(int j=0;j<SIZE;j++) {
            int pos=(index+j*j)%SIZE;

            if(occupied[pos] && table[pos]==key) {
                cout<<"Booking already exists"<<endl;
                return;
            }

            if(!occupied[pos]) {
                table[pos]=key;
                occupied[pos]=true;
                count++;

                cout<<"Booking inserted at "<<pos<<endl;
                return;
            }
        }

        cout<<"No available slot. Rehash needed"<<endl;
    }

    void search(int key) {
        int index=key%SIZE;

        for(int j=0;j<SIZE;j++) {
            int pos=(index+j*j)%SIZE;

            if(!occupied[pos]) {
                cout<<"Booking not found"<<endl;
                return;
            }

            if(table[pos]==key) {
                cout<<"Booking found at "<<pos<<endl;
                return;
            }
        }

        cout<<"Booking not found"<<endl;
    }

    void display() {
        for(int i=0;i<SIZE;i++) {
            cout<<i<<": ";

            if(occupied[i]) {
                cout<<table[i];
            }
            else {
                cout<<"Empty";
            }

            cout<<endl;
        }

        cout<<"Load factor: "<<loadFactor()<<endl;
    }
};

int main() {
    HashTable h;

    h.insert(10);
    h.insert(21);
    h.insert(32);
    h.insert(43);
    h.insert(54);
    h.insert(65);

    h.display();

    h.insert(76);

    return 0;
}
