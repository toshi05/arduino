#include<stdio.h>
#include <stdbool.h>
#define BULLET_NUM 10

//void move_bullet(int x,int y,bool flag);
int check_input(int b,int count);
typedef struct{
  bool flag;//弾が発射中かどうか
  int x;//x座標
  int y;//y座標
}SHOT;
SHOT shot_bullet[BULLET_NUM];
void ima(SHOT *data,int count);
int count = 0;
int b =0;
int x,y = 0;
int y_pos = 1;
int main(void){
  do{
    printf("%d\n",count);
    scanf("%d",&b);
    if(check_input(b,count)){//入力があったかどうか（射撃タイミングかどうか）
      scanf("%d,%d",&x,&y);//ジョイコン入力の座標想定
      shot_bullet[count].flag = true;
      printf("draw\n");//描画関数呼び出し
      shot_bullet[count].x = x;//初期x
      shot_bullet[count].y = y;//初期y
      ima(&shot_bullet,count);
      if(shot_bullet[count].flag && shot_bullet[count].y < 2){//発射ステータスだけど発射位置が画面外
        shot_bullet[count].flag = false;//ダメ
        printf("remove");//描画削除(id = 12)とか
      }else count++;//描画できるならカウントすすめる．
    }if(b == 0) printf("no mark");//入力ないならなにもしない
    for(int i = 0;i < BULLET_NUM;i++){//たま10発で描画できるものがあるか，あれば描画する
      if(shot_bullet[i].flag == true){
          shot_bullet[i].y -= y_pos;
          if(shot_bullet[i].y < 2){
            shot_bullet[i].flag = false;
            printf("remove1");
          }
        printf("y = %d,x = %d,i = %d",shot_bullet[i].y,shot_bullet[i].x,i);
      }
    }
    printf("%dcount",count);
  }while(count < 10);
  for(int j = 0;j < 10;j++)
  printf("%d,%d\n",shot_bullet[j].x,shot_bullet[j].y);
}

int check_input(int b,int count){
  if(b == 1 && count < 10) return(1);
  else return(0);
}

void ima(SHOT*data,int count){
  printf("%daho",(data+count)->x);
  data->x = 0;
}

/*void move_bullet(int x,int y,bool flag){
  y -= y_pos;
  if(y < 2){
    flag = false;
  }
}*/
