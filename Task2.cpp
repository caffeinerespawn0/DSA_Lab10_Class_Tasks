
#include <iostream>
using namespace std;

const int SIZE=10;

class HashTable {
    int table[SIZE];
    int status[SIZE];

public:
    HashTable() {
        for(int i=0;i<SIZE;i++) {
            status[i]=0;
        }
    }

    void insert(int id) {
        int index=id%SIZE;
        int probes=0;

        for(int i=0;i<SIZE;i++) {
            int pos=(index+i)%SIZE;
            probes++;

            if(status[pos]==1 && table[pos]==id) {
                cout<<"Package already exists"<<endl;
                cout<<"Probes: "<<probes<<endl;
                return;
            }

            if(status[pos]==0 || status[pos]==2) {
                table[pos]=id;
                status[pos]=1;

                cout<<"Package inserted at "<<pos<<endl;
                cout<<"Probes: "<<probes<<endl;
                return;
            }
        }

        cout<<"Locker system full"<<endl;
        cout<<"Probes: "<<probes<<endl;
    }

    void search(int id) {
        int index=id%SIZE;

        for(int i=0;i<SIZE;i++) {
            int pos=(index+i)%SIZE;

            if(status[pos]==0) {
                cout<<"Package not found"<<endl;
                return;
            }

            if(status[pos]==1 && table[pos]==id) {
                cout<<"Package found at "<<pos<<endl;
                return;
            }
        }

        cout<<"Package not found"<<endl;
    }

    void remove(int id) {
        int index=id%SIZE;

        for(int i=0;i<SIZE;i++) {
            int pos=(index+i)%SIZE;

            if(status[pos]==0) {
                cout<<"Package not found"<<endl;
                return;
            }

            if(status[pos]==1 && table[pos]==id) {
                status[pos]=2;
                cout<<"Package picked up"<<endl;
                return;
            }
        }

        cout<<"Package not found"<<endl;
    }

    void display() {
        for(int i=0;i<SIZE;i++) {
            cout<<i<<": ";

            if(status[i]==1) {
                cout<<table[i];
            }
            else if(status[i]==2) {
                cout<<"Deleted";
            }
            else {
                cout<<"Empty";
            }

            cout<<endl;
        }
    }
};

int main() {
    HashTable h;

    h.insert(12);
    h.insert(22);
    h.insert(32);

    h.display();

    h.remove(22);

    h.search(32);
    h.search(22);

    return 0;
}
