#include "tiltshift.h"
TiltShift::TiltShift() {}

TiltShift::TiltShift(const std::string& filename) {
  this->downSigmaX = this->downSigmaY = this->upSigmaX = this->upSigmaY = 0;
  this->upSize = this->downSize = this->upHeight = this->downHeight = 1;
  this->imageCpu = cv::imread(filename, 1);
  this->resultCpu = this->imageCpu.clone();
}

TiltShift::~TiltShift() {
  cv::destroyAllWindows();
}

void TiltShift::showImg() const {
  cv::namedWindow("Obraz oryginalny");
  cv::namedWindow("Rezultat");
  cv::imshow("Obraz oryginalny", imageCpu);
  cv::imshow("Rezultat", resultCpu);
}

void TiltShift::saveResult(const std::string& filename) const {
  cv::imwrite(filename, this->resultCpu);
}

void TiltShift::gaussianBlur() {
  this->resultCpu.release();
  this->resultCpu = this->imageCpu.clone();

  // Gorne rozmycie
  int endPoint = int(this->imageCpu.rows / 2 * double(this->upHeight) / 100.);
  cv::Mat imgUp = this->resultCpu(cv::Rect(0, 0, this->imageCpu.cols, endPoint));

  cv::Mat imgUpBlur;
  cv::Ptr<cv::cuda::Filter> filterUp = cv::cuda::createGaussianFilter(imgUp.type(), imgUpBlur.type(), cv::Size(this->upSize, this->upSize),
                                                                    this->upSigmaX, this->upSigmaY);
  filterUp->apply(imgUp,imgUpBlur);

  for (int i = 0; i < imgUpBlur.rows - 2; i++) {
    for (int j = 0; j < imgUpBlur.cols; j++) {
      this->resultCpu.at<double>(i, j) = imgUpBlur.at<double>(i, j);
    }
  }

  // Dolne rozmycie
  cv::Mat imgDown = this->resultCpu.clone();

  cv::Mat imgDownBlur;
  cv::Ptr<cv::cuda::Filter> filterDown = cv::cuda::createGaussianFilter(imgDown.type(), imgDownBlur.type(), cv::Size(this->downSize, this->downSize), this->downSigmaX,
                                                                        this->downSigmaY);
    filterDown->apply(imgDown, imgDownBlur);
  int startPoint =
      imgDownBlur.rows / 2 +
      int((imgDownBlur.rows / 2 * double(this->downHeight) / 100.));
  for (int i = startPoint; i < imgDownBlur.rows; i++) {
    for (int j = 0; j < imgDownBlur.cols / 2; j++) {
      this->resultCpu.at<double>(i, j) = imgDownBlur.at<double>(i, j);
    }
  }

  cv::imshow("Rezultat", this->resultCpu);
}
