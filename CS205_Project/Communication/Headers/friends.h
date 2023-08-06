#ifndef FRIENDS_H
#define FRIENDS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QSqlQueryModel>
#include "Database/Headers/database.h"
#include "profile.h"
#include "string.h"
#include "userManagement/Headers/login.h"


namespace Ui {
class Friends;
}

class Friends : public QWidget
{
    Q_OBJECT

public:
    explicit Friends(QWidget *parent = nullptr);
    ~Friends();

    void addFriend(const std::string& userName);
signals:
    /**
     * @brief friendToHome
     * A signal that will be detected page stack object to switch current Widget from Friend to Home
     */
    void friendToHome();

private slots:
    /**
     * @brief on_button_clicked
     * A slot that is triggers by click to emit friendToHome() signal
     */
    void on_button_clicked();

    /**
     * @brief on_button_2_clicked
     * A slot that is triggers by click to emit friendToHome() signal
     * (Second button is hidden where the logo is, so that user can go back to home by clicking logo)
     */
    void on_button_2_clicked();

    /**
     * @brief on_nextUser_button_clicked
     * A slot that is triggers by click to add specified user name friend to your friend list
     */
    void on_nextUser_button_clicked();

    /**
     * @brief on_load_list_clicked
     * A slot that is triggers by click to show possible friends who are on the platform
     */
    void on_load_list_clicked();


    void on_pushButton_clicked();

private:
    Ui::Friends *ui;
    Database* data;
    Login login;
};

#endif // FRIENDS_H
