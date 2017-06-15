#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  cv::Mat image = cv::imread("D://Qt//Project//AO//test.jpg", 1);

  cv::namedWindow("My Image");

  cv::imshow("My Image", image);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QMessageBox::information(this, "title", "Open");
}

void MainWindow::on_actionSave_triggered()
{
    QMessageBox::information(this, "title", "Save");
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "title", "About");
}
