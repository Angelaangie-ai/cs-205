#include "userManagement/Headers/registration.h"
#include "ui_registration.h"


using namespace std;

/**
 * @brief Registration::Registration
 * @param parent
 * constructor for registration.
 * This hides error message first; however, it can always be shown by show() function.
 */
Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->regiWarning_label->hide();
    db = new Database();
}

/**
 * @brief Registration::~Registration
 * deconstructor for registration.
 */
Registration::~Registration()
{
    delete ui;
}

/**
 * @brief Registration::on_submit_Button_clicked
 * when his button gets clcked, it firist checks whether, the prompted username exists in a database,
 * if not it will create a user object and it the information of user gets added to the database.
 * Then, it will make a transition to the user preference setting page by emitting signals.
 * It also records when the user gets created using "ctime" include so that the admin or higher authorizer can check
 * which user has been on a platform for how long.
 */
void Registration::on_submit_Button_clicked()
{
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    string year = to_string(1900 + local_time->tm_year);
    string month = to_string(1 + local_time->tm_mon);
    string day = to_string(local_time->tm_mday);
    string date = month + "/" + day + "/" + year;
    string userName = ui->regiUser_input->text().toStdString();
    string password = ui->regiPass_input->text().toStdString();
    string fName = ui->regiFName_input->text().toStdString();
    string lName = ui->regiLName_input->text().toStdString();


    if(db->userExist(userName))// should check if a username already exist or not.
    {
        ui->regiFName_input->clear();
        ui->regiLName_input->clear();
        ui->regiPass_input->clear();
        ui->regiUser_input->clear();
        ui->regiWarning_label->show();
    }
    else
    {
    // these items should be stored into user objects (either can be parametarized or individually)
        user = new User(userName,password, fName, lName, date);
        db->addUser(user);
        currUserName = userName;
        emit toPreference();
    }
}

