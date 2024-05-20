// Admin.cpp

#include "Admin.h"
#include <iostream>
#include <fstream>
using namespace std;

Admin::Admin(const string& username, const string& password) {
    // ���캯����ʵ��
    this->username = username;
    this->password = password;
}


//����Ա��¼
bool Admin::login(const string& username, const string& password) {
   
    if (this->username == username && this->password == password) {
        cout << "��¼�ɹ���" << endl;
        return true;
    }
    else {
        cout << "��¼ʧ�ܣ������û��������롣" << endl;
        return false;
    }
}


//��ӹ���Ա
void Admin::addAdmin(const string& newUsername, const string& newPassword) {
    // ��ӹ���Ա������ʵ��
    // ��admin.txt�ļ�������¹���Ա���˺ź�������Ϣ
    ofstream file("admin.txt", ios::app);
    file << newUsername << " " << newPassword << endl;
    file.close();
    // ���¹���Ա���û��������뱣�浽���ݿ���������ݽṹ��
    cout << "����Ա " << newUsername << " ��ӳɹ���" << endl;
}

void Admin::deleteAdmin(const string& username) {
    // ɾ������Ա������ʵ��...
    // ��admin.txt�ļ���ɾ��ָ������Ա���˺ź�������Ϣ
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

    cout << "����Ա " << username << " ɾ���ɹ���" << endl;
}

void Admin::changePassword(const string& newPassword) {
    // �޸����뺯����ʵ��...
    // ����admin.txt�ļ��е�ǰ����Ա��������Ϣ
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
    rename("temp.txt", "admin.txt");// ����admin.txt�ļ��е�ǰ����Ա��������Ϣ
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

    // �������뱣�浽���ݿ���������ݽṹ��
    cout << "�����޸ĳɹ���" << endl;
}

void Admin::addDish(const string& dishName, const string& ingredients, const string& location, double price) {
    // ��Ӳ�ɫ������ʵ��...
    // ��dishes.txt�ļ�������²�ɫ����Ϣ
    ofstream file("dishes.txt", ios::app);
    file << dishName << " " << ingredients << " " << location << " " << price << endl;
    file.close();
    // ���²�ɫ����Ϣ���浽���ݿ���������ݽṹ��
    cout << "��ɫ " << dishName << " ��ӳɹ���" << endl;
}

void Admin::deleteDish(const string& dishName) {
    // ɾ����ɫ������ʵ��...
    
   // ��dishes.txt�ļ���ɾ��ָ����ɫ����Ϣ
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
    // �����ݿ���������ݽṹ��ɾ��ָ����ɫ����Ϣ
    cout << "��ɫ " << dishName << " ɾ���ɹ���" << endl;
}

void Admin::viewFeedback() {
    // �鿴�û�����������ʵ��...
    // �����ݿ���������ݽṹ�л�ȡ�û��ķ�����Ϣ����ʾ
    cout << "�������û��ķ�����" << endl;
    // ��comments.txt�ļ��ж�ȡ����ʾ�û��ķ�����Ϣ
    ifstream file("comments.txt");
    string comment;
    while (getline(file, comment)) {
        cout << comment << endl;
    }
    file.close();
}