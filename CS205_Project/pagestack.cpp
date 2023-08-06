#include "pagestack.h"

PageStack::PageStack()
{
    s = new QStackedWidget();
    r = new Registration();
    l = new Login();
    p = new Preference();
    h = new Home();
    e = new Education();
    t = new Trade();
    a = new Admin();
    f = new Friends();
    m = new Chat();

    s->addWidget(r);
    s->addWidget(l);
    s->addWidget(p);
    s->addWidget(h);
    s->addWidget(e);
    s->addWidget(t);
    s->addWidget(a);
    s->addWidget(f);
    s->addWidget(m);
    s->setCurrentWidget(l);
    connection();
}
/**
 * @brief PageStack::loginToMain
 * A function to switch a current widget to main from login
 */
void PageStack::loginToMain()
{
    // should pass the information of user that gets from the login objects )
    h->currUserName = l->currUserName;
    s->setCurrentWidget(h);
}

/**
 * @brief PageStack::toRegistration
 * A function to switch a current widget to registration from login
 */
void PageStack::toRegistration()
{
    s->setCurrentWidget(r);
}

/**
 * @brief PageStack::toPreference
 * A function to switch a current widget to preference from registration
 */
void PageStack::toPreference()
{
    p->currUserName = r->currUserName;
    m->currUserName = r->currUserName;
    s->setCurrentWidget(p);
}

/**
 * @brief PageStack::prefToMain
 * A function to switch a current widget to main from preference
 */
void PageStack::prefToMain()
{
    p->currUserName = h->currUserName;
    s->setCurrentWidget(h);
}

/**
 * @brief PageStack::homeToPref
 * A function to switch a current widget home to preference
 */
void PageStack::homeToPref()
{
    delete p;
    p = new Preference();
    s->removeWidget(p);
    s->addWidget(p);
    connection();
    p->currUserName = h->currUserName;
    s->setCurrentWidget(p);
}

/**
 * @brief PageStack::homeToEdu
 * A function to switch a current widget home to education
 */
void PageStack::homeToEdu()
{
    e->currUserName = h->currUserName;
    s->setCurrentWidget(e);
}

/**
 * @brief PageStack::homeToTrade
 * A function to switch current widget home to trade
 */
void PageStack::homeToTrade()
{
    t->currUserName = h->currUserName;
    s->setCurrentWidget(t);
}

/**
 * @brief PageStack::homeToFriends
 * A function to switch current widget home to friend
 */
void PageStack::homeToFriends()
{
    //f->currUserName = h->currUserName;
    s->setCurrentWidget(f);
}

/**
 * @brief PageStack::homeToChat
 * A function to switch current widget home to Chat
 */
void PageStack::homeToChat()
{
    m->currUserName = h->currUserName;
    s->setCurrentWidget(m);
}

/**
 * @brief PageStack::eduToHome
 * A function to switch current widget home to education
 */
void PageStack::eduToHome()
{
    s->setCurrentWidget(h);
}

/**
 * @brief PageStack::eduToPref
 * A function to switch a current widget education to preference
 */
void PageStack::eduToPref()
{
    delete p;
    p = new Preference();
    s->removeWidget(p);
    s->addWidget(p);
    connection();
    p->currUserName = h->currUserName;
    s->setCurrentWidget(p);
}

/**
 * @brief PageStack::eduToTrade
 * A function to switch current widget edu to trade
 */
void PageStack::eduToTrade()
{
    t->currUserName = h->currUserName;
    s->setCurrentWidget(t);
}

/**
 * @brief PageStack::eduToFriends
 * A function to switch current widget education to friend
 */
void PageStack::eduToFriends()
{
    s->setCurrentWidget(f);
}

/**
 * @brief PageStack::tradeToHome
 * A function to switch current widget trade to home
 */
void PageStack::tradeToHome()
{
    s->setCurrentWidget(h);
}

/**
 * @brief PageStack::FriendsToHome
 * A function to switch current widget friend to home
 */
void PageStack::friendToHome()
{
    s->setCurrentWidget(h);
}

/**
 * @brief PageStack::FriendsToHome
 * A function to switch current widget friend to home
 */
void PageStack::chatToHome()
{
    s->setCurrentWidget(h);

    //m->currUserName = h->currUserName;
    //s->setCurrentWidget(m);
}

/**
 * @brief PageStack::toAdmin
 * A function to switch current widget login to admin
 */
void PageStack::toAdmin()
{
    s->setCurrentWidget(a);
}

/**
 * @brief PageStack::adminToHome
 * A function to switch current widget login to admin
 */
void PageStack::adminToHome()
{
    connection();
    s->setCurrentWidget(h);
}




/**
 * @brief PageStack::connection
 * A function to build a connection between two widgets using signals ans slots.
 * This connection function controlls all the transition for widgets.
 */
void PageStack::connection()
{

    connect(l, SIGNAL(loginToMain()),    this, SLOT(loginToMain()));
    connect(l, SIGNAL(toRegistration()), this, SLOT(toRegistration()));
    connect(l, SIGNAL(toAdmin()),        this, SLOT(toAdmin()));

    connect(r, SIGNAL(toPreference()),   this, SLOT(toPreference()));
    connect(p, SIGNAL(prefToMain()),     this, SLOT(prefToMain()));    
    connect(a, SIGNAL(adminToHome()),    this, SLOT(adminToHome()));


    connect(h, SIGNAL(homeToPref()),     this, SLOT(homeToPref()));
    connect(h, SIGNAL(homeToEdu()),      this, SLOT(homeToEdu()));
    connect(h, SIGNAL(homeToTrade()),    this, SLOT(homeToTrade()));
    connect(h, SIGNAL(homeToFriends()),  this, SLOT(homeToFriends()));
    connect(h, SIGNAL(homeToChat()),     this, SLOT(homeToChat()));



    connect(e, SIGNAL(eduToHome()),      this, SLOT(eduToHome()));



    connect(t, SIGNAL(tradeToHome()),    this, SLOT(tradeToHome()));


    connect(f, SIGNAL(friendToHome()),   this, SLOT(friendToHome()));

    connect(m, SIGNAL(chatToHome()),     this, SLOT(chatToHome()));



}
