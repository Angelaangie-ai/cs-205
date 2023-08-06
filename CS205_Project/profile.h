#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>


class Profile : public QWidget {
    Q_OBJECT
public:
    explicit Profile(QWidget* parent = nullptr);

    /**
     * @brief getFriendId
     * @return
     * Getter function for frindIds
     */
    int getFriendId();

    std::string userId;
    std::string friendId;
    int         connection_id;
    static int  current_connection_id;

private:
    QLabel* nameLabel;

    QVBoxLayout* layout;
};


#endif // PROFILE_H
