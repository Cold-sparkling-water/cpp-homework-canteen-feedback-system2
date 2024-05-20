// User.cpp

#include "User.h"
#include <iostream>
#include <fstream>
using namespace std;

User::User(const string& username, const string& password) {
    // 构造函数的实现
    this->username = username;
    this->password = password;
}

bool User::login(const string& username, const string& password) {
    // 登录函数的实现
    if (username == "user" && password == "user123") {
        cout << "登录成功！" << endl;
        return true;
    }
    else {
        cout << "登录失败，请检查用户名和密码。" << endl;
        return false;
    }
}

void User::viewAllDishes() {
    // 查看所有菜色函数的实现...
    // 从数据库或其他数据结构中获取所有菜色的信息并显示
    cout << "以下是所有菜色：" << endl;
    // 从dishes.txt文件中读取并显示所有菜色的信息
    ifstream file("dishes.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void User::searchDish(const string& dishName) {
    // 搜索菜色函数的实现...
    // 在菜单中搜索包含菜名的菜色
    // 假设菜单存储在 dishes 容器中
    bool found = false;

    for (const auto& dish : dishes) {
        if (dish.find(dishName) != string::npos) {
            cout << "找到匹配的菜色：" << dish << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "未找到匹配的菜色。" << endl;
    }
    
    
}

void User::submitFeedback(const string& feedback) {
    // 提交意见函数的实现...
    // 将用户的反馈信息保存到数据库或其他数据结构中
    // 将意见反馈保存到文件或数据库中
    // 这里只是简单示例，将意见反馈写入 feedback.txt 文件中
    ofstream outputFile("feedback.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << feedback << endl;
        outputFile.close();
        cout << "意见反馈提交成功！" << endl;
    }
    else {
        cout << "无法打开反馈文件。" << endl;
    }
    cout << "感谢您的反馈！" << endl;
}