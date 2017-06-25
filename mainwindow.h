#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tiltshift.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  void unblockAndClear();
  ~MainWindow();

 private slots:

  void on_actionSave_triggered();

  void on_actionOpen_triggered();

  void on_actionExit_triggered();

  void on_actionAbout_triggered();

  void on_spinBoxBlurUp_valueChanged(int arg1);

  void on_verticalSliderUp_valueChanged(int value);

  void on_doubleSpinBoxDeviationXUp_valueChanged(double arg1);

  void on_doubleSpinBoxDeviationYUp_valueChanged(double arg1);

  void on_doubleSpinBoxDeviationXDown_valueChanged(double arg1);

  void on_doubleSpinBoxDeviationYDown_valueChanged(double arg1);

  void on_spinBoxBlurDown_valueChanged(int arg1);

  void on_verticalSliderDown_valueChanged(int value);

private:
  TiltShift tiltShift;
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
