#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <iostream>
#include "struct.h"
using namespace std;

int doLogin(User *headUser, User *tailUser)
{
    int statusUser = 0;
    string username, password;
    cout<<"Login : "<<endl;
    cout<<"Username : ";
    cin>>username;
    cout<<"Password : ";
    cin>>password;
    User *curr = headUser->next;
    while(curr != tailUser)
    {
        if(username != curr->username)
        {
            statusUser = 0;
            return statusUser;
        }

        if(username == curr->username)
        {
            if(password == curr->password)
            {
                statusUser = curr->privilage;
            }

            if(password != curr->password)
            {
                statusUser = 3;
            }

            return statusUser;
            break;

        }

        curr = curr->next;
    }
}

int login(User *headUser, User *tailUser)
{
    int statusUser;
    do
    {
        int isLogin = doLogin(headUser,tailUser);
        if(isLogin == 0)
        {
            statusUser = 0;
            cout << "User tidak ditemukan !"<<endl;
        }

        if(isLogin == 3)
        {
            statusUser = 3;
            cout << "Password salah !"<<endl;
        }

        if(isLogin == 1 || isLogin == 2)
        {
            statusUser = isLogin;
            return statusUser;
            break;
        }
    }
    while(true);
}

#endif // LOGIN_H_INCLUDED
