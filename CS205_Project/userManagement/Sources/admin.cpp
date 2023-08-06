#include "userManagement/Headers/admin.h"
#include "ui_admin.h"
#include <string>
using namespace std;

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->adminWarning_label->hide();
}

Admin::~Admin()
{
    delete ui;
}

/**
 * @brief Admin::on_adminSubmit_button_clicked
 * Function to ban a user from the platform by typing their username.
 */
void Admin::on_adminSubmit_button_clicked()
{
    string bannedUser = ui->admin_input->text().toStdString();
    ui->adminWarning_label->hide();
    if(!db->userExist(bannedUser))
    {
        ui->adminWarning_label->show();
    }
    ui->admin_input->clear();
    db->banUser(bannedUser);
}

/**
 * @brief Admin::on_adminToHome_button_clicked
 * function to go ot home screen
 */
void Admin::on_adminToHome_button_clicked()
{
    emit adminToHome();
}

