#ifndef BOX_H
#define BOX_H
#include "string"
using namespace std;

class Box
{
public:
    /**
     * @brief Box
     * This class is being used as a container class to hold sufficient
     * information about user's personal preference to update.
     */
    Box();
    string currUserName;
    int anonymous;
    string skin;
    string waterType;
    string tankSize;
    int showFriends;
    string location;
};

#endif // BOX_H
