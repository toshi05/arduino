#include <PixelPlus.h>


#define MAX_DISP_X 127//画面サイズ
#define MAX_DISP_Y 127//画面サイズ


PixelPlus PIXEL ;
void DrawImage(int id,int x,int y,int flag);
void Shot(int id,int x,int y,int flag);
typedef struct{
  int id;
  int x;
  int y;
  int flag;
}
bull_info;
bull_info bullet = {
  {0,60,60,0}}


// ボールのデータ（縁取りが白いボール）
PROGMEM uint16_t white[] = {
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
};

PROGMEM uint16_t ball[] = {
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFB79,0xFB79,0xFB79,0xFB79,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFB79,0xFB79,0xFB79,0xFB79,0xFB79,0xFB79,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFB79,0xFB79,0xFB79,0xFB79,0xFB79,0xFB79,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFB79,0xFB79,0xFB79,0xFB79,0xFB79,0xFB79,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFB79,0xFB79,0xFB79,0xFB79,0xFB79,0xFB79,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFB79,0xFB79,0xFB79,0xFB79,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
};

PROGMEM uint16_t player[] = {
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
  0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,0xFFFE,
};
int x_pos = 0;
int y_pos = -1;

void setup(){
  Serial.begin(9600);
  PIXEL.init() ;
  PIXEL.backLight(1) ;
  PIXEL.clear(255, 255, 255);
  PIXEL.createSprite(12,10,10);//白塗りつぶし
  PIXEL.fillSprite(12,white);//
  PIXEL.createSprite(11,10,10);//黒四角
  PIXEL.fillSprite(11,player);//黒四角
  PIXEL.createSprite(0, 10,10);//ボール
  PIXEL.fillSprite(0, ball);
}

void loop(){
  Shot(id,x,y,flag);


void Shot(int id,int x,int y,int flag){
  do{
    if(y == 1) {
        DrawImage(12,x,y,flag);
        flag = 0;
        break;
      }
      if(flag == 1){
        DrawImage(id,x,y,flag);
        delay(1);
        y = y + y_pos;
      }
  }while(flag != 0);
}

void DrawImage(int id,int x,int y,int flag){
  if(flag == 0) PIXEL.drawSprite(12,x,y);
  else PIXEL.drawSprite(id,x,y);
}
