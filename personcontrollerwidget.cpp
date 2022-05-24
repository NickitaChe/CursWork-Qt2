#include "personcontrollerwidget.h"

personControllerWidget::personControllerWidget(QString t)
{
    sBox->setValue(1);

    tEdit->setMaximumSize(80,40);
    sBox->setMaximumSize(80,40);

    setName(t);
    vBox->addWidget(tEdit);
    vBox->addWidget(sBox);

}



void personControllerWidget::setName(QString t){

    tEdit->setText(t);
}

int personControllerWidget::getNuber(){

    return sBox->value();
}

QVBoxLayout *personControllerWidget::getLayout(){

    return vBox;
}


