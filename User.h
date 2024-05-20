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
    // 用户的私有成员变量和其他私有函数
    string name;
    string username;
    string password;
};

#endif  // USER_H