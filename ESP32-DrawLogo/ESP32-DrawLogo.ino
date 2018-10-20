/*
  06/01/2016
  Author: Makerbro
  Platforms: ESP8266
  Language: C++
  File: DrawLogo.ino
  ------------------------------------------------------------------------
  Description: 
  Drawing an image in the OLED display. The image date was generated using a 
  bitmap generator.
  ------------------------------------------------------------------------
  Please consider buying products from ACROBOTIC to help fund future
  Open-Source projects like this! We'll always put our best effort in every
  project, and release all our design files and code for you to use. 
  https://acrobotic.com/
  ------------------------------------------------------------------------
  License:
  Released under the MIT license. Please check LICENSE.txt for more
  information.  All text above must be included in any redistribution. 
*/
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

static unsigned char ACROBOT[] PROGMEM ={
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x80,0x80,0x00,0x00,0x00,0x02,
0x06,0x8E,0xFE,0xFC,0xFC,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xE0,0xF8,0xF8,0xFC,0xFC,0xCE,0x86,0x02,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x03,0x0F,0x1F,0x1E,0x3C,0x3E,
0x3F,0x3F,0x3F,0x3F,0x7F,0xFF,0xFF,0xFE,0xFC,0x78,0x30,0x90,0xC0,0xE0,0xE0,0xF0,
0xF0,0xF0,0xF8,0xF8,0xF8,0xF0,0xF0,0xF0,0xE0,0xE0,0xC0,0x80,0x30,0x78,0xFC,0xFE,
0xFF,0xFF,0xFF,0x7F,0x3F,0x3F,0x3F,0x3F,0x3C,0x1E,0x1F,0x0F,0x03,0x00,0x00,0xF0,
0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0xF0,0x10,0x10,0x10,0x10,0x10,
0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x20,0x10,0x10,0x10,0x30,0x60,0xC0,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0xF9,0xFE,0xFF,0x7F,0x3F,0x3F,0x1F,0x3F,
0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x3F,0x1F,0x1F,0x3F,0x7F,0xFF,0xFE,0xF9,0x83,
0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,
0x01,0x01,0x01,0x01,0x1F,0x00,0x00,0x00,0x00,0x00,0x1F,0x11,0x11,0x11,0x11,0x11,
0x00,0x00,0x00,0x00,0x1F,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x1F,0x10,0x10,
0x10,0x10,0x10,0x00,0x00,0x00,0x07,0x08,0x10,0x10,0x10,0x18,0x0C,0x07,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x83,0x3F,0xFF,0xFF,0xF8,0xF0,0xF8,0xFC,0xFC,
0xFE,0xFF,0x7F,0x9F,0x3F,0xFF,0xFE,0xFC,0xFC,0xF8,0xF0,0xF0,0xFF,0xFF,0x3F,0x87,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0xF0,
0x00,0xC0,0x7C,0x0C,0xF8,0x80,0x80,0xF8,0x0C,0x00,0x00,0x00,0xF0,0x18,0x0C,0x04,
0x04,0x04,0x08,0xF0,0x00,0x00,0x00,0x00,0xFC,0x44,0x44,0x44,0xC4,0x6C,0x38,0x00,
0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x04,0x04,0x04,
0x04,0x0C,0xF8,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0xC0,0xE0,0xF0,0x78,0x38,0x7C,
0xFC,0xFC,0xFC,0xFC,0xFE,0xFF,0xFF,0x7F,0x3E,0x1C,0x1B,0x07,0x3F,0x7F,0x7F,0x7F,
0x3F,0x3F,0x7F,0x7F,0x7F,0x3F,0x3F,0x7F,0x7F,0x7F,0x3F,0x07,0x0B,0x1C,0x3E,0x7F,
0xFF,0xFF,0xFE,0xFE,0xFC,0xFC,0xFC,0x7C,0x38,0x78,0xF0,0xE0,0xC0,0x00,0x00,0x00,
0x07,0x07,0x00,0x00,0x00,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x06,0x04,
0x04,0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x03,0x06,0x04,
0x00,0x00,0x00,0x07,0x04,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x07,0x04,0x04,0x04,
0x04,0x06,0x03,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x01,0x01,0x00,0x00,0x00,0x40,
0x60,0x71,0x7F,0x3F,0x3F,0x1F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x07,0x1F,0x3F,0x3F,0x7F,0x73,0x60,0x40,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

void setup()
{
  pinMode(16,OUTPUT);
  digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
  delay(50); 
  digitalWrite(16, HIGH); // while OLED is running, must set GPIO16 to high  
  
  Wire.begin(4,15);	
  oled.init();                      // Initialze SSD1306 OLED display
  oled.clearDisplay();              // Clear screen
  oled.drawBitmap(ACROBOT, 1024);   // 1024 pixels for logo
}

void loop()
{
}
