#pragma once

#include "templates.h"
#include "time.h"
#include <string>
#include <map>

class Template1 : public uiApp {

  uiFrame * ScheduleFrame;
  uiFrame * firstBulletFrame;
  uiFrame * secondBulletFrame;
  uiFrame * thirdBulletFrame;
  uiFrame * fourthBulletFrame;

  uiStaticLabel * authorLabel;
  uiStaticLabel * headlineLabel;
  uiStaticLabel * clocklabel;
  uiStaticLabel * firstBulletlabel;
  uiStaticLabel * secondBulletlabel;
  uiStaticLabel * thirdBulletlabel;
  uiStaticLabel * fourthBulletlabel;

  char* cStringClock;

  template1Data* m_template1;
  int m_hour;
  int m_minute;

  std::map<std::string, fabgl::RGB888> color_map;
  color_map["GREEN"] = RGB888(60, 179, 113);
  color_map["BRIGHT_GREEN"] = RGB888(152, 251, 152);

  color_map["ORANGE"] = RGB888(245, 163, 62);
  color_map["BRIGHT_ORANGE"] = RGB888(245, 190, 115);

  color_map["RED"] = RGB888(255, 0, 0);
  color_map["BRIGHT_RED"] = RGB888(255, 82, 80 );

  color_map["BLUE"] = RGB888(0, 0, 255);
  color_map["BRIGHT_RED"] = RGB888(255, 82, 80 );

public:
  Template1() = default;

  Template1(template1Data* template1, tm* curr_time): m_template1(template1){
    m_hour = curr_time->tm_hour;
    m_minute = curr_time->tm_min;
    cStringClock = new char[10];
  };

  void init() {
    appProps().realtimeReshaping = true;

    // set root window background color to dark green - https://www.w3schools.com/html/html_colors_rgb.asp
    //rootWindow()->frameStyle().backgroundColor = RGB888(60, 179, 113); //previous: 123, 150, 132 now: 60, 179, 113

    rootWindow()->frameStyle().backgroundColor = color_map[m_template1->backgroundColor];

    // Main healine
    headlineLabel = new uiStaticLabel(rootWindow(), "Welcome To Our IOT Expo! ", Point(190, 20));
    headlineLabel->setText(m_template1->mainHeadline);
    headlineLabel->labelStyle().backgroundColor = rootWindow()->frameStyle().backgroundColor;
    headlineLabel->labelStyle().textFont = &fabgl::FONT_std_24;
    headlineLabel->labelStyle().textColor = RGB888(255, 255, 255);
    headlineLabel->update();

    // clock label
    clocklabel = new uiStaticLabel(rootWindow(), "Very Nice Clock", Point(20, 20));
    std::string clock;
    if(m_minute<10)
    {
      clock = std::to_string(m_hour) + ":0" + std::to_string(m_minute);
    }
    else
    {
      clock = std::to_string(m_hour) + ":" + std::to_string(m_minute);
    }
    strcpy(cStringClock,clock.c_str());
    clocklabel->setText(cStringClock);
    clocklabel->labelStyle().backgroundColor = rootWindow()->frameStyle().backgroundColor;
    clocklabel->labelStyle().textFont = &fabgl::FONT_10x20;
    clocklabel->labelStyle().textColor = RGB888(255, 255, 255);
    clocklabel->update();

    // author label
    authorLabel = new uiStaticLabel(rootWindow(), "Expo Entrance", Point(440, 200));
    authorLabel->labelStyle().backgroundColor = rootWindow()->frameStyle().backgroundColor;
    authorLabel->labelStyle().textFont = &fabgl::FONT_10x20;
    authorLabel->labelStyle().textColor = RGB888(255,255, 255);
    authorLabel->update();

    // frame where to schdule bullets
    ScheduleFrame = new uiFrame(rootWindow(), "", Point(10, 60), Size(330, 190)); //Size(330, 245)
    if (m_template1->backgroundColor == "GREEN") {
      ScheduleFrame->frameStyle().backgroundColor = color_map["BRIGHT_GREEN"];
    }
    else if (m_template1->backgroundColor == "ORANGE") {
      ScheduleFrame->frameStyle().backgroundColor = color_map["BRIGHT_ORANGE"];
    }
    else if (m_template1->backgroundColor == "RED") {
      ScheduleFrame->frameStyle().backgroundColor = color_map["BRIGHT_RED"];
    }
    else if (m_template1->backgroundColor == "BLUE") {
      ScheduleFrame->frameStyle().backgroundColor = color_map["BRIGHT_BLUE"];
    }
    else {
      ScheduleFrame->frameStyle().backgroundColor = color_map["BRIGHT_GREEN"];
    }
    //ScheduleFrame->frameStyle().backgroundColor = RGB888(152, 251, 152); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144

    // first bullet frame
    firstBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 10), Size(310, 45));
    firstBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144
    // first bullet label inside the frame
    firstBulletlabel = new uiStaticLabel(firstBulletFrame, "10:00 - Ms. Zeno's Lecture", Point(10, 20));
    firstBulletlabel->setText(m_template1->task1);
    firstBulletlabel->labelStyle().backgroundColor = color_map[m_template1->taskBackgroundColor]; //RGB888(245, 163, 62); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144
    firstBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    firstBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    firstBulletlabel->update();  

    // second bullet frame
    secondBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 70), Size(310, 45));
    secondBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144
    // first bullet label inside the frame
    secondBulletlabel = new uiStaticLabel(secondBulletFrame, "12:00 - Lunch", Point(10, 20));
    secondBulletlabel->setText(m_template1->task2);
    secondBulletlabel->labelStyle().backgroundColor = color_map[m_template1->taskBackgroundColor];
    secondBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    secondBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    secondBulletlabel->update();  

    // third bullet frame
    thirdBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 130), Size(310, 45));
    thirdBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144
    // first bullet label inside the frame
    thirdBulletlabel = new uiStaticLabel(thirdBulletFrame, "13:30 - Mr. Ephraim's Product Launch", Point(10, 20));
    thirdBulletlabel->setText(m_template1->task3);
    thirdBulletlabel->labelStyle().backgroundColor = color_map[m_template1->taskBackgroundColor];
    thirdBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    thirdBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    thirdBulletlabel->update();  
  }

};