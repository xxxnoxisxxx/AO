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
      this, tr("Otwórz plik"), QString(),
      tr("Plik graficzny (*.png *.jpg *.bmp *.jpeg)"));

  if (filename.isEmpty())
    return;

  this->tiltShift = TiltShift(filename.toStdString());

  if (this->tiltShift.ifImagesOpen()) {
    this->tiltShift.showImg();
    ui->actionSave->setEnabled(true);
    this->unblockAndClear();
  } else {
    QMessageBox::critical(this, "Błąd", "Nie udało się wczytać obrazu.");
    ui->actionSave->setEnabled(false);
  }
}

void MainWindow::on_actionSave_triggered() {
  QString filename = QFileDialog::getSaveFileName(
      this, tr("Zapisz wynik"), "",
      tr("Pliki graficzne (*.png *.jpg *.bmp *.jpeg)"));
  if (!filename.isEmpty()) {
    this->tiltShift.saveResult(filename.toStdString());
    QMessageBox::information(this, "Zapisano!", filename);
  }
}

void MainWindow::on_actionExit_triggered() {
  QApplication::quit();
}

void MainWindow::on_actionAbout_triggered() {
  QMessageBox::information(this, "Informacje", "Program napisany w ramach projektu z przedmiotu Analiza i przetwarzanie obrazów.");
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

void MainWindow::unblockAndClear() {
    this->ui->spinBoxBlurDown->setEnabled(true);
    this->ui->spinBoxBlurUp->setEnabled(true);
    this->ui->verticalSliderDown->setEnabled(true);
    this->ui->verticalSliderUp->setEnabled(true);
    this->ui->doubleSpinBoxDeviationXDown->setEnabled(true);
    this->ui->doubleSpinBoxDeviationXUp->setEnabled(true);
    this->ui->doubleSpinBoxDeviationYDown->setEnabled(true);
    this->ui->doubleSpinBoxDeviationYUp->setEnabled(true);

    this->ui->spinBoxBlurDown->setValue(1);
    this->ui->spinBoxBlurUp->setValue(1);
    this->ui->verticalSliderUp->setValue(1);
    this->ui->verticalSliderDown->setValue(1);
    this->ui->doubleSpinBoxDeviationXDown->setValue(0.00);
    this->ui->doubleSpinBoxDeviationXUp->setValue(0.00);
    this->ui->doubleSpinBoxDeviationYDown->setValue(0.00);
    this->ui->doubleSpinBoxDeviationYUp->setValue(0.00);

    this->ui->spinBoxBlurDown->setFocusPolicy(Qt::StrongFocus);
    this->ui->spinBoxBlurUp->setFocusPolicy(Qt::StrongFocus);
}
