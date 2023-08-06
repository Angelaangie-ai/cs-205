#include "profile.h"

int Profile::current_connection_id = 0;

Profile::Profile(QWidget* parent) : QWidget(parent){

    connection_id = ++current_connection_id;

}


int Profile::getFriendId() {
    return connection_id;
}

