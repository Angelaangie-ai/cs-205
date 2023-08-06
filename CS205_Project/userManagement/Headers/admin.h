#ifndef ADMIN_H
#define ADMIN_H
#include "Database/Headers/database.h"
#include <QWidget>

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
signals:
    /**
     * @brief adminToHome
     * A signal that will be detected page stack object to switch current Widget from admin to Home
     */
    void adminToHome();

private slots:
    /**
     * @brief on_adminSubmit_button_clicked
     * A slot that is triggers by click to execute banning user from Database.
     */
    void on_adminSubmit_button_clicked();

    /**
     * @brief on_adminToHome_button_clicked
     * A slot that is triggers by click to emit adminToHome() signal.
     */
    void on_adminToHome_button_clicked();

private:
    Ui::Admin *ui;
    Database* db;
};

#endif // ADMIN_H
