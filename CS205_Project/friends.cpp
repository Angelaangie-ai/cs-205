#include "friends.h"
#include "ui_friends.h"

Friends::Friends(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Friends)
{
    ui->setupUi(this);
    ui->logWarning_label->hide();
    ui->friends_label->hide();
    data = new Database();
}

Friends::~Friends()
{
    delete ui;
}

/**
 * @brief Friends::on_button_clicked
 *
 */
void Friends::on_button_clicked()
{
    emit friendToHome();
}


void Friends::on_button_2_clicked()
{
    emit friendToHome();
}


//need to fix this part using the page stack !!!

/**
 * @brief Home::on_homePreference_button_clicked
 * a functin to go to preference page, it emits a signal and pageStack class does the transition
 */
/*void Friends::on_homePreference_button_clicked()
{
    emit homeToPref();
}*/

/**
 * @brief Home::on_edu_button_clicked
 * a functin to go to education page, it emits a signal and pageStack class does the transition
 */
/*void Friends::on_edu_button_clicked()
{
    emit homeToEdu();

}*/

/**
 * @brief Friend::on_trade_button_clicked
 * a functin to go to trade page, it emits a signal and pageStack class does the transition
 */
/*void Friends::on_trade_button_clicked()
{
    emit homeToTrade();
}*/
int currentConectId = 0;


void Friends::addFriend(const std::string& userName){

    // check if user name exist
    if(data->userExist(userName) && !(data->friendExist(userName))){
        ui->logWarning_label->hide();
        ui->friends_label->hide();

        Profile newFriend;
        newFriend.userId = login.currUserName;
        newFriend.friendId = userName;
        newFriend.connection_id = currentConectId;

        currentConectId++;

        // Create a new ProfileWidget object
        ProfileWidget* prof = new ProfileWidget(); // Replace with your actual PostWidget constructor

        // Set the properties of the ProfileWidget object
        prof->setName(QString::fromStdString(userName));

        // Add the ProfileWidget object to the postLayout
        ui->postLayout->addWidget(prof);

        data->addFriend(newFriend);

    }else if(data->friendExist(userName)){
        ui->friends_label->show();
    }else{
        // if the username is not correct
        ui->logWarning_label->show();
    }


}


void Friends::on_nextUser_button_clicked(){
    // Get input values from the UI
    std::string userName = ui->title_input->text().toStdString();

    // Call the addFriend() function with the input values
    addFriend(userName);

    // clearing the input
    ui->title_input->clear();
}

void Friends::on_load_list_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery* qry = new QSqlQuery(data->db);

    qry->prepare("select User_name from user");

    qry->exec();

    model->setQuery(*qry);
    ui->listView->setModel(model);

    qDebug() <<(model -> rowCount());

}

void Friends::on_pushButton_clicked()
{
     emit friendToHome();
}

