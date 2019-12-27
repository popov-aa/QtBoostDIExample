#include "DataSources/PermissionsContainer.h"
#include "Dialogs/AboutDialog.h"
#include "Dialogs/ConnectionDialog.h"
#include "Dialogs/MainWindow.h"
#include "Models/PermissionsModel.h"
#include "Service/ConnectionService.h"
#include "Widgets/UserWidget.h"

#include <QApplication>
#include <QWidget>
#include <boost/di.hpp>
#include <boost/di/extension/injections/factory.hpp>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    auto injector = boost::di::make_injector(
        boost::di::bind<PermissionsContainer>(),
        boost::di::bind<PermissionsModel>(),
        boost::di::bind<ConnectionService>(),
        boost::di::bind<boost::di::extension::ifactory<AboutDialog>>().to(boost::di::extension::factory<AboutDialog> {}),
        boost::di::bind<boost::di::extension::ifactory<UserWidget, QString>>().to(boost::di::extension::factory<UserWidget> {}),
        boost::di::bind<boost::di::extension::ifactory<ConnectionDialog>>().to(boost::di::extension::factory<ConnectionDialog> {}),
        boost::di::bind<MainWindow>());

    boost::di::create<MainWindow*>(injector)->show();

    return app.exec();
}
