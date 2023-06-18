#include <ESP32Lib.h>
#include <Ressources/Font6x8.h>
#include <memory>

//pin configuration
const int redPin = 21;
const int greenPin = 18;
const int bluePin = 4;
const int hsyncPin = 23;
const int vsyncPin = 15;

const int SIZE_OF_CHAR = 8;
const int NUM_OF_LABELS = 3;


VGA3Bit vga;

class Ilabel
{
public:
  int xres;
  int yres;
  char* m_data;
  int placeHolderlength;
  bool isActive;
  
  Ilabel(int x,int y,int len):xres(x),yres(y){
    isActive = true;
    m_data = new char[len];
    for(int i = 0; i<len; i++)
    {
      m_data[i] = '\0';
    }
    placeHolderlength = len;
  }
  bool active() {
    return isActive;
  }
  void drawCmnLabel(char* data)
  {
    //text position
    vga.setCursor(xres, yres);
    //m_data = db.getMainTitle();
    //White text color no background color
    vga.setTextColor(vga.RGB(255));
    //show the remaining memory
    vga.println(data);
  }
  virtual void drawSpecificLabel() = 0;
};

class CMainTitle : public Ilabel
{
public:
  CMainTitle(int x, int y, int len) : Ilabel(x, y, len) {}
  //"db.getMainTitle()"
  void drawSpecificLabel()
  {
    //m_data = "db.getMainTitle()"
    memcpy(m_data, "MainTitle", sizeof(m_data));
    drawCmnLabel(m_data);
  }
};

class CSubTitle: public Ilabel
{
public:
  //"db.getSubTitle()"
  CSubTitle(int x, int y, int len) : Ilabel(x, y, len) {}
  void drawSpecificLabel()
  {
    //m_data = "db.getSubTitle()"
    memcpy(m_data, "SubTitle", sizeof(m_data));
    drawCmnLabel(m_data);
  }
};

class CTextBlock : public Ilabel
{
public:
  //"db.getTextBlock()"
  CTextBlock(int x, int y, int len) : Ilabel(x, y, len) {}
  void drawSpecificLabel()
  {
    //m_data = "db.getTextBlock()"
    memcpy(m_data, "TEXTTTTTTTTTTTTTT_  ___    _____  BOXXXXXXXXXXXX", sizeof(m_data));
    drawCmnLabel(m_data);
  }  
};

class displayManager
{
public:
  displayManager() = default;
  void init()
  {
    createLabelsMetadata();
  }
  void createLabelsMetadata()
  {
    //line1
    m_labelsContainer[0] = new CMainTitle((vga.xres)/4, 0, 10);
    //line2
    m_labelsContainer[1] = new CSubTitle((vga.xres)/4, 10, 8);
    //line3
    m_labelsContainer[2] = new CTextBlock((vga.xres)/4, 40, 100);
    //line4

    //line5

    //line6

    //line7
  }
  void drawActiveLabels()
  {
    for (int i = 0; i<NUM_OF_LABELS; i++)
    {
      if(m_labelsContainer[i]->active())
      {
        m_labelsContainer[i]->drawSpecificLabel();
      }
      //show the backbuffer (only needed when using backbuffering)
      vga.show();
    }
  }
private:
  Ilabel* m_labelsContainer[3];
};


displayManager displayInstance;

void setup() {
  Serial.begin(115200);
  //enabling double buffering
  vga.setFrameBufferCount(2);
  //Mode::custom(xres, yres, fixedYDivider = 1) calculates the parameters for our custom resolution.
  //the y resolution is only scaling integer divisors (yet).
  //if you don't like to let it scale automatically pass a fixed parameter with a fixed divider.
  Mode myMode = vga.MODE640x480.custom(80, 60);
  
  // //print the parameters
  // myMode.print<HardwareSerial>(Serial);

  //use the mode
  vga.init(vga.MODE320x240, redPin, greenPin, bluePin, hsyncPin, vsyncPin);
  //setting the font
  vga.setFont(Font6x8);

  displayInstance.init();
}

void loop() {
  
  displayInstance.drawActiveLabels();
  // put your main code here, to run repeatedly:


}
