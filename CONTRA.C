/*-------------------------------------------------------------------------*/
	/*--------------------------------------------------*/
	/*--------------- CONTRA ---------------------------*/
	/*------ An air strike game.------------------------*/
	/*------ Developers:-  SOHARAB (M.C.A)--------------*/
	/*------ Colllege:-    TOCE-------------------------*/
	/*------ Place:-       Bangalore--------------------*/
	/*------ TOC:-         Sun, Apr 22, 2012, 7:38 PM---*/
	/*--------------------------------------------------*/
/*-------------------------------------------------------------------------*/

	#include <graphics.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>
	#include <dos.h>

	#define MAX_OPPONENT 1
	#define BULLETS      2

/*----------------Prototype declaration------------------------------------*/

	void *F16(int midx,int midy,int rang);
	void *EX_Choper(int midx,int midy,int rang);
	void *Blast(int midx,int midy,int rang);
	void *Bullets(int rang,int side);
	void *Numbers(int midx,int midy,int rang,int num);
	void *Missiles(int midx,int midy,int rang,int side);
	void *Allocate(int X1,int Y1,int X2,int Y2);
	int  Selectoion_screen(int MaxY,void *f16[5]);
	void Background(int MaxX,int MaxY,int rang);
	void ERROR_ALLOCATE(int locate);
	void display_Score(void *img[11],int num);
	void display_Life(void *img1,void *img2);
	void display_Health(int health);
	void display_Reduce_Health(int health,int loss);
	void getUsername(int midx,int midy,int score);
	void callGameOver();

/*-------------------------------------------------------------------------*/
	void main(void)
	{
		int  gdriver = DETECT, gmode,errorcode,midx,midy, maxcolor,MaxX,MaxY,i,j,k,l,m;
	    int  mx=16,my=250,key,ch,current_Key[4] = {72,80,75,77},tem_key=0,bulx[30],buly[30],up = 100,f16disp = 0,f16_flag = 0;
		int  blast_f16x[10],blast_f16y[10],hit_f16[10],blast_times_f16[10];
		int  blast_f16x1[10],blast_f16y1[10],hit_f161[10],blast_times_f161[10],f16hitBybulc[10];
	    int  chopx[10], chopy[10],chop_type[5],disX_chop[10],bulcx[10][10],bulcy[10][10],chop_flag[10],chopdisp = 0;
	    int  blast_cx[10],blast_cy[10],hit_c[10],blast_times_c[10];
	    int  score = 0,flag_score[10];
	    int  life = 5,level = 1,health = 100,loss = 0;

	    void *imag_f16[6];
	    void *imag_choper[10];
	    void *imag_fighter1[10];
	    void *imag_fighter2[10];
	    void *imag_bullets[2];
	    void *imag_missiels[2];
	    void *imag_B737[10];
	    void *imag_blast[4];
	    void *imag_Numbers[11];

		 //Initialization of bullets of f16.
	    for(i=0;i<30;i++)
		{
			bulx[i] = buly[i] = 0;
		}
		key = 75;

		 //Initialization of blast of choper and f16.
	    for(i=0;i<10;i++)
		{
			blast_cx[i] = blast_cy[i] = hit_c[i] = blast_times_c[i] = 0;
			blast_f16x[i] = blast_f16y[i] = hit_f16[i] = blast_times_f16[i] = f16hitBybulc[i] = 0;
			blast_f16x1[i] = blast_f16y1[i] = hit_f161[i]  = blast_times_f161[i],f16hitBybulc[i] = 0;
	    }
		
	    //Initialization of choper.
	    for(i=0;i<10;i++)
	    {
			chop_flag[i] = 0;
			for(j=0;j<10;j++)
			{
				bulcx[i][j] = bulcy[i][j] = 0;
			}
	    }
		
		//Initialization of score.
		for(i=0;i<10;i++) flag_score[i] = 0;

		//Initialization of f16 flag.
		f16_flag = 1;
		
		/* initialize graphics, local variables */
	    initgraph(&gdriver, &gmode, "");

	    /* read result of initialization */
	    errorcode = graphresult();
	    if (errorcode != grOk)
	    /* an error occurred */
	    {
			printf("Graphics error: %s\n", grapherrormsg(errorcode));
			printf("Press any key to halt:");
			getch();
			exit(1);
	    }
	    midx = getmaxx() / 2;  midy = getmaxy() / 2;
	    MaxX = getmaxx();  MaxY = getmaxy();
	    maxcolor = getmaxcolor();
/*-------------------------------------------------------------------------*/
	    /* Allocation of the memory to images */
	    for(i=0;i<5;i++)
	    {
			if((imag_f16[i] = F16(midx,midy,i+2)) == NULL)
				ERROR_ALLOCATE(1);
			cleardevice();
	    }
	    for(i=0;i<10;i++)
	    {
			if((imag_choper[i] = EX_Choper(midx,midy,i+2)) == NULL)
				ERROR_ALLOCATE(4);
			cleardevice();
	    }
	    for(i=0;i<2;i++)
	    {
			if((imag_bullets[i]=Bullets(15,i)) == NULL)
				ERROR_ALLOCATE(5);
				clrscr();cleardevice();
			if((imag_missiels[i]=Missiles(midx,midy,15,i)) == NULL)
				ERROR_ALLOCATE(6);
			cleardevice();
	    }
	    for(i=0,j=0;i<40&&j<4;i+=10,j++)
	    {
			if((imag_blast[j] = Blast(midx,midy,i)) == NULL)
				ERROR_ALLOCATE(8);
			cleardevice();
	    }
	    for(i=0;i<11;i++)
	    {
			if((imag_Numbers[i] = Numbers(midx,midy,6,i)) == NULL)
				ERROR_ALLOCATE(9);
			cleardevice();
	    }
/*-------------------------------------------------------------------------*/
	    /* Welcome screen */
	    /* Selection screen */
		cleardevice();
		Background(MaxX,MaxY,maxcolor);
		ch=Selectoion_screen(MaxY,imag_f16);
	    /* Setting background */
	    for ( i=0 ; i<500; ++i )
			putpixel(random(MaxX), random(MaxY), random(maxcolor-1 )+1);
	    putimage(mx,my,imag_f16[ch],1);
	    display_Life(imag_Numbers[level],imag_Numbers[life]);
		display_Health(health);
/*-------------------------------------------------------------------------*/
		while(1)
		{	
			if(f16_flag == 1  && life > 0)
			{
				if(level == 1){delay(6);}
				if(level == 2){delay(5);}
				if(level == 3){delay(4);}
				if(level == 4){delay(3);}
				if(level == 5){delay(2);}
				if(kbhit()) key = get_scancode();
				if(key == 72)//up.
				{
					if(my>10)
					{
						putimage(mx,my,imag_f16[ch],XOR_PUT); my-=4+ f16disp;
						putimage(mx,my,imag_f16[ch],XOR_PUT); key = 72;
					}
					tem_key = key;
				}
				if(key == 80)//down.
				{
				  if(my < 420)
				  {
				   putimage(mx,my,imag_f16[ch],XOR_PUT); my+=4+ f16disp;
				   putimage(mx,my,imag_f16[ch],1); key = 80;
				  }
				  tem_key = key;
				 }
				if(key == 75)//left.
				{
				  if(mx > 15)
				  {
				   putimage(mx,my,imag_f16[ch],XOR_PUT); mx-=4+ f16disp;
				   putimage(mx,my,imag_f16[ch],1); key = 75;
				 }
				 tem_key = key;
				}
				if(key == 77)//right.
				{
					if(mx < 540)
					{
					   putimage(mx,my,imag_f16[ch],XOR_PUT); mx+=4+ f16disp;
					   putimage(mx,my,imag_f16[ch],1); key = 77;
					}
					tem_key = key;
				}
				if(key == 57) // Space--> missile launched.
				{
					for(i=0;i<30;i++)
					{
						if(bulx[i] == 0 && buly[i] == 0)
						{
							bulx[i] = mx+56; buly[i] = my+11;
							putimage(bulx[i],buly[i],imag_missiels[0],1);
							for(j=0;j<4;j++)
							{
								if(current_Key[j] == tem_key) key = current_Key[j];
							}
							if(mx > 30)
							{
								putimage(mx,my,imag_f16[ch],XOR_PUT); mx-=16+ f16disp;
								putimage(mx,my,imag_f16[ch],1);
							}
							break;
						}
					}
				}
				if(key == 1){getUsername(midx,midy,score);callGameOver();}
			}
			//move the bullet of f16.
			for(i=0;i<30&&key!=0;i++)
			{
				if(bulx[i] != 0 && buly[i] != 0)
				{
					putimage(bulx[i],buly[i],imag_missiels[0],1);
					bulx[i] += 6 + f16disp;
					putimage(bulx[i],buly[i],imag_missiels[0],1);
					//Reintialize the bullet value of f16.
					if(bulx[i] > 620)
					{
						putimage(bulx[i],buly[i],imag_missiels[0],1);
						bulx[i] = 0;buly[i] = 0;
					}
				}
			}
			/* Incoming chopers  movement */
			//set the random values of chopper to initiate the attack.
			for(j=0;j<MAX_OPPONENT + chopdisp;j++)
			{
				k = random(MAX_OPPONENT + chopdisp) ;
				if(chop_flag[k] == 0 && hit_c[k] == 0)
				{
					chop_flag[k] = 1;
					chopx[k] = 604;
					while(1)
					{
						chopy[k] = random(424);
							if(chopy[k] > 32) break;
					}
					chop_type[k] = random(10);
					while(1)
					{
						disX_chop[k] = random(4);
						if(disX_chop[k] > 2) break;
					}
					hit_c[k] = 0;
				}
			}
			//move the chopper.
			for(i=0;i<MAX_OPPONENT+ chopdisp;i++)
			{
				if(chop_flag[i] == 1 && hit_c[i] == 0)
				{
					putimage(chopx[i],chopy[i],imag_choper[chop_type[i]],1);
					chopx[i]-= disX_chop[i]+ chopdisp;
					putimage(chopx[i],chopy[i],imag_choper[chop_type[i]],1);
					if(chopx[i] < 10)
					{
						putimage(chopx[i],chopy[i],imag_choper[chop_type[i]],1);
						chop_flag[i] = 0;
					}
				}
			}
			//set the bullet of chopper.
			for(i=0;i<MAX_OPPONENT+ chopdisp;i++)
			{
				for(k=0;k<random(BULLETS)+ chopdisp;k++)
				{
					if(bulcx[i][k] == 0 && bulcy[i][k] == 0 &&	chop_flag[i] == 1 && chopx[i] < 554 && hit_c[i] != 1)
					{
						bulcx[i][k] = chopx[i];
						bulcy[i][k] = chopy[i]+11;
						putimage(bulcx[i][k],bulcy[i][k],imag_missiels[1],1);
						break;
					}
				}
			}
			//move the bullet of chopper.
			for(i=0;i<MAX_OPPONENT+ chopdisp;i++)
			{
				for(k=0;k<BULLETS+ chopdisp;k++)
				{
					if(bulcx[i][k] != 0 && bulcy[i][k] != 0)
					{
						putimage(bulcx[i][k],bulcy[i][k],imag_missiels[1],1);
						bulcx[i][k] -= 10 + chopdisp;
						putimage(bulcx[i][k],bulcy[i][k],imag_missiels[1],1);
						if (bulcx[i][k] < 12)
						{
							putimage(bulcx[i][k],bulcy[i][k],imag_missiels[1],1);
							bulcx[i][k] = bulcy[i][k] = 0;
						}
					}
				}
			}
			//Detect when bullet of f16 hit the choper
			for(i=0;i<30&&key!=0;i++)
			{
				if(bulx[i] != 0 && buly[i] != 0)
				{
					for(j=0;j<MAX_OPPONENT+chopdisp;j++)
					{
						if(chop_flag[j] == 1)
						{
							if( bulx[i] >= chopx[j] && bulx[i]+10 <= chopx[j]+80 && buly[i] >= chopy[j] && buly[i]+5 <= chopy[j]+28 && hit_c[j]  == 0)
							{
								if(blast_times_c[j] == 0)
								{
									blast_times_c[j] = 6;
									blast_cx[j] = chopx[j]+20;
									blast_cy[j] = chopy[j]+5;
									putimage(blast_cx[j],blast_cy[j],imag_blast[3],1);
									putimage(bulx[i],buly[i],imag_missiels[0],1);
									putimage(chopx[j],chopy[j],imag_choper[chop_type[j]],1);
									bulx[i] = buly[i] = 0;
									chopx[j] = chopy[j] = chop_type[j] = 0;
									chop_flag[j] = 0;
									hit_c[j]  = 1;
									score+=5;
									l=score;m=0;
									while(l>0)
									{
									   k = l % 10;
									   putimage(580-m,5,imag_Numbers[10],0);
									   l /= 10;m += 14;
									}
									display_Score(imag_Numbers,score);
									if(score >= up)
									{
										if(level <= 4) 
										{ 
											display_Life(imag_Numbers[level],imag_Numbers[life]);
											level += 1; up += 100;
											chopdisp += 1;
											f16disp += 1;
											display_Life(imag_Numbers[level],imag_Numbers[life]);
											
										}
									}
								}
								break;
							}
						}
					}
				}	  
			}
			//Show the blast scene of choper hit by bullet of f16
			for(l = 0; l<MAX_OPPONENT+chopdisp;l++)
			{
				if(hit_c[l]  == 1)
				{
					if(blast_times_c[l] > 0 && !blast_times_f16[l])
					{
						putimage(blast_cx[l],blast_cy[l],imag_blast[3],1);
						blast_cx[l]-=2;
						putimage(blast_cx[l],blast_cy[l],imag_blast[3],1);
						blast_times_c[l]--;
						if(blast_times_c[l] == 1)
						{
							putimage(blast_cx[l],blast_cy[l],imag_blast[3],1);
							blast_cx[l] = blast_cy[l] = blast_times_c[l] = 0;
							hit_c[l]  = 0;
							blast_times_c[l] = 0;
							break;
						}
					}
				}
			}
			//Detect the crash of the f16 and chopper.
			for(j=0;j<MAX_OPPONENT+chopdisp;j++)
			{
				if(chop_flag[j] == 1 && f16_flag == 1)
				{
					if( mx <= chopx[j] && mx+60 >= chopx[j] && my-10 <= chopy[j] && my+50 >= chopy[j] && hit_c[j] == 0 && hit_f16[j]  == 0)
					{
						if(blast_times_f16[j] == 0 && blast_times_c[j] == 0)
						{
							blast_times_c[j] = 6;
							blast_times_f16[j] = 6;
							blast_cx[j] = chopx[j]+20;
							blast_cy[j] = chopy[j]+5;
							blast_f16x[j] = mx+20;
							blast_f16y[j] = my+5;
							putimage(blast_cx[j],blast_cy[j],imag_blast[3],1);
							putimage(blast_f16x[j],blast_f16y[j],imag_blast[3],1);
							putimage(mx,my,imag_f16[ch],1);
							putimage(chopx[j],chopy[j],imag_choper[chop_type[j]],1);
							chopx[j] = chopy[j] = chop_type[j] = 0;
							mx=16;
							my=250;
							putimage(mx,my,imag_f16[ch],1);
							f16_flag = 0;
							chop_flag[j] = 0;
							hit_c[j]  = 1;
							hit_f16[j]  = 1;
							display_Life(imag_Numbers[level],imag_Numbers[life]);
							life -= 1;
							health = 100;
							loss = 0;
							display_Health(health);
							if(life == 0)
							{
								getUsername(midx,midy,score);
								callGameOver();
							}
							display_Life(imag_Numbers[level],imag_Numbers[life]);
						}
						break;
					}
				}
			}
			//Show the blast scene of f16 and choper crash.
			for(l = 0; l<MAX_OPPONENT+chopdisp;l++)
			{
				if(hit_c[l]  == 1 && chop_flag[l] == 0 && hit_f16[l]  == 1 && f16_flag == 0)
				{
					if(blast_times_c[l] > 0 && blast_times_f16[l] > 0)
					{
						putimage(blast_cx[l],blast_cy[l],imag_blast[3],1);
						blast_cx[l]-=2;
						putimage(blast_cx[l],blast_cy[l],imag_blast[3],1);
						putimage(blast_f16x[l],blast_f16y[l],imag_blast[3],1);
						blast_f16x[l]-=2;
						putimage(blast_f16x[l],blast_f16y[l],imag_blast[3],1);
						if(blast_times_c[l] == 1 && blast_times_f16[l] == 1)
						{
							f16_flag = 1;
							putimage(blast_cx[l],blast_cy[l],imag_blast[3],1);
							putimage(blast_f16x[l],blast_f16y[l],imag_blast[3],1);
							blast_cx[l] = blast_cy[l] = blast_times_c[l] = 0;
							blast_f16x[l] = blast_f16y[l] = 0;
							hit_c[l]  = 0;
							hit_f16[l]  = 0;
							blast_times_c[l] = 0;
							blast_times_f16[l] = 0;
							break;
						}
						blast_times_c[l] -= 1;
						blast_times_f16[l] -= 1;
						//printf("%d,%d\n",blast_times_c[l],blast_times_f16[l]);
					}
				}
			}
			//Detect the hit of chopper bullet and f16.
			for(j=0;j<MAX_OPPONENT+chopdisp;j++)
			{
				if(chop_flag[j] == 1 && f16_flag == 1)
				{
					for(k=0;k<BULLETS+ chopdisp;k++)
					{
						if(bulcx[j][k] != 0 && bulcy[j][k] != 0)
						{
							if(mx <= bulcx[j][k] && mx+60 >= bulcx[j][k] && my <= bulcy[j][k] && my+40 >= bulcy[j][k] && f16hitBybulc[j] == 0 && hit_f161[0] == 0)
							{
								putimage(bulcx[j][k],bulcy[j][k],imag_missiels[1],1);
								putimage(bulcx[j][k],bulcy[j][k],imag_blast[1],1);
								putimage(bulcx[j][k],bulcy[j][k],imag_blast[1],1);
								putimage(bulcx[j][k],bulcy[j][k],imag_blast[1],1);
								putimage(bulcx[j][k],bulcy[j][k],imag_blast[1],1);
								loss++;
								display_Reduce_Health(health,loss);
								health -= 1;
								if(health == 0)
								{
									if(blast_times_f161[j] == 0)
									{	
										blast_times_f161[j] = 6;
										f16hitBybulc[j] = 1;
										f16_flag = 0;
										hit_f161[0] = 1;
										blast_f16x1[j] = mx+20;
										blast_f16y1[j] = my+5;
										putimage(blast_f16x1[j],blast_f16y1[j],imag_blast[3],1);
										putimage(mx,my,imag_f16[ch],1);
										mx=16;
										my=250;
										putimage(mx,my,imag_f16[ch],1);
										display_Life(imag_Numbers[level],imag_Numbers[life]);
										life -= 1;
										health = 100;
										loss = 0;
										display_Health(health);
										if(life == 0)
										{
											getUsername(midx,midy,score);
											callGameOver();
										}
										display_Life(imag_Numbers[level],imag_Numbers[life]);									
									}
								}
								putimage(bulcx[j][k],bulcy[j][k],imag_blast[1],1);
								putimage(bulcx[j][k],bulcy[j][k],imag_blast[1],1);
								putimage(bulcx[j][k],bulcy[j][k],imag_blast[1],1);
								putimage(bulcx[j][k],bulcy[j][k],imag_blast[1],1);
								bulcx[j][k] = bulcy[j][k] = 0;
							}
						}
					}
				}
			}
			//Reduce the health of f16 and choper crash.
			for(l = 0; l<MAX_OPPONENT+chopdisp;l++)
			{
				if(f16_flag == 0 && f16hitBybulc[l] == 1)
				{
					if(blast_times_f161[l] > 0)
					{
						putimage(blast_f16x1[l],blast_f16y1[l],imag_blast[3],1);
						blast_f16x1[l]-=2;
						putimage(blast_f16x1[l],blast_f16y1[l],imag_blast[3],1);
						if(blast_times_f161[l] == 1)
						{
							f16_flag = 1;
							hit_f161[l] = 0;
							putimage(blast_f16x1[l],blast_f16y1[l],imag_blast[3],1);
							blast_f16x1[l] = blast_f16y1[l] = 0;
							f16hitBybulc[l]  = 0;
							blast_times_f161[l] = 0;
							break;
						}
						blast_times_f161[l] -= 1;
					}
				}				
			}
		}//end of while loop.
	}// end of main function

/*-------------------------------------------------------------------------*/

	void Background(int MaxX,int MaxY,int maxcolor)
	{
		int i;
		rectangle(0,0,MaxX,10);
		for(i=0;i<MaxX;i+=5)circle(1+i,5,5);

		rectangle(0,MaxY-10,MaxX,MaxY);
		for(i=0;i<MaxX;i+=5)circle(5+i,(MaxY-5),5);

		rectangle(0,0,10,MaxY);
		rectangle(MaxX-10,0,MaxX,MaxY);
		for ( i=0 ; i<500; ++i )
			putpixel(random(MaxX), random(MaxY), random( maxcolor-1 )+1);
	}

/*---------------------------------DRAW------------------------------------*/

	//12 F16
	void *F16(int midx,int midy,int rang)
	{
	    int stangle = 0,endangle = 130,xradius = 30,yradius = 5,i;
		setcolor(rang);
		//rectangle(midx-29, midy-16,midx+35, midy+16);
		ellipse(midx, midy, stangle, endangle, xradius, yradius);
		for(i=midx+9;i>midx-22;i-=2)
			line(i,midy+2,i,midy+2);
		for(i=midx+32;i>midx-22;i-=2)
			line(i,midy,i,midy);
		ellipse(midx+13, midy, stangle, 360, xradius-25, yradius-3);
		for(i=midx+9;i>midx-22;i-=2)
			line(i,midy-2,i,midy-2);
		ellipse(midx, midy, 220,stangle, xradius, yradius);
		ellipse(midx-22,midy, 0,360,1,3);
		setcolor(4);
		line(midx-22,midy,midx-28,midy-6);
		line(midx-22,midy,midx-28,midy-3);
		line(midx-22,midy,midx-28,midy);
		line(midx-22,midy,midx-28,midy+3);
		line(midx-22,midy,midx-28,midy+6);
		setcolor(rang);
		for(i=0;i<20;i++)
			line(midx+(15-i),midy-5,midx-(20-i),midy-15);
		for(i=0;i<20;i++)
			line(midx+(15-i),midy+5,midx-(20-i),midy+15);
	    return(Allocate(midx-29, midy-16,midx+35, midy+16));
	}

/*---------------------------------DRAW------------------------------------*/

	//13 chopers
	void *EX_Choper(int midx,int midy,int rang)
	{
	    int stangle = 0,endangle = 360,xradius = 20,yradius = 6,i;
		setcolor(rang);
		//rectangle(midx-25, midy-16,midx+55, midy+12);
		ellipse(midx, midy, stangle, endangle, xradius, yradius);
		line(midx,midy-yradius,midx + (xradius+5),midy-(yradius+10));
		circle(midx,midy-8,1);
		line(midx,midy-yradius,midx - (xradius+5),midy-(yradius+10));
		for(i=28;i>0;i-=2)   
			circle(midx+19-i,midy-3,1);
		for(i=30;i>0;i-=2)   
			circle(midx+18-i,midy-1,1);
		circle(midx+19,midy,1);
		for(i=32;i>0;i-=2)   
			circle(midx+18-i,midy+2,1);
		for(i=34;i>0;i-=2)   circle(midx+18-i,midy+4,1);
			circle(midx+5,midy+9,1);
		circle(midx-5,midy+9,1);
		setcolor(15);
		for(i=0;i<6;i+=2)
			line(midx-20+i,midy-i,midx-15+i,midy-i);
		for(i=1;i<4;i++)    
			circle(midx+xradius+31,midy-5,i);
		for(i=0;i<3;i++)
			line(midx+(18+i),midy-2+i,midx + xradius+27-i,midy-3);
		return(Allocate(midx-25, midy-16,midx+55, midy+12));
	}

/*-----------------------------DRAW----------------------------------------*/

	// two bullets
	void *Bullets(int rang,int side)
	{
		int i;
		clrscr();
		cleardevice();
		for ( i=0 ; i<9500; ++i )
			putpixel(random(getmaxx()), random(getmaxy()), 15);
		if(side == 0)//F16
		{
			rectangle(110,6,130,12);
			return(Allocate(119,3,127,11));
		}
		if(side == 1)
		{
			rectangle(110,6,130,12);
			return(Allocate(119,3,127,11));
		}
		setcolor(rang);
		return NULL;
	}

/*-------------------------------------------------------------------------*/

	// two missiels
	void *Missiles(int midx,int midy,int rang,int side)
	{
	    int stangle = 0,endangle = 130,xradius = 7,yradius = 3;
		cleardevice();
		setcolor(rang);
		if(side == 0)//F16
		{
			//rectangle(midx-8, midy-5,midx+8, midy+5);
			ellipse(midx, midy, stangle, endangle, xradius, yradius);
			ellipse(midx, midy, 220,stangle, xradius, yradius);
			ellipse(midx-7,midy, 0,360,1,3);
			return(Allocate(midx-8, midy-5,midx+8, midy+5));
		}
		if(side == 1)
		{
			//rectangle(midx-3, midy-5,midx+3, midy+5);
			ellipse(midx,midy, 0,360,1,2);
			return(Allocate(midx-3, midy-5,midx+3, midy+5));
		}
		cleardevice();
		return NULL;
	}

/*-------------------------------------------------------------------------*/

	void *Blast(int midx,int midy,int rang)
	{
		int i;
		//rectangle(midx-(rang+10),midy-(rang+10), midx+(rang+10),midy+(rang+10));
		for(i=0;i<10+rang;i++)
		{
			setcolor(i);
			circle(midx,midy,i);
		}
		return(Allocate(midx-(rang+10),midy-(rang+10), midx+(rang+10),midy+(rang+10)));
	}

/*-------------------------------------------------------------------------*/

	void *Numbers(int midx,int midy,int rang,int num)
	{
		char *Number = "0123456789";
		setcolor(rang);
		//rectangle(midx-3,midy+2,midx+11,midy+24);
		settextstyle(3,0,2);
		outtextxy(midx,midy,Number+num);
		if(num == 10)
		{
			return(Allocate(midx-3,midy+2,midx+11,midy+24));
		}
		else
		{
			return(Allocate(midx-3,midy+2,midx+11,midy+24));
		}
	}

/*-------------------------------------------------------------------------*/

	void *Allocate(int X1,int Y1,int X2,int Y2)
	{
		int size; void *img;
		size = imagesize(X1,Y1,X2,Y2);
		if ((img = malloc(size)) != NULL)
		{
			getimage(X1,Y1,X2,Y2,img);
			return img;
		}
		else
			return img;
	}

/*-------------------------------------------------------------------------*/

	int get_scancode( )
	{
		union REGS inregs, outregs;
		inregs.h.ah = 0 ;
		int86(22, &inregs, &outregs);
		return (outregs.h.ah ) ;
	}

/*-------------------------------------------------------------------------*/

	void ERROR_ALLOCATE(int locate)
	{
		cleardevice();
		closegraph();
		printf("\n\tERROR : Failed to Load necessary elements."
				"\n\tERROR : Not sufficient memory."
				"\n\tModule no. : %d."
				"\n\tPress any to exit.",locate);
		getch();
		exit(1);
	}

/*-------------------------------------------------------------------------*/

	int Selectoion_screen(int MaxY, void *f16[5])
	{
		int i,j=1,ch;
		settextstyle(1,0,1);
		for(i=50;i<500,j<6;i+=100,j++)
		{
			rectangle(i,100,100+i,200);
			putimage(i,130,f16[j-1],1);
		}
		outtextxy(60,180,"1");
		outtextxy(160,180,"2");
		outtextxy(260,180,"3");
		outtextxy(360,180,"4");
		outtextxy(460,180,"5");
		outtextxy(200,MaxY/2,"Select F16");
		gotoxy(28,18);
		while(1)
		{
			ch = get_scancode( );
			switch(ch)
			{
				case 2: cleardevice();return 0;
				case 3:	cleardevice();return 1;
				case 4: cleardevice();return 2;
				case 5: cleardevice();return 3;
				case 6: cleardevice();return 4;
			}
		}
	}

/*-------------------------------------------------------------------------*/

	void display_Score(void *img[11],int num)
	{
		int i=num,j=0,k;
		while(i>0)
		{
			k = i % 10;
			putimage(580-j,5,img[k],1);
			i /= 10;j += 14;
		}
	}

/*-------------------------------------------------------------------------*/

	void display_Life(void *img1,void *img2)
	{
		int i;
		setcolor(6);
		outtextxy(200,15,"Level:-");
		putimage(258,15,img1,1);
		outtextxy(320,15,"Lifes:-");
		putimage(380,15,img2,1);
		outtextxy(440,15,"Score:-");
	}

/*-------------------------------------------------------------------------*/
	void display_Health(int health)
	{
		int x = 25,y = 10,i;
		setcolor(3);
		rectangle(x,y,x+health,y+15);
		for(i = 1;i<100;i++)
			line(x+i,y,x+i,y+15);
	}
/*-------------------------------------------------------------------------*/
	void display_Reduce_Health(int health,int loss)
	{
		int x = 25,y = 10,i;
		setcolor(4);
		rectangle(x,y,x+loss,y+15);
		for(i = health;i<(health-loss);i--)
			line(x+i,y,x+i,y+15);

	}
/*-------------------------------------------------------------------------*/
	void getUsername(int midx,int midy,int score)
	{
		int i,key,rem;
		cleardevice();
		setcolor(7);
		rectangle(midx-300,midy-210,midx+300,midy+210);
		floodfill(midx-295,midy-47,7);
		rectangle(midx-290,midy-200,midx+290,midy+200);
		setcolor(8);
		for(i=midx-290;i<=midx+290;i++)
			line(i,midy-200,i,midy+200);
		setcolor(15);
		settextstyle(31,0,3);
		outtextxy(midx-80,midy-150,"Game Over!!!");
		settextstyle(3,0,1);
		outtextxy(midx-200,midy-125,"-:Developers:-");
		outtextxy(midx-180,midy-100,"1. Soharab.");
		outtextxy(midx-180,midy-75,"2. Nasir.");
		outtextxy(midx-180,midy-50,"3. Chims.");
		outtextxy(midx-280,midy-10,"Your score is :- ");
		gotoxy(wherex()-1,wherey()-2);
		printf("%d",score);
		outtextxy(midx-200,midy+100,"Press escape key to exit.");
		while(1)
		{
			if(kbhit()) key = get_scancode();
			if(key == 1) {break;}
		}
	}
/*-------------------------------------------------------------------------*/								
	void callGameOver()
	{
		nosound();
		closegraph(); 
		exit(0);
	}
/*-------------------------------------------------------------------------*/