#include <iostream>
#include <vector>
using namespace std;

class Pateint{
    private:
        string name;
        int id;
        int room;
        string condition;
    public:

        void getDetails(){
            cout << "Enter patient's name: " << endl;
            cin >> this->name;
            cout << "Enter patient's ID: " << endl;
            cin >> this->id;
            cout << "Enter patient's Room number: " << endl;
            cin >> this->room;
            cout << "Enter patient's condition: " << endl;
            cin >> this->condition;
        }

        void dispDetails(){
            cout << "ID: " << this->id << endl;
            cout << "Name: " << this->name << endl;
            cout << "Room: " << this->room << endl;
            cout << "Condition: " << this->condition << endl;
        }

        int getID(){
            return this->id;
        }
};

int main(){

    int n,choice;
    vector<Pateint> pateints;

    while(1){
        cout << "Patient Management System" << endl;
        cout << "\nEnter your choice\n" << endl;
        cout << "1. Enter details\n2. Display details\n3. Search\n4. Exit" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter number of pateints: ";
                cin >> n;
                for(int i=0; i<n; i++){
                    Pateint p;
                    p.getDetails();
                    pateints.emplace_back(p);
                }
                break;
            case 2:
                for(auto it: pateints){
                    it.dispDetails();
                    cout <<endl;
                }
                break;
            case 3:
                int sid;
                cout << "Enter ID to search: ";
                cin >> sid;
                for(auto it: pateints){
                    int pid = it.getID();
                    if(pid == sid){
                        cout << "Patient found! "<< endl;
                        it.dispDetails();
                    }else{
                        cout << "Patient not found!" << endl;
                    }
                }
                break;
            case 4:
                exit(0);
                break;
        }
    }

    return 0;
}