#include "database.h"
#include "box.h"
#include <fstream>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <string>
#include "vector"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "QDateTime"
#include "Communication/Headers/chatmessage.h"

using namespace std;

/**
 * @brief Database::Database
 * Opens up database using specified command that is connected to the build tables.
 * Available tables are below:
 * 1) achievements
 * 2) friends
 * 3) communicate
 * 4) trade
 * 5) post_manip
 * 6) education_post
 */
Database::Database()
{
    QString path("../UserDB/userDB.sqlite");


    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(path);
    // verify the database opened
    if (!db.open())
    {
        std::cout << "Error: connection with database fail" << std::endl;
        exit(1);
    }
    else
    {
        std::cout << "Database: connection ok" << std::endl;
    }

}

/**
 * @brief Database::getName
 * @param name
 * @return
 * Getter function for first name by using given user name
 */
QString Database::getName(string name)
{
    // Create a query object to the database
    QSqlQuery query(db);

    // Establish the SQL command
    QString sqlcmd = "SELECT * FROM user WHERE User_name = \"";
    QString str = QString::fromStdString(name) + "\";";
    sqlcmd.append(str);

    // Execute the provided SQL call
    if (query.exec(sqlcmd) == false)
    {
        QSqlError err = query.lastError();
        std::cout << "Query failed with error: " << err.text().toStdString() << std::endl;
    }

    // Retrieve the first name of the user
    QString firstName;
    if (query.next())
    {
        firstName = query.value(1).toString(); // Assuming the first name is stored in the second column
    }

    return firstName;
}

/**
 * @brief Database::userExist
 * @param name
 * @return
 * A function to go through the database to see if a given userName user is already existed on a database or not.
 */
bool Database::userExist(string name)
{

    // establish the sql command
    QSqlQuery query;

    QString sqlcmd = "select * from user where User_name = \"";
    QString str = QString::fromStdString(name) + "\";";
    sqlcmd.append(str);

    // execute the provided sql call
    if (query.exec(sqlcmd) == false)
    {
        QSqlError err = query.lastError();
        std::cout << "Query failed with error: " << err.text().toStdString() << std::endl;
    }

    // iterate through each returned item
    int numRows;
    while (query.next())
    {
        QString title = query.value(0).toString();
        std::cout << title.toStdString() << "  " << std::endl;
    }

    // determine number of rows
    query.last();
    numRows = query.at() + 1;

    if(numRows > 0) return true;
    else return false;
}

/**
 * @brief Database::passExist
 * @param pass
 * @return
 * A function to go through the database to see if a given passWord is already existed on a database or not.
 */
bool Database::passExist(string pass)
{
    QSqlQuery query(db);

    QString sqlcmd = "select * from user where Password = \"";
    QString str = QString::fromStdString(pass) + "\";";
    sqlcmd.append(str);

    // establish the sql command

    // execute the provided sql call
    if (query.exec(sqlcmd) == false)
    {
        QSqlError err = query.lastError();
        std::cout << "Query failed with error: " << err.text().toStdString() << std::endl;
    }

    // iterate through each returned item
    int numRows;
    while (query.next())
    {
        QString title = query.value(0).toString();
        std::cout << title.toStdString() << "  " << std::endl;
    }

    // determine number of rows
    query.last();
    numRows = query.at() + 1;

    if(numRows > 0) return true;
    else return false;
    std::cout << "Rows found : " << numRows << std::endl;
}

/**
 * @brief Database::addUser
 * @param user
 * A function for add a user to the database
 * It also write it on csv file so that the next time this program is being ran, it knows that the user is being added.
 */
void Database::addUser(User* user)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO user (User_name, Password, Date_registrate, FName, LName, Items ) "
                  "VALUES (:username, :password, :created_at, :first_name, :last_name, items)");
    query.bindValue(":username", QString::fromStdString(user->getUsername()));
    query.bindValue(":password", QString::fromStdString(user->getPassword()));
    query.bindValue(":first_name", QString::fromStdString(user->getFName()));
    query.bindValue(":last_name", QString::fromStdString(user->getLName()));
    query.bindValue(":created_at", QString::fromStdString(user->getDate()));
    query.bindValue(":items", user->getItems());
    query.exec();

    ofstream outfile;
    outfile.open("../UserDB/user.csv", std::ios_base::app);
    outfile << endl <<user->getUsername() << "," << user->getPassword() << ","
                << user->getDate() << "," << user->getFName() << ","
                << user->getLName() << "," << user->getItems() << "\n";
        outfile.close();
}

/**
 * @brief Database::addPost
 * @param post
 * A function to add a post to the database
 * append post id, title, body, and checkmark values to CSV file
 */
void Database::addPost(const Post& post)
{
    ifstream file("../UserDB/post_manip.csv");
        int row_count = 1;
        string line;
        while (getline(file, line)) {
            row_count++;
        }

    QSqlQuery query;

    query.prepare("INSERT INTO post_manip (id, Title, Body, CheckBox_fresh, CheckBox_salt, CheckBox_bigTank, CheckBox_smallTank) "
                  "VALUES (:id, :title, :body, :checkBox_fresh, :checkBox_salt, :checkBox_bigTank, :checkBox_smallTank)");
    query.bindValue(":id", post.post_id); // Bind value for :id from post.id
    query.bindValue(":title", QString::fromStdString(post.title)); // Convert std::string to QString
    query.bindValue(":body", QString::fromStdString(post.body)); // Bind value for :body
    query.bindValue(":checkBox_fresh", post.checkBox_fresh ? 1 : 0); // Bind value for :checkBox_fresh from post.checkBox_fresh
    query.bindValue(":checkBox_salt", post.checkBox_salt ? 1 : 0); // Bind value for :checkBox_salt from post.checkBox_salt
    query.bindValue(":checkBox_bigTank", post.checkBox_bigTank ? 1 : 0); // Bind value for :checkBox_bigTank from post.checkBox_bigTank
    query.bindValue(":checkBox_smallTank", post.checkBox_smallTank ? 1 : 0); // Bind value for :checkBox_smallTank from post.checkBox_smallTank
    query.exec();

    // Append post id, title, body, and checkmark values to CSV file
    ofstream outfile;
    outfile.open("../UserDB/post_manip.csv", std::ios_base::app);
    outfile << row_count << "," << post.title << "," << post.body << "," << (post.checkBox_fresh ? "1" : "0") << ","
            << (post.checkBox_salt ? "1" : "0") << "," << (post.checkBox_bigTank ? "1" : "0") << ","
            << (post.checkBox_smallTank ? "1" : "0") << "\n"; // Assuming getPostTitle() returns a std::string
    outfile.close();
}

/**
 * @brief Database::addMessage
 * @param message
 * A function add a message to the database.
 * It appends the provided information to the CSV file
 */
void Database::addMessage(const chatMessage& message)
{
    QSqlQuery query(db);

    // Prepare the SQL statement
    query.prepare("INSERT INTO communicate (Sender_id, Reciever_id, Message) "
                  "VALUES (:sender, :recipient, :message_text)");
    query.bindValue(":sender", QString::fromStdString(message.sender));
    query.bindValue(":recipient", QString::fromStdString(message.receiver));
    query.bindValue(":message", QString::fromStdString(message.message));
    query.exec();


    QDateTime timestamp = QDateTime::currentDateTime();

    ifstream file("../UserDB/communicate.csv");
        int row_count = 1;
        string line;
        while (getline(file, line)) {
            row_count++;
        }

    fstream outfile;
    outfile.open("../UserDB/communicate.csv", std::ios_base::app);
    outfile << "\n" << row_count << "," << message.sender << "," << message.receiver << "," << timestamp.toString().toStdString() << ","
            << message.message;
    outfile.close();
    file.close();

}

/**
 * @brief Database::getMessagesForUser
 * @param username
 * Getter function for a user to retrieve the chat history of specified user.
 */
void Database::getMessagesForUser(string username)
{
    QSqlQuery query(db);

    QString sqlcmd = "SELECT * FROM communicate WHERE Reciever_id = '";
    sqlcmd += QString::fromStdString(username) + "';";

    // Execute the SQL command
    if (query.exec(sqlcmd) == false)
    {
        QSqlError err = query.lastError();
        cerr << "Query failed with error: " << err.text().toStdString() << endl;
        return;
    }

    // Iterate over the result of the SQL query
    while (query.next()) {
        QString sender = query.value("Sender_id").toString();
        QString receiver = query.value("Reciever_id").toString();
        QString message = query.value("Message").toString();

        // Print each message to the console
        cout << "From: " << sender.toStdString() << endl;
        cout << "To: " << receiver.toStdString() << endl;
        cout << "Message: " << message.toStdString() << endl;
    }
}



/**
 * @brief Database::addEduPost
 * @param post
 *  A function to add a post to the database that will be shown to the Educatio screen,
 *  Each post has a id, title, description, source, and tags
 */
void Database::addEduPost(const Post& post)
{

    ifstream file("../UserDB/education_post.csv");
        int row_count = 1;
        string line;
        while (getline(file, line)) {
            row_count++;
        }

    QSqlQuery query;

    query.prepare("INSERT INTO education_post (id, User_id, Description, Source, CheckBox_generalKnowledge, CheckBox_specific) "
                  "VALUES (:id, :user, :title, :description, :source, :checkBox_generalKnowledge, :checkBox_specific)");
    query.bindValue(":id", QString::number(row_count)); // Bind value for :id from post.id
    query.bindValue(":user", QString::fromStdString(post.user));//Bind value for :id from post.id
    query.bindValue(":title", QString::fromStdString(post.title)); // Convert std::string to QString
    query.bindValue(":description", QString::fromStdString(post.body)); // Bind value for :description
    query.bindValue(":source", QString::fromStdString(post.source)); // Bind value for :source
    query.bindValue(":checkBox_generalKnowledge", post.checkBox_generalKnowledge ? 1 : 0); // Bind value for :checkBox_generalKnowledge from post.checkBox_generalKnowledge
    query.bindValue(":checkBox_specific", post.checkBox_specific ? 1 : 0); // Bind value for :checkBox_specific from post.checkBox_specific
    query.exec();

    // Append post id, title, description, source, and checkmark values to CSV file
    ofstream outfile;
    outfile.open("../UserDB/education_post.csv", std::ios_base::app);
    outfile << row_count << "," << post.title << "," << post.description << "," << post.source << ","<< post.user << ","<<
            (post.checkBox_generalKnowledge ? "1" : "0") << "," << (post.checkBox_specific ? "1" : "0") << "\n";
    outfile.close();
}

/**
 * @brief Database::banUser
 * @param userName
 * deletion function for a user database to ban a user.
 * ** Only Admin can be execute this function.
 */
void Database::banUser(string userName)
{
    //deleting from user db
    QSqlQuery query;
    query.prepare("delete from user where User_name = :userName;");
    query.bindValue(":userName", QString::fromStdString(userName));
    query.exec();

    // deletion for user csv
    ifstream file_in("../UserDB/user.csv");
    if (!file_in) {
        cout << "Error: File could not be opened!" << endl;
        return;
    }

    vector<string> rows;
    string row;
    while (getline(file_in, row)) {
        string item = row.substr(0, row.find(","));
        if (item != userName) {
            rows.push_back(row);
        }
    }
    file_in.close();

    ofstream file_out("../UserDB/user.csv");
    if (!file_out) {
        cout << "Error: File could not be opened!" << endl;
        return;
    }

    for (const auto &r : rows) {
        file_out << r << endl;
    }
    file_out.close();

    //deletion for prefs csv & db
    deletePref(userName);
}

/**
 * @brief Database::deletePref
 * @param userName
 * delete preference that is associated with the given user name.
 * this is being use when the ban user is being ran
 */
void Database::deletePref(string userName)
{
    QSqlQuery query;
    // deleting from prefs db
    query.prepare("delete from prefs where User_id = :userName;");
    query.bindValue(":userName", QString::fromStdString(userName));
    query.exec();

    ifstream file_in("../UserDB/prefs.csv");
    if (!file_in) {
        cout << "Error: File could not be opened!" << endl;
        return;
    }

    vector<string> rows;
    string row;
    while (getline(file_in, row)) {
        string item = row.substr(0, row.find(","));
        if (item != userName) {
            rows.push_back(row);
        }
    }
    file_in.close();

    ofstream file_out("../UserDB/prefs.csv");
    if (!file_out) {
        cout << "Error: File could not be opened!" << endl;
        return;
    }

    for (const auto &r : rows) {
        file_out << r << endl;
    }
    file_out.close();

}

/**
 * @brief Database::getAllUsernames
 * @return
 * Getter function for collecting all user's username to the vector
 * that will be used to create a dropdown menu for chat.
 */
std::vector<std::string> Database::getAllUsernames()
{
    std::vector<std::string> usernames;

    // create a query object to the database
    QSqlQuery query(db);

    // establish the sql command
    QString sqlcmd = "SELECT User_name FROM user;";

    // execute the provided sql call
    if (query.exec(sqlcmd) == false)
    {
        QSqlError err = query.lastError();
        std::cout << "Query failed with error: " << err.text().toStdString() << std::endl;
    }

    // iterate through each returned item and add to the usernames vector
    while (query.next())
    {
        QString username = query.value(0).toString();
        usernames.push_back(username.toStdString());
    }

    return usernames;
}

/**
 * @brief Database::changePref
 * @param box
 * A function to change the preference, based on the input the user have prompted in a user preference screen.
 */
std::vector<std::string> Database::getAllItems()
{
    std::vector<std::string> items;

    // create a query object to the database
    QSqlQuery query(db);

    // establish the sql command
    QString sqlcmd = "SELECT Item FROM trade;";

    // execute the provided sql call
    if (query.exec(sqlcmd) == false)
    {
        QSqlError err = query.lastError();
        std::cout << "Query failed with error: " << err.text().toStdString() << std::endl;
    }

    // iterate through each returned item and add to the items vector
    while (query.next())
    {
        QString item = query.value(0).toString();
        items.push_back(item.toStdString());
    }

    return items;
}

/**
 * @brief Database::changePref
 * @param box
 * change user's preference on database
 */
void Database::changePref(Box box)
{
    QSqlQuery query;
    query.prepare("UPDATE prefs SET Anonymous_self = :anonymous , Skin = :skin , Water_type = :waterType ,Tank_size = :tankSize ,Show_friends = :showFriends , Location = : location where User_id = :userName;");
    query.bindValue(":userName", QString::fromStdString(box.currUserName));
    query.bindValue(":anonymous", QString::number(box.anonymous));
    query.bindValue(":skin", QString::fromStdString(box.skin));
    query.bindValue(":waterType", QString::fromStdString(box.waterType));
    query.bindValue(":tankSize", QString::fromStdString(box.tankSize));
    query.bindValue(":showFriends", QString::number(box.showFriends));
    query.bindValue(":location", QString::fromStdString(box.location));


    //deleting fromcsv
    ifstream file_in("../UserDB/prefs.csv");
    if (!file_in) {
        cout << "Error: File could not be opened!" << endl;
        return;
    }

    vector<string> rows;
    string row;
    while (getline(file_in, row)) {
        string item = row.substr(0, row.find(","));
        if (item != box.currUserName) {
            rows.push_back(row);
        }
    }
    file_in.close();
    ofstream file_out("../UserDB/prefs.csv");
    if (!file_out) {
        cout << "Error: File could not be opened!" << endl;
        return;
    }

    for (const auto &r : rows) {
        file_out << r << endl;
    }
    file_out.close();

    // adding back to csv
    ofstream outfile;
    outfile.open("../UserDB/prefs.csv", std::ios_base::app);
    outfile << box.currUserName << ","
            << box.anonymous << ","
            << box.skin << ","
            << box.waterType << ","
            << box.tankSize << ","
            << box.showFriends << ","
            << box.location;
        outfile.close();

        cout << box.currUserName << endl;

    query.exec();
}

/**
 * @brief Database::friendExist
 * @param name
 * @return
 * Checking function to see if a specified name of user exists within frineds tables.
 */
bool Database::friendExist(string name)
{


        // establish the sql command
    QSqlQuery query;

    QString sqlcmd = "select * from friends where friend_Id = \"";
    QString str = QString::fromStdString(name) + "\";";
    sqlcmd.append(str);

    // execute the provided sql call
    if (query.exec(sqlcmd) == false)
    {
        QSqlError err = query.lastError();
        std::cout << "Query failed with error: " << err.text().toStdString() << std::endl;
    }

    // iterate through each returned item
    int numRows;
    while (query.next())
    {
        QString title = query.value(0).toString();
        std::cout << title.toStdString() << "  " << std::endl;
    }

    // determine number of rows
    query.last();
    numRows = query.at() + 1;

    if(numRows > 0) return true;
    else return false;
}

/**
 * @brief Database::addFriend
 * @param profile
 * add friends to the friends tables/database
 */
void Database::addFriend(Profile& profile){
    QSqlQuery query(db);

    query.prepare("INSERT INTO friends (Connection_id, User_id, Friend_id) "
                  "VALUES (:id, :userid, :friendid)");
    query.bindValue(":id", profile.connection_id);
    query.bindValue(":userid", QString::fromStdString(profile.userId));
    query.bindValue(":friendid", QString::fromStdString(profile.friendId));
    query.exec();

    ofstream outfile;
    outfile.open("../UserDB/friends.csv", std::ios_base::app);
    outfile << endl << profile.connection_id << "," << profile.userId << "," << profile.friendId;
    outfile.close();

}

/**
 * @brief Database::addItemforUser
 * A function to add an item for a user.
 */
void Database::addItemforUser()
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO user (Item) "
                   "VALUES (:item)");
    query.bindValue(":item", user->items);
    query.exec();

    ofstream outfile;
    fstream file("../UserDB/user.csv", std::ios_base::app);
    outfile << user->items;
}

/**
 * @brief Database::getItemsForUser
 * @param username
 * @return
 * Getter function for an item that the specified user has.
 */
int Database::getItemsForUser(const std::string& username) {
       QSqlQuery query(db);
       query.prepare("SELECT * FROM user WHERE User_name = :username");
       query.bindValue(":username", QString::fromStdString(username));
       query.exec();
    int items = 0;

       if (query.next()) {
            items = query.value(5).toInt();
       }

       return items;
   };

/**
 * @brief Database::setItemsForUser
 * @param username
 * Setter fuction for Item that the given user's item.
 */
void Database::setItemsForUser(const std::string& username)
{
    QSqlQuery query(db);

    // Update the items for the user in the database
    query.prepare("UPDATE user SET Items = :items WHERE User_name = :username");
    query.bindValue(":items", user->getItems());
    query.bindValue(":username", QString::fromStdString(username));
    query.exec();

}

/**
 * @brief Database::getMessages
 * @param currUserName
 * @return
 * Getter function to collect all the previous chat history that can be used to display on a screen
 * so that people will know what they have said
 */
vector<chatMessage> Database::getMessages(string currUserName)
{
    QSqlQuery query;
    vector<chatMessage> cm;

    cout << currUserName << endl;
    ifstream file("../UserDB/communicate.csv");
    if (!file)
    {
            std::cout << "Error opening file" << std::endl;
            return cm;
    }

    std::string line;
    while (getline(file, line))
    {
        if (line.find(currUserName + ",") != std::string::npos || line.find("," + currUserName) != std::string::npos)
        {
            istringstream lineStream(line);
            string cell;
            chatMessage c;
            getline(lineStream, cell, ',');
            c.messageId = stoi(cell);
            getline(lineStream, cell, ',');
            c.sender = cell;
            getline(lineStream, cell, ',');
            c.receiver = cell;
            getline(lineStream, cell, ',');
            c.time = cell;
            getline(lineStream, cell, ',');
            c.message = cell;
            cm.push_back(c);
        }
    }
    return cm;
}
