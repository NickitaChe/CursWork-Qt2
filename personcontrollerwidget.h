#ifndef PERSONCONTROLLERWIDGET_H
#define PERSONCONTROLLERWIDGET_H


#include <QVBoxLayout>
#include <QString>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>

class personControllerWidget : QWidget
{
public:
    void setName(QString t);
    int getNuber();
    QPushButton* getButton();
    QVBoxLayout *getLayout();
    personControllerWidget(QString t  = "Временное");

private:
    QPushButton* pButton = new QPushButton;
    QVBoxLayout* vBox = new QVBoxLayout;
    QTextEdit* tEdit = new QTextEdit;
    QSpinBox* sBox = new QSpinBox;

};

#endif // PERSONCONTROLLERWIDGET_H
