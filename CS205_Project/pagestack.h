#ifndef PAGESTACK_H
#define PAGESTACK_H
#include "userManagement/Headers/registration.h"
#include "userManagement/Headers/login.h"
#include "userManagement/Headers/preference.h"
#include "Screens/Headers/home.h"
#include "Screens/Headers/education.h"
#include "trade.h"
#include "Communication/Headers/chat.h"
#include "UserManagement/Headers/admin.h"
#include "Communication/Headers/friends.h"
#include <QObject>
#include <QWidget>
#include <QStackedWidget>


class PageStack : public QObject
{
    Q_OBJECT
public:
    PageStack();
    Login* l;
    Registration* r;
    Preference* p;
    QStackedWidget* s;
    Home* h;
    Education* e;
    Trade* t;
    Admin* a;
    Friends* f;
    Chat* m;
    void connection();

public slots:
    /**
     * @brief toRegistration
     * A slot that is triggered by click to switch current Widget from Login to Registration
     */
    void toRegistration();

    /**
     * @brief toPreference
     * A slot that is triggered by click to switch current Widget from Registration to Preference
     */
    void toPreference();

    /**
     * @brief prefToMain
     * A slot that is triggered by click to switch current Widget from Preference to Home
     */
    void prefToMain();

    /**
     * @brief loginToMain
     * A slot that is triggered by click to switch current Widget from Login to Home
     */
    void loginToMain();

    /**
     * @brief homeToPref
     * A slot that is triggered by click to switch current Widget from Home to Preference
     */
    void homeToPref();

    /**
     * @brief homeToEdu
     * A slot that is triggered by click to switch current Widget from Home to Education
     */
    void homeToEdu();
    /**
     * @brief homeToTrade
     * A slot that is triggered by click to switch current Widget from Home to Trade
     */
    void homeToTrade();

    /**
     * @brief homeToFriends
     * A slot that is triggered by click to switch current Widget from Home to Friends
     */
    void homeToFriends();

    /**
     * @brief eduToHome
     * A slot that is triggered by click to switch current Widget from Education to Home
     */
    void eduToHome();
    /**
     * @brief eduToPref
     * A slot that is triggered by click to switch current Widget from Education to Preference
     */
    void eduToPref();

    /**
     * @brief eduToTrade
     * A slot that is triggered by click to switch current Widget from Education to Trade
     */
    void eduToTrade();

    /**
     * @brief eduToFriends
     * A slot that is triggered by click to switch current Widget from Education to Friends
     */
    void eduToFriends();
    /**
     * @brief tradeToHome
     * A slot that is triggered by click to switch current Widget from Trade to Home
     */
    void tradeToHome();

    /**
     * @brief friendToHome
     * A slot that is triggered by click to switch current Widget from Friends to Home
     */
    void friendToHome();

    /**
     * @brief chatToHome
     * A slot that is triggered by click to switch current Widget from Chat to Home
     */
    void chatToHome();

    /**
     * @brief toAdmin
     * A slot that is triggered by click to switch current Widget from Login to Admin
     */
    void toAdmin();

    /**
     * @brief adminToHome
     * A slot that is triggered by click to switch current Widget from Admin to Home
     */
    void adminToHome();

    /**
     * @brief homeToChat
     * A slot that is triggered by click to switch current Widget from Home to Chat
     */
    void homeToChat();

};

#endif // PAGESTACK_H
