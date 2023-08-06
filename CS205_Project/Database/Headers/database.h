#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "QVariant"
#include "QSqlRecord"
#include "string"
#include "userManagement/Headers/user.h"
#include "Communication/Headers/chatmessage.h"
#include "postManipulation/Headers/post.h"
#include "box.h"
#include "postManipulation/Headers/postwidget.h"
#include "profile.h"
#include "profilewidget.h"
#include <vector>

using namespace std;

class Database
{
public:
    Database();


    void addItemforUser();
    vector<chatMessage> getMessages(string currUserName);
    std::vector<std::string> getAllItems();
    void setItemsForUser(const std::string& username);
    int getItemsForUser(const std::string& username);

    bool                        userExist(string);
    bool                        friendExist(string);
    bool                        passExist(string);
    void                        changePref(User*);
    void                        addPost(const Post& post);
    void                        addMessage(const chatMessage& message);
    void                        addUser(User*);
    void                        banUser(string);
    void                        changePref(Box);
    void                        addFriend(Profile& profile);
    void                        addEduPost(const Post& post);
    void                        addTradePost(const Post& post);
    void                        deletePref(string);
    User*                       getUser(string);
    const QSqlQuery             *result();
    QString                     getName(string name);
    std::vector<std::string>    getAllUsernames();
    void                        getMessagesForUser(string username);



    QSqlQuery                   query;
    User*                       user;
    QSqlDatabase                db;

};

#endif // DATABASE_H
