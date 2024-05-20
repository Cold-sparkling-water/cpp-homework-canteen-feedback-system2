// User.cpp

#include "User.h"
#include <iostream>
#include <fstream>
using namespace std;

User::User(const string& username, const string& password) {
    // ���캯����ʵ��
    this->username = username;
    this->password = password;
}

bool User::login(const string& username, const string& password) {
    // ��¼������ʵ��
    if (username == "user" && password == "user123") {
        cout << "��¼�ɹ���" << endl;
        return true;
    }
    else {
        cout << "��¼ʧ�ܣ������û��������롣" << endl;
        return false;
    }
}

void User::viewAllDishes() {
    // �鿴���в�ɫ������ʵ��...
    // �����ݿ���������ݽṹ�л�ȡ���в�ɫ����Ϣ����ʾ
    cout << "���������в�ɫ��" << endl;
    // ��dishes.txt�ļ��ж�ȡ����ʾ���в�ɫ����Ϣ
    ifstream file("dishes.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void User::searchDish(const string& dishName) {
    // ������ɫ������ʵ��...
    // �ڲ˵����������������Ĳ�ɫ
    // ����˵��洢�� dishes ������
    bool found = false;

    for (const auto& dish : dishes) {
        if (dish.find(dishName) != string::npos) {
            cout << "�ҵ�ƥ��Ĳ�ɫ��" << dish << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "δ�ҵ�ƥ��Ĳ�ɫ��" << endl;
    }
    
    
}

void User::submitFeedback(const string& feedback) {
    // �ύ���������ʵ��...
    // ���û��ķ�����Ϣ���浽���ݿ���������ݽṹ��
    // ������������浽�ļ������ݿ���
    // ����ֻ�Ǽ�ʾ�������������д�� feedback.txt �ļ���
    ofstream outputFile("feedback.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << feedback << endl;
        outputFile.close();
        cout << "��������ύ�ɹ���" << endl;
    }
    else {
        cout << "�޷��򿪷����ļ���" << endl;
    }
    cout << "��л���ķ�����" << endl;
}