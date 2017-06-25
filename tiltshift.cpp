#include "tiltshift.h"
TiltShift::TiltShift() {}

TiltShift::TiltShift(const std::string& filename) {
  this->downSigmaX = this->downSigmaY = this->upSigmaX = this->upSigmaY = 0;
  this->upSize = this->downSize = this->upHeight = this->downHeight = 1;
  this->image = cv::imread(filename, 1);
  this->result = this->image.clone();
}

TiltShift::~TiltShift() {
  cv::destroyAllWindows();
}

void TiltShift::showImg() const {
  cv::namedWindow("Obraz oryginalny");
  cv::namedWindow("Rezultat");
  cv::imshow("Obraz oryginalny", image);
  cv::imshow("Rezultat", result);
}

void TiltShift::saveResult(const std::string& filename) const {
  cv::imwrite(filename, this->result);
}

void TiltShift::gaussianBlur() {
  this->result.release();
  this->result = this->image.clone();

  // Gorne rozmycie
  int endPoint = int(this->image.rows / 2 * double(this->upHeight) / 100.);
  cv::Mat imgUp = this->result(cv::Rect(0, 0, this->image.cols, endPoint));

  cv::Mat imgUpBlur;
  cv::GaussianBlur(imgUp, imgUpBlur, cv::Size(this->upSize, this->upSize),
                   this->upSigmaX, this->upSigmaY);

  for (int i = 0; i < imgUpBlur.rows - 2; i++) {
    for (int j = 0; j < imgUpBlur.cols; j++) {
      this->result.at<double>(i, j) = imgUpBlur.at<double>(i, j);
    }
  }

  // Dolne rozmycie
  cv::Mat imgDown = this->result.clone();

  cv::Mat imgDownBlur;
  cv::GaussianBlur(imgDown, imgDownBlur,
                   cv::Size(this->downSize, this->downSize), this->downSigmaX,
                   this->downSigmaY);

  int startPoint =
      imgDownBlur.rows / 2 +
      int((imgDownBlur.rows / 2 * double(this->downHeight) / 100.));
  for (int i = startPoint; i < imgDownBlur.rows; i++) {
    for (int j = 0; j < imgDownBlur.cols / 2; j++) {
      this->result.at<double>(i, j) = imgDownBlur.at<double>(i, j);
    }
  }

  cv::imshow("Rezultat", this->result);
}
