#include "userManagement/Headers/preference.h"
#include "ui_preference.h"


using namespace std;
/**
 * @brief Preference::Preference
 * @param parent
 * constructor that set up for the ui for be ready.
 */
Preference::Preference(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Preference)
{
    ui->setupUi(this);
    db = new Database();
}

Preference::~Preference()
{
    delete ui;
}

/**
 * @brief Preference::on_prefSubmit_button_clicked
 * when the submit button gets clicked, it will get the take the routpust of
 * user prompt and then updates to user preference in the database.
 * The preference setting options are below:
 * 1) favorite type of fish
 * 2) location of user
 * 3) anonymous
 * 4) skin setting for the user avatar.
 *
 *Then it widget will transition to main for user to enjoy the contents.
 */
void Preference::on_prefSubmit_button_clicked()
{
    string waterType = ui->waterType_check->currentText().toStdString();
    string tankType = ui->tank_check->currentText().toStdString();
    string location = ui->location_input->text().toStdString();
    bool anonymous = ui->anonymous_check->checkState(); // seems like it produces 0|1
    string skin = ui->skin_box->currentText().toStdString();
    bool priv = ui->private_check->checkState();
    Box box;
    box.anonymous = anonymous;
    box.currUserName = currUserName;
    box.location = location;
    box.showFriends = priv;
    if(tankType == "Big tank") box.tankSize = "Big tank";
    else if(tankType == "Small tank") box.tankSize = "Small tank";
    if(waterType == "Salt water") box.waterType = "Salt water";
    else if(waterType == "Fresh water") box.waterType = "Fresh water";
    box.skin = skin;
    db->changePref(box);
    emit prefToMain();
}


