#pragma once


class Template1 : public uiApp {

  uiFrame * ScheduleFrame;
  uiFrame * firstBulletFrame;
  uiFrame * secondBulletFrame;
  uiFrame * thirdBulletFrame;
  uiFrame * fourthBulletFrame;

  uiStaticLabel * authorLabel;
  uiStaticLabel * headlineLabel;
  uiStaticLabel * firstBulletlabel;
  uiStaticLabel * secondBulletlabel;
  uiStaticLabel * thirdBulletlabel;
  uiStaticLabel * fourthBulletlabel;

public:
  void init() {
    // resizeWindow(rootWindow(),640,480);
    appProps().realtimeReshaping = true;

    // set root window background color to dark green - https://www.w3schools.com/html/html_colors_rgb.asp
    rootWindow()->frameStyle().backgroundColor = RGB888(60, 179, 113); //previous: 123, 150, 132 now: 60, 179, 113

   // Main healine
    headlineLabel = new uiStaticLabel(rootWindow(), "Welcome To Our IOT Expo! ", Point(190, 20));
    // headlineLabel->setText("ASAF TEST");
    headlineLabel->labelStyle().backgroundColor = rootWindow()->frameStyle().backgroundColor;
    headlineLabel->labelStyle().textFont = &fabgl::FONT_std_24;
    headlineLabel->labelStyle().textColor = RGB888(255, 255, 255);
    headlineLabel->update();

    // author label
    authorLabel = new uiStaticLabel(rootWindow(), "Expo Entrance", Point(440, 200));
    authorLabel->labelStyle().backgroundColor = rootWindow()->frameStyle().backgroundColor;
    authorLabel->labelStyle().textFont = &fabgl::FONT_10x20;
    authorLabel->labelStyle().textColor = RGB888(255,255, 255);
    authorLabel->update();

    // frame where to schdule bullets
    ScheduleFrame = new uiFrame(rootWindow(), "", Point(10, 60), Size(330, 245)); //Size(330, 245)
    ScheduleFrame->frameStyle().backgroundColor = RGB888(152, 251, 152); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144

    // first bullet frame
    firstBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 10), Size(310, 45));
    firstBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144
    // first bullet label inside the frame
    firstBulletlabel = new uiStaticLabel(firstBulletFrame, "10:00 - Ms. Zeno's Lecture", Point(10, 20));
    firstBulletlabel->labelStyle().backgroundColor =  RGB888(245, 163, 62);
    firstBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    firstBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    firstBulletlabel->update();  

    // second bullet frame
    secondBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 70), Size(310, 45));
    secondBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144
    // first bullet label inside the frame
    secondBulletlabel = new uiStaticLabel(secondBulletFrame, "12:00 - Lunch", Point(10, 20));
    secondBulletlabel->labelStyle().backgroundColor =  RGB888(245, 163, 62);
    secondBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    secondBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    secondBulletlabel->update();  

    // third bullet frame
    thirdBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 130), Size(310, 45));
    thirdBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144
    // first bullet label inside the frame
    thirdBulletlabel = new uiStaticLabel(thirdBulletFrame, "13:30 - Mr. Ephraim's Product Launch", Point(10, 20));
    thirdBulletlabel->labelStyle().backgroundColor =  RGB888(245, 163, 62);
    thirdBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    thirdBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    thirdBulletlabel->update();  

    // fourth bullet frame
    fourthBulletFrame = new uiFrame(ScheduleFrame, "", Point(10, 190), Size(310, 45));
    fourthBulletFrame->frameStyle().backgroundColor = RGB888(245, 163, 62); // https://www.w3schools.com/html/html_colors_rgb.asp // 144, 238, 144
    // first bullet label inside the frame
    fourthBulletlabel = new uiStaticLabel(fourthBulletFrame, "15:00 - End Of The Day", Point(10, 20));
    fourthBulletlabel->labelStyle().backgroundColor =  RGB888(245, 163, 62);
    fourthBulletlabel->labelStyle().textFont = &fabgl::FONT_LCD_8x14;
    fourthBulletlabel->labelStyle().textColor = RGB888(0, 0, 0);
    fourthBulletlabel->update();  
  
    //setActiveWindow(ScheduleFrame);
  }

};

