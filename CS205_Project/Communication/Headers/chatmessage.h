#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H
#include "string"

class chatMessage
{
public:
    chatMessage();
    std::string message;
    std::string sender;
    std::string receiver;
    std::string time;
    int messageId;
    ~chatMessage();
};

#endif // CHATMESSAGE_H
