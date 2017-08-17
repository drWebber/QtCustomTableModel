#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new CustomTableModel();
    proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(model);

    ui->tableView->setModel(proxy);
    model->appendItem("Яблоко", "Яблоко \"Анталия\ 1кг", 2.4, "В продаже");
    model->appendItem("Молоко",  "Молоко \"Вкусное\" 1л", 0.99, "В продаже");
    model->appendItem("Колбаса", "Колбаса в/с \"Докторская\"", 3.12, "В ассортименте");
}

MainWindow::~MainWindow()
{
    delete ui;
}
