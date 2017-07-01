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
  // Odblokowaie GUI i wyczyszczenie jego parametrow na poczatkowe
  void unblockAndClear();
  ~MainWindow();

 private slots:
  // Zapisywanie obrazu
  void on_actionSave_triggered();
  // Otwieranie obrazu
  void on_actionOpen_triggered();
  // Wyjscie z programu
  void on_actionExit_triggered();
  // Wyswietlenie iformacji
  void on_actionAbout_triggered();
  // Zmiana wartosci rozmiaru
  void on_spinBoxBlurUp_valueChanged(int arg1);
  // Zmiara wartosci obszaru
  void on_verticalSliderUp_valueChanged(int value);
  // Zmiana wartosci odchylenia standardowego w kierunku X, gora
  void on_doubleSpinBoxDeviationXUp_valueChanged(double arg1);
  // Zmiana wartosci odchylenia standardowego w kierunku Y, gora
  void on_doubleSpinBoxDeviationYUp_valueChanged(double arg1);
  // Zmiana wartosci odchylenia standardowego w w kierunku X, dol
  void on_doubleSpinBoxDeviationXDown_valueChanged(double arg1);
  // Zmiana wartosci odchylenia standardowego w kierunku Y, dol
  void on_doubleSpinBoxDeviationYDown_valueChanged(double arg1);
  // Zmiana wartosci rozmycia
  void on_spinBoxBlurDown_valueChanged(int arg1);
  // Zmiana wartosci obszaru
  void on_verticalSliderDown_valueChanged(int value);

private:
  // Obiekt klasy przechowujacy obraz oryginalny oraz rezultat, umozliwiajacy wykonywanie operacji na obrazie wynikowym
  TiltShift tiltShift;
  // GUI
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
