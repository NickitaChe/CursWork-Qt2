#include "barber.h"

barber::barber(bool master)
{
    if(master == false){
        speed = 10;
    }

    name->setMaximumSize(100,25);
    client->setMaximumSize(100,25);
    timeText->setMaximumSize(100,25);

    timeText->setText("Свободен");
    client->setText("Свободен");

    vBox->setSpacing(0);

    vBox->addWidget(name);
    vBox->addWidget(client);
    vBox->addWidget(timeText);

    connect(Timer, SIGNAL(timeout()), this, SLOT(makeTime()));
}

void barber::setName(QString str){
    name->setText(str);
}

void barber::takeClient(int id){
    timeInt = speed;
    client->setText("Клиент#" + QString::number(id));

    timeInt = speed;
    Timer->start(1000);

}

void barber::makeTime(){
    timeInt--;
    timeText->setText("Осталось " + QString::number(timeInt));


    if(timeInt <= 0){
        Timer->stop();
        timeText->setText("Свободен");
        client->setText("Свободен");
        timeInt = 0;
    }

}


bool barber::getStatus(){
    if(timeText->toPlainText() == "Свободен")

        return false;

    return true;
}


QVBoxLayout* barber::getLable(){
    return vBox;
}
