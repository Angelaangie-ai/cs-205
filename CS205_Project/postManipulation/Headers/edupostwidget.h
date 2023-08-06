#ifndef EDUPOSTWIDGET_H
#define EDUPOSTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include "post.h"


class eduPostWidget : public QWidget {
    Q_OBJECT
public:
    explicit eduPostWidget(QWidget* parent = nullptr);

    void setTitle(const QString& title);
    void setDescription(const QString& description);
    void setCheckBoxGeneral(bool generalCheckedBox);
    void setCheckBoxSpecific(bool specificCheckedBox);
    void setSource(const QString& source);
    void setUser(const QString& user);
    Post* getPost() const; // Declaration of getPost() function
    bool isChecked();
    QCheckBox* generalCheckedBox;
    QCheckBox* specificCheckedBox;
    QLabel* userLabel;


private:
    QLabel* descriptionLabel;
    QLabel* titleLabel;
    QLabel* sourceLabel;
    QVBoxLayout* layout;
    Post* post;
};

#endif // EDUPOSTWIDGET_H
