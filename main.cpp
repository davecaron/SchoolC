#include <QApplication>
#include <QFont> 
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
  
    QPushButton quit("Quitter");
    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    quit.show();
    return app.exec();
