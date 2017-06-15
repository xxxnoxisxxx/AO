#include "tiltshift.h"
TiltShift::TiltShift() {}

TiltShift::TiltShift(const std::string& filename) {
  this->image = cv::imread(filename, 1);
  this->result = this->image.clone();
}

TiltShift::~TiltShift() {
  cv::destroyAllWindows();
}

void TiltShift::showImg() const {
  cv::namedWindow("My Image");
  cv::namedWindow("My Result");
  cv::imshow("My Image", image);
  cv::imshow("My Result", result);
}

void TiltShift::saveResult(const std::string& filename) const {
  cv::imwrite(filename, this->result);
}
