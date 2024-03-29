#pragma once

#include "TestModalDialog.h"
#include "TestPaintBoxFrame.h"
#include "TestTimerFrame.h"
#include "TestControlsFrame.h"


class MyApp : public uiApp {

  uiFrame * testsFrame;
  uiButton * createFrameButton, * destroyFrameButton, * testModalDialogButton, * msgBoxButton;
  uiButton * testPaintBoxButton, * testTimerButton, * testControlsButton, * testInputBoxButton;
  TestPaintBoxFrame * paintBoxFrame;
  TestTimerFrame * testTimerFrame;
  uiLabel * freeMemLabel1, * freeMemLabel2;
  uiStaticLabel * authorLabel;
  TestControlsFrame * testControlsFrame;

  fabgl::Stack<uiFrame*> dynamicFrames;

  void init() {

    // set root window background color to dark green - https://www.w3schools.com/html/html_colors_rgb.asp
    rootWindow()->frameStyle().backgroundColor = RGB888(123, 130, 132);

    // // setup a timer to show updated free memory every 2s
    // setTimer(this, 2000);
    // onTimer = [&](uiTimerHandle tHandle) { showFreeMemory(); };

    // author label
    // authorLabel = new uiStaticLabel(rootWindow(), "VGA Smart Signage", Point(400, 200));
    // authorLabel->labelStyle().backgroundColor = rootWindow()->frameStyle().backgroundColor;
    // authorLabel->labelStyle().textFont = &fabgl::FONT_std_22;
    // authorLabel->labelStyle().textColor = RGB888(0, 0, 0);
    // authorLabel->update();

    // // frame where to put test buttons
    // testsFrame = new uiFrame(rootWindow(), "", Point(10, 30), Size(320, 420));
    // testsFrame->frameStyle().backgroundColor = RGB888(200,200, 200); // https://www.w3schools.com/html/html_colors_rgb.asp
    // testsFrame->windowStyle().borderSize     = 0;

    // // // label where to show free memory
    // // freeMemLabel1 = new uiLabel(testsFrame, "", Point(2, 420));
    // // freeMemLabel2 = new uiLabel(testsFrame, "", Point(2, 435));
    // // freeMemLabel1->labelStyle().backgroundColor = freeMemLabel2->labelStyle().backgroundColor = testsFrame->frameStyle().backgroundColor;
    // // freeMemLabel1->labelStyle().textFont        = freeMemLabel2->labelStyle().textFont        = &fabgl::FONT_std_12;

    // // button to show TestControlsFrame
    // //testControlsFrame = new TestControlsFrame(rootWindow());
    // testControlsButton = new uiButton(testsFrame, "hey it's a text bla bla 1 2 3 4 5 6", Point(10, 80), Size(300, 30));
    // //testControlsButton->onClick = [&]() { showWindow(testControlsFrame, true); setActiveWindow(testControlsFrame); };
    // //testControlsButton->buttonStyle().textFont = &fabgl::FONT_BROADWAY_8x14;

    // // create a destroy frame buttons
    // createFrameButton  = new uiButton(testsFrame, "hey it's a text bla bla 1 2 3 4 5 6", Point(10, 130), Size(300, 30));
    // //createFrameButton->buttonStyle().textFont = &fabgl::FONT_COURIER_8x14;

    // // createFrameButton->onClick = [&]() { onCreateFrameButtonClick(); };
    // destroyFrameButton = new uiButton(testsFrame, "hey it's a text bla bla 1 2 3 4 5 6", Point(10, 180), Size(300, 30));
    // destroyFrameButton->onClick = [&]() { destroyWindow(dynamicFrames.pop()); };

    // // test modal dialog button
    // testModalDialogButton = new uiButton(testsFrame, "hey it's a text bla bla 1 2 3 4 5 6", Point(10, 230), Size(300, 30));
    // // testModalDialogButton->onClick = [&]() { onTestModalDialogButtonClick(); };

    // // test message box
    // msgBoxButton = new uiButton(testsFrame, "hey it's a text bla bla 1 2 3 4 5 6", Point(10, 280), Size(300, 30));
    // // msgBoxButton->onClick = [&]() {
    // //   app()->messageBox("This is the title", "This is the main text", "Button1", "Button2", "Button3", uiMessageBoxIcon::Info);
    // //   app()->messageBox("This is the title", "This is the main text", "Yes", "No", nullptr, uiMessageBoxIcon::Question);
    // //   app()->messageBox("This is the title", "This is the main text", "OK",  nullptr, nullptr, uiMessageBoxIcon::Info);
    // //   app()->messageBox("This is the title", "This is the main text", "OK",  nullptr, nullptr, uiMessageBoxIcon::Error);
    // //   app()->messageBox("This is the title", "Little text", "OK",  nullptr, nullptr, uiMessageBoxIcon::Warning);
    // //   app()->messageBox("This is the title", "No icon", "OK",  nullptr, nullptr, uiMessageBoxIcon::None);
    // //   app()->messageBox("", "No title", "OK",  nullptr, nullptr);
    // // };

    // // // button to show TestPaintBoxFrame
    // // paintBoxFrame = new TestPaintBoxFrame(rootWindow());
    // // testPaintBoxButton = new uiButton(testsFrame, "Test PaintBox", Point(5, 145), Size(105, 20));
    // // testPaintBoxButton->onClick = [&]() { showWindow(paintBoxFrame, true); };

    // // // button to show TestTimerFrame
    // // testTimerFrame = new TestTimerFrame(rootWindow());
    // // testTimerButton = new uiButton(testsFrame, "Test Timer", Point(5, 170), Size(105, 20));
    // // testTimerButton->onClick = [&]() { showWindow(testTimerFrame, true); };

    // // // inputbox test
    // // testInputBoxButton = new uiButton(testsFrame, "Test InputBox", Point(5, 195), Size(105, 20));
    // // testInputBoxButton->onClick = [&]() { onTestInputBox(); };

    setActiveWindow(testsFrame);

  }

  // void showFreeMemory() {
  //   freeMemLabel1->setTextFmt("Free 8bit: %d KiB", heap_caps_get_free_size(MALLOC_CAP_8BIT) / 1024);
  //   freeMemLabel2->setTextFmt("Free 32bit: %d KiB", heap_caps_get_free_size(MALLOC_CAP_32BIT) / 1024);
  //   freeMemLabel1->repaint();
  //   freeMemLabel2->repaint();
  // }

  // void onCreateFrameButtonClick() {
  //   uiFrame * newFrame = new uiFrame(rootWindow(), "", Point(110 + random(400), random(300)), Size(175, 80));
  //   newFrame->setTitleFmt("Frame #%d", dynamicFrames.count());
  //   newFrame->frameStyle().backgroundColor = RGB888(random(256), random(256), random(256));
  //   auto label = new uiStaticLabel(newFrame, "FabGL - www.fabgl.com", Point(5, 30));
  //   label->anchors().left = false;
  //   label->anchors().top = false;
  //   label->labelStyle().textFont  = &fabgl::FONT_std_17;
  //   label->labelStyle().textColor = RGB888(random(256), random(256), random(256));
  //   label->labelStyle().backgroundColor = newFrame->frameStyle().backgroundColor;
  //   label->update();
  //   dynamicFrames.push(newFrame);
  // }

  // void onTestModalDialogButtonClick() {
  //   // show TestModalDialog as modal window
  //   auto testModalDialog = new TestModalDialog(rootWindow());
  //   showModalWindow(testModalDialog);
  //   destroyWindow(testModalDialog);
  // }

  // void onTestInputBox() {
  //   InputBox ib(this);
  //   ib.setAutoOK(5);
  //   //// simple message box
  //   ib.message("InputBox", "This is a message box using InputBox object");
  //   //// progress bar
  //   ib.progressBox("Example of Progress Bar", "Abort", true, 200, [&](fabgl::ProgressForm * form) {
  //     for (int i = 0; i <= 100; ++i) {
  //       if (!form->update(i, "Index is %d/100", i))
  //         break;
  //       delay(40);
  //     }
  //     delay(400);
  //   });
  //   //// menu
  //   int s = ib.menu("Example of simple Menu", "Click on one item", "Item number zero;Item number one;Item number two;Item number three");
  //   ib.messageFmt("", nullptr, "OK", "You have selected item %d", s);
  //   //// options selection box with OK button (items from separated strings) and autoOK of 5 seconds
  //   s = ib.select("Example of Menu with timeout", "Click on one item", "Item number zero;Item number one;Item number two;Item number three", ';', "Cancel", "OK");
  //   ib.messageFmt("", nullptr, "OK", "You have selected item %d", s);
  // }

};

