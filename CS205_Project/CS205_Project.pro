TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle

QT += core                # this should be added
QT += sql                 # this should be added

QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    Admin_Tests.cpp \
    Chat_Tests.cpp \
    Communication/Sources/chat.cpp \
    Communication/Sources/chatmessage.cpp \
    Communication/Sources/friends.cpp \
    Communication/Sources/message.cpp \
    Database/Sources/database.cpp \
    Education_Test.cpp \
    Post_test.cpp \
    Screens/Sources/education.cpp \
    Screens/Sources/home.cpp \
    achievement.cpp \
    box.cpp \
    main.cpp \
    mainwindow.cpp \
    pagestack.cpp \
    postManipulation/Sources/edupostwidget.cpp \
    postManipulation/Sources/post.cpp \
    postManipulation/Sources/postwidget.cpp \
    profile.cpp \
    profilewidget.cpp \
    trade.cpp \
    tradeitem.cpp \
    ../BackEngine/register.cpp \
    ../gtest/googletest/src/gtest-all.cc \
    userManagement/Sources/admin.cpp \
    userManagement/Sources/login.cpp \
    userManagement/Sources/preference.cpp \
    userManagement/Sources/registration.cpp \
    userManagement/Sources/user.cpp
INCLUDEPATH += ../gtest  \
                        ../gtest/googletest \
                        ../gtest/googletest/include \
                        ../gtest/googletest/include/gtest

HEADERS += \
    Communication/Headers/chat.h \
    Communication/Headers/chatmessage.h \
    Communication/Headers/friends.h \
    Communication/Headers/message.h \
    Database/Headers/database.h \
    Screens/Headers/education.h \
    Screens/Headers/home.h \
    Screens/Headers/mainwindow.h \
    achievement.h \
    box.h \
    database.h \
    edupostwidget.h \
    database.h \
    friends.h \
    education.h \
    login.h \
    mainwindow.h \
    pagestack.h \
    post.h \
    postManipulation/Headers/edupostwidget.h \
    postManipulation/Headers/post.h \
    postManipulation/Headers/postwidget.h \
    postwidget.h \
    preference.h \
    profile.h \
    profilewidget.h \
    trade.h \
    tradeitem.h \
    user.h \
    ../BackEngine/register.h\
    userManagement/Headers/achievement.h \
    userManagement/Headers/admin.h \
    userManagement/Headers/login.h \
    userManagement/Headers/preference.h \
    userManagement/Headers/registration.h \
    userManagement/Headers/user.h

FORMS += \
    achievement.ui \
    admin.ui \
    chat.ui \
    friends.ui \
    education.ui \
    home.ui \
    login.ui \
    mainwindow.ui \
    post.ui \
    preference.ui \
    profile.ui \
    registration.ui \
    trade.ui


RESOURCES += \
    Resources.qrc \
    Resources.qrc

DISTFILES += \
    CS205_Project_en_US.ts \
    FishDB/sql/build_tables.sql \
    FishDB/sql/drop_tables.sql \
    NicePng_png-ballons_4121775.png \
    achievements.csv \
    admin.png \
    build_tables.sql \
    clipart4273239.png \
    clipart4449882.png \
    communicate.csv \
    drop_tables.sql \
    education_post.csv \
    fish-logo.png \
    friends.csv \
    friends.png \
    kindpng_1973521.png \
    logo.jpg \
    post_manip.csv \
    prefs.csv \
    trade.csv \
    user.csv \
    userDB.sqlite \
    wind-wave-cartoon-water-waves-6e912dfb99f8506682a88de1e14af64b.png
