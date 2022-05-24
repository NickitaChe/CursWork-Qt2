#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    table->setMaximumHeight(60);
    table->setMaximumWidth(120);
    tEdit->setMaximumSize(120,25);
    tEdit->setText("Очередь");
    startButton->setMaximumSize(120,25);
    startButton->setText("Начать");
    nextButton->setMaximumSize(120,25);
    nextButton->setText("Создать Клиента");


    vBox->addWidget(tEdit);
    vBox->addWidget(table);
    vBox->setSpacing(0);



    bnuttonBox->addWidget(startButton);
    bnuttonBox->addWidget(nextButton);
    bnuttonBox->setSpacing(0);

    menuLayout->addLayout(masters->getLayout());
    menuLayout->addLayout(students->getLayout());
    menuLayout->addLayout(queue->getLayout());
    menuLayout->addLayout(vBox);
    menuLayout->addLayout(bnuttonBox);

    menuLayout->setSpacing(0);

    connect(startButton, SIGNAL(clicked()), this, SLOT(buttonStart()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(buttonPushed()));


    ui->verticalLayout->addLayout(menuLayout);
    ui->verticalLayout->addLayout(mastersLayout);
    ui->verticalLayout->addLayout(studentsLayout);

    connect(Timer, SIGNAL(timeout()), this, SLOT(makeTime()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateQueue(){
    table->clear();
    for (int i = 0;i < clientQueue->count() ; ++i) {
        table->addItem(QString::number(clientQueue->at(i)));
    }

}

void MainWindow::buttonPushed(){
    if(clientQueue->count() < queue->getNuber()){
        clientQueue->append(nextClientId);

        updateQueue();
    }
    nextClientId++;
}

void MainWindow::buttonStart(){
    for (int i = 0; i < masters->getNuber(); ++i ) {
        mastersList->append(new barber);
        mastersList->at(i)->setName("Мастер #" + QString::number(i));
        mastersLayout->addLayout(mastersList->at(i)->getLable(),i/4,i%4);
    }
    for (int i = 0; i < students->getNuber(); ++i ) {
        studentsList->append(new barber(false));
        studentsList->at(i)->setName("Студент #" + QString::number(i));
        studentsLayout->addLayout(studentsList->at(i)->getLable(),i/4,i%4);
    }

    Timer->start(1000);
}


void MainWindow::makeTime(){

    if(clientQueue->count()>0){
        if(mastersList->count()>0){
            for (int i = 0; i < mastersList->count() ; ++i ) {
                if(!mastersList->at(i)->getStatus()){
                    mastersList->at(i)->takeClient(clientQueue->at(0));
                    clientQueue->pop_front();
                    updateQueue();
                    return;
                }
            }
            for (int i = 0; i < studentsList->count() ; ++i ) {
                if(!studentsList->at(i)->getStatus()){
                    studentsList->at(i)->takeClient(clientQueue->at(0));
                    clientQueue->pop_front();
                    updateQueue();
                    return;
                }
            }
        }
    }
}
