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

  uiStaticLabel * authorLabel;
  uiStaticLabel * headlineLabel;
  uiStaticLabel * clocklabel;
  uiStaticLabel * firstBulletlabel;
  uiStaticLabel * secondBulletlabel;
  uiStaticLabel * thirdBulletlabel;

  std::map<std::string, fabgl::RGB888> m_colorMap;

  char* cStringClock;

  template1Data* m_template1;
  int m_hour;
  int m_minute;

public:
  Template1() = default;

  Template1(template1Data* template1): m_template1(template1) {};
  
  Template1(template1Data* template1, tm* curr_time): m_template1(template1) {
    m_colorMap["GREEN"] = RGB888(60, 179, 113);
    m_colorMap["BRIGHT_GREEN"] = RGB888(152, 251, 152);
    m_colorMap["ORANGE"] = RGB888(245, 163, 62);
    m_colorMap["BRIGHT_ORANGE"] = RGB888(245, 179, 112);
    m_colorMap["RED"] = RGB888(215, 60, 60);
    m_colorMap["BRIGHT_RED"] = RGB888(255, 110, 100);
    m_colorMap["BLUE"] = RGB888(0, 0, 255);
    m_colorMap["BRIGHT_BLUE"] = RGB888(152, 152, 251);

    m_hour = curr_time->tm_hour;
    m_minute = curr_time->tm_min;
    cStringClock = new char[10];
  };

  void init() {
    appProps().realtimeReshaping = true;
    bool backgroundColorEmpty = strlen(m_template1->backgroundColor) == 0;
    // set root window background color to dark green - https://www.w3schools.com/html/html_colors_rgb.asp
    if (backgroundColorEmpty) {
      rootWindow()->frameStyle().backgroundColor = RGB888(60, 179, 113);
    }
    else {
      rootWindow()->frameStyle().backgroundColor = m_colorMap[m_template1->backgroundColor];
    }

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
    authorLabel->labelStyle().textColor = RGB888(255, 255, 255);
    authorLabel->update();

    // frame where to schdule bullets
    ScheduleFrame = new uiFrame(rootWindow(), "", Point(10, 60), Size(330, 190)); //Size(330, 245)
    if (backgroundColorEmpty) {
      ScheduleFrame->frameStyle().backgroundColor = RGB888(152, 251, 152);
    }
    else {
      std::string backColor = m_template1->backgroundColor;
      std::string scheduleBackColor = "BRIGHT_" + backColor;
      ScheduleFrame->frameStyle().backgroundColor = m_colorMap[scheduleBackColor];
    }
    bool taskBackgroundColorEmpty = strlen(m_template1->taskBackgroundColor) == 0;
    // first bullet frame
    firstBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 10), Size(310, 45));
    if (taskBackgroundColorEmpty) {
      firstBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62);
    }
    else {
      firstBulletFrame->frameStyle().backgroundColor = m_colorMap[m_template1->taskBackgroundColor];
    }
    // first bullet label inside the frame
    firstBulletlabel = new uiStaticLabel(firstBulletFrame, "10:00 - Ms. Zeno's Lecture", Point(10, 20));
    firstBulletlabel->setText(m_template1->task1);
    if (taskBackgroundColorEmpty) {
      firstBulletlabel->labelStyle().backgroundColor = RGB888(245, 163, 62);
    }
    else {
      firstBulletlabel->labelStyle().backgroundColor = m_colorMap[m_template1->taskBackgroundColor];
    }
    firstBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    firstBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    firstBulletlabel->update();  

    // second bullet frame
    secondBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 70), Size(310, 45));
    if (taskBackgroundColorEmpty) {
      secondBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62);
    }
    else {
      secondBulletFrame->frameStyle().backgroundColor = m_colorMap[m_template1->taskBackgroundColor];
    }
    secondBulletlabel = new uiStaticLabel(secondBulletFrame, "12:00 - Lunch", Point(10, 20));
    secondBulletlabel->setText(m_template1->task2);
    if (taskBackgroundColorEmpty) {
      secondBulletlabel->labelStyle().backgroundColor = RGB888(245, 163, 62);
    }
    else {
      secondBulletlabel->labelStyle().backgroundColor = m_colorMap[m_template1->taskBackgroundColor];
    }
    secondBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    secondBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    secondBulletlabel->update();  

    // third bullet frame
    thirdBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 130), Size(310, 45));
    if (taskBackgroundColorEmpty) {
      thirdBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62);
    }
    else {
      thirdBulletFrame->frameStyle().backgroundColor = m_colorMap[m_template1->taskBackgroundColor];
    }
    thirdBulletlabel = new uiStaticLabel(thirdBulletFrame, "13:30 - Mr. Ephraim's Product Launch", Point(10, 20));
    thirdBulletlabel->setText(m_template1->task3);
    if (taskBackgroundColorEmpty) {
      thirdBulletlabel->labelStyle().backgroundColor = RGB888(245, 163, 62);
    }
    else {
      thirdBulletlabel->labelStyle().backgroundColor = m_colorMap[m_template1->taskBackgroundColor];
    }
    thirdBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    thirdBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    thirdBulletlabel->update();  
  }

};