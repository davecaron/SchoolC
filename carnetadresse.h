
class CarnetAdresse : public QWidget
{
    Q_OBJECT

public:
    CarnetAdresse(QWidget *parent = 0);

private:
    QLineEdit *nameLine;
    QTextEdit *addressText;
};
