class CarnetAdresse : public QWidget

{
    Q_OBJECT

public:
    CarnetAdresse(QWidget *parent = 0);
    void addContact();
    void submitContact();
    void cancel();

private:
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QLineEdit *nameLine;
    QTextEdit *addressText;
    QMap<QString, QString> contacts;
    QString oldName;
    QString oldAddress;
};
