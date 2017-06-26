#ifndef TILTSHIFT_H
#define TILTSHIFT_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/cudafilters.hpp>


class TiltShift {
 public:
  TiltShift();
  TiltShift(const std::string& filename);
  ~TiltShift();
  void showImg() const;
  void saveResult(const std::string& filename) const;
  inline bool ifImagesOpen() const { return imageCpu.data ? true : false; }
  void gaussianBlur();

 private:
  cv::Mat imageCpu;
  cv::Mat resultCpu;
 public:
  int upHeight;
  int downHeight;
  int upSize;
  int downSize;
  double upSigmaX;
  double upSigmaY;
  double downSigmaX;
  double downSigmaY;
};

#endif  // TILTSHIFT_H
