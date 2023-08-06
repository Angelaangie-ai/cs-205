#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "registration.h"
#include "Database/Headers/database.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    //deconstructor
    ~Login();
    string currUserName;
signals:
    /**
     * @brief toRegistration
     * A signal that will be detected page stack object to switch current Widget from Login to Registration
     */
    void toRegistration();

    /**
     * @brief loginToMain
     * A signal that will be detected page stack object to switch current Widget from Login to Home
     */
    void loginToMain();

    /**
     * @brief toAdmin
     * A signal that will be detected page stack object to switch current Widget from Login to Admin
     */
    void toAdmin();

private slots:
    /**
     * @brief on_submit_button_clicked
     * A slot that is triggered by click to verify the user name and password matches to the user on the database
     */
    void on_submit_button_clicked();

    /**
     * @brief on_registration_button_clicked
     * A slot that is triggered by click to emit loginToRegistration() signal
     */
    void on_registration_button_clicked();


private:
    Ui::Login *ui;
    Database* db;
};

#endif // LOGIN_H
