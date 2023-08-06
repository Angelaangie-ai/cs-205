#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "home.h"
#include "postManipulation/Headers/post.h"
#include "Database/Headers/database.h"


namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();
    /**
     * @brief addPost
     * @param title
     * @param body
     * @param tag
     */
    void addPost(const std::string& title, const std::string& body,
                 bool checkBox_fresh, bool checkBox_salt,
                 bool checkBox_bigTank, bool checkBox_smallTank);

    int nextPostId; // Define nextPostId with an initial value of 0
    string currUserName;



signals:
    /**
     * @brief homeToPref
     * A signal that will be detected page stack object to switch current Widget from Home to Preference
     */
    void homeToPref();
    /**
     * @brief homeToEdu
     * A signal that will be detected page stack object to switch current Widget from Home to Preference
     */
    void homeToEdu();
    /**
     * @brief homeToTrade
     * A signal that will be detected page stack object to switch current Widget from Home to Education
     */
    void homeToTrade();   
    /**
     * @brief homeToFriends
     * A signal that will be detected page stack object to switch current Widget from Home to Friends
     */
    void homeToFriends();

    /**
     * @brief homeToChat
     * A signal that will be detected page stack object to switch current Widget from Home to Chat
     */
    void homeToChat();


private slots:
    /**
     * @brief on_homePreference_button_clicked
     * A slot that is triggers by click to emit homeToPref() signal
     */
    void on_homePreference_button_clicked();

    /**
     * @brief on_edu_button_clicked
     * A slot that is triggers by click to emit homeToEdu() signal
     */
    void on_edu_button_clicked();

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
     * @brief on_addPost_button_clicked
     * A slot that is triggers by click to add a post to the homescreen.
     */
    void on_addPost_button_clicked();

    /**
     * @brief on_checkBox_saltWater_stateChanged
     * @param arg1
     * A slot that is triggers by click to check the state of check box to figure out what type of posts to be shown on a screen
     */
    void on_checkBox_saltWater_stateChanged(int arg1);

    /**
     * @brief on_checkBox_smallTanks_stateChanged
     * @param arg1
     * A slot that is triggers by click to check the state of check box to figure out what type of posts to be shown on a screen
     */
    void on_checkBox_smallTanks_stateChanged(int arg1);

    /**
     * @brief on_checkBox_freshWater_stateChanged
     * @param arg1
     * A slot that is triggers by click to check the state of check box to figure out what type of posts to be shown on a screen
     */
    void on_checkBox_freshWater_stateChanged(int arg1);

    /**
     * @brief on_checkBox_bigTanks_stateChanged
     * @param arg1
     * A slot that is triggers by click to check the state of check box to figure out what type of posts to be shown on a screen
     */
    void on_checkBox_bigTanks_stateChanged(int arg1);

    /**
     * @brief on_chat_button_clicked
     * A slot that is triggers by click to emit homeToChat();
     */
    void on_chat_button_clicked();

private:
    Ui::Home *ui;
    std::vector<Post> posts;
    Database* db;
    int lastPostId = 0;
};

#endif // HOME_H
