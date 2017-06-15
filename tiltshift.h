#ifndef TILTSHIFT_H
#define TILTSHIFT_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
class TiltShift {
 public:
  TiltShift();
  TiltShift(const std::string& filename);
  ~TiltShift();
  void showImg() const;
  void saveResult(const std::string& filename) const;
  inline bool ifImagesOpen() const { return image.data ? true : false; }

 private:
  cv::Mat image;
  cv::Mat result;
};

#endif  // TILTSHIFT_H
