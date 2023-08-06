#include "Screens/Headers/education.h"
#include "ui_education.h"
#include "postManipulation/Headers/post.h"
#include "Screens/Headers/education.h"
#include "ui_education.h"
#include "postManipulation/Headers/edupostwidget.h"
#include "Database/Headers/database.h"

Education::Education(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Education)
{
    ui->setupUi(this);
}

Education::~Education()
{
    delete ui;
}

/**
 * @brief Education::on_eduToHome_button_clicked
 * signal function to emit a signal that will switch a Widget
 */
void Education::on_eduToHome_button_clicked()
{
    emit eduToHome();
}

/**
 * @brief Education::on_eduToHome_button_2_clicked
 * signal function to emit a signal that will switch a Widget
 */
void Education::on_eduToHome_button_2_clicked()
{
    emit eduToHome();
}

/**
<<<<<<< HEAD
 * @brief Home::on_homePreference_button_clicked
 * a functin to go to preference page, it emits a signal and pageStack class does the transition
 */
void Education::on_Pref_button_clicked()
{
    emit eduToPref();
}

void Education::on_chat_button_clicked()
{
    emit eduToChat();
}

/**
 * @brief Home::on_trade_button_clicked
 * a functin to go to trade page, it emits a signal and pageStack class does the transition
 */
void Education::on_trade_button_clicked()
{
    emit eduToTrade();
}

void Education::on_friend_button_clicked()
{
    emit eduToFriends();
}



/**
 * @brief Education::addEduPost
 * @param title
 * @param description
 * @param source
 * @param checkBox_general
 * @param checkBox_specific
 * A function to add a education post to the database with given parameters
 */
void Education::addEduPost(const std::string& title, const std::string& description,
                        const std::string& source, bool checkBox_general,
                           bool checkBox_specific)
{
    Post newPost;
    newPost.title = title;
    newPost.user = currUserName;
    newPost.description = description;
    newPost.source = source;
    newPost.checkBox_generalKnowledge = checkBox_general;
    newPost.checkBox_specific = checkBox_specific;

    // Create a new PostWidget object
    eduPostWidget* EduPostWidget = new eduPostWidget();

    EduPostWidget->setTitle(QString::fromStdString(newPost.title));
    EduPostWidget->setUser(QString::fromStdString(newPost.user));
    EduPostWidget->setDescription(QString::fromStdString(newPost.description));
    EduPostWidget->setSource(QString::fromStdString(newPost.source));
    EduPostWidget->setCheckBoxGeneral(newPost.checkBox_generalKnowledge);
    EduPostWidget->setCheckBoxSpecific(newPost.checkBox_specific);
    EduPostWidget->generalCheckedBox->hide();
    EduPostWidget->specificCheckedBox->hide();
    EduPostWidget->userLabel->hide();
    ui->postLayout->addWidget(EduPostWidget);
    db->addEduPost(newPost);
}



/**
 * @brief Education::on_addPost_button_clicked
 * Trigger function to call addPost function and it retreieve all the user prompt and let the other function know
 */
void Education::on_addPost_button_clicked()
{
    std::string title = ui ->title_input ->text().toStdString();
    std::string description = ui ->description_input ->text().toStdString();
    std::string source = ui -> source_input -> text().toStdString();
    bool checkBox_general = ui -> checkBox_general -> isChecked();
    bool checkBox_specific = ui -> checkBox_specific -> isChecked();

    // Call the addPost() function with the input values
    addEduPost(title, description, source,
            checkBox_general, checkBox_specific);

    ui->title_input->clear();
    ui->description_input->clear();
    ui->source_input->clear();
    ui -> checkBox_general -> setChecked(false);
    ui -> checkBox_specific -> setChecked(false);
}


/**
 * @brief Education::on_checkBox_generalKnowledge_stateChanged
 * @param arg1
 * This function will show only general knowlege tagged post when it is on;however, if it is off, it does not.
 */
void Education::on_checkBox_generalKnowledge_stateChanged(int arg1)
{
    // Get the current state of the checkbox
    bool isChecked = arg1 == Qt::Checked;

    // Check if the post layout is empty
    if (ui->postLayout->count() == 0) {
        return;
    }

    // Iterate over all the posts in the post layout
    for (int i = 0; i < ui->postLayout->count(); i++) {
        // Check if the post layout is not empty
        if (ui->postLayout->itemAt(i) != nullptr) {
            // Get the post widget
            eduPostWidget *EduPostWidget = static_cast<eduPostWidget*>(ui->postLayout->itemAt(i)->widget());

            // Check if postWidget is not nullptr
            if (EduPostWidget != nullptr) {
                // If the checkbox is checked and the check post is checked, show the post
                if (isChecked && EduPostWidget->generalCheckedBox->isChecked()) {
                    EduPostWidget->show();
                } else if (!ui->checkBox_generalKnowledge->isChecked() &&
                           !ui->checkBox_specificType->isChecked())
                {
                    EduPostWidget->show();
                } else {
                    EduPostWidget->hide();
                }
            }
        }
    }
}

/**
 * @brief Education::on_checkBox_specificType_stateChanged
 * @param arg1
 * This function will only show the specific knowlege tagged post when the check box is on.
 */
void Education::on_checkBox_specificType_stateChanged(int arg1)
{
    // Get the current state of the checkbox
    bool isChecked = arg1 == Qt::Checked;

    // Check if the post layout is empty
    if (ui->postLayout->count() == 0) {
        return;
    }

    // Iterate over all the posts in the post layout
    for (int i = 0; i < ui->postLayout->count(); i++) {
        // Check if the post layout is not empty
        if (ui->postLayout->itemAt(i) != nullptr) {
            // Get the post widget
            eduPostWidget *EduPostWidget = static_cast<eduPostWidget*>(ui->postLayout->itemAt(i)->widget());

            // Check if postWidget is not nullptr
            if (EduPostWidget != nullptr) {
                // If the checkbox is checked and the check post is checked, show the post
                if (isChecked && EduPostWidget->specificCheckedBox->isChecked()) {
                    EduPostWidget->show();
                } else if (!ui->checkBox_generalKnowledge->isChecked() &&
                           !ui->checkBox_specificType->isChecked())
                {
                    EduPostWidget->show();
                } else {
                    EduPostWidget->hide();
                }
            }
        }
    }
}

