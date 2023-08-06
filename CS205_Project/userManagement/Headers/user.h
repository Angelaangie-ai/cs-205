#ifndef USER_H
#define USER_H
#include "string"
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "iostream"


using namespace std;


class User
{
public:
    /**
     * @brief User
     * default constructor for the User class
     */
    User();

    /**
     * @brief User
     * constructor for the User class that initializes the user's userName, password, fName, lName, and regiDate properties
     */
    User(string, string, string, string, string);
    string userName;
    string password;
    string fName;
    string lName;
    string regiDate;
    int items;

    /**
     * @brief setUsername
     * method to set the userName property of the user
     */
    void setUsername();

    /**
     * @brief setPassword
     * method to set the password property of the user
     */
    void setPassword();

    /**
     * @brief setFName
     * method to set the first name property of the user
     */
    void setFName();

    /**
     * @brief setLName
     * method to set the last name property of the user
     */
    void setLName();

    /**
     * @brief setDate
     * method to set the regiDate property of the user
     */
    void setDate();

    /**
     * @brief setFName
     * overloaded method to set the fName property of the user with a given string
     */
    void setFName(string);

    /**
     * @brief setLName
     * overloaded method to set the lName property of the user with a given string
     */
    void setLName(string);

    /**
     * @brief setUsername
     * overloaded method to set the userName property of the user with a given string
     */
    void setUsername(string);

    /**
     * @brief setPassword
     * overloaded method to set the password property of the user with a given string
     */
    void setPassword(string);

    /**
     * @brief setDate
     * overloaded method to set the regiDate property of the user with a given string
     */

    void setDate(string);

    /**
     * @brief getUsername
     * @return
     * getter function for username
     */
    std::string getUsername();

    /**
     * @brief getPassword
     * @return
     * getter function for password
     */
    std::string getPassword();

    /**
     * @brief getFName
     * @return
     * getter function for first name
     */
    std::string getFName();

    /**
     * @brief getLName
     * @return
     * getter function for last name
     */
    std::string getLName();
    int getItems();

    /**
     * @brief getDate
     * @return
     * getter function for registration date.
     */
    std::string getDate();


    ~User();

};

#endif // USER_H
