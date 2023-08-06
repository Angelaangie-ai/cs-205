#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <ctime>
#include <string>
#include <iostream>
#include <QWidget>
#include "Database/Headers/database.h"
#include "user.h"

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();
    string currUserName;
    User* user;
signals:
    /**
     * @brief toPreference
     * A signal that will be detected page stack object to switch current Widget from Registration to Home
     */
    void toPreference();

private slots:

    /**
     * @brief on_submit_Button_clicked
     * this button gets clicked when a user wants to submit their preferences are.
     */
    void on_submit_Button_clicked();

private:
    Ui::Registration *ui;
    Database* db;
};

#endif // REGISTRATION_H
