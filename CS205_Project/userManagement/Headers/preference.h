#ifndef PREFERENCE_H
#define PREFERENCE_H
#include "userManagement/Headers/user.h"
#include "box.h"
#include "Database/Headers/database.h"
#include <QWidget>
#include <string>
#include <iostream>
#include <ctime>

namespace Ui {
class Preference;
}

class Preference : public QWidget
{
    Q_OBJECT
public:
    explicit Preference(QWidget *parent = nullptr);
    ~Preference();
    string currUserName;
signals:
    /**
     * @brief prefToMain
     * A signal that will be detected page stack object to switch current Widget from Preference to Home
     */
    void prefToMain();

private slots:
    /**
     * @brief on_prefSubmit_button_clicked
     * this is a slot to submit thier user preference.
     */
    void on_prefSubmit_button_clicked();

private:
    Ui::Preference *ui;
    Database* db;
};

#endif // PREFERENCE_H
