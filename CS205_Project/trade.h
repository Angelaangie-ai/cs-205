#ifndef TRADE_H
#define TRADE_H

#include <QWidget>
#include <vector>
#include "Database/Headers/database.h"
#include "string"
using namespace std;

namespace Ui {
class Trade;
}

class Trade : public QWidget
{
    Q_OBJECT

public:
    explicit Trade(QWidget *parent = nullptr);
    ~Trade();
    string currUserName;
signals:
    /**
     * @brief tradeToHome
     * A signal that will be detected page stack object to switch current Widget from Trade to Home
     */
    void tradeToHome();

private slots:
    /**
     * @brief on_tradeToHome_button_clicked
     * this button gets clicked when a user would like to go back to home screen
     */
    void on_tradeToHome_button_clicked();

    /**
     * @brief on_pushButton_2_clicked
     * this button gets clicked when a user would like to go back to home screen
     * This is hidden to fish logo, so that when a user click the logo it will go to home screen as well.
     */
    void on_pushButton_2_clicked();
    void populateList();

    void on_pushButton_clicked();

private:
    Ui::Trade *ui;
    Database* db;
    int totalTrades;

};

#endif // TRADE_H
