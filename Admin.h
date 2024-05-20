#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <string>
using namespace std;

class Admin {
public:
    Admin(const string& username, const string& password);
    bool login(const string& username, const string& password);
    void addAdmin(const string& username, const string& password);
    void deleteAdmin(const string& username);
    void changePassword(const string& newPassword);
    void addDish(const string& dishName, const string& ingredients, const string& location, double price);
    void deleteDish(const string& dishName);
    void viewFeedback();

private:
    // 管理员的私有成员变量和其他私有函数...
    string username;
    string password;
};

#endif  // ADMIN_H
