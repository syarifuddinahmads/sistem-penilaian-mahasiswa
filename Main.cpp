#include <iostream>
using namespace std;

struct User{
    string namaUser;
    string username;
    string password;
    string privilage;
    User *prev;
    User *next;
};



struct MataKuliah{
    string namaMatkul;
    int sks;
    int semester;
    MataKuliah *prev;
    MataKuliah *next;
};

struct Penilaian{
    int npmMahasiswa;
    string mataKuliah;
    int nilai;
    Penilaian *prev;
    Penilaian *next;
};

void inputDummyUserForLogin(User *head, User *tail, string namaUser, string username, string password, string privilage);

int main(){

}

void inputDummyUserForLogin(User *head, User *tail, string namaUser, string username, string password, string privilage){
    User *temp = new User;
    temp->namaUser = namaUser;
    temp->username = username;
    temp->password = password;
    temp->privilage = privilage;
    if(head->next == NULL){
        head->next = temp;
        tail->prev = temp;
    }else{
        temp->prev = tail->prev;
        tail->prev->next = temp;
    }
    temp->next = tail;
    tail->prev = temp;
};
