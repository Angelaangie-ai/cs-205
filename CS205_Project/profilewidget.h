#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include "profile.h"

class ProfileWidget : public QWidget {
        Q_OBJECT
public:
    explicit ProfileWidget(QWidget* parent = nullptr);


    /**
     * @brief setName
     * @param name
     * Setter function for name
     */
    void setName        (const QString& name);

    /**
     * @brief getProfile
     * @return profile*
     * Getter function for profile
     */
    Profile* getProfile               ()const;

private:
    QLabel* nameLabel;

    QVBoxLayout* layout;

    Profile* profile;

};

#endif // PROFILEWIDGET_H

