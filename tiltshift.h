#ifndef TILTSHIFT_H
#define TILTSHIFT_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
class TiltShift {
 public:
  // Konstruktor domyslny
  TiltShift();
  // Konstruktor za pomoca ktorego wczytujemy obraz oryginalny, tworzymy jego kopie (rezultat) oraz inicjalizujemy podstawowe parametry
  TiltShift(const std::string& filename);
  // Destruktor
  ~TiltShift();
  // Metoda wyswietlajaca obraz oryginalny oraz rezultat
  void showImg() const;
  // Metoda do zapisywania obrazu wynikowego
  void saveResult(const std::string& filename) const;
  // Sprawdza czy otworzono plik z obrazem
  inline bool ifImagesOpen() const { return image.data ? true : false; }
  // Metoda odpowiedzialna za rozmycie obrazu
  void gaussianBlur();

 private:
  // Zmienna przechowujaca oryginalny rozmiar
  cv::Mat image;
  // Zmienna przechowujaca obraz wynikowy
  cv::Mat result;
 public:
  // Obszar rozmycia wyrazony jako liczba od 1 do 99 (99 to wysokosc maksymalna rowna 1/2 obrazu od gory)
  int upHeight;
  // Obszar rozmycia wyrazony jako liczba od 1 do 99 (99 to wysokosc maksymalna obrazu liczac od 1/2 obrazu)
  int downHeight;
  // Rozmiar gornego rozmycia
  int upSize;
  // Rozmiar dolnego rozmycia
  int downSize;
  // Odchylenie standardowe w kierunku X, rozmycie gorne
  double upSigmaX;
  // Odchylenie standardowe w kierunku Y, rozmycie gorne
  double upSigmaY;
  // Odchylenie standardowe w kierunku X, rozmycie dolne
  double downSigmaX;
  // Odchylenie standardowe w kierunku Y, rozmycie dolne
  double downSigmaY;
};

#endif  // TILTSHIFT_H
