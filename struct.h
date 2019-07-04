#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <iostream>
using namespace std;

struct User
{
    string namaUser;
    string username;
    string password;
    int privilage;
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

#endif // STRUCT_H_INCLUDED
