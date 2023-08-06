#include "Communication/Headers/chat.h"
#include "ui_chat.h"
#include <QButtonGroup>
#import <QStringList>
#import <QFile>

Chat::Chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);

    // Initialize db pointer with a Database object
    db = new Database(); // Replace this with your actual database initialization code
    setupDropdown();

}

Chat::~Chat()
{
    delete db; // Delete the db object
    delete ui;
}


void Chat::on_button_clicked()
{
    emit chatToHome();
}


void Chat::on_button_2_clicked()
{
    emit chatToHome();
}


/**
 * @brief Chat::on_sendButton_clicked
 *  create a message using user input and store it into QVBoxLayout as a QLabels.
 *  and the input gets cleared so that people dpp not have to delete their previous message.
 */

void Chat::on_sendButton_clicked()
{
    // Get the text from the QLineEdit
    QString messageText = ui->lineEdit->text();

    // Retrieve the selected username from the QComboBox
    QString selectedUsername = ui->userDropdown->currentText();
    qDebug() << "Selected username: " << selectedUsername;

    // Create a new chatMessage object
    chatMessage newMessage;
    newMessage.message = messageText.toStdString();
    newMessage.sender = currUserName;
    newMessage.receiver = selectedUsername.toStdString();

    // Add the new message to the database
    db->addMessage(newMessage);


    // Create a formatted message string
    QDateTime timestamp = QDateTime::currentDateTime();
    QString formattedMessage = timestamp.toString("dd/MM/yyyy hh:mm:ss") +
            "To <b>" + selectedUsername + "</b>: " + messageText;

    // Create a new QLabel for the message and add it to the appropriate user's QVBoxLayout
    QLabel* label = new QLabel(formattedMessage);
    QString username = QString::fromStdString(selectedUsername.toStdString());
    std::string usernameStr = username.toStdString();
    QVBoxLayout* layout = userLayouts[usernameStr];

    layout->addWidget(label);

    // Clear the QLineEdit for new input
    ui->lineEdit->clear();
}


/**
 * @brief Chat::setupDropdown
 *  setup function for chat. It goes through all the people on the platform and list them on a dropdown.
 *  Which allows logged in user to choose who to communicate with.
 */
void Chat::setupDropdown()
{
    // Get all the usernames from the database
    std::vector<std::string> usernames = db->getAllUsernames();

    // Create a QVBoxLayout for each user and store in a map
    for (const auto& username : usernames) {
        QVBoxLayout* layout = new QVBoxLayout();
        ui->messages->addLayout(layout);
        userLayouts[username] = layout;
    }

    // Set the dropdown with the usernames
    QStringList userDropdown;
    for (const auto& username : usernames) {
        userDropdown.append(QString::fromStdString(username));
    }
    ui->userDropdown->clear();
    ui->userDropdown->addItems(userDropdown);
}


/**
 * @brief Chat::on_retrieveButton_clicked
 * goes through the past chat history to display so that the user can see it.
 */
void Chat::on_retrieveButton_clicked()
{
    // Retrieve the messages for the specified user
    Database db;
    db.getMessagesForUser(currUserName);
{    
    //maybe when I have time.
//    userLayouts.clear();
//    std::vector<std::string> usernames = db->getAllUsernames();
//    for (const auto& username : usernames) {
//        QVBoxLayout* layout = new QVBoxLayout();
//        ui->messages->addLayout(layout);
//        userLayouts[username] = layout;
//    }


    vector<chatMessage> cm;
    cm = db.getMessages(currUserName);
    cout << cm.size() << "," << "currUser: " << currUserName << endl;
    for(unsigned int i = 0;i < cm.size();i++)
    {
        if(cm.at(i).sender == currUserName){
        QString formattedMessage = QString::fromStdString(cm.at(i).time) +
                "To <b>" + QString::fromStdString(cm.at(i).receiver) + "</b>: " + QString::fromStdString(cm.at(i).message);
        cout << formattedMessage.toStdString() << endl;
        QLabel* label = new QLabel(formattedMessage);
        userLayouts[cm.at(i).receiver]->addWidget(label);

        }
        else
        {
            QString formattedMessage = QString::fromStdString(cm.at(i).time) +
                    "From <b>" + QString::fromStdString(cm.at(i).sender) + "</b>: " + QString::fromStdString(cm.at(i).message);
            cout << formattedMessage.toStdString() << endl;
            QLabel* label = new QLabel(formattedMessage);
            userLayouts[cm.at(i).sender]->addWidget(label);
        }
    }

}
}


void Chat::on_pushButton_clicked()
{
    emit chatToHome();
}

