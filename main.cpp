#include "Admin.h"
#include "User.h"
#include <iostream>
using namespace std;

int main() {
    int choice;
    string username, password;

    while (true) {
        cout << "====== ��ӭ�����ൺУ��ʳ�÷���ϵͳ ======" << endl;
        cout << "=========== 1. ����Ա��¼ ================" << endl;
        cout << "=========== 2. �û���¼ ==================" << endl;
        cout << "=========== 3. �˳� ======================" << endl;
        cout << "======= ����������ѡ��: ";
        cin >> choice;

        if (choice == 1) {
            cout << "����Ա��¼" << endl;
            cout << "�û���: ";
            cin >> username;
            cout << "����: ";
            cin >> password;

            // ��������Ա����
            Admin admin(username, password);

            // ��֤����Ա��¼
            if (admin.login(username, password)) {
                int adminChoice;
                while (true) {
                    cout << "====== ����Ա�˵� ======" << endl;
                    cout << "1. ����µĹ���Ա" << endl;
                    cout << "2. ɾ������Ա" << endl;
                    cout << "3. �޸Ĺ���Ա����" << endl;
                    cout << "4. ���Ӳ�ɫ" << endl;
                    cout << "5. ɾ����ɫ" << endl;
                    cout << "6. �鿴�û�����" << endl;
                    cout << "7. �˳���¼" << endl;
                    cout << "����������ѡ��: ";
                    cin >> adminChoice;

                    // ���ݹ���Աѡ��ִ����Ӧ�Ĳ���
                    switch (adminChoice) {
                    case 1:
                        // ����¹���Ա
                        string newUsername, newPassword;
                        cout << "�������µĹ���Ա�˺�: ";
                        cin >> newUsername;
                        cout << "�������¹���Ա������: ";
                        cin >> newPassword;
                        admin.addAdmin(newUsername, newPassword);
                        break;
                    case 2:
                        // ɾ�����й���Ա
                        string deleteUsername;
                        cout << "��������Ҫɾ���Ĺ���Ա�˺�: ";
                        cin >> deleteUsername;
                        admin.deleteAdmin(deleteUsername);
                        break;
                    case 3:
                        // �޸Ĺ���Ա����
                        string newPwd;
                        cout << "������������: ";
                        cin >> newPwd;
                        admin.changePassword(newPwd);
                        break;
                    case 4:
                        // ��Ӳ�ɫ
                        string dishName, ingredients, location;
                        double price;
                        cout << "�������ɫ����: ";
                        cin.ignore();
                        getline(cin, dishName);
                        cout << "������ԭ��: ";
                        getline(cin, ingredients);
                        cout << "������ص�: ";
                        getline(cin, location);
                        cout << "������۸�: ";
                        cin >> price;
                        admin.addDish(dishName, ingredients, location, price);
                        break;
                    case 5:
                        // ɾ����ɫ
                        string deleteDishName;
                        cout << "��������Ҫɾ���Ĳ�ɫ������: ";
                        cin.ignore();
                        getline(cin, deleteDishName);
                        admin.deleteDish(deleteDishName);
                        break;
                    case 6:
                        // �鿴�û�����
                        admin.viewFeedback();
                        break;
                    case 7:
                        // �˳���¼
                        cout << "�˳��ɹ�����ӭ�´ε�¼" << endl;
                        break;
                    default:
                        cout << "��Ч��ѡ������������" << endl;
                        break;
                    }

                    if (adminChoice == 7) {
                        break;
                    }
                }
            }
            else {
                cout << "�˺Ż������������������" << endl;
            }
        }
        else if (choice == 2) {
            cout << "�û���¼" << endl;
            cout << "�û��˺�: ";
            cin >> username;
            cout << "�û�����: ";
            cin >> password;

            // �����û�����
            User user(username, password);

            // ��֤�û���¼
            if (user.login(username, password)) {
                int userChoice;
                while (true) {
                    cout << "====== �û��˵� ======" << endl;
                    cout << "1.�鿴���в�ɫ" << endl;
                    cout << "2. ������ɫ" << endl;
                    cout << "3. �ύ���" << endl;
                    cout << "4. �˳�" << endl;
                    cout << "����������ѡ��: ";
                    cin >> userChoice;

                    // �����û�ѡ��ִ����Ӧ�Ĳ���
                    switch (userChoice) {
                    case 1:
                        // �鿴���в�ɫ
                        user.viewAllDishes();
                        break;
                    case 2:
                        // ������ɫ
                        string searchDishName;
                        cout << "������Ҫ�����Ĳ�ɫ��: ";
                        cin.ignore();
                        getline(cin, searchDishName);
                        
                        user.searchDish(searchDishName);
                        break;
                    case 3:
                        // �ύ���
                        string feedback;
                        cout << "���������ı������: ";
                        cin.ignore();
                        getline(cin, feedback);
                        user.submitFeedback(feedback);
                        break;
                    case 4:
                        // �˳���¼
                        cout << "�˳��ɹ�����ӭ�´ε�¼" << endl;
                        break;
                    default:
                        cout << "��Ч��ѡ������������" << endl;
                        break;
                    }

                    if (userChoice == 4) {
                        break;
                    }
                }
            }
            else {
                cout << "�˺Ż������������������" << endl;
            }
        }
        else if (choice == 3) {
            // �˳�����
            cout << "лл��ʹ��ɽ����ѧ�ൺУ��ʳ�÷���ϵͳ����ӭ�´�ʹ��" << endl;
            break;
        }
        else {
            cout << "��Ч��ѡ������������" << endl;
        }
    }

    return 0;
}