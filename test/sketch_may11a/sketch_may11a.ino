#include <Arduino.h>
#include "fabgl.h"
#include "fonts/font_8x19.h"
#include "fonts/font_8x8.h"

using namespace fabgl;
VGAController vga;

void setup() {
  // Setup pins and resolution (5 GPIOs hence we have up to 8 colors)
  vga.begin();
  vga.setResolution(VGA_640x350_70HzAlt1);
  
  // Paint a green rectangle with red border
  Canvas cv(&vga);
  cv.setPenColor(Color::Blue);
  cv.setBrushColor(Color::Yellow);
  cv.fillRectangle(0, 0, cv.getWidth(), cv.getHeight());
  cv.drawRectangle(0, 0, cv.getWidth(), cv.getHeight());
  cv.setGlyphOptions(GlyphOptions().FillBackground(true).DoubleWidth(1));
  int main_headline_pos_col = cv.getWidth() /3; //
  int main_headline_pos_row = cv.getHeight() /5; //
  
  cv.selectFont(&Font_8x19);
  
  cv.drawText(main_headline_pos_col, main_headline_pos_row, "Main Headline:");
  
  int second_headline_pos_col = cv.getWidth() /3; //
  int second_headline_pos_row = cv.getHeight() /4 ; //
  
  cv.selectFont(&Font_8x8);
  
  cv.drawText(second_headline_pos_col, second_headline_pos_row, "Second Headline:");
  
  int text_pos_col = 0; //
  int text_pos_row = cv.getHeight() /2 ; //
  
  cv.drawText(text_pos_col, text_pos_row, "Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet.",true);
  
  // cv.drawText(20, 20, "Hello World!");
  // cv.drawText(20, 20, "Hello World!");

}

void loop() {
  
}
