#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QListWidget>

#include <personcontrollerwidget.h>
#include <barber.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);


    QHBoxLayout* menuLayout = new QHBoxLayout;
    QGridLayout* mastersLayout = new QGridLayout;
    QGridLayout* studentsLayout = new QGridLayout;

    QListWidget *table = new QListWidget;
    QVBoxLayout *vBox = new QVBoxLayout;
    QTextEdit *tEdit = new QTextEdit;
    QPushButton *startButton = new QPushButton;
    QPushButton *nextButton = new QPushButton;

    QVBoxLayout *bnuttonBox = new QVBoxLayout;

    personControllerWidget* masters = new personControllerWidget("Количество мастеров");
    personControllerWidget* students = new personControllerWidget("Количество учеников");
    personControllerWidget* queue = new personControllerWidget("Длинна Очереди");

    QList <barber*> *mastersList = new QList <barber*>;
    QList <barber*> *studentsList = new QList <barber*>;
    QList <int> *clientQueue = new QList <int>;

    QTimer *Timer = new QTimer();

    int nextClientId = 0;
    void updateQueue();

    ~MainWindow();

public slots:
    void buttonPushed();
    void buttonStart();
    void makeTime();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
