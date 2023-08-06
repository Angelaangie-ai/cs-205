#include "home.h"
#include "string.h"
#include "ui_home.h"
#include "post.h"
#include "postwidget.h"
#include "database.h"
#include "pagestack.h"
#include <QVBoxLayout>

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    db = new Database();

}

Home::~Home()
{
    delete ui;
}

/**
 * @brief Home::on_homePreference_button_clicked
 * a functin to go to preference page, it emits a signal and pageStack class does the transition
 */
void Home::on_homePreference_button_clicked()
{
    emit homeToPref();
}

void Home::on_chat_button_clicked()
{
    emit homeToChat();
}



/**
 * @brief Home::on_edu_button_clicked
 * a functin to go to education page, it emits a signal and pageStack class does the transition
 */
void Home::on_edu_button_clicked()
{
    emit homeToEdu();

}

/**
 * @brief Home::on_trade_button_clicked
 * a functin to go to trade page, it emits a signal and pageStack class does the transition
 */
void Home::on_trade_button_clicked()
{
    emit homeToTrade();
}

void Home::on_friend_button_clicked()
{
    emit homeToFriends();
}

/**
 * @brief Home::addPost
 * @param title
 * @param body
 * @param tag
 *
 * A function to post a post that will be shown on the main page.
 */

int currentPostId = 0;

void Home::addPost(const std::string& title, const std::string& body, bool checkBox_fresh,
                   bool checkBox_salt, bool checkBox_bigTank, bool checkBox_smallTank)
{

    int postId = ++lastPostId;

    // Create a new post with the provided data
    Post newPost;
    newPost.title = title;
    //this is not working properly, the id is not getting the last id
    newPost.post_id = currentPostId; // Set the post id using the currentPostId counter
    newPost.body = body;
    newPost.checkBox_fresh = checkBox_fresh;
    newPost.checkBox_salt = checkBox_salt;
    newPost.checkBox_bigTank = checkBox_bigTank;
    newPost.checkBox_smallTank = checkBox_smallTank;

    currentPostId++;


    // Create a new PostWidget object
    PostWidget* postWidget = new PostWidget(); // Replace with your actual PostWidget constructor

    // Set the properties of the PostWidget object
    postWidget->setTitle(QString::fromStdString(newPost.title));
    postWidget->setBody(QString::fromStdString(newPost.body));
    postWidget->setCheckBoxFresh(checkBox_fresh);
    postWidget->setCheckBoxSalt(newPost.checkBox_salt);
    postWidget->setCheckBoxBigTank(newPost.checkBox_bigTank);
    postWidget->setCheckBoxSmallTank(newPost.checkBox_smallTank);
    postWidget->bigTankCheckedBox->hide();
    postWidget->freshCheckedBox->hide();
    postWidget->smallTankCheckedBox->hide();
    postWidget->saltCheckedBox ->hide();

    // Add the PostWidget object to the postLayout
    ui->postLayout->addWidget(postWidget);
    db->addPost(newPost);


    // Print success message with the post id
    std::cout << "Post added successfully with id: " << newPost.post_id << ", title: " << title << ", body: " << body <<  std::endl;

    // Print success message
    std::cout << "Post added successfully with title: " << title << ", body: " << body <<  std::endl;


}




void Home::on_addPost_button_clicked()
{
    // Get input values from the UI
    std::string title = ui->title_input->text().toStdString();
    std::string body = ui->body_input->text().toStdString();
    bool checkBox_fresh = ui->checkBox_fresh->isChecked();
    bool checkBox_salt = ui->checkBox_salt->isChecked();
    bool checkBox_bigTank = ui->checkBox_bigTank->isChecked();
    bool checkBox_smallTank = ui->checkBox_smallTank->isChecked();

    // Call the addPost() function with the input values
    addPost(title, body, checkBox_fresh,
            checkBox_salt, checkBox_bigTank,
            checkBox_smallTank);

    // clearing the input
    ui->title_input->clear();
    ui->body_input->clear();
    ui -> checkBox_fresh -> setChecked(false);
    ui -> checkBox_salt -> setChecked(false);
    ui -> checkBox_bigTank -> setChecked(false);
    ui -> checkBox_smallTank -> setChecked(false);
}

void Home::on_checkBox_saltWater_stateChanged(int arg1)
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
            PostWidget *postWidget = static_cast<PostWidget*>(ui->postLayout->itemAt(i)->widget());

            // Check if postWidget is not nullptr
            if (postWidget != nullptr) {
                // If the checkbox is checked and the check post is checked, show the post
                if (isChecked && postWidget->saltCheckedBox->isChecked()) {
                    postWidget->show();
                } else if (!ui->checkBox_saltWater->isChecked() &&
                           !ui->checkBox_freshWater->isChecked() &&
                           !ui -> checkBox_bigTanks -> isChecked() &&
                           !ui -> checkBox_smallTanks -> isChecked())
                {
                    postWidget->show();
                } else {
                    postWidget->hide();
                }
            }
        }
    }
}




void Home::on_checkBox_freshWater_stateChanged(int arg1)
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
            PostWidget *postWidget = static_cast<PostWidget*>(ui->postLayout->itemAt(i)->widget());

            // Check if postWidget is not nullptr
            if (postWidget != nullptr) {
                // If the checkbox is checked and the check post is checked, show the post
                if (isChecked && postWidget->freshCheckedBox->isChecked()) {
                    postWidget->show();
                } else if (!ui->checkBox_saltWater->isChecked() &&
                           !ui->checkBox_freshWater->isChecked() &&
                           !ui -> checkBox_bigTanks -> isChecked() &&
                           !ui -> checkBox_smallTanks -> isChecked())
                {
                    postWidget->show();
                } else {
                    postWidget->hide();
                }
            }
        }
    }
}


void Home::on_checkBox_bigTanks_stateChanged(int arg1)
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
            PostWidget *postWidget = static_cast<PostWidget*>(ui->postLayout->itemAt(i)->widget());

            // Check if postWidget is not nullptr
            if (postWidget != nullptr) {
                // If the checkbox is checked and the check post is checked, show the post
                if (isChecked && postWidget->bigTankCheckedBox->isChecked()) {
                    postWidget->show();
                } else if (!ui->checkBox_saltWater->isChecked() &&
                           !ui->checkBox_freshWater->isChecked() &&
                           !ui -> checkBox_bigTanks -> isChecked() &&
                           !ui -> checkBox_smallTanks -> isChecked())
                {
                    postWidget->show();
                }
                else {
                    postWidget->hide();
                }
            }
        }
    }
}


void Home::on_checkBox_smallTanks_stateChanged(int arg1)
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
            PostWidget *postWidget = static_cast<PostWidget*>(ui->postLayout->itemAt(i)->widget());

            // Check if postWidget is not nullptr
            if (postWidget != nullptr) {
                // If the checkbox is checked and the check post is checked, show the post
                if (isChecked && postWidget->bigTankCheckedBox->isChecked()) {
                    postWidget->show();
                } else if (!ui->checkBox_saltWater->isChecked() &&
                           !ui->checkBox_freshWater->isChecked() &&
                           !ui -> checkBox_bigTanks -> isChecked() &&
                           !ui -> checkBox_smallTanks -> isChecked())
                {
                    postWidget->show();
                } else {
                    postWidget->hide();
                }
            }
        }
    }

}

