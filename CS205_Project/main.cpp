#include "userManagement/Headers/login.h"
#include "userManagement/Headers/registration.h"
#include "pagestack.h"
#include "userManagement/Headers/preference.h"
#include "Communication/Headers/chat.h"
#include "trade.h"
#include "Communication/Headers/friends.h"
#include "Screens/Headers/home.h"
#include "achievement.h"
#include "Screens/Headers/education.h"
#include "PostManipulation/Headers/post.h"
#include "userManagement/Headers/admin.h"
#include "userManagement/Headers/user.h"
#include "Database/Headers/database.h"
#include "profile.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QObject>
#include <QStackedWidget>
#include <QLocale>
#include <QTranslator>
#include <QWidget>
#include <QVBoxLayout>
#include "gtest.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "CS205_Project_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // Create a main window and set its layout
    QWidget mainWindow;
    QVBoxLayout *layout = new QVBoxLayout();
    mainWindow.setLayout(layout);



    // Create a PageStack object and add it to the layout
    testing::InitGoogleTest(&argc, argv);

    RUN_ALL_TESTS();
    PageStack ps;
    layout->addWidget(ps.s);
    mainWindow.resize(mainWindow.maximumSize());
    mainWindow.show();
    return a.exec();


        //testing::InitGoogleTest(&argc, argv);




}
