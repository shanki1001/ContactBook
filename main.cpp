#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

struct Contact{
    string name;
    string PhoneNumber;
    string email;
};

vector<Contact>ContactList;

void AddContact(){
    Contact NewContact;

    cout<<"Enter Name of the Contact:";
    getline(cin,NewContact.name);

    cout<<"Enter (10-digit) Phone Number :";
    getline(cin,NewContact.PhoneNumber);

    cout<<"Enter email of the Contact:";
    getline(cin,NewContact.email);

    ContactList.push_back(NewContact);
    cout<<"Contact added successfully\n";
}
void ViewAllContacts(){
    cout<<"     -----List of All the Contacts ----\n";
    if(ContactList.size()==0){
        cout<<"No Contacts in the list!!!!\n";
        return;
    }

    for(int i=0 ; i<ContactList.size(); i++){
        cout<<i+1<<".Name of the Contact: "<<ContactList[i].name<<", Phone Number: "<<ContactList[i].PhoneNumber;
        cout<<", Email of the Contact: "<<ContactList[i].email<<"\n\n";
    }
}

void SearchContact(){
    string nameToFind;
    cout<<"Enter a name to Find the Contact:";
    getline(cin,nameToFind);
    for(int i=0 ; i<ContactList.size(); i++){
        if(ContactList[i].name == nameToFind){
            cout<<"Contact Found!!!\n";
            cout<<"Name :"<<ContactList[i].name<<", Phone Number: "<<ContactList[i].PhoneNumber;
            cout<<", Email of the Contact: "<<ContactList[i].email<<"\n\n";
            return;
        }
    }
    cout<<"No Such Contact in the List!!!!\n\n";
}
void DeleteContact(){

    ViewAllContacts();
    int index;
    cout<<"Enter contact index number in the List:-";
    cin>>index;
    cin.ignore();
    if(index>=1 && index<=ContactList.size()){
        ContactList.erase(ContactList.begin()+ index-1);
    }
    else cout<<"Invalid Contact list Number!!!!\n";

}
void LoadContacts(){

    ContactList.clear();
    ifstream inFile("Contacts.txt");
    if(!inFile){
        cout<<"No saved Contacts found.\n";
        return ;
    }
    string line;
    while(getline(inFile,line)){
        stringstream ss(line);
        string name,phone,email;

        if(getline(ss,name,',')&&getline(ss,phone,',')&&getline(ss,email)){
            Contact contact;
            contact.name = name;
            contact.PhoneNumber = phone;
            contact.email = email;

            ContactList.push_back(contact);
        }
    }
    inFile.close();
    cout<<"Contacts loaded successfully!\n";
}
void SaveContacts(){
    ofstream file("Contacts.txt");
    if(!file){
        cout<<"Error saving contacs to file.\n";
        return;
    }
    for(auto &Contact : ContactList){
       file<<Contact.name<<","<<Contact.PhoneNumber<<","<<Contact.email<<"\n";
    }
    file.close();
}

int main()
{
    int choice;
    LoadContacts();

    do{
        cout<<"             -----Contact Menu-----\n";
        cout<<"             1.Add a Contact\n";
        cout<<"             2.View All Contacts\n";
        cout<<"             3.Search A Contact\n";
        cout<<"             4.Delete a Contact\n";
        cout<<"             5.Save The Contacts and exit\n";
        cout<<"             ----- End of Menu -----\n";
        cout<<"\nEnter a Choice:";
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1: AddContact();break;
            case 2: ViewAllContacts(); break;
            case 3: SearchContact(); break;
            case 4: DeleteContact(); break;
            case 5: SaveContacts(); break;
            default: cout<<"Invalid choice option\n"; break;
        }
    }while(choice!=5);

    return 0;
}
