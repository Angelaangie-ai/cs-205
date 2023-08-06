#ifndef EDUCATION_H
#define EDUCATION_H

#include <QWidget>
#include "Database/Headers/database.h"
#include "string"
using namespace std;

namespace Ui {
class Education;
}

class Education : public QWidget
{
    Q_OBJECT

public:
    explicit Education(QWidget *parent = nullptr);
    ~Education();
    void addEduPost(const std::string& title, const std::string& description,
                            const std::string& source, bool checkBox_general,
                               bool checkBox_specific);
    string currUserName;
signals:
    /**
     * @brief eduToHome
     * A signal that will be detected page stack object to switch current Widget from Education to Home
     */
    void eduToHome();

    /**
     * @brief homeToPref
     * A signal that will be detected page stack object to switch current Widget from Home to Preference
     */
    void eduToPref();

    /**
     * @brief homeToTrade
     * A signal that will be detected page stack object to switch current Widget from Home to Education
     */
    void eduToTrade();
    /**
     * @brief homeToFriends
     * A signal that will be detected page stack object to switch current Widget from Home to Friends
     */
    void eduToFriends();

    /**
     * @brief homeToChat
     * A signal that will be detected page stack object to switch current Widget from Home to Chat
     */
    void eduToChat();



private slots:
    /**
     * @brief on_eduToHome_button_clicked
     * A slot that is triggers by click to emit eduToHome() signal
     */
    void on_eduToHome_button_clicked();

    /**
     * @brief on_eduToHome_button_2_clicked
     * A slot that is triggers by click toemit eduToHome() signal.
     * (Second button is hidden where the logo is, so that user can go back to home by clicking logo)
     */
    void on_eduToHome_button_2_clicked();

    /**
     * @brief on_homePreference_button_clicked
     * A slot that is triggers by click to emit homeToPref() signal
     */
    void on_Pref_button_clicked();

    /**
     * @brief on_trade_button_clicked
     * A slot that is triggers by click to emit homeToTrade() signal
     */
    void on_trade_button_clicked();

    /**
     * @brief on_friend_button_clicked
     * A slot that is triggers by click to emit homeToFriend() signal
     */
    void on_friend_button_clicked();
    /**
     * @brief on_chat_button_clicked
     * A slot that is triggers by click to emit homeToChat();
     */
    void on_chat_button_clicked();

    /**
     * @brief on_addPost_button_clicked
     * A slot that is triggers by click to post a post on home screen.
     */
    void on_addPost_button_clicked();

    /**
     * @brief on_checkBox_generalKnowledge_stateChanged
     * @param arg1
     * A slot that is triggers by click to show all general knowledge tagged posts to the screen.
     */
    void on_checkBox_generalKnowledge_stateChanged(int arg1);

    /**
     * @brief on_checkBox_specificType_stateChanged
     * @param arg1
     * A slot that is triggers by click to show all specific knowledge tagged posts to the screen.
     */
    void on_checkBox_specificType_stateChanged(int arg1);

private:
    Ui::Education *ui;
    Database* db;


};

#endif // EDUCATION_H
