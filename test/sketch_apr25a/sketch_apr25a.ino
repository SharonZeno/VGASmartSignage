#include "fabgl.h"

using namespace fabgl;

// Setup VGA Controller
VGATextController vgaController;

// Setup Canvas
Terminal canvas(&vgaController);

void setup() {
  // Set up the VGA controller with 480x640 resolution
  vgaController.begin();
  vgaController.setResolution();

  // Set up the canvas
  canvas.begin();
  canvas.setGlyphOptions(GlyphOptions().FillBackground(true));

  // Calculate the position to center the text
  int x = (vgaController.getScreenWidth() - canvas.textWidth("Hello World")) / 2;
  int y = vgaController.getScreenHeight() / 2;

  // Draw the text
  canvas.drawText(x, y, "Hello World");
}

void loop() {
}
