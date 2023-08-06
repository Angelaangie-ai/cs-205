#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QDateTime>
#include <QTextEdit>
#include "UserManagement/Headers/user.h"
#include "Database/Headers/database.h"
#include "Communication/Headers/chatmessage.h"
#include <unordered_map>
#include <QDebug>
#include "string"
using namespace std;

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT


public:
    explicit Chat(QWidget *parent = nullptr);
    void setupDropdown();
    void setupUserList();
    ~Chat();
    string currUserName;
signals:
    /**
     * @brief friendToHome
     * A signal that will be detected page stack object to switch current Widget from Friend to Home
     */
    void chatToHome();

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
     * @brief on_sendButton_clicked
     * A slot that is triggers by click to send user input to specified user.
     */
    void on_sendButton_clicked();

    /**
     * @brief on_retrieveButton_clicked
     * A slot that is triggers by click to refresh previous chat history with current logged in user
     */
    void on_retrieveButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Chat *ui;
    User* currentUser; // Store currentUser as a member variable
    std::map<std::string, QLabel*> messageLabels;
    std::map<std::string, QVBoxLayout*> userLayouts;
    Database* db;


};

#endif // CHAT_H
