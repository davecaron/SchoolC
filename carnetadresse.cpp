#include "carnetadresse.h"
#include "annuaire.h"

CarnetAdresse::CarnetAdresse(QWidget *parent)
    : QWidget(parent)
{
    QLabel *nameLabel = new QLabel(tr("Nom:"));
    nameLine = new QLineEdit;
    nameLine->setReadOnly(true);

    QLabel *addressLabel = new QLabel(tr("Annuaire:"));
    addressText = new QTextEdit;
    addressText->setReadOnly(true);
        
    addButton = new QPushButton(tr("&Ajouter"));
    addButton->show();
    submitButton = new QPushButton(tr("&Soumettre"));
    submitButton->hide();
    cancelButton = new QPushButton(tr("&Annuler"));
    cancelButton->hide();
        
    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(addButton, Qt::AlignTop);
    buttonLayout1->addWidget(submitButton);
    buttonLayout1->addWidget(cancelButton);
    buttonLayout1->addStretch();
    
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(nameLine, 0, 1);
    mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(addressText, 1, 1);
    mainLayout->addLayout(buttonLayout1, 1, 2);
    
    setLayout(mainLayout);
    setWindowTitle(tr("Annuaire"));
}
