
QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_emprunt.cpp \
    add_modifyadherent.cpp \
    add_modifyauteur.cpp \
    add_modifyexemplaire.cpp \
    add_modifylivre.cpp \
    adherent.cpp \
    adherentwindow.cpp \
    aidewidget.cpp \
    aproposwidget.cpp \
    auteur.cpp \
    auteurwindow.cpp \
    connexionbd.cpp \
    emprunt.cpp \
    empruntwindow.cpp \
    exemplaire.cpp \
    exemplairewindow.cpp \
    livre.cpp \
    livrewindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    add_emprunt.h \
    add_modifyadherent.h \
    add_modifyauteur.h \
    add_modifyexemplaire.h \
    add_modifylivre.h \
    adherent.h \
    adherentwindow.h \
    aidewidget.h \
    aproposwidget.h \
    auteur.h \
    auteurwindow.h \
    connexionbd.h \
    emprunt.h \
    empruntwindow.h \
    exemplaire.h \
    exemplairewindow.h \
    livre.h \
    livrewindow.h \
    mainwindow.h

FORMS += \
    add_emprunt.ui \
    add_modifyadherent.ui \
    add_modifyauteur.ui \
    add_modifyexemplaire.ui \
    add_modifylivre.ui \
    adherentwindow.ui \
    aidewidget.ui \
    aproposwidget.ui \
    auteurwindow.ui \
    empruntwindow.ui \
    exemplairewindow.ui \
    livrewindow.ui \
    mainwindow.ui

TRANSLATIONS += \
    GestionBibliotheque_en_CM.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
