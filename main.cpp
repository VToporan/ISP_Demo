#include "window.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setOverrideCursor(QCursor(Qt::BlankCursor));

    MainWindow *window = new MainWindow(nullptr);
    return app.exec();
}
