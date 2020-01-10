#include "DataSources/PermissionsContainerImpl.h"
#include "Dialogs/AboutDialog.h"
#include "Dialogs/ConnectionDialog.h"
#include "Dialogs/MainWindow.h"
#include "Models/PermissionsModel.h"
#include "Service/ConnectionService.h"
#include "Widgets/UserWidget.h"

#include "boost/di/extension/injections/named_parameters.hpp"
#include <QApplication>
#include <QWidget>
#include <boost/di.hpp>
#include <boost/di/extension/injections/factory.hpp>

int main(int argc, char* argv[])
{
    using namespace boost::di::extension;

    QApplication app(argc, argv);

    auto injector = boost::di::make_injector(
        boost::di::bind<int>().to(42),
        boost::di::bind<int>().named("toto"_s).to(72),
        boost::di::bind<PermissionsContainer>().to<PermissionsContainerImpl>(),
        boost::di::bind<PermissionsModel>(),
        boost::di::bind<ConnectionService>(),
        boost::di::bind<boost::di::extension::ifactory<AboutDialog>>().to(boost::di::extension::factory<AboutDialog> {}),
        boost::di::bind<boost::di::extension::ifactory<UserWidget, QString>>().to(boost::di::extension::factory<UserWidget> {}),
        boost::di::bind<boost::di::extension::ifactory<ConnectionDialog>>().to(boost::di::extension::factory<ConnectionDialog> {}),
        boost::di::bind<MainWindow>());
    injector.create<MainWindow*>()->show();

    return app.exec();
}
