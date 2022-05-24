#ifndef BARBER_H
#define BARBER_H

#include <QVBoxLayout>
#include <QString>
#include <QTextEdit>
#include <QSpinBox>
#include <QTimer>
#include <QPushButton>

class barber : QWidget
{
    Q_OBJECT
public:
    barber(bool master = true);// master - true, student false;

    QVBoxLayout* getLable();
    void takeClient(int id);
    void setName(QString);
    bool getStatus(); //t - active f - unactive

private:
    int speed = 5;

    QVBoxLayout* vBox = new QVBoxLayout;
    QTextEdit* name = new QTextEdit;
    QTextEdit* client = new QTextEdit;
    QTextEdit* timeText = new QTextEdit;
    QTimer *Timer = new QTimer();
    int timeInt = 0;


public slots:
    void makeTime();
};

#endif // BARBER_H
