// postwidget.h

#ifndef POSTWIDGET_H
#define POSTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QFrame>
#include "post.h"

class PostWidget : public QWidget {
    Q_OBJECT
public:
    explicit PostWidget(QWidget* parent = nullptr);
    /**
     * @brief setTitle
     * @param title
     * Setter function for Title
     */
    void setTitle(const QString& title);

    /**
     * @brief setBody
     * @param body
     * Setter function for Body
     */
    void setBody(const QString& body);

    /**
     * @brief setCheckBoxFresh
     * @param freshChecked
     * Setter function for tag of Fresh water
     */
    void setCheckBoxFresh(bool freshChecked);

    /**
     * @brief setCheckBoxSalt
     * @param saltChecked
     * Setter function for tag of Salt water
     */
    void setCheckBoxSalt(bool saltChecked);

    /**
     * @brief setCheckBoxBigTank
     * @param bigTankChecked
     * Setter function for tag of Big tank
     */
    void setCheckBoxBigTank(bool bigTankChecked);
    /**
     * @brief setCheckBoxSmallTank
     * @param smallTankChecked
     * Setter function for tag of Small tank
     */
    void setCheckBoxSmallTank(bool smallTankChecked);

    /**
     * @brief getPost
     * @return
     * Getter function for post
     */
    Post* getPost() const;

    bool isChecked();
    QCheckBox* saltCheckedBox;
    QCheckBox* freshCheckedBox;
    QCheckBox* bigTankCheckedBox;
    QCheckBox* smallTankCheckedBox;


private:
    QLabel* titleLabel;
    QLabel* bodyLabel;
    QLabel* tagLabel;
    QFrame* frame;
    QVBoxLayout* layout;
    Post* post;
};

#endif // POSTWIDGET_H
