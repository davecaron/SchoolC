#include <QApplication>
#include <QFont> 
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QWidget window;
    window.resize(200, 120);
  
    QPushButton quit("Quitter", &window);
    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    window.show();
    return app.exec();
