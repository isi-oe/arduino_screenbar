#include <FastLED.h>

#define DATA_PIN 2
#define NUM_LEDS 15

CRGB leds[NUM_LEDS];

// Mapping pins for buttons
int BUTTON1 = 5;
int BUTTON2 = 6;
int BUTTON3 = 7;
int BUTTON4 = 10;
int BUTTON5 = 9;
int BUTTON6 = 8;

// Values for determining states
int anim = 0;
int start = 1;
int ct = 50;
int functionState = 1;
int buttonPressed = 0;

// Start up brightness
int brightness = 128;

// Struct for storing RGB values
struct RGB {
    unsigned char R;
    unsigned char G;
    unsigned char B;
};
struct RGB*rgb = malloc(111*sizeof(struct RGB));

void setup() {
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
  pinMode(BUTTON5, INPUT_PULLUP);
  pinMode(BUTTON6, INPUT_PULLUP);
  
  // 1000
  rgb[0].R = 255;
  rgb[0].G = 56;
  rgb[0].B = 0;
  
  // 1100
  rgb[1].R = 255;
  rgb[1].G = 71;
  rgb[1].B = 0;
  
  // 1200
  rgb[2].R = 255;
  rgb[2].G = 83;
  rgb[2].B = 0;
  
  // 1300
  rgb[3].R = 255;
  rgb[3].G = 93;
  rgb[3].B = 0;
  
  // 1400
  rgb[4].R = 255;
  rgb[4].G = 101;
  rgb[4].B = 0;
  
  // 1500
  rgb[5].R = 255;
  rgb[5].G = 109;
  rgb[5].B = 0;
  
  // 1600
  rgb[6].R = 255;
  rgb[6].G = 115;
  rgb[6].B = 0;
  
  // 1700
  rgb[7].R = 255;
  rgb[7].G = 121;
  rgb[7].B = 0;
  
  // 1800
  rgb[8].R = 255;
  rgb[8].G = 126;
  rgb[8].B = 0;
  
  // 1900
  rgb[9].R = 255;
  rgb[9].G = 131;
  rgb[9].B = 0;
  
  // 2000
  rgb[10].R = 255;
  rgb[10].G = 138;
  rgb[10].B = 18;
  
  // 2100
  rgb[11].R = 255;
  rgb[11].G = 142;
  rgb[11].B = 33;
  
  // 2200
  rgb[12].R = 255;
  rgb[12].G = 147;
  rgb[12].B = 44;
  
  // 2300
  rgb[13].R = 255;
  rgb[13].G = 152;
  rgb[13].B = 54;
  
  // 2400
  rgb[14].R = 255;
  rgb[14].G = 157;
  rgb[14].B = 63;
  
  // 2500
  rgb[15].R = 255;
  rgb[15].G = 161;
  rgb[15].B = 72;
  
  // 2600
  rgb[16].R = 255;
  rgb[16].G = 165;
  rgb[16].B = 79;
  
  // 2700
  rgb[17].R = 255;
  rgb[17].G = 169;
  rgb[17].B = 87;
  
  // 2800
  rgb[18].R = 255;
  rgb[18].G = 173;
  rgb[18].B = 94;
  
  // 2900
  rgb[19].R = 255;
  rgb[19].G = 177;
  rgb[19].B = 101;
  
  // 3000
  rgb[20].R = 255;
  rgb[20].G = 180;
  rgb[20].B = 107;
  
  // 3100
  rgb[21].R = 255;
  rgb[21].G = 184;
  rgb[21].B = 114;
  
  // 3200
  rgb[22].R = 255;
  rgb[22].G = 187;
  rgb[22].B = 120;
  
  // 3300
  rgb[23].R = 255;
  rgb[23].G = 190;
  rgb[23].B = 126;
  
  // 3400
  rgb[24].R = 255;
  rgb[24].G = 193;
  rgb[24].B = 132;
  
  // 3500
  rgb[25].R = 255;
  rgb[25].G = 196;
  rgb[25].B = 137;
  
  // 3600
  rgb[26].R = 255;
  rgb[26].G = 199;
  rgb[26].B = 143;
  
  // 3700
  rgb[27].R = 255;
  rgb[27].G = 201;
  rgb[27].B = 148;
  
  // 3800
  rgb[28].R = 255;
  rgb[28].G = 204;
  rgb[28].B = 153;
  
  // 3900
  rgb[29].R = 255;
  rgb[29].G = 206;
  rgb[29].B = 159;
  
  // 4000
  rgb[30].R = 255;
  rgb[30].G = 209;
  rgb[30].B = 163;
  
  // 4100
  rgb[31].R = 255;
  rgb[31].G = 211;
  rgb[31].B = 163;
  
  // 4200
  rgb[32].R = 255;
  rgb[32].G = 213;
  rgb[32].B = 173;
  
  // 4300
  rgb[33].R = 255;
  rgb[33].G = 215;
  rgb[33].B = 177;
  
  // 4400
  rgb[34].R = 255;
  rgb[34].G = 217;
  rgb[34].B = 182;
  
  // 4500
  rgb[35].R = 255;
  rgb[35].G = 219;
  rgb[35].B = 186;
  
  // 4600
  rgb[36].R = 255;
  rgb[36].G = 221;
  rgb[36].B = 190;
  
  // 4700
  rgb[37].R = 255;
  rgb[37].G = 223;
  rgb[37].B = 194;
  
  // 4800
  rgb[38].R = 255;
  rgb[38].G = 225;
  rgb[38].B = 198;
  
  // 4900
  rgb[39].R = 255;
  rgb[39].G = 227;
  rgb[39].B = 202;
  
  // 5000
  rgb[40].R = 255;
  rgb[40].G = 228;
  rgb[40].B = 206;
  
  // 5100
  rgb[41].R = 255;
  rgb[41].G = 230;
  rgb[41].B = 210;
  
  // 5200
  rgb[42].R = 255;
  rgb[42].G = 232;
  rgb[42].B = 213;
  
  // 5300
  rgb[43].R = 255;
  rgb[43].G = 233;
  rgb[43].B = 217;
  
  // 5400
  rgb[44].R = 255;
  rgb[44].G = 235;
  rgb[44].B = 220;
  
  // 5500
  rgb[45].R = 255;
  rgb[45].G = 236;
  rgb[45].B = 224;
  
  // 5600
  rgb[46].R = 255;
  rgb[46].G = 238;
  rgb[46].B = 227;
  
  // 5700
  rgb[47].R = 255;
  rgb[47].G = 239;
  rgb[47].B = 230;
  
  // 5800
  rgb[48].R = 255;
  rgb[48].G = 240;
  rgb[48].B = 233;
  
  // 5900
  rgb[49].R = 255;
  rgb[49].G = 242;
  rgb[49].B = 236;
  
  // 6000
  rgb[50].R = 255;
  rgb[50].G = 243;
  rgb[50].B = 239;

  // 6100
  rgb[51].R = 255;
  rgb[51].G = 244;
  rgb[51].B = 242;

  // 6200
  rgb[52].R = 255;
  rgb[52].G = 245;
  rgb[52].B = 245;

  // 6300
  rgb[53].R = 255;
  rgb[53].G = 246;
  rgb[53].B = 247;

  // 6400
  rgb[54].R = 255;
  rgb[54].G = 248;
  rgb[54].B = 251;

  // 6500
  rgb[55].R = 255;
  rgb[55].G = 249;
  rgb[55].B = 253;

  // 6600
  rgb[56].R = 254;
  rgb[56].G = 249;
  rgb[56].B = 255;

  // 6700
  rgb[57].R = 252;
  rgb[57].G = 247;
  rgb[57].B = 255;

  // 6800
  rgb[58].R = 249;
  rgb[58].G = 246;
  rgb[58].B = 255;

  // 6900
  rgb[59].R = 247;
  rgb[59].G = 245;
  rgb[59].B = 255;

  // 7000
  rgb[60].R = 245;
  rgb[60].G = 243;
  rgb[60].B = 255;

  // 7100
  rgb[61].R = 243;
  rgb[61].G = 242;
  rgb[61].B = 255;

  // 7200
  rgb[62].R = 240;
  rgb[62].G = 241;
  rgb[62].B = 255;

  // 7300
  rgb[63].R = 239;
  rgb[63].G = 240;
  rgb[63].B = 255;

  // 7400
  rgb[64].R = 237;
  rgb[64].G = 239;
  rgb[64].B = 255;

  // 7500
  rgb[65].R = 235;
  rgb[65].G = 238;
  rgb[65].B = 255;

  // 7600
  rgb[66].R = 233;
  rgb[66].G = 237;
  rgb[66].B = 255;

  // 7700
  rgb[67].R = 231;
  rgb[67].G = 236;
  rgb[67].B = 255;

  // 7800
  rgb[68].R = 230;
  rgb[68].G = 235;
  rgb[68].B = 255;

  // 7900
  rgb[69].R = 228;
  rgb[69].G = 234;
  rgb[69].B = 255;

  // 8000
  rgb[70].R = 227;
  rgb[70].G = 233;
  rgb[70].B = 255;

  // 8100
  rgb[71].R = 225;
  rgb[71].G = 232;
  rgb[71].B = 255;

  // 8200
  rgb[72].R = 224;
  rgb[72].G = 231;
  rgb[72].B = 255;

  // 8300
  rgb[73].R = 222;
  rgb[73].G = 230;
  rgb[73].B = 255;

  // 8400
  rgb[74].R = 221;
  rgb[74].G = 230;
  rgb[74].B = 255;

  // 8500
  rgb[75].R = 220;
  rgb[75].G = 229;
  rgb[75].B = 255;

  // 8600
  rgb[76].R = 218;
  rgb[76].G = 229;
  rgb[76].B = 255;

  // 8700
  rgb[77].R = 217;
  rgb[77].G = 227;
  rgb[77].B = 255;

  // 8800
  rgb[78].R = 216;
  rgb[78].G = 227;
  rgb[78].B = 255;

  // 8900
  rgb[79].R = 215;
  rgb[79].G = 226;
  rgb[79].B = 255;

  // 9000
  rgb[80].R = 214;
  rgb[80].G = 225;
  rgb[80].B = 255;

  // 9100
  rgb[81].R = 212;
  rgb[81].G = 225;
  rgb[81].B = 255;

  // 9200
  rgb[82].R = 211;
  rgb[82].G = 224;
  rgb[82].B = 255;

  // 9300
  rgb[83].R = 210;
  rgb[83].G = 223;
  rgb[83].B = 255;

  // 9400
  rgb[84].R = 209;
  rgb[84].G = 223;
  rgb[84].B = 255;

  // 9500
  rgb[85].R = 208;
  rgb[85].G = 222;
  rgb[85].B = 255;

  // 9600
  rgb[86].R = 207;
  rgb[86].G = 221;
  rgb[86].B = 255;

  // 9700
  rgb[87].R = 207;
  rgb[87].G = 221;
  rgb[87].B = 255;

  // 9800
  rgb[88].R = 206;
  rgb[88].G = 220;
  rgb[88].B = 255;

  // 9900
  rgb[89].R = 205;
  rgb[89].G = 220;
  rgb[89].B = 255;

  // 10000
  rgb[90].R = 207;
  rgb[90].G = 218;
  rgb[90].B = 255;

  // 10100
  rgb[91].R = 207;
  rgb[91].G = 218;
  rgb[91].B = 255;

  // 10200
  rgb[92].R = 206;
  rgb[92].G = 217;
  rgb[92].B = 255;

  // 10300
  rgb[93].R = 205;
  rgb[93].G = 217;
  rgb[93].B = 255;

  // 10400
  rgb[94].R = 204;
  rgb[94].G = 216;
  rgb[94].B = 255;

  // 10500
  rgb[95].R = 204;
  rgb[95].G = 216;
  rgb[95].B = 255;

  // 10600
  rgb[96].R = 203;
  rgb[96].G = 215;
  rgb[96].B = 255;

  // 10700
  rgb[97].R = 202;
  rgb[97].G = 215;
  rgb[97].B = 255;

  // 10800
  rgb[98].R = 202;
  rgb[98].G = 214;
  rgb[98].B = 255;

  // 10900
  rgb[99].R = 201;
  rgb[99].G = 214;
  rgb[99].B = 255;

  // 11000
  rgb[100].R = 200;
  rgb[100].G = 213;
  rgb[100].B = 255;

  // 11100
  rgb[101].R = 200;
  rgb[101].G = 213;
  rgb[101].B = 255;

  // 11200
  rgb[102].R = 199;
  rgb[102].G = 212;
  rgb[102].B = 255;

  // 11300
  rgb[103].R = 198;
  rgb[103].G = 212;
  rgb[103].B = 255;

  // 11400
  rgb[104].R = 198;
  rgb[104].G = 212;
  rgb[104].B = 255;

  // 11500
  rgb[105].R = 197;
  rgb[105].G = 211;
  rgb[105].B = 255;

  // 11600
  rgb[106].R = 197;
  rgb[106].G = 211;
  rgb[106].B = 255;

  // 11700
  rgb[107].R = 197;
  rgb[107].G = 210;
  rgb[107].B = 255;

  // 11800
  rgb[108].R = 196;
  rgb[108].G = 210;
  rgb[108].B = 255;

  // 11900
  rgb[109].R = 195;
  rgb[109].G = 210;
  rgb[109].B = 255;

  // 12000
  rgb[110].R = 195;
  rgb[110].G = 209;
  rgb[110].B = 255;
  
  // correction
  rgb[111].R = 200;
  rgb[111].G = 255;
  rgb[111].B = 255;

  
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}

void loop() {
  int BUTTON_STATE_1 = digitalRead(BUTTON1);
  int BUTTON_STATE_2 = digitalRead(BUTTON2);
  int BUTTON_STATE_3 = digitalRead(BUTTON3);
  int BUTTON_STATE_4 = digitalRead(BUTTON4);
  int BUTTON_STATE_5 = digitalRead(BUTTON5);
  int BUTTON_STATE_6 = digitalRead(BUTTON6);
  
  if(BUTTON_STATE_1 == 0) {
    brightness += 5;
  } else if(BUTTON_STATE_2 == 0) {
    if(functionState == 0 && buttonPressed == 0) {
      functionState = 1;
      buttonPressed = 1;
    } else if(functionState == 1 && buttonPressed == 0) {
      functionState = 0;
      buttonPressed = 1;
    }
  } else if(BUTTON_STATE_3 == 0) {
    brightness -= 5;
  } else if(BUTTON_STATE_4 == 0) {
    changeTemperature(1);
  } else if(BUTTON_STATE_5 == 0) {
    ct = 50;
  } else if(BUTTON_STATE_6 == 0) {
    changeTemperature(0);
  }

  if(BUTTON_STATE_2 == 1) {
    buttonPressed = 0;
  }
  
  cleanValue(1);
  setLight(); 
  delay(20);
}

// Setting the light after every loop
void setLight() {
  if(functionState == 0 && buttonPressed == 0) {
    fill_solid(leds, NUM_LEDS, CRGB(rgb[ct].R, rgb[ct].G, rgb[ct].B));
    if(anim == 1) {
      fadeLight(1);
      anim = 0;
    } else {
      FastLED.setBrightness(brightness);
      FastLED.show();
    }
  } else if(functionState == 1 && buttonPressed == 0 && anim == 0) {
    if(start == 0) {
      fadeLight(0);
      turnOff();
      anim = 1;
    } else {
      turnOff();
      start = 0;
      anim = 1;
    }
  }
}

// Fade down/up, 1 for up, 0 for down
void fadeLight(int a) {
  if(a == 1) {
    for(int i = 0; i <= brightness; i += 5) {
      FastLED.setBrightness(i);
      FastLED.show();
      delay(20);
    }
  } else {
    for(int i = brightness; i >= 0; i -= 5) {
      FastLED.setBrightness(i);
      FastLED.show();
      delay(20);
    }    
  }
}

// Turn off lights
void turnOff() {
  FastLED.setBrightness(0);
  FastLED.show();
}

// Changing the temperature, 1 for down, 0 for up
void changeTemperature(int a) {
  if(a == 1) {
    ct += 1;
  } else {
    ct -= 1;
  }
  cleanValue(0);
}

// Cleaning the values
void cleanValue(int a) {
  if(a == 1) {
    if(brightness < 0) {
      brightness = 0;
    }
    if(brightness > 255) {
      brightness = 255;
    }  
  } else {
    if(ct > 110) {
      ct = 110;
    }
    if(ct < 0) {
      ct = 0;
    }
  }
}
