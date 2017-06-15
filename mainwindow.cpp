#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include "iostream"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_actionOpen_triggered() {
  QString filename = QFileDialog::getOpenFileName(
      this, tr("Open File"), QString(),
      tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));

  if (filename.isEmpty())
    return;

  this->tiltShift = TiltShift(filename.toStdString());

  if (this->tiltShift.ifImagesOpen()) {
    this->tiltShift.showImg();
    ui->actionSave->setEnabled(true);
  } else {
    QMessageBox::critical(this, "Error", "Could not open or find the image.");
    ui->actionSave->setEnabled(false);
  }
}

void MainWindow::on_actionSave_triggered() {
  QString filename = QFileDialog::getSaveFileName(
      this, tr("Save result"), "",
      tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
  if (!filename.isEmpty()) {
    this->tiltShift.saveResult(filename.toStdString());
    QMessageBox::information(this, "Completed!", filename);
  }
}

void MainWindow::on_actionExit_triggered() {
  QApplication::quit();
}

void MainWindow::on_actionAbout_triggered() {
  QMessageBox::information(this, "title", "About");
}

void MainWindow::on_spinBoxBlurUp_valueChanged(int value)
{
    this->tiltShift.upSize = value;
    this->tiltShift.gaussianBlur();
}

void MainWindow::on_verticalSliderUp_valueChanged(int value)
{
    this->tiltShift.upHeight = value;
    this->tiltShift.gaussianBlur();
}

void MainWindow::on_doubleSpinBoxDeviationXUp_valueChanged(double value)
{
    this->tiltShift.upSigmaX = value;
    this->tiltShift.gaussianBlur();
}

void MainWindow::on_doubleSpinBoxDeviationYUp_valueChanged(double value)
{
    this->tiltShift.upSigmaY = value;
    this->tiltShift.gaussianBlur();
}

void MainWindow::on_spinBoxBlurDown_valueChanged(int size)
{
    this->tiltShift.downSize = size;
    this->tiltShift.gaussianBlur();
}

void MainWindow::on_doubleSpinBoxDeviationXDown_valueChanged(double value)
{
    this->tiltShift.downSigmaX = value;
    this->tiltShift.gaussianBlur();
}

void MainWindow::on_doubleSpinBoxDeviationYDown_valueChanged(double value)
{
    this->tiltShift.downSigmaY = value;
    this->tiltShift.gaussianBlur();
}

void MainWindow::on_verticalSliderDown_valueChanged(int value)
{
    this->tiltShift.downHeight = value;
    this->tiltShift.gaussianBlur();
}
