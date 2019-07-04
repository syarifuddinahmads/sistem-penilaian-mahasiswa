#include <iostream>
#include "struct.h";
#include "login.h"
using namespace std;
// 1.Admin
//  1. User
//  2. Mahasiswa
//  3. Mata Kuliah
// 2.Operator
//  1. Input Nilai

int typeMenu,statusUser = 0;
bool isLoggedIn = false;

void inputUser(User *headUser, User *tailUser, string namaUser, string username, string password, int privilage)
{
    User *temp = new User;
    temp->namaUser = namaUser;
    temp->username = username;
    temp->password = password;
    temp->privilage = privilage;
    if(headUser->next == NULL)
    {
        headUser->next = temp;
        tailUser->prev = temp;
    }
    else
    {
        temp->prev = tailUser->prev;
        tailUser->prev->next = temp;
    }
    temp->next = tailUser;
    tailUser->prev = temp;
};

void showUser(User *headUser, User *tailUser)
{
    User *temp = headUser->next;
    if(temp == NULL)
    {
        cout <<endl;
        cout << "User Tidak Tersedia !"<<endl;
        cout <<endl;
    }
    else
    {
        cout <<endl;
        cout << "Data User : "<<endl;
        cout <<endl;
        while(temp != tailUser)
        {
            cout<< "Nama : " << temp->namaUser <<endl;
            cout<< "Username : " << temp->username <<endl;
            cout<< "Privilage : " << temp->privilage <<endl;
            cout <<endl;
            temp = temp->next;
        }
        cout <<endl;
    }
}

int main()
{
    // User Linkedlist initiator
    User headUser, tailUser;
    headUser.next=NULL;
    headUser.prev=NULL;
    tailUser.prev=NULL;
    tailUser.next=NULL;
    // User Linkedlist initiator
    Mahasiswa headMhs, tailMhs;
    headMhs.next=NULL;
    headMhs.prev=NULL;
    tailMhs.prev=NULL;
    tailMhs.next=NULL;
    // Matkul Linkedlist initiator
    MataKuliah headMatkul, tailMatkul;
    headMatkul.next = NULL;
    headMatkul.prev = NULL;
    tailMatkul.next = NULL;
    tailMatkul.prev = NULL;

    if(isLoggedIn == false)
    {
        inputUser(&headUser,&tailUser, "Admin", "admin", "admin", 1);
        inputUser(&headUser,&tailUser, "Operator", "op", "op", 2);
        inputUser(&headUser,&tailUser, "Operator", "ad", "ad", 1);
        showUser(&headUser, &tailUser);
        statusUser = login(&headUser,&tailUser);
    }

    if(statusUser == 1)
    {
        cout<<"Menu Admin : "<<endl;
        cout<<"1. User"<<endl;
        cout<<"2. Mata Kuliah"<<endl;
        cout<<"3. Mahasiswa"<<endl;
        cout<<"4. Logout"<<endl;
        int menu;
        do
        {
            cout<<"Pilih Menu : ";
            cin>>menu;
            switch(menu)
            {
            case 1:
                cout<<"1 !"<<endl;
                break;
            case 2:
                cout<<"2 !"<<endl;
                break;
            case 3:
                cout<<"3 !"<<endl;
                break;
            case 4:
                login(&headUser,&tailUser);
            default:
                cout<<"Menu tidak valid !"<<endl;
                break;
            }
        }
        while(menu != 4);
    }

    if(statusUser == 2)
    {
        cout<<"operato";
    }
}
