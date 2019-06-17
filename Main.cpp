#include <iostream>
#include <stdlib.h>
using namespace std;

struct User
{
    string namaUser;
    string username;
    string password;
    string privilage;
    User *prev;
    User *next;
};

struct Mahasiswa
{
    string namaMhs, jurusan;
    int npm;
    Mahasiswa *prev;
    Mahasiswa *next;
};

struct MataKuliah
{
    string namaMatkul;
    int sks;
    int semester;
    MataKuliah *prev;
    MataKuliah *next;
};

struct Penilaian
{
    int npmMahasiswa;
    string mataKuliah;
    int nilai;
    Penilaian *prev;
    Penilaian *next;
};
// App Init
void initLogin(User *headUser, User *tailUser, Mahasiswa *headMhs, Mahasiswa *tailMhs, MataKuliah *headMatkul, MataKuliah *tailMatkul);
void initApp(User *headUser, User *tailUser, Mahasiswa *headMhs, Mahasiswa *tailMhs, MataKuliah *headMatkul, MataKuliah *tailMatkul);
// Modul Admin
void adminModule(User *headUser, User *tailUser, Mahasiswa *headMhs, Mahasiswa *tailMhs, MataKuliah *headMatkul, MataKuliah *tailMatkul);
void menuAdmin();
// Modul Operator
void operatorModule();
// Modul User
void userModule(User *headUser, User *tailUser);
void menuUser();
void inputUser(User *headUser, User *tailUser, string namaUser, string username, string password, string privilage);
void showUser(User *headUser, User *tailUser);
void editUser(User *headUser, User *tailUser, string username);
void deleteUser(User *headUser, User *tailUser, string username);
void detailUser(User *headUser, User *tailUser, string username,string option);
// Modul Matakuliah
void matkulModule(MataKuliah *headMatkul, MataKuliah *tailMatkul,User *headUser, User *tailUser);
void menuMatkul();
void inputMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul, string namaMatkul, int sks, int semester);
void showMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul);
void editMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul, string namaMatkul);
void deleteMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul, string namaMatkul);
void detailMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul, string namaMatkul,string option);
// Modul Mahasiswa
void mhsModule(Mahasiswa *headMhs, Mahasiswa *tailMhs,User *headUser, User *tailUser);
void menuMhs();
void inputMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs, int npmMhs, string namaMhs, string jurusan);
void showMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs);
void editMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs, int npmMhs);
void deleteMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs, int npmMhs);
void detailMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs, int npmMhs,string option);

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
    // App initiator
    initApp(&headUser,&tailUser,&headMhs,&tailMhs,&headMatkul,&tailMatkul);
}

// App Init

void initApp(User *headUser, User *tailUser, Mahasiswa *headMhs, Mahasiswa *tailMhs, MataKuliah *headMatkul, MataKuliah *tailMatkul){
    inputUser(headUser,tailUser, "Admin", "admin", "admin", "admin");
    initLogin(headUser,tailUser,headMhs,tailMhs,headMatkul,tailMatkul);
}

// Login Modul
void initLogin(User *headUser, User *tailUser, Mahasiswa *headMhs, Mahasiswa *tailMhs, MataKuliah *headMatkul, MataKuliah *tailMatkul)
{
    string username, password;
    do
    {
        cout<<"Login : "<<endl;
        cout<<"Username : ";
        cin>>username;
        cout<<"Password : ";
        cin>>password;
        User *curr = headUser->next;
        while(curr != tailUser)
        {
            if(curr->username != username){
                cout<<"Username yang anda masukkan tidak tersedia atau salah !"<<endl;
            }

            if(curr->username == username && curr->password != password){
                cout<<"Password yang anda masukkan salah !"<<endl;
            }

            if(curr->username == username && curr->password == password)
            {
                if(curr->privilage == "admin")
                {
                    adminModule(headUser, tailUser, headMhs, tailMhs, headMatkul, tailMatkul);
                    break;
                }

                if(curr->privilage == "operator")
                {
                    operatorModule();
                    break;
                }
            }
            curr = curr->next;
        }
    }
    while(true);
}

// Module Admin

void menuAdmin()
{
    cout<<"Menu Admin : "<<endl;
    cout<<"1. User"<<endl;
    cout<<"2. Mata Kuliah"<<endl;
    cout<<"3. Mahasiswa"<<endl;
    cout<<"4. Logout"<<endl;
};

void adminModule(User *headUser, User *tailUser, Mahasiswa *headMhs, Mahasiswa *tailMhs, MataKuliah *headMatkul, MataKuliah *tailMatkul)
{
    int menu;
    do
    {
        menuAdmin();
        cout<<"Pilih Menu : ";
        cin>>menu;
        switch(menu)
        {
        case 1:
            userModule(headUser,tailUser);
            break;
        case 2:
            matkulModule(headMatkul, tailMatkul,headUser,tailUser);
            break;
        case 3:
            mhsModule(headMhs, tailMhs,headUser,tailUser);
            break;
        case 4:
            initLogin(headUser,tailUser,headMhs,tailMhs,headMatkul,tailMatkul);
        default:
            cout<<"Menu tidak valid !"<<endl;
            break;
        }
    }
    while(menu != 4);
};

void operatorModule()
{
    cout<<"Operator"<<endl;
};

// User Modul
void userModule(User *headUser, User *tailUser)
{
    int menu,jumlahUser;
    string name, user_name, pwd, role;
    do
    {
        menuUser();
        cout<<"Pilih Menu :";
        cin>>menu;
        switch(menu)
        {
        case 1:
            cout<<"Masukkan Jumlah User : ";
            cin>>jumlahUser;
            for(int i = 0; i<jumlahUser; i++)
            {
                cout<<"User ke - "<<i+1<<endl;
                cout<<"Nama :";
                cin>>name;
                cout<<"Username :";
                cin>>user_name;
                cout<<"Password :";
                cin>>pwd;
                cout<<"Privilage :";
                cin>>role;
                inputUser(headUser, tailUser, name, user_name, pwd, role);
            }
            break;
        case 2:
            showUser(headUser, tailUser);
            break;
        case 3:
            cout<<"Masukkan Username yang akan di Edit : ";
            cin>>user_name;
            editUser(headUser, tailUser, user_name);
            break;
        case 4:
            cout<<"Masukkan Username yang akan di Delete : ";
            cin>>user_name;
            deleteUser(headUser, tailUser, user_name);
            break;
        case 5:
            adminModule(headUser, tailUser,NULL,NULL,NULL,NULL);
            break;
        case 6:
            initLogin(headUser,tailUser,NULL,NULL,NULL,NULL);
            break;
        default:
            cout<<"Menu tidak valid !"<<endl;
            break;
        }
    }
    while(menu <= 6);
}

void menuUser()
{
    cout<<"Menu User : "<<endl;
    cout<<"1. Input User"<<endl;
    cout<<"2. Show User"<<endl;
    cout<<"3. Edit User"<<endl;
    cout<<"4. Delete User"<<endl;
    cout<<"5. Kembali Ke Menu Utama"<<endl;
    cout<<"6. Logout"<<endl;
}

void inputUser(User *headUser, User *tailUser, string namaUser, string username, string password, string privilage)
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

void editUser(User *headUser, User *tailUser, string username)
{
    User *curr = headUser->next;
    if(curr == NULL)
    {
        cout <<endl;
        cout << "User tidak ditemukan !"<<endl;
        cout <<endl;
    }
    else
    {
        cout <<endl;
        while(curr != tailUser)
        {
            if(curr->username == username)
            {
                detailUser(curr,tailUser,username,"edit");
            }
            curr = curr->next;
        }
        cout <<endl;
    }
}

void deleteUser(User *headUser, User *tailUser, string username)
{
    User *curr = headUser->next;
    if(curr == NULL)
    {
        cout <<endl;
        cout << "User tidak ditemukan !"<<endl;
        cout <<endl;
    }
    else
    {
        cout <<endl;
        while(curr != tailUser)
        {
            if(curr->username == username)
            {
                detailUser(curr,tailUser,username,"delete");
            }
            curr = curr->next;
        }
        cout <<endl;
    }
}

void detailUser(User *headUser, User *tailUser, string username,string option)
{
    char kode;
    string name, user_name, pwd, role;
    User *temp = headUser;
    cout<<"Detail User : "<<endl;
    cout<<"Nama :"<<temp->namaUser<<endl;
    cout<<"Username :"<<temp->username<<endl;
    cout<<"Privilage :"<<temp->privilage<<endl;
    cout<<endl;
    if(option == "edit")
    {
        cout<<"Edit User : "<<endl;
        cout<<"Nama : ";
        cin>>name;
        cout<<"Username : ";
        cin>>user_name;
        cout<<"Password : ";
        cin>>pwd;
        cout<<"Privilage : ";
        cin>>role;
        do
        {
            cout<<"Simpan & Update User (y/t) ?";
            cin>>kode;
            if(kode == 'y')
            {
                temp->namaUser = name;
                temp->username = user_name;
                temp->password = pwd;
                temp->privilage = role;
                cout<<"Update Data User berhasil !"<<endl;
            }
            else if(kode == 't')
            {
                cout<<"Update Data User dibatalkan !"<<endl;
                break;
            }
            else
            {
                cout<<"Masukkan y/t untuk konfirmasi !"<<endl;
            }
        }
        while(kode != 'y');
    }

    if(option == "delete")
    {
        do
        {
            cout<<"Hapus Data User (y/t) ?";
            cin>>kode;
            if(kode == 'y')
            {
                while(temp != tailUser)
                {
                    if(temp->username == username)
                    {
                        // Front
                        if(temp->prev == NULL)
                        {
                            cout<<"top"<<endl;
                            temp->next = NULL;
                            delete temp;

                        }
                        // Mid
                        if(temp->prev != NULL && temp->next != NULL)
                        {
                            temp->prev->next = temp->next;
                            temp->next->prev = temp->prev;

                            delete temp;
                        }
                        // Last
                        if(temp->next == NULL)
                        {
                            temp->prev->next = tailUser->next;
                            tailUser->prev = temp;
                        }
                    }
                    temp = temp->next;
                }
                cout<<"Delete Data User berhasil !"<<endl;
            }
            else if(kode == 't')
            {
                cout<<"Delete Data User dibatalkan !"<<endl;
                break;
            }
            else
            {
                cout<<"Masukkan y/t untuk konfirmasi !"<<endl;
            }
        }
        while(kode != 'y');
    }
}
// End User Modul

// Matakuliah Modul
void matkulModule(MataKuliah *headMatkul, MataKuliah *tailMatkul,User *headUser, User *tailUser)
{
    int menu,jumlahMatkul, sks, semester;
    string namaMatkul;
    do
    {
        menuMatkul();
        cout<<"Pilih Menu :";
        cin>>menu;
        switch(menu)
        {
        case 1:
            cout<<"Masukkan Jumlah Mata Kuliah : ";
            cin>>jumlahMatkul;
            for(int i = 0; i<jumlahMatkul; i++)
            {
                cout<<"Mata Kuliah ke - "<<i+1<<endl;
                cout<<"Nama :";
                cin>>namaMatkul;
                cout<<"SKS :";
                cin>>sks;
                cout<<"Semester :";
                cin>>semester;
                inputMatkul(headMatkul, tailMatkul, namaMatkul, sks, semester);
            }
            break;
        case 2:
            showMatkul(headMatkul, tailMatkul);
            break;
        case 3:
            cout<<"Masukkan Nama Mata Kuliah yang akan di Edit : ";
            cin>>namaMatkul;
            editMatkul(headMatkul, tailMatkul, namaMatkul);
            break;
        case 4:
            cout<<"Masukkan Nama Mata Kuliah yang akan di Delete : ";
            cin>>namaMatkul;
            deleteMatkul(headMatkul, tailMatkul, namaMatkul);
            break;
        case 5:
            adminModule(NULL,NULL,NULL,NULL,headMatkul,tailMatkul);
            break;
        case 6:
            initLogin(headUser,tailUser,NULL,NULL,NULL,NULL);
            break;
        default:
            cout<<"Menu tidak valid !"<<endl;
            break;
        }
    }
    while(menu <= 6);
}

void menuMatkul()
{
    cout<<"Menu Mata Kuliah : "<<endl;
    cout<<"1. Input Mata Kuliah"<<endl;
    cout<<"2. Show Mata Kuliah"<<endl;
    cout<<"3. Edit Mata Kuliah"<<endl;
    cout<<"4. Delete Mata Kuliah"<<endl;
    cout<<"5. Kembali Ke Menu Utama"<<endl;
    cout<<"6. Logout"<<endl;
}

void inputMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul, string namaMatkul, int sks, int semester)
{
    MataKuliah *temp = new MataKuliah;
    temp->namaMatkul = namaMatkul;
    temp->sks = sks;
    temp->semester = semester;
    if(headMatkul->next == NULL)
    {
        headMatkul->next = temp;
        tailMatkul->prev = temp;
    }
    else
    {
        temp->prev = tailMatkul->prev;
        tailMatkul->prev->next = temp;
    }
    temp->next = tailMatkul;
    tailMatkul->prev = temp;
}

void showMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul)
{
    MataKuliah *temp = headMatkul->next;
    if(temp == NULL)
    {
        cout <<endl;
        cout << "Mata Kuliah Tidak Tersedia !"<<endl;
        cout <<endl;
    }
    else
    {
        cout <<endl;
        cout << "Data Mata Kuliah : "<<endl;
        cout <<endl;
        while(temp != tailMatkul)
        {
            cout<< "Nama : " << temp->namaMatkul <<endl;
            cout<< "SKS : " << temp->sks <<endl;
            cout<< "Semester : " << temp->semester <<endl;
            cout <<endl;
            temp = temp->next;
        }
        cout <<endl;
    }
}

void editMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul, string namaMatkul)
{
    MataKuliah *curr = headMatkul->next;
    if(curr == NULL)
    {
        cout <<endl;
        cout << "Matakuliah tidak ditemukan !"<<endl;
        cout <<endl;
    }
    else
    {
        cout <<endl;
        while(curr != tailMatkul)
        {
            if(curr->namaMatkul == namaMatkul)
            {
                detailMatkul(curr,tailMatkul,namaMatkul,"edit");
            }
            curr = curr->next;
        }
        cout <<endl;
    }
}

void deleteMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul, string namaMatkul)
{
    MataKuliah *curr = headMatkul->next;
    if(curr == NULL)
    {
        cout <<endl;
        cout << "Matakuliah tidak ditemukan !"<<endl;
        cout <<endl;
    }
    else
    {
        cout <<endl;
        while(curr != tailMatkul)
        {
            if(curr->namaMatkul == namaMatkul)
            {
                detailMatkul(curr,tailMatkul,namaMatkul,"delete");
            }
            curr = curr->next;
        }
        cout <<endl;
    }
}

void detailMatkul(MataKuliah *headMatkul, MataKuliah *tailMatkul, string namaMatkul,string option)
{
    char kode;
    string nama_matkul;
    int sks, semester;
    MataKuliah *temp = headMatkul;
    cout<<"Detail Mata Kuliah : "<<endl;
    cout<<"Nama Matkul :"<<temp->namaMatkul<<endl;
    cout<<"SKS :"<<temp->sks<<endl;
    cout<<"Semester :"<<temp->semester<<endl;
    cout<<endl;
    if(option == "edit")
    {
        cout<<"Edit Mata Kuliah : "<<endl;
        cout<<"Nama Matkul: ";
        cin>>nama_matkul;
        cout<<"SKS : ";
        cin>>sks;
        cout<<"Semester : ";
        cin>>semester;
        do
        {
            cout<<"Simpan & Update Matkul (y/t) ?";
            cin>>kode;
            if(kode == 'y')
            {
                temp->namaMatkul = nama_matkul;
                temp->sks = sks;
                temp->semester = semester;
                cout<<"Update Data Matkul berhasil !"<<endl;
            }
            else if(kode == 't')
            {
                cout<<"Update Data Matkul dibatalkan !"<<endl;
                break;
            }
            else
            {
                cout<<"Masukkan y/t untuk konfirmasi !"<<endl;
            }
        }
        while(kode != 'y');
    }

    if(option == "delete")
    {
        do
        {
            cout<<"Hapus Data Mata Kuliah (y/t) ?";
            cin>>kode;
            if(kode == 'y')
            {
                while(temp != tailMatkul)
                {
                    if(temp->namaMatkul == namaMatkul)
                    {
                        // Front
                        if(temp->prev == NULL)
                        {
                            cout<<"top"<<endl;
                            temp->next = NULL;
                            delete temp;

                        }
                        // Mid
                        if(temp->prev != NULL && temp->next != NULL)
                        {
                            temp->prev->next = temp->next;
                            temp->next->prev = temp->prev;

                            delete temp;
                        }
                        // Last
                        if(temp->next == NULL)
                        {
                            temp->prev->next = tailMatkul->next;
                            tailMatkul->prev = temp;
                        }
                    }
                    temp = temp->next;
                }
                cout<<"Delete Data Matakuliah berhasil !"<<endl;
            }
            else if(kode == 't')
            {
                cout<<"Delete Data Matakuliah dibatalkan !"<<endl;
                break;
            }
            else
            {
                cout<<"Masukkan y/t untuk konfirmasi !"<<endl;
            }
        }
        while(kode != 'y');
    }
}
// End Matakuliah Modul
// Mahasiswa Modul
void mhsModule(Mahasiswa *headMhs, Mahasiswa *tailMhs,User *headUser, User *tailUser)
{
    int menu,jumlahMhs, npm;
    string namaMhs, jurusan;
    do
    {
        menuMhs();
        cout<<"Pilih Menu :";
        cin>>menu;
        switch(menu)
        {
        case 1:
            cout<<"Masukkan Jumlah Mahasiswa : ";
            cin>>jumlahMhs;
            for(int i = 0; i<jumlahMhs; i++)
            {
                cout<<"NPM :";
                cin>>npm;
                cout<<"Mahasiswa ke - "<<i+1<<endl;
                cout<<"Nama :";
                cin>>namaMhs;
                cout<<"Jurusan :";
                cin>>jurusan;
                inputMhs(headMhs, tailMhs, npm, namaMhs, jurusan);
            }
            break;
        case 2:
            showMhs(headMhs, tailMhs);
            break;
        case 3:
            cout<<"Masukkan NPM Mahasiswa yang akan diedit : ";
            cin>>npm;
            editMhs(headMhs, tailMhs, npm);
            break;
        case 4:
            cout<<"Masukkan NPM Mahasiswa yang akan didelete : ";
            cin>>npm;
            deleteMhs(headMhs, tailMhs, npm);
            break;
        case 5:
            adminModule(NULL,NULL,headMhs,tailMhs,NULL,NULL);
            break;
        case 6:
            initLogin(headUser,tailUser,NULL,NULL,NULL,NULL);
            break;
        default:
            cout<<"Menu tidak valid !"<<endl;
            break;
        }
    }
    while(menu <= 6);
}

void menuMhs()
{
    cout<<"Menu Mahasiswa : "<<endl;
    cout<<"1. Input Mahasiswa"<<endl;
    cout<<"2. Show Mahasiswa"<<endl;
    cout<<"3. Edit Mahasiswa"<<endl;
    cout<<"4. Delete Mahasiswa"<<endl;
    cout<<"5. Kembali Ke Menu Utama"<<endl;
    cout<<"6. Logout"<<endl;
}

void inputMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs, int npmMhs, string namaMhs, string jurusan)
{
    Mahasiswa *temp = new Mahasiswa;
    temp->npm = npmMhs;
    temp->namaMhs = namaMhs;
    temp->jurusan = jurusan;
    if(headMhs->next == NULL)
    {
        headMhs->next = temp;
        tailMhs->prev = temp;
    }
    else
    {
        temp->prev = tailMhs->prev;
        tailMhs->prev->next = temp;
    }
    temp->next = tailMhs;
    tailMhs->prev = temp;
}

void showMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs)
{
    Mahasiswa *temp = headMhs->next;
    if(temp == NULL)
    {
        cout <<endl;
        cout << "Mahasiswa Tidak Tersedia !"<<endl;
        cout <<endl;
    }
    else
    {
        cout <<endl;
        cout << "Data Mahasiswa : "<<endl;
        cout <<endl;
        while(temp != tailMhs)
        {
            cout<< "NPM : " << temp->npm <<endl;
            cout<< "Nama : " << temp->namaMhs <<endl;
            cout<< "Jurusan : " << temp->jurusan <<endl;
            cout <<endl;
            temp = temp->next;
        }
        cout <<endl;
    }
}

void editMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs, int npm)
{
    Mahasiswa *curr = headMhs->next;
    if(curr == NULL)
    {
        cout <<endl;
        cout << "Mahasiswa tidak ditemukan !"<<endl;
        cout <<endl;
    }
    else
    {
        cout <<endl;
        while(curr != tailMhs)
        {
            if(curr->npm == npm)
            {
                detailMhs(curr,tailMhs,npm,"edit");
            }
            curr = curr->next;
        }
        cout <<endl;
    }
}

void deleteMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs, int npm)
{
    Mahasiswa *curr = headMhs->next;
    if(curr == NULL)
    {
        cout <<endl;
        cout << "Mahasiswa tidak ditemukan !"<<endl;
        cout <<endl;
    }
    else
    {
        cout <<endl;
        while(curr != tailMhs)
        {
            if(curr->npm == npm)
            {
                detailMhs(curr,tailMhs,npm,"delete");
            }
            curr = curr->next;
        }
        cout <<endl;
    }
}

void detailMhs(Mahasiswa *headMhs, Mahasiswa *tailMhs, int npm,string option)
{
    char kode;
    string namaMhs, jurusan;
    int npmMhs;
    Mahasiswa *temp = headMhs;
    cout<<"Detail Mahasiswa : "<<endl;
    cout<<"NPM :"<<temp->npm<<endl;
    cout<<"Nama Mahasiswa :"<<temp->namaMhs<<endl;
    cout<<"Jurusan :"<<temp->jurusan<<endl;
    cout<<endl;
    if(option == "edit")
    {
        cout<<"Edit Mahasiswa : "<<endl;
        cout<<"Nama: ";
        cin>>namaMhs;
        cout<<"Jurusan : ";
        cin>>jurusan;
        do
        {
            cout<<"Simpan & Update Mahasiswa (y/t) ?";
            cin>>kode;
            if(kode == 'y')
            {
                temp->namaMhs = namaMhs;
                temp->jurusan = jurusan;
                cout<<"Update Data Mahasiswa berhasil !"<<endl;
            }
            else if(kode == 't')
            {
                cout<<"Update Data Mahasiswa dibatalkan !"<<endl;
                break;
            }
            else
            {
                cout<<"Masukkan y/t untuk konfirmasi !"<<endl;
            }
        }
        while(kode != 'y');
    }

    if(option == "delete")
    {
        do
        {
            cout<<"Hapus Data Mahasiswa (y/t) ?";
            cin>>kode;
            if(kode == 'y')
            {
                while(temp != tailMhs)
                {
                    if(temp->npm == npm)
                    {
                        // Front
                        if(temp->prev == NULL)
                        {
                            cout<<"top"<<endl;
                            temp->next = NULL;
                            delete temp;

                        }
                        // Mid
                        if(temp->prev != NULL && temp->next != NULL)
                        {
                            temp->prev->next = temp->next;
                            temp->next->prev = temp->prev;

                            delete temp;
                        }
                        // Last
                        if(temp->next == NULL)
                        {
                            temp->prev->next = tailMhs->next;
                            tailMhs->prev = temp;
                        }
                    }
                    temp = temp->next;
                }
                cout<<"Delete Data Mahasiswa berhasil !"<<endl;
            }
            else if(kode == 't')
            {
                cout<<"Delete Data Mahasiswa dibatalkan !"<<endl;
                break;
            }
            else
            {
                cout<<"Masukkan y/t untuk konfirmasi !"<<endl;
            }
        }
        while(kode != 'y');
    }
}
// End Mahasiswa Modul
