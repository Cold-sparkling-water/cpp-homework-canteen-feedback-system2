// Admin.cpp

#include "Admin.h"
#include <iostream>
#include <fstream>
using namespace std;

Admin::Admin(const string& username, const string& password) {
    // 构造函数的实现
    this->username = username;
    this->password = password;
}


//管理员登录
bool Admin::login(const string& username, const string& password) {
   
    if (this->username == username && this->password == password) {
        cout << "登录成功！" << endl;
        return true;
    }
    else {
        cout << "登录失败，请检查用户名和密码。" << endl;
        return false;
    }
}


//添加管理员
void Admin::addAdmin(const string& newUsername, const string& newPassword) {
    // 添加管理员函数的实现
    // 在admin.txt文件中添加新管理员的账号和密码信息
    ofstream file("admin.txt", ios::app);
    file << newUsername << " " << newPassword << endl;
    file.close();
    // 将新管理员的用户名和密码保存到数据库或其他数据结构中
    cout << "管理员 " << newUsername << " 添加成功！" << endl;
}

void Admin::deleteAdmin(const string& username) {
    // 删除管理员函数的实现...
    // 从admin.txt文件中删除指定管理员的账号和密码信息
    ifstream inputFile("admin.txt");
    ofstream outputFile("temp.txt");

    string line;
    while (getline(inputFile, line)) {
        string storedUsername, storedPassword;
        istringstream iss(line);

        if (iss >> storedUsername >> storedPassword) {
            if (storedUsername != username) {
                outputFile << line << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    remove("admin.txt");
    rename("temp.txt", "admin.txt");

    cout << "管理员 " << username << " 删除成功！" << endl;
}

void Admin::changePassword(const string& newPassword) {
    // 修改密码函数的实现...
    // 更新admin.txt文件中当前管理员的密码信息
    ifstream inputFile("admin.txt");
    ofstream outputFile("temp.txt");

    string line;
    while (getline(inputFile, line)) {
        string storedUsername, storedPassword;
        istringstream iss(line);
        if (iss >> storedUsername >> storedPassword) {
            if (storedUsername == username) {
                outputFile << storedUsername << " " << newPassword << endl;
            }
            else {
                outputFile << line << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    remove("admin.txt");
    rename("temp.txt", "admin.txt");// 更新admin.txt文件中当前管理员的密码信息
    ifstream inputFile("admin.txt");
    ofstream outputFile("temp.txt");

    string line;
    while (getline(inputFile, line)) {
        string storedUsername, storedPassword;
        istringstream iss(line);
        if (iss >> storedUsername >> storedPassword) {
            if (storedUsername == username) {
                outputFile << storedUsername << " " << newPassword << endl;
            }
            else {
                outputFile << line << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    remove("admin.txt");
    rename("temp.txt", "admin.txt");

    // 将新密码保存到数据库或其他数据结构中
    cout << "密码修改成功！" << endl;
}

void Admin::addDish(const string& dishName, const string& ingredients, const string& location, double price) {
    // 添加菜色函数的实现...
    // 在dishes.txt文件中添加新菜色的信息
    ofstream file("dishes.txt", ios::app);
    file << dishName << " " << ingredients << " " << location << " " << price << endl;
    file.close();
    // 将新菜色的信息保存到数据库或其他数据结构中
    cout << "菜色 " << dishName << " 添加成功！" << endl;
}

void Admin::deleteDish(const string& dishName) {
    // 删除菜色函数的实现...
    
   // 从dishes.txt文件中删除指定菜色的信息
    ifstream inputFile("dishes.txt");
    ofstream outputFile("temp.txt");

    string line;
    while (getline(inputFile, line))
    {
        string storedDishName, storedIngredients, storedLocation;
        double storedPrice;
        istringstream iss(line);

        if (iss >> storedDishName >> storedIngredients >> storedLocation >> storedPrice) {
            if (storedDishName != dishName) {
                outputFile << line << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    remove("dishes.txt");
    rename("temp.txt", "dishes.txt");
    // 从数据库或其他数据结构中删除指定菜色的信息
    cout << "菜色 " << dishName << " 删除成功！" << endl;
}

void Admin::viewFeedback() {
    // 查看用户反馈函数的实现...
    // 从数据库或其他数据结构中获取用户的反馈信息并显示
    cout << "以下是用户的反馈：" << endl;
    // 从comments.txt文件中读取并显示用户的反馈信息
    ifstream file("comments.txt");
    string comment;
    while (getline(file, comment)) {
        cout << comment << endl;
    }
    file.close();
}