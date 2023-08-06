#include "trade.h"
#include "UserManagement/Headers/user.h"
#include <QListWidget>
#include "ui_trade.h"
#include <QButtonGroup>

Trade::Trade(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Trade)
{
    ui->setupUi(this);
    db = new Database();
    populateList();
}

Trade::~Trade()
{
    delete ui;
}

/**
 * @brief Trade::on_tradeToHome_button_clicked
 * A function to emit a signal to switch current Widget
 */
void Trade::on_tradeToHome_button_clicked()
{
    emit tradeToHome();
}

/**
 * @brief Trade::on_pushButton_2_clicked
 * A function to emit a signal to switch current Widget
 *
 */
void Trade::on_pushButton_2_clicked()
{
    emit tradeToHome();
}

/**
 * @brief Trade::populateList
 * A function to populate the list of tradable items.
 * It also checkes if an items
 */
void Trade::populateList()
{
    // Check that db is not null
    if (!db)
    {
        qDebug() << "Database not initialized.";
        return;
    }

    // Get all usernames from the database
    std::vector<std::string> usernames = db->getAllItems();

    // Clear existing widgets in the friendsLayout
    QLayoutItem* item;
    while ((item = ui->friendsLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }

    // Add usernames as labels with checkboxes and buttons to the friendsLayout
    for (const std::string& username : usernames)
    {
        // Create a QHBoxLayout to hold the label, button, and traded label
        QHBoxLayout* hLayout = new QHBoxLayout;

        // Create a QLabel for the username
        QLabel* label = new QLabel(QString::fromStdString(username));
        hLayout->addWidget(label);

        // Create a QPushButton for the username
        QPushButton* button = new QPushButton("Trade");
        hLayout->addWidget(button);

        // Create a QLabel to indicate whether the item has been traded or not
        QLabel* tradedLabel = new QLabel("Not Traded");
        tradedLabel->setStyleSheet("color: red");
        hLayout->addWidget(tradedLabel);

        // Add the QHBoxLayout to the friendsLayout
        ui->friendsLayout->addLayout(hLayout);

        // Connect the buttonClicked() signal of the button to a slot that updates the selected item
        connect(button, &QPushButton::clicked, this, [=](){

            tradedLabel->setText("Traded");
            tradedLabel->setStyleSheet("color: green");
        });
    }
}

void Trade::on_pushButton_clicked()
{
    emit tradeToHome();
}

