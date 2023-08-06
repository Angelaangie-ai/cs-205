#include "userManagement/Headers/login.h"
#include "ui_login.h"
#include <iostream>
#include <string>

using namespace std;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->logWarning_label->hide();
    db = new Database();
}
/**
 * @brief Login::~Login
 * destructor.
 */
Login::~Login()
{
    delete ui;
}
/**
 * @brief Login::on_submit_button_clicked
 * checks if the user exists within a database
 * if not it prompts the error message, and lets user type again.
 */
void Login::on_submit_button_clicked()
{
    string userName = ui->logUser_input->text().toStdString();
    string pass = ui->logPass_input->text().toStdString();
    currUserName = userName;

    // prolly can use a sql command of exist to see if the specified user exists or not
     if(userName == "admin" && pass == "Buddies4eva")
    {
        emit toAdmin();
    }
    else if(db->userExist(userName) && db->passExist(pass)) // should pass this user info to home.
    {
        emit loginToMain();
    }
    else // CASE: when there is no existing user in database that the user typed.
    {
        // if the username/password is not correct
        ui->logWarning_label->show();
        ui->logUser_input->clear();
        ui->logPass_input->clear();
    }
}

/**
 * @brief Login::on_registration_button_clicked
 *  when the button gets clicked, it will mit signals that will make a transition of widget via pageStack.
 */
void Login::on_registration_button_clicked()
{
    emit toRegistration();
}
