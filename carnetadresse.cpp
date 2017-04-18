#include "carnetadresse.h"
#include "annuaire.h"
#include <QtGui>
#include <QDialog>

CarnetAdresse::CarnetAdresse(QWidget *parent)
    : QWidget(parent)
{

    QLabel *addressLabel = new QLabel(tr("Personne:"));
    addressText = new QTextEdit;
    addressText->setReadOnly(true);
        
    ajouterButton = new QPushButton(tr("&Ajouter"));
    ajouterButton->show();
    suivantButton = new QPushButton(tr("&Suivant"));
    suivantButton->show();
    precedentButton = new QPushButton(tr("&Précédent"));
    precendentButton->show();
        
    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(ajouterButton, Qt::AlignTop);
    buttonLayout1->addWidget(suivantButton);
    buttonLayout1->addWidget(precedentButton);
    buttonLayout1->addStretch();
    
    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(addressText, 1, 1);
    mainLayout->addLayout(buttonLayout1, 1, 2);
    
    setLayout(mainLayout);
    setWindowTitle(tr("Annuaire"));
}
