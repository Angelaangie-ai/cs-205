#include "profilewidget.h"

/**
 * @brief ProfileWidget::ProfileWidget
 * @param parent
 * ProfileWidget constructor to change its stylesheet
 */
ProfileWidget::ProfileWidget(QWidget* parent) : QWidget(parent){

    // Create and configure labels for title, body, and tag
    nameLabel = new QLabel(this);

    // Create a vertical layout for the widget
    layout = new QVBoxLayout(this);

    layout->addWidget(nameLabel);

    setLayout(layout);

    // Initialize post pointer to nullptr
    profile = nullptr;
}

/**
 * @brief ProfileWidget::setName
 * @param name
 * Setter for name
 */
void ProfileWidget::setName(const QString& name){
    nameLabel->setText("Username: " + name);
}

/**
 * @brief ProfileWidget::getProfile
 * @return
 * Getter for profile object
 */
Profile* ProfileWidget::getProfile() const {
    return profile;
}
