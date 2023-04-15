#include "window.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();
    return app.exec();
}

#include "main.moc"
