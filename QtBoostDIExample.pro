QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += \
    src \
    boost-di/include \
    boost-di/extension/include

SOURCES += \
    src/DataSources/PermissionsContainerImpl.cpp \
    src/DataSources/VersionInformation.cpp \
    src/Dialogs/AboutDialog.cpp \
    src/Dialogs/ConnectionDialog.cpp \
    src/Service/ConnectionService.cpp \
    src/main.cpp \
    src/Dialogs/MainWindow.cpp \
    src/Models/PermissionsModel.cpp \
    src/Widgets/UserWidget.cpp

HEADERS += \
    src/DataSources/PermissionsContainer.h \
    src/DataSources/PermissionsContainerImpl.h \
    src/DataSources/VersionInformation.h \
    src/Dialogs/AboutDialog.h \
    src/Dialogs/ConnectionDialog.h \
    src/Dialogs/MainWindow.h \
    src/DataTypes/Permission.h \
    src/Models/PermissionsModel.h \
    src/Service/ConnectionService.h \
    src/Widgets/UserWidget.h

FORMS += \
    src/Dialogs/AboutDialog.ui \
    src/Dialogs/ConnectionDialog.ui \
    src/Dialogs/MainWindow.ui \
    src/Widgets/UserWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
