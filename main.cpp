#include "Admin.h"
#include "User.h"
#include <iostream>
using namespace std;

int main() {
    int choice;
    string username, password;

    while (true) {
        cout << "====== 欢迎来到青岛校区食堂反馈系统 ======" << endl;
        cout << "=========== 1. 管理员登录 ================" << endl;
        cout << "=========== 2. 用户登录 ==================" << endl;
        cout << "=========== 3. 退出 ======================" << endl;
        cout << "======= 请输入您的选择: ";
        cin >> choice;

        if (choice == 1) {
            cout << "管理员登录" << endl;
            cout << "用户名: ";
            cin >> username;
            cout << "密码: ";
            cin >> password;

            // 创建管理员对象
            Admin admin(username, password);

            // 验证管理员登录
            if (admin.login(username, password)) {
                int adminChoice;
                while (true) {
                    cout << "====== 管理员菜单 ======" << endl;
                    cout << "1. 添加新的管理员" << endl;
                    cout << "2. 删除管理员" << endl;
                    cout << "3. 修改管理员密码" << endl;
                    cout << "4. 增加菜色" << endl;
                    cout << "5. 删除菜色" << endl;
                    cout << "6. 查看用户反馈" << endl;
                    cout << "7. 退出登录" << endl;
                    cout << "请输入您的选择: ";
                    cin >> adminChoice;

                    // 根据管理员选择执行相应的操作
                    switch (adminChoice) {
                    case 1:
                        // 添加新管理员
                        string newUsername, newPassword;
                        cout << "请输入新的管理员账号: ";
                        cin >> newUsername;
                        cout << "请输入新管理员的密码: ";
                        cin >> newPassword;
                        admin.addAdmin(newUsername, newPassword);
                        break;
                    case 2:
                        // 删除已有管理员
                        string deleteUsername;
                        cout << "请输入需要删除的管理员账号: ";
                        cin >> deleteUsername;
                        admin.deleteAdmin(deleteUsername);
                        break;
                    case 3:
                        // 修改管理员密码
                        string newPwd;
                        cout << "请输入新密码: ";
                        cin >> newPwd;
                        admin.changePassword(newPwd);
                        break;
                    case 4:
                        // 添加菜色
                        string dishName, ingredients, location;
                        double price;
                        cout << "请输入菜色名字: ";
                        cin.ignore();
                        getline(cin, dishName);
                        cout << "请输入原料: ";
                        getline(cin, ingredients);
                        cout << "请输入地点: ";
                        getline(cin, location);
                        cout << "请输入价格: ";
                        cin >> price;
                        admin.addDish(dishName, ingredients, location, price);
                        break;
                    case 5:
                        // 删除菜色
                        string deleteDishName;
                        cout << "请输入需要删除的菜色的名字: ";
                        cin.ignore();
                        getline(cin, deleteDishName);
                        admin.deleteDish(deleteDishName);
                        break;
                    case 6:
                        // 查看用户反馈
                        admin.viewFeedback();
                        break;
                    case 7:
                        // 退出登录
                        cout << "退出成功，欢迎下次登录" << endl;
                        break;
                    default:
                        cout << "无效的选择，请重新输入" << endl;
                        break;
                    }

                    if (adminChoice == 7) {
                        break;
                    }
                }
            }
            else {
                cout << "账号或密码错误，请重新输入" << endl;
            }
        }
        else if (choice == 2) {
            cout << "用户登录" << endl;
            cout << "用户账号: ";
            cin >> username;
            cout << "用户密码: ";
            cin >> password;

            // 创建用户对象
            User user(username, password);

            // 验证用户登录
            if (user.login(username, password)) {
                int userChoice;
                while (true) {
                    cout << "====== 用户菜单 ======" << endl;
                    cout << "1.查看所有菜色" << endl;
                    cout << "2. 搜索菜色" << endl;
                    cout << "3. 提交意见" << endl;
                    cout << "4. 退出" << endl;
                    cout << "请输入您的选择: ";
                    cin >> userChoice;

                    // 根据用户选择执行相应的操作
                    switch (userChoice) {
                    case 1:
                        // 查看所有菜色
                        user.viewAllDishes();
                        break;
                    case 2:
                        // 搜索菜色
                        string searchDishName;
                        cout << "请输入要搜索的菜色名: ";
                        cin.ignore();
                        getline(cin, searchDishName);
                        
                        user.searchDish(searchDishName);
                        break;
                    case 3:
                        // 提交意见
                        string feedback;
                        cout << "请输入您的宝贵意见: ";
                        cin.ignore();
                        getline(cin, feedback);
                        user.submitFeedback(feedback);
                        break;
                    case 4:
                        // 退出登录
                        cout << "退出成功，欢迎下次登录" << endl;
                        break;
                    default:
                        cout << "无效的选择，请重新输入" << endl;
                        break;
                    }

                    if (userChoice == 4) {
                        break;
                    }
                }
            }
            else {
                cout << "账号或密码错误，请重新输入" << endl;
            }
        }
        else if (choice == 3) {
            // 退出程序
            cout << "谢谢您使用山东大学青岛校区食堂反馈系统，欢迎下次使用" << endl;
            break;
        }
        else {
            cout << "无效的选择，请重新输入" << endl;
        }
    }

    return 0;
}