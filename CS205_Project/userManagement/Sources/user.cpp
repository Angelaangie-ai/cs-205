#include "UserManagement/Headers/user.h"

using namespace std;

User::User()
{
    userName = password = regiDate = fName = lName = " ";
}
User::User(string userName, string password, string fName, string lName, string regiDate)
{
    this->userName = userName;
    this->password = password;
    this->fName = fName;
    this->lName = lName;
    this->regiDate = regiDate;
}
/**
 * @brief getUsername
 * @return
 * getter function for username
 */
string User::getUsername(){
    return userName;
}

/**
 * @brief getPassword
 * @return
 * getter function for password
 */
string User::getPassword()
{
    return password;
}

/**
 * @brief getFName
 * @return
 * getter function for first name
 */
string User::getFName()
{
    return fName;
}

/**
 * @brief getLName
 * @return
 * getter function for last name
 */
string User::getLName()
{
    return lName;
}

/**
 * @brief getDate
 * @return
 * getter function for registration date.
 */
string User::getDate()
{
    return regiDate;
}

/**
 * @brief User::setFName
 * @param fName
 * Setter for first name
 */
void User::setFName(string fName)
{
    this->fName = fName;
}

/**
 * @brief User::setLName
 * @param lName
 * Setter for last name
 */
void User::setLName(string lName)
{
    this->lName = lName;
}

/**
 * @brief User::setUsername
 * @param userName
 * Setter for username.
 */
void User::setUsername(string userName)
{
    this->userName = userName;
}

/**
 * @brief User::setPassword
 * @param password
 * Setter for password
 */
void User::setPassword(string password)
{
    this->password = password;
}

/**
 * @brief User::setDate
 * @param date
 * Setter for date.
 */
void User::setDate(string date)
{
    this->regiDate = date;

}

/**
 * @brief User::getItems
 * @return
 * Getter for item
 */
int User::getItems() {
    return items;
}
