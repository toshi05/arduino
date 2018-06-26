#include<stdio.h>

void Shot_bullet(int id,int x,int y,int flag);
void DrawImage(int id,int x,int y,int flag);
int y_pos = -1;
int main(void){
        Shot_bullet(1,2,3,1);
        return(0);
}
void Shot_bullet(int id,int x,int y,int flag){
  do{
    if(y == 1) {
        DrawImage(12,x,y,flag);
        flag = 0;
        break;
      }
      if(flag == 1){
        DrawImage(id,x,y,flag);
        y = y + y_pos;
      }
  }while(flag != 0);
}
void DrawImage(int id,int x,int y,int flag){
        printf("%d,%d,%d,%d",id,x,y,flag);
}
