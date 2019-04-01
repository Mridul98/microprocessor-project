#include <SPI.h>
#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
int analogPin = A0;
ESP8266WebServer server;
char* ssid ="TP-LINK_A98E76";
char* pass = "33115524650";
IPAddress localIP ;
//const char* html  ="<!DOCTYPE html> <html lang=\"en\"> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\"> <script src=\"https://canvasjs.com/assets/script/canvasjs.min.js\"></script> <title>Canvas Chart</title> </head> <script> window.onload = function(){ var chartRef; var max = 120; var min = 20; var chart = new CanvasJS.Chart(\"chartContainer\", { theme:\"light2\", title: { text: \"Live temparature Data\" }, axisX: { title : \"Time\" }, axisY : { title : \"Value\" }, data:[ { type: \"line\", toolTipContent : \" {y} taka\", dataPoints : [ {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min}, {y : Math.random()*(+max - +min)+ +min} ] } ] } ); chart.render(); setInterval(function(){ chart.options.data[0].dataPoints.push( {y : Math.random()*(+max - +min)+ +min} ); if(chart.options.data[0].type === \"bar\"){ chart.options.data[0].type = \"line\"; } else { chart.options.data[0].type = \"bar\"; } chart.render(); },1000); } </script> <body> <div id=\"chartContainer\" style=\"height:500px; width: 100%\"> </div> </body> </html>";
//const char* html ="<!DOCTYPE html> <html lang=\"en\"> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\"><script src=\"https://canvasjs.com/assets/script/canvasjs.min.js\"><title>Temparature Data</title> </head> <script> window.onload = function () { var chartContainer = document.getElementById('chartContainer'); var chart = new CanvasJS.Chart(\"chartContainer\", { animationEnabled: true, theme: \"light2\", title:{ text: \"Temparature data\" }, axisX:{ title: \"time\" }, axisY:{ title: \"temparature\", includeZero: false }, data: [{ xValueFormatString:\"HH mm s\", type: \"line\", dataPoints: [ ] }] }); addDataPoints(); setInterval(addDataPoints,2000); function addDataPoints() { var xVal = new Date(); var date = xVal.toLocaleString(); var yVal = Math.random()*100; chart.options.data[0].dataPoints.push({x:xVal,y: yVal}); chart.render(); console.log(xVal.toString()); console.log(yVal); // console.log(chart.options.data[0].dataPoints); } } </script> <body> <div id=\"chartContainer\"> </div> </body> </html>";
//const char* html ="<!DOCTYPE html> <html lang=\"en\"> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\"> <title>Document</title> <script src=\"https://cdnjs.cloudflare.com/ajax/libs/canvasjs/1.7.0/jquery.canvasjs.js\"></script> <script src=\"https://cdnjs.cloudflare.com/ajax/libs/canvasjs/1.7.0/jquery.canvasjs.min.js\"></script> </head> <script> window.onload = function () { var chartContainer = document.getElementById('chartContainer'); var chart = new CanvasJS.Chart(\"chartContainer\", { animationEnabled: true, theme: \"light2\", title:{ text: \"Temparature data\" }, axisX:{ title: \"time\" }, axisY:{ title: \"temparature\", includeZero: false }, data: [{ xValueFormatString:\"HH mm s\", type: \"line\", dataPoints: [ ] }] }); addDataPoints(); setInterval(addDataPoints,2000); function addDataPoints() { var xVal = new Date(); var date = xVal.toLocaleString(); var yVal = Math.random()*100; chart.options.data[0].dataPoints.push({x:xVal,y: yVal}); chart.render(); console.log(xVal.toString()); console.log(yVal); // console.log(chart.options.data[0].dataPoints); } } </script> <body> <div id=\"chartContainer\"> </div> </body> </html>";
const char* 
html ="<!DOCTYPE html> <html lang=\"en\"> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\"> <title>Document</title> <script src=\"https://cdnjs.cloudflare.com/ajax/libs/canvasjs/1.7.0/jquery.canvasjs.js\"></script> <script src=\"https://cdnjs.cloudflare.com/ajax/libs/canvasjs/1.7.0/jquery.canvasjs.min.js\"></script> </head> <script> window.onload = function () { var chartContainer = document.getElementById('chartContainer'); var chart = new CanvasJS.Chart(\"chartContainer\", { animationEnabled: true, theme: \"light2\", title:{ text: \"Temparature data\" }, axisX:{ title: \"time\" }, axisY:{ title: \"temparature\", includeZero: false }, data: [{ xValueFormatString:\"HH mm s\", type: \"line\", dataPoints: [ ] }] }); addDataPoints(); setInterval(addDataPoints,2000); function addDataPoints() { var xVal = new Date(); var date = xVal.toLocaleString(); var yVal = Math.random()*100; chart.options.data[0].dataPoints.push({x:xVal,y: yVal}); chart.render(); console.log(xVal.toString()); console.log(yVal); // console.log(chart.options.data[0].dataPoints); } } </script> <body> <div id=\"chartContainer\"> </div> </body> </html>";

#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  WiFi.begin(ssid,pass);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED){
    testscrolltext(".");
  }
  localIP = WiFi.localIP();
  testscrolltext(localIP.toString());
  Serial.println(String(localIP));
  delay(5000);
  server.on("/",[]{server.send(200,"text/html",html);} );
  server.begin();

}
void testfillroundrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2-2; i+=2) {
    // The INVERSE color is used so round-rects alternate white/black
    display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i,
      display.height()/4, INVERSE);
    display.display();
    delay(1);
  }

  delay(2000);
}
void testdrawtriangle(void) {
  display.clearDisplay();

  for(int16_t i=0; i<max(display.width(),display.height())/2; i+=5) {
    display.drawTriangle(
      display.width()/2  , display.height()/2-i,
      display.width()/2-i, display.height()/2+i,
      display.width()/2+i, display.height()/2+i, WHITE);
    display.display();
    delay(1);
  }

  delay(2000);
}
void testscrolltext(String data) {
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println(data);
  display.display();      // Show initial text
  delay(100);

  // Scroll in various directions, pausing in-between:
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  //display.startscrolldiagright(0x00, 0x07);
  //delay(2000);
  //display.startscrolldiagleft(0x00, 0x07);
  //delay(2000);
  //display.stopscroll();
  //delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
//testfillroundrect();
//testdrawtriangle();
int analogValue = analogRead(analogPin);
float milivolts = (analogValue/1024.0)*3300;
float celcius = milivolts/10;
server.handleClient();
Serial.print("in DegreeC = " );
String value = String(celcius);
Serial.println(value);
testscrolltext(value);
}
