#include "DxLib.h"
#include "Suken.h"
#define _USE_MATH_DEFINES
#include <math.h>


int x; //�ʂ̒��S
int y;
bool check[8][5];
int bswitch; //�ʂ̐F
int box1; 
int boxy1;
double kaitenn; //�����̔��̌X��
double kaitenn2; //��̔��̌X��
double kaitenn3; //�E��̔��̌X��
int ball; 
int ballcolor;
double kyoriR;
double kyoriRR;
double kyoriRRR;
double sikiy;
double sikix;
int tokuten;
int i;

struct{
	int x,y;
}balls[3];

void Awake(){


	/*for(int i=0;i<8;i++){
		for(int j=0;j<5;j++){
			check[i][j]=true;
		}

		
	}*/
	x=320;
	box1 = LoadGraph("hako.png");
}

void GameLoop(){


	     DrawBox(0,420,200,480,RED,true); //���̐Ԑ΂̔�
         DrawBox(220,420,420,480,GREEN,true);
         DrawBox(440,420,640,480,BLUE,true);

       	 if(y==0){
				 ballcolor = GetRand(2);} //�ʂ̐F�����߂�
		 
		 //y+=5;
		 
		 if(ball % 10 == 0 && ballcolor == 0){ //�F�̋�
			 DrawCircle(x,y,20,BLUE,true);
			 bswitch=1;
		 }
		 if(bswitch ==1 && ballcolor == 0){
		 DrawCircle(x,y,20,BLUE,true);
		 }
		 
		 
		 if(ball % 10 == 0 && ballcolor == 1){ //�΂̋�
			 DrawCircle(x,y,20,GREEN,true);
			 bswitch=1;
		 }
		 if(bswitch ==1 && ballcolor == 1){
		    DrawCircle(x,y,20,GREEN,true);
		 }

		 
		 if(ball % 10 == 0 && ballcolor == 2){ //�Ԃ̋�
			 DrawCircle(x,y,20,RED,true);
			 bswitch=1;
		 }
		 if(bswitch ==1 && ballcolor == 2){
		    DrawCircle(x,y,20,RED,true);
		 }

		 kyoriRR = abs(tan(kaitenn2)*x-y-tan(kaitenn2)*320+190)/sqrt(tan(kaitenn2)+1); //��̔�
		 kyoriR = abs(tan(kaitenn)*x-y-tan(kaitenn)*190+310)/sqrt(tan(kaitenn)+1);     //�����̔�
		 kyoriRRR = abs(tan(kaitenn3)*x-y-tan(kaitenn3)*190+310)/sqrt(tan(kaitenn3)+1); //�E���̔�
		 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 ///////////////////////////////////�������� ��̔��ɂ��E���A�E��̔��ɂ��������Ă��Ȃ��Ƃ�////////////////////////////////
		 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 if( (kyoriRR>30  /*�������畝����*/ || ( (int)pow((double)(320 - x),2) + (int)pow((double)(190 -y),2 )) > 100*100 ) && (kyoriR>30  /*�������畝����*/ || ( (int)pow((double)(190 - x),2) + (int)pow((double)(310 -y),2 )) > 100*100) && (kyoriRRR>30  /*�������畝����*/ || ( (int)pow((double)(450 - x),2) + (int)pow((double)(310 -y),2 )) > 100*100  )){
			y+=5;
		 }
		 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 if( kyoriRR<30 && kaitenn2>0   /*�������畝����*/ &&( (int)pow((double)(320 - x),2) + (int)pow((double)(190 -y),2 )) < 100*100   ){     
			DrawBox(10,10,30,30,RED,true); ///�m�F�p  ��̔�
			//kyoriRR>30;
			//y-=5;
			x+=2;
			///////y���W///////////////////////////////////////////////////////////////
			y+=tan(kaitenn2)*2;
			/////////////////////////////////////////////////////////////////////////////////
		  }
		 if(kyoriRR<30 && kaitenn2==0       ){     
			DrawBox(10,10,30,30,RED,true); ///�m�F�p
			//kyoriRR>30;
			y=160;
		  }
		  if(kyoriRR<30 && kaitenn2<0  /*�������畝����*/ &&( (int)pow((double)(320 - x),2) + (int)pow((double)(190 -y),2 )) < 100*100   ){     
			DrawBox(30,30,50,50,BLUE,true); ///�m�F�p
			//kyoriRR>30;
			//y-=5;
			x-=2;
			///////y���W///////////////////////////////////////////////////////////////
			y-=tan(kaitenn2)*2;
			/////////////////////////////////////////////////////////////////////////////////
		  }



		  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		  
		 if( kyoriR<30 && kaitenn>0   /*�������畝����*/ &&( (int)pow((double)(190 - x),2) + (int)pow((double)(310 -y),2 )) < 100*100   ){     
			DrawBox(10,10,30,30,RED,true); ///�m�F�p  ��̔�
			//kyoriR>30;
			//y-=5;
			x+=2;
			///////y���W///////////////////////////////////////////////////////////////
			y+=tan(kaitenn)*2;
			/////////////////////////////////////////////////////////////////////////////////
		  }
		 if(kyoriR<30 && kaitenn==0       ){     
			DrawBox(10,10,30,30,RED,true); ///�m�F�p
			//kyoriR>30;
			y=280;
		  }
		  if(kyoriR<30 && kaitenn<0  /*�������畝����*/ &&( (int)pow((double)(190 - x),2) + (int)pow((double)(310 -y),2 )) < 100*100   ){     
			DrawBox(30,30,50,50,BLUE,true); ///�m�F�p
			//kyoriR>30;
			//y-=5;
			x-=2;
			///////y���W///////////////////////////////////////////////////////////////
			y-=tan(kaitenn)*2;
			/////////////////////////////////////////////////////////////////////////////////
		  }


		  
		  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		   
		 if( kyoriRRR<30 && kaitenn3>0   /*�������畝����*/ &&( (int)pow((double)(450 - x),2) + (int)pow((double)(310 -y),2 )) < 100*100   ){     
			DrawBox(10,10,30,30,RED,true); ///�m�F�p  ��̔�
			//kyoriRRR>30;
			//y-=5;
			x+=2;
			///////y���W///////////////////////////////////////////////////////////////
			y+=tan(kaitenn3)*2;
			/////////////////////////////////////////////////////////////////////////////////
		  }
		 if(kyoriRRR<30 && kaitenn3==0       ){     
			DrawBox(10,10,30,30,RED,true); ///�m�F�p
			//kyoriRRR>30;
			y=280;
		  }
		  if(kyoriRRR<30 && kaitenn3<0  /*�������畝����*/ &&( (int)pow((double)(450 - x),2) + (int)pow((double)(310 -y),2 )) < 100*100   ){     
			DrawBox(30,30,50,50,BLUE,true); ///�m�F�p
			//kyoriRRR>30;
			//y-=5;
			x-=2;
			///////y���W///////////////////////////////////////////////////////////////
			y-=tan(kaitenn3)*2;
			/////////////////////////////////////////////////////////////////////////////////
		  }



		  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		  
		 /*if( kyoriR<30 && kaitenn>0){  ////////////�����̔�    
			x+=2;
		  }
		 if(kyoriR<30 && kaitenn==0){
			y=280;
		  }
		  if(kyoriR<30 && kaitenn<0){     
			x-=2;
		  }

		  if( kyoriRRR<30 && kaitenn3>0){  //////////�E���̔�   
			x+=2;
		  }
		 if(kyoriRRR<30 && kaitenn3==0){
			y=280;
		  }
		  if(kyoriRRR<30 && kaitenn3<0){     
			x-=2;
		  }*/

		 /*for(int i=0;i<3;i++){
			 if(balls[i].y>400){
				 balls[i].y = 0;
			}
		 }*/
		 if(y>400){
			y=0;
		 }
		 if(CheckHitKey(KEY_INPUT_L)){ //��̔��̉�]
		    kaitenn2+=M_PI*5/180;
		 }
		 if(CheckHitKey(KEY_INPUT_J)){
			  kaitenn2-=M_PI*5/180;
		 }
		  if(CheckHitKey(KEY_INPUT_D)){ //���̔��̉�]
		    kaitenn+=M_PI*5/180;
			kaitenn3+=M_PI*5/180;
		 }
		 if(CheckHitKey(KEY_INPUT_A)){
			  kaitenn-=M_PI*5/180;
			  kaitenn3-=M_PI*5/180;
		 }
		 if(kaitenn>M_PI*30/180){ ///��]�̕��̐���
			kaitenn = M_PI*30/180;
		 }
		 if(kaitenn<M_PI*-30/180){
			kaitenn = M_PI*-30/180;
		 }
		 if(kaitenn3>M_PI*30/180){
			kaitenn3 = M_PI*30/180;
		 }
		 if(kaitenn3<M_PI*-30/180){
			kaitenn3 = M_PI*-30/180;
		 }
		 if(kaitenn2>M_PI*30/180){
			kaitenn2 = M_PI*30/180;
		 }
		 if(kaitenn2<M_PI*-30/180){
			kaitenn2 = M_PI*-30/180;
		 }
		 
		 
		 if(y==400 && 0<x<200 && ballcolor==2){      ///////���_
			tokuten+=1;
		 }
		 if(y==400 && 220<x<420 && ballcolor==1){
			 tokuten+=1;
		 }
		 if(y==400 && 440<x<640 && ballcolor==0){
			tokuten+=1;
		 }
		 DrawRotaGraph(190,310,1,kaitenn,box1,true,0); //�����̔�
		 DrawRotaGraph(450,310,1,kaitenn3,box1,true,0); //�E���̔�
		 DrawRotaGraphF(320,190,1,kaitenn2,box1,true,0); //��̔�
		 
		 
		 DrawFormatString(0,0,RED,"%d",tokuten); 
		 
}



	