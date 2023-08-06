// postwidget.cpp

#include "postManipulation/Headers/postwidget.h"

/**
 * @brief PostWidget::PostWidget
 * @param parent
 * Post Widget constructor that handles style sheet via coding.
 */
PostWidget::PostWidget(QWidget* parent) : QWidget(parent) {
    // Create and configure labels for title, body, and tag
    titleLabel = new QLabel(this);
    titleLabel->setStyleSheet("font-weight: bold;");

    bodyLabel = new QLabel(this);
    bodyLabel->setWordWrap(true);
    bodyLabel->setFrameStyle(QFrame::Box | QFrame::Plain); // Add frame style to body label
    bodyLabel->setLineWidth(2);
    bodyLabel->setMidLineWidth(0);
    bodyLabel->setStyleSheet("padding: 5px;"); // Add padding to body label

    tagLabel = new QLabel(this);

    // Create checkboxes for fresh, salt, big tank, and small tank
    freshCheckedBox = new QCheckBox(this);
    saltCheckedBox = new QCheckBox(this);
    bigTankCheckedBox = new QCheckBox(this);
    smallTankCheckedBox = new QCheckBox(this);

    // Create a vertical layout for the widget
    layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(bodyLabel);
    layout->addWidget(tagLabel);
    layout->addWidget(freshCheckedBox);
    layout->addWidget(saltCheckedBox);
    layout->addWidget(bigTankCheckedBox);
    layout->addWidget(smallTankCheckedBox);

    setLayout(layout);

    // Initialize post pointer to nullptr
    post = nullptr;
}

/**
 * @brief PostWidget::setTitle
 * @param title
 * Setter function for title
 */
void PostWidget::setTitle(const QString& title) {
    titleLabel->setText("Title: " + title);
}

/**
 * @brief PostWidget::setBody
 * @param body
 * Setter function for Body
 */
void PostWidget::setBody(const QString& body) {
    bodyLabel->setText("Body: " + body);
}

/**
 * @brief PostWidget::setCheckBoxFresh
 * @param freshChecked
 * Setter function for checked box
 */
void PostWidget::setCheckBoxFresh(bool freshChecked) {
    freshCheckedBox->setChecked(freshChecked);
}

/**
 * @brief PostWidget::setCheckBoxSalt
 * @param saltChecked
 * Setter function for checked box
 */
void PostWidget::setCheckBoxSalt(bool saltChecked) {
    saltCheckedBox->setChecked(saltChecked);
}

/**
 * @brief PostWidget::setCheckBoxBigTank
 * @param bigTankChecked
 * Setter function for checked box
 */
void PostWidget::setCheckBoxBigTank(bool bigTankChecked){
    bigTankCheckedBox->setChecked(bigTankChecked);
}

/**
 * @brief PostWidget::setCheckBoxSmallTank
 * @param smallTankChecked
 * Setter function for checked box
 */
void PostWidget::setCheckBoxSmallTank(bool smallTankChecked){
    smallTankCheckedBox->setChecked(smallTankChecked);
}

/**
 * @brief PostWidget::getPost
 * @return
 * Getter function for post
 */
Post* PostWidget::getPost() const {
    return post;
}

/**
 * @brief PostWidget::isChecked
 * @return
 * Check function tosee if salt check box is being checked or not
 */
bool PostWidget::isChecked() {
    return saltCheckedBox->isChecked();
}
