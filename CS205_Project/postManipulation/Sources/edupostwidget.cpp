#include "postManipulation/Headers/edupostwidget.h"

eduPostWidget::eduPostWidget(QWidget* parent) : QWidget(parent)
{
    titleLabel = new QLabel(this);
    descriptionLabel = new QLabel (this);
    sourceLabel = new QLabel (this);
    userLabel = new QLabel(this);
    generalCheckedBox = new QCheckBox(this);
    specificCheckedBox = new QCheckBox(this);

    // Create a vertical layout for the widget
    layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(userLabel);
    layout->addWidget(descriptionLabel);
    layout->addWidget(sourceLabel);
    layout->addWidget(generalCheckedBox);
    layout->addWidget(specificCheckedBox);

    setLayout(layout);

    // Initialize post pointer to nullptr
    post = nullptr;

}

/**
 * @brief eduPostWidget::setTitle
 * @param title
 * Setter function for title
 */
void eduPostWidget::setTitle(const QString& title) {
    titleLabel->setText("Title: " + title);
}

/**
 * @brief eduPostWidget::setDescription
 * @param description
 * Setter function for description
 */
void eduPostWidget::setDescription(const QString& description){
    descriptionLabel->setText("Body: " + description);
}

/**
 * @brief eduPostWidget::setCheckBoxGeneral
 * @param generalChecked
 * Setter function for general knowlege check box
 */
void eduPostWidget::setCheckBoxGeneral(bool generalChecked){
    generalCheckedBox -> setChecked(generalChecked);
}


/**
 * @brief eduPostWidget::setCheckBoxSpecific
 * @param specificChecked
 * Setter function for specific knowlege check box
 */
void eduPostWidget::setCheckBoxSpecific(bool specificChecked) {
    specificCheckedBox -> setChecked(specificChecked);
}

/**
 * @brief eduPostWidget::setUser
 * @param user
 * Setter function for user
 */
void eduPostWidget::setUser(const QString& user) {
    userLabel -> setText("User: " + user);
}

/**
 * @brief eduPostWidget::setSource
 * @param source
 * Setter function for source
 */
void eduPostWidget::setSource(const QString& source){
    sourceLabel->setText("Source: " + source);
}


/**
 * @brief eduPostWidget::getPost
 * @return
 * Getter function for post
 */
Post* eduPostWidget::getPost() const {
    return post;
}
