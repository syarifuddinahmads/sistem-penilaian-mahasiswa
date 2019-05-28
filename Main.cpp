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

struct Mahasiswa{
string namaMhs, jurusan;
int npm;
Mahasiswa *prev;
Mahasiswa *next;
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
// Modul Mahasiswa
void inputMahasiswa(Mahasiswa *head, Mahasiswa *tail, string namaMhs, string jurusan, int npm);

int main(){
    User head, tail;
    head.next=NULL;
    head.prev=NULL;
    tail.prev=NULL;
    tail.next=NULL;

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
    tail->prev = temp;https://github.com/syarifuddinahmads/sistem-penilaian-mahasiswa.git
};

void inputMahasiswa(Mahasiswa *head, Mahasiswa *tail, string namaMhs, string jurusan, int npm){
Mahasiswa *baru=new Mahasiswa;
if(tail->prev=NULL){
    tail->prev=baru;
    head->next=baru;
}
else{
    baru->prev=tail->prev;
    tail->prev->next=baru;
    tail->prev=baru;
}
};
