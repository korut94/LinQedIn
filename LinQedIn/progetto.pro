#-------------------------------------------------
#
# Project created by QtCreator 2014-12-15T19:24:02
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinQedIn
TEMPLATE = app

SOURCES += main.cpp\
    utente.cpp \
    info.cpp \
    smartclass.cpp \
    database.cpp \
    sortgrouputente.cpp \
    hashgrouputente.cpp \
    smartptr_utente.cpp \
    searchgrouputente.cpp \
    frankenstein.cpp \
    entity.cpp \
    query.cpp \
    smartptr_entity.cpp \
    mainwindow.cpp \
    mainwindow_controller.cpp \
    mainwindow_model.cpp \
    mainwindow_view.cpp \
    riconoscimenti.cpp \
    link.cpp \
    admininterface_model.cpp \
    admininterface_view.cpp \
    admininterface_controller.cpp \
    tableusers.cpp \
    labeltools.cpp \
    usersearch.cpp \
    lineeditvalidate.cpp \
    userinterface_view.cpp \
    userinterface_model.cpp \
    userinterface_controller.cpp \
    usereditpage.cpp \
    boardfriends.cpp \
    top.cpp \
    viewexperience.cpp \
    id.cpp \
    line.cpp \
    experience.cpp \
    personal.cpp \
    skill.cpp \
    moduleid.cpp \
    moduleskills.cpp \
    moduleexperience.cpp \
    usermodified.cpp \
    userinsert.cpp \
    moduleeducation.cpp \
    moduleaccout.cpp \
    utentebasic.cpp \
    utentebusiness.cpp \
    utenteexecutive.cpp \
    useritem.cpp \
    login.cpp \
	databaseio.cpp \
    databasexmlfile.cpp \
    viewbasic.cpp \
    viewbase.cpp \
    viewbusiness.cpp \
    viewi.cpp \
    viewexecutive.cpp \
    viewother.cpp \
    databasefile.cpp \
    modulequalifica.cpp \
    moduleskill.cpp \
    modulestudio.cpp \
    usermodified_utente.cpp \
    usermodified_admin.cpp

HEADERS  += \
    utente.h \
    info.h \
    smartclass.h \
    sortlist.h \
    database.h \
    sortgrouputente.h \
    hashgrouputente.h \
    smartptr_utente.h \
    hashlistutente.h \
    searchgrouputente.h \
    frankenstein.h \
    query.h \
    entity.h \
    smartptr_entity.h \
    mainwindow.h \
    mainwindow_controller.h \
    mainwindow_model.h \
    mainwindow_view.h \
    riconoscimenti.h \
    link.h \
    admininterface_model.h \
    admininterface_view.h \
    admininterface_controller.h \
    tableusers.h \
    labeltools.h \
    usersearch.h \
    lineeditvalidate.h \
    userinterface_view.h \
    userinterface_model.h \
    userinterface_controller.h \
    usereditpage.h \
    boardfriends.h \
    levelaccess.h \
    top.h \
    viewexperience.h \
    id.h \
    line.h \
    experience.h \
    personal.h \
    skill.h \
    moduleid.h \
    moduleskills.h \
    moduleexperience.h \
    usermodified.h \
    userinsert.h \
    moduleeducation.h \
    moduleaccout.h \
    errorstate.h \
    utentebasic.h \
    utentebusiness.h \
    utenteexecutive.h \
    useritem.h \
    login.h \
	databaseio.h \
    databasexmlfile.h \ 
    viewbasic.h \
    viewbase.h \
    viewbusiness.h \
    viewi.h \
    viewexecutive.h \
    viewother.h \
    databasefile.h \
    modulequalifica.h \
    moduleskill.h \
    modulestudio.h \
    usermodified_utente.h \
    usermodified_admin.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    LICENCE.txt \
    User.png \
    User_40x30.png \
    User_48x36.png \
    User_90x80.png \
    User_100x100.png \
    User_150x114.png \
    ../../../Dropbox/UNIPD/Corsi/Informatica/Secondo Anno/Programmazione ad oggetti/relazione.pdf \
    ../relazione.pdf
