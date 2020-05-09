// Copyright 2018 Slightech Co., Ltd. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <serialLIB/serial_port.h>
#include "mynteye/api/api.h"
using namespace std;
MYNTEYE_USE_NAMESPACE

const char* uartname="/dev/ttyTHS1";

int fd;

int main(int argc, char const *argv[]) {
  //open serial port
  
  fd = serialport::serial_OpenPort(uartname);
  
  
  if(fd<0){
    std::cout<<"open\t"<<uartname<<"\tfailed"<<std::endl;
    std::cout<<"please check your connection of serail port" << std::endl;
    return -1;
  }

  
  
  if(serialport::serial_SetParameters(fd,115200,8,'N',1)<0){
    std::cout<<"parameters set fail"<<std::endl;
    return -1;
  }






  auto &&api = API::Create(0, nullptr);
  if (!api) return 1;

  bool ok;
  auto &&request = api->SelectStreamRequest(&ok);
  if (!ok) return 1;
  api->ConfigStreamRequest(request);
  api->Start(Source::VIDEO_STREAMING);

  double fps;
  double t = 0.01;
  std::cout << "fps:" << std::endl;

//  cv::namedWindow("frame");

  while (true) {
    api->WaitForStreams();

    auto &&left_data = api->GetStreamData(Stream::LEFT);
    auto &&right_data = api->GetStreamData(Stream::RIGHT);
    cv::Mat img;
    if (!left_data.frame.empty() && !right_data.frame.empty()) {
      double t_c = cv::getTickCount() / cv::getTickFrequency();
      fps = 1.0/(t_c - t);
      //printf("\r\n");
      printf("\b\b\b\b\b\b\b\b\b%.2f", fps);
      t = t_c;
      cv::hconcat(left_data.frame, right_data.frame, img);
 //     cv::imshow("frame", img);
    }

    char key = static_cast<char>(cv::waitKey(1));
    if (key == 27 || key == 'q' || key == 'Q') {  // ESC/Q
      break;
    }
  }

  api->Stop(Source::VIDEO_STREAMING);
  return 0;
}
