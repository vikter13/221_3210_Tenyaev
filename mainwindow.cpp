#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditPin->setEchoMode(QLineEdit::Password);

    connect(ui->pushButtonLogin, &QPushButton::clicked, this, &MainWindow::login);
    connect(ui->pushButtonOpenPromo, &QPushButton::clicked, this, &MainWindow::openPromo);

    createPromo();
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::generateCode()
{
    const QString characters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 4;

    QString randomString;
    for (int i = 0; i < randomStringLength; ++i) {
        int index = QRandomGenerator::global()->bounded(characters.length());
        QChar nextChar = characters.at(index);
        randomString.append(nextChar);
    }

    return randomString;
}


void MainWindow::addPromo()
{
    QString newCode = generateCode();
    promoCodes.append(newCode);

    QPushButton *newPromoCard = new QPushButton("Промокод");
    newPromoCard->setFixedSize(200, 100);

    int row = promoCard.size() / 2;
    int col = promoCard.size() % 2;

    QGridLayout *layout = qobject_cast<QGridLayout*>(ui->promoCodesPage->layout());
    if (layout) {
        layout->addWidget(newPromoCard, row, col);
    }

    promoCard.append(newPromoCard);
}


void MainWindow::login()
{
    const QString correctPin = "1488";

    if (ui->lineEditPin->text() == correctPin) {
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        ui->label->setText("Неверный пин!");
        ui->label->setStyleSheet("color:red");
    }
}


void MainWindow::createPromo()
{
    QGridLayout *layout = new QGridLayout;
    ui->promoCodesPage->setLayout(layout);

    qDeleteAll(promoCard);
    promoCard.clear();

    for (int i = 0; i < 9; ++i) {
        addPromo();
    }
}


void MainWindow::openPromo()
{
    int randomIndex = QRandomGenerator::global()->bounded(promoCard.size());
    promoCard[randomIndex]->setText(promoCodes[randomIndex]);
    promoCard[randomIndex]->setStyleSheet("color:green");

    addPromo();
}







