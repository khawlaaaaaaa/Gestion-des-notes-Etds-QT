QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
#LIBS += -lsqlite3  # Remove this line, use QT += sql instead
# ...

SOURCES += \
    administration.cpp \
    enseignant.cpp \
    etudiant.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    administration.h \
    dbheader.h \
    enseignant.h \
    etudiant.h \
    mainwindow.h

FORMS += \
    administration.ui \
    enseignant.ui \
    etudiant.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
