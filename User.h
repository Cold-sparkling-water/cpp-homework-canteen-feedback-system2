#pragma once
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    User(const string& username, const string& password);
    bool login(const string& username, const string& password);
    void viewAllDishes();
    void searchDish(const string& dishName);
    void submitFeedback(const string& feedback);

private:
    // �û���˽�г�Ա����������˽�к���
    string name;
    string username;
    string password;
};

#endif  // USER_H