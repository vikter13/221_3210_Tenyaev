#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void login();
    void openPromo();

private:
    Ui::MainWindow *ui;
    QVector<QString> promoCodes;
    QVector<QPushButton*> promoCard;

    void createPromo();
    void addPromo();
    QString generateCode();
};
#endif // MAINWINDOW_H
