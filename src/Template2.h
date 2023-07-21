#pragma once

#include "templates.h"
#include "time.h"
#include <string>

class Template2 : public uiApp {

  uiFrame * firstFloorFrame;
  uiFrame * firstBulletFrame;
  uiFrame * secondFloorFrame;
  uiFrame * secondBulletFrame;
  uiFrame * thirdFloorFrame;
  uiFrame * thirdBulletFrame;

  uiStaticLabel * headlineLabel;
  uiStaticLabel * clocklabel;
  uiStaticLabel * firstBulletlabel;
  uiStaticLabel * secondBulletlabel;
  uiStaticLabel * thirdBulletlabel;
  uiStaticLabel * forthBulletlabel;

  uiStaticLabel * firstBulletlabel_2;
  uiStaticLabel * secondBulletlabel_2;
  uiStaticLabel * thirdBulletlabel_2;
  uiStaticLabel * forthBulletlabel_2;

  uiStaticLabel * firstBulletlabel_3;
  uiStaticLabel * secondBulletlabel_3;
  uiStaticLabel * thirdBulletlabel_3;
  uiStaticLabel * forthBulletlabel_3;

  template2Data* m_template2;

  char* cStringClock;
  int m_hour;
  int m_minute;

public:
  Template2() = default;

  // Template2(template2Data* template2, tm* curr_time): m_template2(template2) {
  //   m_hour = curr_time->tm_hour;
  //   m_minute = curr_time->tm_min;
  //   cStringClock = new char[10];
  // };

  void init() {
    // resizeWindow(rootWindow(),640,480);
    appProps().realtimeReshaping = true;

    // set root window background color to dark green - https://www.w3schools.com/html/html_colors_rgb.asp
    rootWindow()->frameStyle().backgroundColor = RGB888(0, 0, 0); //previous: 123, 150, 132 now: 60, 179, 113

    // Main healine
    headlineLabel = new uiStaticLabel(rootWindow(), "Class For Exams - Ullman", Point(190, 20));
    //headlineLabel->setText(m_template1->mainHeadline);
    headlineLabel->labelStyle().backgroundColor = rootWindow()->frameStyle().backgroundColor;
    headlineLabel->labelStyle().textFont = &fabgl::FONT_std_24;
    headlineLabel->labelStyle().textColor = RGB888(255, 255, 255);
    headlineLabel->update();

    // clock label
    // clocklabel = new uiStaticLabel(rootWindow(), "Very Nice Clock", Point(20, 20));
    // std::string clock;
    // if(m_minute<10)
    // {
    //   clock = std::to_string(m_hour) + ":0" + std::to_string(m_minute);
    // }
    // else
    // {
    //   clock = std::to_string(m_hour) + ":" + std::to_string(m_minute);
    // }
    // strcpy(cStringClock,clock.c_str());
    // // Serial.println("Clock:");
    // // Serial.println(cStringClock);
    // clocklabel->setText(cStringClock);
    // clocklabel->labelStyle().backgroundColor = rootWindow()->frameStyle().backgroundColor;
    // clocklabel->labelStyle().textFont = &fabgl::FONT_10x20;
    // clocklabel->labelStyle().textColor = RGB888(255, 255, 255);
    // clocklabel->update();

    firstFloorFrame = new uiFrame(rootWindow(), "", Point(20, 60), Size(190, 180)); //Size(330, 245)
    firstFloorFrame->frameStyle().backgroundColor = RGB888(245, 163, 62);
    firstBulletFrame = new uiFrame(firstFloorFrame, "", Point(0, 0), Size(190, 40));
    firstBulletFrame->frameStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    firstBulletlabel = new uiStaticLabel(firstBulletFrame, "First Floor", Point(30, 15));
    //firstBulletlabel->setText(m_template1->task1);
    firstBulletlabel->labelStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    firstBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    firstBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    firstBulletlabel->update();  

    // // second bullet frame
    // first bullet label inside the frame
    secondBulletlabel = new uiStaticLabel(firstFloorFrame, "100 - 102 : IOT 1", Point(5, 50));
    //secondBulletlabel->labelStyle().backgroundColor =  RGB888(245, 163, 62);
    secondBulletlabel->labelStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    secondBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    secondBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    secondBulletlabel->update(); 

    thirdBulletlabel = new uiStaticLabel(firstFloorFrame, "103 - 107 : Algebra 1", Point(5, 70));
    thirdBulletlabel->labelStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    thirdBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    thirdBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    thirdBulletlabel->update();   

    forthBulletlabel = new uiStaticLabel(firstFloorFrame, "108 - 115 : Calculus 1", Point(5, 90));
    forthBulletlabel->labelStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    forthBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    forthBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    forthBulletlabel->update();  

    secondFloorFrame = new uiFrame(rootWindow(), "", Point(220, 60), Size(190, 180)); //Size(330, 245)
    secondFloorFrame->frameStyle().backgroundColor = RGB888(106, 90, 205);
    secondBulletFrame = new uiFrame(secondFloorFrame, "", Point(0, 0), Size(190, 40));
    secondBulletFrame->frameStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    firstBulletlabel_2 = new uiStaticLabel(secondBulletFrame, "Second Floor", Point(30, 15));
    firstBulletlabel_2->labelStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    firstBulletlabel_2->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    firstBulletlabel_2->labelStyle().textColor = RGB888(0, 0, 0);
    firstBulletlabel_2->update();  

    secondBulletlabel_2 = new uiStaticLabel(secondFloorFrame, "200 - 202 : IOT 2", Point(5, 50));
    secondBulletlabel_2->labelStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    secondBulletlabel_2->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    secondBulletlabel_2->labelStyle().textColor = RGB888(0, 0, 0);
    secondBulletlabel_2->update(); 

    thirdBulletlabel_2 = new uiStaticLabel(secondFloorFrame, "203 - 207 : Algebra 2", Point(5, 70));
    thirdBulletlabel_2->labelStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    thirdBulletlabel_2->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    thirdBulletlabel_2->labelStyle().textColor = RGB888(0, 0, 0);
    thirdBulletlabel_2->update();   

    forthBulletlabel_2 = new uiStaticLabel(secondFloorFrame, "208 - 215 : Calculus 2", Point(5, 90));
    forthBulletlabel_2->labelStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    forthBulletlabel_2->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    forthBulletlabel_2->labelStyle().textColor = RGB888(0, 0, 0);
    forthBulletlabel_2->update();   


    thirdFloorFrame = new uiFrame(rootWindow(), "", Point(420, 60), Size(190, 180)); //Size(330, 245)
    thirdFloorFrame->frameStyle().backgroundColor = RGB888(215, 60, 60);
    thirdBulletFrame = new uiFrame(thirdFloorFrame, "", Point(0, 0), Size(190, 40));
    thirdBulletFrame->frameStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    firstBulletlabel_3 = new uiStaticLabel(thirdFloorFrame, "Third Floor", Point(30, 15));
    firstBulletlabel_3->labelStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    firstBulletlabel_3->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    firstBulletlabel_3->labelStyle().textColor = RGB888(0, 0, 0);
    firstBulletlabel_3->update();  

    secondBulletlabel_3 = new uiStaticLabel(thirdFloorFrame, "300 - 302 : IOT 3", Point(5, 50));
    secondBulletlabel_3->labelStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    secondBulletlabel_3->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    secondBulletlabel_3->labelStyle().textColor = RGB888(0, 0, 0);
    secondBulletlabel_3->update(); 

    thirdBulletlabel_3 = new uiStaticLabel(thirdFloorFrame, "303 - 307 : Algebra 3", Point(5, 70));
    thirdBulletlabel_3->labelStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    thirdBulletlabel_3->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    thirdBulletlabel_3->labelStyle().textColor = RGB888(0, 0, 0);
    thirdBulletlabel_3->update();   

    forthBulletlabel_3 = new uiStaticLabel(thirdFloorFrame, "308 - 315 : Calculus 3", Point(5, 90));
    forthBulletlabel_3->labelStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    forthBulletlabel_3->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    forthBulletlabel_3->labelStyle().textColor = RGB888(0, 0, 0);
    forthBulletlabel_3->update(); 
  }
};