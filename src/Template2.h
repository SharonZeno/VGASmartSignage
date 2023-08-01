#ifndef _TEMPLATE2
#define _TEMPLATE2

#include "templates.h"
#include "time.h"
#include <string>

class Template2 : public uiApp {

  uiFrame * firstFloorFrame;
  uiFrame * firstFloorHeaderFrame;
  uiFrame * secondFloorFrame;
  uiFrame * secondFloorHeaderFrame;
  uiFrame * thirdFloorFrame;
  uiFrame * thirdFloorHeaderFrame;

  uiStaticLabel * headlineLabel;
  uiStaticLabel * clocklabel;
  uiStaticLabel * firstFloorHeaderlabel;
  uiStaticLabel * firstClasseslabel_1;
  uiStaticLabel * secondClasseslabel_1;
  uiStaticLabel * thirdClasseslabel_1;
  uiStaticLabel * forthClasseslabel_1;

  uiStaticLabel * secondFloorHeaderlabel;
  uiStaticLabel * firstClasseslabel_2;
  uiStaticLabel * secondClasseslabel_2;
  uiStaticLabel * thirdClasseslabel_2;
  uiStaticLabel * forthClasseslabel_2;

  uiStaticLabel * thirdFloorHeaderlabel;
  uiStaticLabel * firstClasseslabel_3;
  uiStaticLabel * secondClasseslabel_3;
  uiStaticLabel * thirdClasseslabel_3;
  uiStaticLabel * forthClasseslabel_3;

  template2Data* m_template2;

  std::map<std::string, fabgl::RGB888> m_colorMap;
  bool db_mode;
  
  char* cStringClock;
  int m_hour;
  int m_minute;

public:
  Template2() = default;

  Template2(template2Data* template2): m_template2(template2) {
    db_mode = false;
    m_colorMap["GREEN"] = RGB888(60, 179, 113);
    m_colorMap["ORANGE"] = RGB888(245, 163, 62);
    m_colorMap["RED"] = RGB888(215, 60, 60);
    m_colorMap["PINK"] = RGB888(238, 130, 238);
    m_colorMap["PURPLE"] = RGB888(106, 90, 205);
    m_colorMap["BLUE"] = RGB888(54, 117, 200);
  };

  Template2(template2Data* template2, tm* curr_time): m_template2(template2) {
    db_mode = true;
    m_colorMap["GREEN"] = RGB888(60, 179, 113);
    m_colorMap["ORANGE"] = RGB888(245, 163, 62);
    m_colorMap["RED"] = RGB888(215, 60, 60);
    m_colorMap["PINK"] = RGB888(238, 130, 238);
    m_colorMap["PURPLE"] = RGB888(106, 90, 205);
    m_colorMap["BLUE"] = RGB888(54, 117, 200);

    m_hour = curr_time->tm_hour;
    m_minute = curr_time->tm_min;
    cStringClock = new char[10];
  };

  int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
  }

  void init() {
    appProps().realtimeReshaping = true;

    rootWindow()->frameStyle().backgroundColor = RGB888(0, 0, 0);
    
    // Main healine
    int headlineLength = stringLength(m_template2->mainHeadline);
    int startPoint = (640-(headlineLength*10))/2;
    headlineLabel = new uiStaticLabel(rootWindow(), "Class Assignments For Exams - Ullmann", Point(startPoint, 20));
    headlineLabel->setText(m_template2->mainHeadline);
    headlineLabel->labelStyle().backgroundColor = rootWindow()->frameStyle().backgroundColor;
    headlineLabel->labelStyle().textFont = &fabgl::FONT_std_24;
    headlineLabel->labelStyle().textColor = RGB888(255, 255, 255);
    headlineLabel->update();

    if (db_mode) {
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
    }

    firstFloorFrame = new uiFrame(rootWindow(), "", Point(20, 60), Size(190, 170)); 
    if (strlen(m_template2->firstFloorBackgroundColor) == 0) {
      firstFloorFrame->frameStyle().backgroundColor = RGB888(245, 163, 62);
    }
    else {
      firstFloorFrame->frameStyle().backgroundColor = m_colorMap[m_template2->firstFloorBackgroundColor];
    }
    firstFloorHeaderFrame = new uiFrame(firstFloorFrame, "", Point(0, 0), Size(190, 40));
    firstFloorHeaderFrame->frameStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    firstFloorHeaderlabel = new uiStaticLabel(firstFloorHeaderFrame, "First Floor", Point(45, 15));
    firstFloorHeaderlabel->setText(m_template2->firstFloorHeadline);
    firstFloorHeaderlabel->labelStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    firstFloorHeaderlabel->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    firstFloorHeaderlabel->labelStyle().textColor = RGB888(0, 0, 0);
    firstFloorHeaderlabel->update();  

    firstClasseslabel_1 = new uiStaticLabel(firstFloorFrame, "100 - 102 : IOT 1", Point(5, 50));
    firstClasseslabel_1->setText(m_template2->firstFloorClassDesc1);
    firstClasseslabel_1->labelStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    firstClasseslabel_1->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    firstClasseslabel_1->labelStyle().textColor = RGB888(0, 0, 0);
    firstClasseslabel_1->update(); 

    secondClasseslabel_1 = new uiStaticLabel(firstFloorFrame, "103 - 107 : Algebra 1", Point(5, 80));
    secondClasseslabel_1->labelStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    secondClasseslabel_1->setText(m_template2->firstFloorClassDesc2);
    secondClasseslabel_1->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    secondClasseslabel_1->labelStyle().textColor = RGB888(0, 0, 0);
    secondClasseslabel_1->update();   

    thirdClasseslabel_1 = new uiStaticLabel(firstFloorFrame, "108 - 115 : Calculus 1", Point(5, 110));
    thirdClasseslabel_1->setText(m_template2->firstFloorClassDesc3);
    thirdClasseslabel_1->labelStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    thirdClasseslabel_1->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    thirdClasseslabel_1->labelStyle().textColor = RGB888(0, 0, 0);
    thirdClasseslabel_1->update();  

    forthClasseslabel_1 = new uiStaticLabel(firstFloorFrame, "116 - 118 : Databases 1", Point(5, 140));
    forthClasseslabel_1->setText(m_template2->firstFloorClassDesc4);
    forthClasseslabel_1->labelStyle().backgroundColor = firstFloorFrame->frameStyle().backgroundColor;
    forthClasseslabel_1->labelStyle().textFont = &fabgl::FONT_WIGGLY_8x16;
    forthClasseslabel_1->labelStyle().textColor = RGB888(0, 0, 0);
    forthClasseslabel_1->update();  

    secondFloorFrame = new uiFrame(rootWindow(), "", Point(220, 60), Size(190, 170)); //Size(330, 245)
    if (strlen(m_template2->secondFloorBackgroundColor) == 0) {
      secondFloorFrame->frameStyle().backgroundColor = RGB888(106, 90, 205);
    }
    else {
      secondFloorFrame->frameStyle().backgroundColor = m_colorMap[m_template2->secondFloorBackgroundColor];
    }
    secondFloorHeaderFrame = new uiFrame(secondFloorFrame, "", Point(0, 0), Size(190, 40));
    secondFloorHeaderFrame->frameStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    secondFloorHeaderlabel = new uiStaticLabel(secondFloorHeaderFrame, "Second Floor", Point(45, 15));
    secondFloorHeaderlabel->setText(m_template2->secondFloorHeadline);
    secondFloorHeaderlabel->labelStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    secondFloorHeaderlabel->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    secondFloorHeaderlabel->labelStyle().textColor = RGB888(0, 0, 0);
    secondFloorHeaderlabel->update();  

    firstClasseslabel_2 = new uiStaticLabel(secondFloorFrame, "200 - 202 : IOT 2", Point(5, 50));
    firstClasseslabel_2->setText(m_template2->secondFloorClassDesc1);
    firstClasseslabel_2->labelStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    firstClasseslabel_2->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    firstClasseslabel_2->labelStyle().textColor = RGB888(0, 0, 0);
    firstClasseslabel_2->update(); 

    secondClasseslabel_2 = new uiStaticLabel(secondFloorFrame, "203 - 207 : Algebra 2", Point(5, 80));
    secondClasseslabel_2->setText(m_template2->secondFloorClassDesc2);
    secondClasseslabel_2->labelStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    secondClasseslabel_2->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    secondClasseslabel_2->labelStyle().textColor = RGB888(0, 0, 0);
    secondClasseslabel_2->update();   

    thirdClasseslabel_2 = new uiStaticLabel(secondFloorFrame, "208 - 215 : Calculus 2", Point(5, 110));
    thirdClasseslabel_2->setText(m_template2->secondFloorClassDesc3);
    thirdClasseslabel_2->labelStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    thirdClasseslabel_2->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    thirdClasseslabel_2->labelStyle().textColor = RGB888(0, 0, 0);
    thirdClasseslabel_2->update();   

    forthClasseslabel_2 = new uiStaticLabel(secondFloorFrame, "216 - 218 : Databases 2", Point(5, 140));
    forthClasseslabel_2->setText(m_template2->secondFloorClassDesc4);
    forthClasseslabel_2->labelStyle().backgroundColor = secondFloorFrame->frameStyle().backgroundColor;
    forthClasseslabel_2->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    forthClasseslabel_2->labelStyle().textColor = RGB888(0, 0, 0);
    forthClasseslabel_2->update();  

    thirdFloorFrame = new uiFrame(rootWindow(), "", Point(420, 60), Size(190, 170)); //Size(330, 245)
    if (strlen(m_template2->thirdFloorBackgroundColor) == 0) {
      thirdFloorFrame->frameStyle().backgroundColor = RGB888(215, 60, 60);
    }
    else {
      thirdFloorFrame->frameStyle().backgroundColor = m_colorMap[m_template2->thirdFloorBackgroundColor];
    }
    thirdFloorHeaderFrame = new uiFrame(thirdFloorFrame, "", Point(0, 0), Size(190, 40));
    thirdFloorHeaderFrame->frameStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    thirdFloorHeaderlabel = new uiStaticLabel(thirdFloorFrame, "Third Floor", Point(45, 15));
    thirdFloorHeaderlabel->setText(m_template2->thirdFloorHeadline);
    thirdFloorHeaderlabel->labelStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    thirdFloorHeaderlabel->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    thirdFloorHeaderlabel->labelStyle().textColor = RGB888(0, 0, 0);
    thirdFloorHeaderlabel->update();  

    firstClasseslabel_3 = new uiStaticLabel(thirdFloorFrame, "300 - 302 : IOT 3", Point(5, 50));
    firstClasseslabel_3->setText(m_template2->thirdFloorClassDesc1);
    firstClasseslabel_3->labelStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    firstClasseslabel_3->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    firstClasseslabel_3->labelStyle().textColor = RGB888(0, 0, 0);
    firstClasseslabel_3->update(); 

    secondClasseslabel_3 = new uiStaticLabel(thirdFloorFrame, "303 - 307 : Algebra 3", Point(5, 80));
    secondClasseslabel_3->setText(m_template2->thirdFloorClassDesc2);
    secondClasseslabel_3->labelStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    secondClasseslabel_3->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    secondClasseslabel_3->labelStyle().textColor = RGB888(0, 0, 0);
    secondClasseslabel_3->update();   

    thirdClasseslabel_3 = new uiStaticLabel(thirdFloorFrame, "308 - 315 : Calculus 3", Point(5, 110));
    thirdClasseslabel_3->setText(m_template2->thirdFloorClassDesc3);
    thirdClasseslabel_3->labelStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    thirdClasseslabel_3->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    thirdClasseslabel_3->labelStyle().textColor = RGB888(0, 0, 0);
    thirdClasseslabel_3->update(); 

    forthClasseslabel_3 = new uiStaticLabel(thirdFloorFrame, "316 - 318 : Databases 3", Point(5, 140));
    forthClasseslabel_3->setText(m_template2->thirdFloorClassDesc4);
    forthClasseslabel_3->labelStyle().backgroundColor = thirdFloorFrame->frameStyle().backgroundColor;
    forthClasseslabel_3->labelStyle().textFont = &fabgl::FONT_SANSERIF_8x16;
    forthClasseslabel_3->labelStyle().textColor = RGB888(0, 0, 0);
    forthClasseslabel_3->update();  
  }
};

#endif