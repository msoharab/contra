/*-------------------------------------------------------------------------*/
	/*--------------------------------------------------*/
	/*--------------- CONTRA ---------------------------*/
	/*------ An air strike game.------------------------*/
	/*------ Developers:-  SOHARAB (M.C.A)--------------*/
	/*------ Colllege:-    TOCE-------------------------*/
	/*------ Place:-       Bangalore--------------------*/
	/*--------------------------------------------------*/
/*-------------------------------------------------------------------------*/

	#include <graphics.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>
	#include <dos.h>
	
	#define MAX_OPPONENT 3
	#define BULLETS      3

/*----------------Prototype declaration------------------------------------*/

	void *F16(int midx,int midy,int rang);
	void *EX_Choper(int midx,int midy,int rang);
	void *Fighter_one(int midx,int midy,int rang);
	void *Fighter_two(int midx,int midy,int rang);
	void *B737(int midx,int midy,int rang);
	void *Blast(int midx,int midy,int rang);
	void *Bullets(int rang,int side);
	void *Numbers(int midx,int midy,int rang,int num);
	void *Lifes(int midx,int midy);
	void *Missiles(int midx,int midy,int rang,int side);
	void *Allocate(int X1,int Y1,int X2,int Y2);
	int  Selectoion_screen(int MaxY,void *f16[5]);
	void Background(int MaxX,int MaxY,int rang);
	void ERROR_ALLOCATE(int locate);
	void display_Score(void *img[11],int num);
	void display_Life(void *img,int num);

/*-------------------------------------------------------------------------*/
	 void main(void)
	 {
	   /* request auto detection */
	   int  gdriver = DETECT, gmode,errorcode,midx,midy, maxcolor,MaxX,MaxY,i,j,k,l,key,mx=1,my=250,ch,current_Key[4] = {72,80,75,77},tem_key=0,bulx[30],buly[30];

	   /*
	    int  chopx=604,chopy=104,chop_type = 0,
		 bulcx[3],bulcy[3],target_Y1[3];
	   */
	   int chopx[MAX_OPPONENT], chopy[MAX_OPPONENT],chop_type[MAX_OPPONENT],disX_chop[MAX_OPPONENT],bulcx[MAX_OPPONENT][3],bulcy[MAX_OPPONENT][3],chop_flag[MAX_OPPONENT],chop_hit_Flag[MAX_OPPONENT];

	   int  ft1x=604,ft1y=300,ft1_type = 0,bulf1_1x[3],bulf1_1y[3],bulf1_2x[3],bulf1_2y[3];
	   int  ft2x=654,ft2y=150,ft2_type = 0,bulf2x[3],bulf2y[3];

	   int  B737x=704,B737y=150,B737_type = 0,bulB737_1x[5],bulB737_1y[5],bulB737_2x[5],bulB737_2y[5],bulB737_3x[5],bulB737_3y[5];
	   int  blastx[MAX_OPPONENT],blasty[MAX_OPPONENT],hit[MAX_OPPONENT],blast_times[MAX_OPPONENT];
	   int  score = 0,flag_score[10];
	   int  life = 5,level = 1;
	   /*
	      12 f16
	      13 choper, fighter1, fighter2
	      2 bullets
	      2 missiels
	      total = 55 images
	      up arrowkey 72
	      downarrow key 80
	      leftarrow key 75
	      rightarrow key 77
	   */

	   void *imag_f16[6];
	   void *imag_choper[10];
	   void *imag_fighter1[10];
	   void *imag_fighter2[10];
	   void *imag_bullets[2];
	   void *imag_missiels[2];
	   void *imag_B737[10];
	   void *imag_blast[4];
	   void *imag_Numbers[11];
	   void *imag_Lifes;

	   for(i=0;i<30;i++)
	    bulx[i] = buly[i] = 0;
	   for(i=0;i<3;i++)
	    bulf1_1x[i] = bulf1_1y[i] = bulf1_2x[i] = bulf1_2y[i] = bulf2x[i] = bulf2y[i] = 0;
	   for(i=0;i<MAX_OPPONENT;i++)
	    blastx[i] = blasty[i] = hit[i] = blast_times[i] = 0;
	   for(i=0;i<5;i++)
	    bulB737_1x[i] = bulB737_1y[i] = bulB737_2x[i] = bulB737_2y[i] = bulB737_3x[i] = bulB737_3y[i] = 0;
	   for(i=0;i<MAX_OPPONENT;i++)
	   {
	    chopx[i] = chopy[i] = chop_type[i] = disX_chop[i] = chop_flag[i] = chop_hit_Flag[i]  = 0;
	    for(j=0;j<BULLETS;j++)
	    {
	     bulcx[i][j] = bulcy[i][j] = 0;
	    }
	    while(1)
	    {
	     disX_chop[i] = random(16);
	     if(disX_chop[i] > 3) break;
	    }
	   }
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
	    if((imag_fighter1[i] = Fighter_one(midx,midy,i+2)) == NULL)
	       ERROR_ALLOCATE(2);
	    cleardevice();
	   }
	   for(i=0;i<10;i++)
	   {
	    if((imag_fighter2[i] = Fighter_two(midx,midy,i+2)) == NULL)
	      ERROR_ALLOCATE(3);
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
	   for(i=0;i<10;i++)
	   {
	    if((imag_B737[i] = B737(midx,midy,i+2)) == NULL)
	      ERROR_ALLOCATE(7);
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
	   if((imag_Lifes = Lifes(midx,midy)) == NULL)
	   {
	     ERROR_ALLOCATE(10);
	   }
	   cleardevice();

/*-------------------------------------------------------------------------*/

	    /* Welcome screen */
	    /* Selection screen */
	   Background(MaxX,MaxY,maxcolor);
	   if((ch=Selectoion_screen(MaxY,imag_f16)) > 0) ch = ch - 1;
	   else
	   {
	    closegraph();
	    exit(1);
	   }
	   cleardevice();
	   for(i=0;i<10;i++) flag_score[i] = 0;
	   /* Setting background */
	   for ( i=0 ; i<500; ++i )
	    putpixel(random(MaxX), random(MaxY), random( maxcolor-1 )+1);
	   putimage(mx,my,imag_f16[ch],1);
	   display_Life(imag_Numbers[life],life);

/*-------------------------------------------------------------------------*/
	  switch(level)
	  {
	   case 1:
      while(1) // start of while loop of level 1.
      {
       if(kbhit()) key = get_scancode();
       if(key == 72)//up
       {
        if(my>10)
        {
         putimage(mx,my,imag_f16[ch],XOR_PUT); my-=4;
         putimage(mx,my,imag_f16[ch],XOR_PUT); key = 72;
        }
        tem_key = key;
       }
       if(key == 80)//down
       {
        if(my < 420)
        {
         putimage(mx,my,imag_f16[ch],XOR_PUT); my+=4;
         putimage(mx,my,imag_f16[ch],1); key = 80;
        }
        tem_key = key;
       }
       if(key == 75)//left
       {
        if(mx > 1)
        {
         putimage(mx,my,imag_f16[ch],XOR_PUT); mx-=4;
         putimage(mx,my,imag_f16[ch],1); key = 75;
        }
        tem_key = key;
       }
       if(key == 77)//right
       {
        if(mx < 540)
        {
         putimage(mx,my,imag_f16[ch],XOR_PUT); mx+=4;
         putimage(mx,my,imag_f16[ch],1); key = 77;
        }
        tem_key = key;
       }
       if(key == 57) // Space // launched
       {
        for(i=0;i<30;i++)
        {
         if(bulx[i] == 0 && buly[i] == 0)
         {
          bulx[i] = mx+56; buly[i] = my+11;
          putimage(bulx[i],buly[i],imag_missiels[0],1);
          for(j=0;j<4;j++)
           if(current_Key[j] == tem_key) key = current_Key[j];
          break;
         }
        }
       }
       //move the bullet of f16
       for(i=0;i<30&&key!=0;i++)
       {
        if(bulx[i] != 0 && buly[i] != 0)
        {
         putimage(bulx[i],buly[i],imag_missiels[0],1);
         bulx[i] += 16;
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
       for(i=0;i<MAX_OPPONENT;i++)
       {
        k = random(3);
        if(chop_flag[k] == 0)
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
          disX_chop[k] = random(6);
          if(disX_chop[k] > 2) break;
         }
         chop_hit_Flag[k] = 0;
        }
       }
       //move the chopper.
       for(i=0;i<MAX_OPPONENT;i++)
       {
        if(chop_flag[i] == 1)
        {
         putimage(chopx[i],chopy[i],imag_choper[chop_type[i]],1);
         chopx[i]-= disX_chop[i];
         putimage(chopx[i],chopy[i],imag_choper[chop_type[i]],1);
         if(chopx[i] < 10)
         {
          putimage(chopx[i],chopy[i],imag_choper[chop_type[i]],1);
          chop_flag[i] = 0;
         }
        }
       }
       //set the bullet of chopper.
       for(i=0;i<MAX_OPPONENT;i++)
       {
        for(k=0;k<random(BULLETS);k++)
        {
         if(bulcx[i][k] == 0 &&
            bulcy[i][k] == 0 &&
            chop_flag[i] == 1 &&
            chopx[i] < 554)
         {
            bulcx[i][k] = chopx[i];bulcy[i][k] = chopy[i]+11;
            putimage(bulcx[i][k],bulcy[i][k],imag_missiels[1],1);
            break;
         }
        }
       }
       //move the bullet of chopper.
       for(i=0;i<MAX_OPPONENT;i++)
       {
        for(k=0;k<BULLETS;k++)
        {
         if(bulcx[i][k] != 0 && bulcy[i][k] != 0)
         {
          putimage(bulcx[i][k],bulcy[i][k],imag_missiels[1],1);
          bulcx[i][k] -= 16;
          putimage(bulcx[i][k],bulcy[i][k],imag_missiels[1],1);
          if (bulcx[i][k] < 12)
          {
           putimage(bulcx[i][k],bulcy[i][k],imag_missiels[1],1);
           bulcx[i][k] = bulcy[i][k] = 0;
          }
         }
        }
       }
       //Detect weather the bullet of f16 hit the choppper
       for(i=0;i<30&&key!=0;i++)
       {
        if(bulx[i] != 0 && buly[i] != 0)
        {
         for(j=0;j<MAX_OPPONENT;j++)
         {
          if(chop_flag[j] == 1)
          {
           if(bulx[i] >= chopx[j] && bulx[i] <= chopx[j]+80 && buly[i] >= chopy[j] && buly[i] <= chopy[j]+28)
           {
            putimage(bulx[i],buly[i],imag_missiels[0],1);
            bulx[i] = 0;buly[i] = 0;
            if(chop_hit_Flag[j] == 0)
            {
             putimage(chopx[j],chopy[j],imag_choper[chop_type[j]],1);
             hit[j]    = 1;
             blastx[j] = chopx[j]+40;
             blasty[j] = chopy[j]+14;
             chop_hit_Flag[j] = 1;
             chop_flag[j] = 0;
             blast_times[j] = 3;
             score+=5;
            }
           }
          }
         }
        }  
       }
       //Show the blast scene of choper
       for(i=0;i<MAX_OPPONENT;i++)
       {
        if(blast_times[i] > 0 &&  hit[i] == 1)
        {
         putimage(blastx[i],blasty[i],imag_blast[0],1);
         putimage(blastx[i],blasty[i],imag_blast[0],1);
         putimage(blastx[i],blasty[i],imag_blast[1],1);
         putimage(blastx[i],blasty[i],imag_blast[1],1);
         putimage(blastx[i],blasty[i],imag_blast[2],1);
         putimage(blastx[i],blasty[i],imag_blast[2],1);
         putimage(blastx[i],blasty[i],imag_blast[3],1);
         putimage(blastx[i],blasty[i],imag_blast[3],1);
         if(blast_times[l] == 1)
         {
          blastx[i] = 0;
          blasty[i] = 0;
          hit[i]    = 0;
          chop_hit_Flag[i] = 0;
         }
         blast_times[i]--;
         break;
        } 
       }
       //hide the previous score
       i=score;j=0;
       while(i>0)
       {
         k = i % 10;
         putimage(580-j,5,imag_Numbers[10],0);
         i /= 10;j += 14;
       }
       display_Score(imag_Numbers,score);
       if(key == 1){ nosound();closegraph(); exit(0);}
      }//end of while loop of level 1.
		  break;
	   case 2:
      while(1)
      {
      }
		 break;
	   case 3:
      while(1)
      {
      }
		 break;
	   case 4:
      while(1)
      {
      }
		 break;
	   case 5:
      while(1)
      {
      }
		 break;
	   case 6:
      while(1)
      {
      }
		 break;
	   case 7:
      while(1)
      {
      }
		 break;
	   case 8:
      while(1)
      {
      }
		 break;
	   case 9:
      while(1)
      {
      }
		 break;
	   case 10:
      while(1)
      {
      }
		 break;
	  }
	  /*
	   while(1)
	   {
	     {//screen animation
	      for(i=0;i<10;i++)
	      {
	       if(flag_aniX[i] == 0)
		 flag_aniX[i] = random(10);
		 while(1)
		 {
		  disX[i] = random(50);
		  if(disX[i] > 30) break;
		 }
	       }
	       for(i=0;i<10;i++)
	       {
		if (flag_aniX[i] > 0 && disX[i] != 0)
		{
		 putimage(aniX[i],25,imag_bullets[1],1);
		 putimage(aniX[i],458,imag_bullets[1],1);
		}
	       }
	     }//end of screen animation.

	     if(kbhit()) key = get_scancode();
	     if(key == 72)//up
	     {
	       if(my>10)
	       {
		putimage(mx,my,imag_f16[ch],XOR_PUT); my-=8;
		putimage(mx,my,imag_f16[ch],XOR_PUT); key = 72;
	       }
	       tem_key = key;
	     }
	     if(key == 80)//down
	     {
	       if(my < 420)
	       {
		putimage(mx,my,imag_f16[ch],XOR_PUT); my+=8;
		putimage(mx,my,imag_f16[ch],1); key = 80;
	       }
	       tem_key = key;
	     }
	     if(key == 75)//left
	     {
	       if(mx > 1)
	       {
		putimage(mx,my,imag_f16[ch],XOR_PUT); mx-=8;
		putimage(mx,my,imag_f16[ch],1); key = 75;
	       }
	       tem_key = key;
	     }
	     if(key == 77)//right
	     {
	       if(mx < 540)
	       {
		putimage(mx,my,imag_f16[ch],XOR_PUT); mx+=8;
		putimage(mx,my,imag_f16[ch],1); key = 77;
	       }
	       tem_key = key;
	     }

	     if(key == 57) // Space // launched
	     {
	      for(i=0;i<15;i++)
	      {
	       if(bulx[i] == 0 && buly[i] == 0)
	       {
		bulx[i] = mx+56; buly[i] = my+11;
		putimage(bulx[i],buly[i],imag_missiels[0],1);
		for(j=0;j<4;j++)
		 if(current_Key[j] == tem_key)
		  key = current_Key[j];
		break;
	       }
	      }
	     }

/*-------------------------------------------------------------------------*/
	     /*
	     for(i=0;i<15&&key!=0;i++)
	     {
	      if(bulx[i] != 0 && buly[i] != 0)
	      {
	       putimage(bulx[i],buly[i],imag_missiels[0],1);
	       bulx[i] += 16;
	       putimage(bulx[i],buly[i],imag_missiels[0],1);

/*-------------------------------------------------------------------------*/
	       /*
	       //choper blasted
	       for(k=0;k<100;k++)
	       {
	       if(bulx[i] >= chopx &&
		   bulx[i] <= chopx+50 &&
		   buly[i] >= chopy &&
		   buly[i] <= chopy+20)
		 {
		  if(blastx[k] == 0 && blasty[k] == 0)
		  {
		   blastx[k] = bulx[i]-15;
		   blasty[k] = buly[i]-15;
		  }
		  else continue;
		  putimage(bulx[i],buly[i],imag_missiels[0],1);
		  putimage(chopx,chopy,imag_choper[chop_type],1);
		  putimage(chopx,chopy,imag_choper[chop_type],1);
		  putimage(chopx,chopy,imag_choper[chop_type],1);
		  bulx[i] = buly[i] = 0;
		  chop_type = random(10);
		  chopx = 600;
		  while(1)
		  {
		   chopy = random(435);
		   if(chopy > 5) break;
		  }
		  break;
		 }
		}

/*-------------------------------------------------------------------------*/
		/*
	       //fighter1 blasted
	       for(k=0;k<100;k++)
	       {
		if(bulx[i] >= ft1x &&
		   bulx[i] <= ft1x+50 &&
		   buly[i] >= ft1y &&
		   buly[i] <= ft1y+80)
		 {
		  if(blastx[k] == 0 && blasty[k] == 0)
		  {
		   blastx[k] = bulx[i]-15;
		   blasty[k] = buly[i]-35;
		  }
		  else continue;
		  putimage(bulx[i],buly[i],imag_missiels[0],1);
		  putimage(ft1x,ft1y,imag_fighter1[ft1_type],1);
		  putimage(ft1x,ft1y,imag_fighter1[ft1_type],1);
		  putimage(ft1x,ft1y,imag_fighter1[ft1_type],1);
		  bulx[i] = buly[i] = 0;
		  ft1_type = random(10);
		  ft1x = 620;
		  while(1)
		  {
		   ft1y = random(420);
		   if(ft1y > 5) break;
		  }
		  break;
		 }
		}

/*-------------------------------------------------------------------------*/
	       /*
	       //fighter2 blasted
	       for(k=0;k<100;k++)
	       {
		if(bulx[i] >= ft2x &&
		   bulx[i] <= ft2x+50 &&
		   buly[i] >= ft2y &&
		   buly[i] <= ft2y+80)
		 {
		  if(blastx[k] == 0 && blasty[k] == 0)
		  {
		   blastx[k] = bulx[i]-15;
		   blasty[k] = buly[i]-35;
		  }
		  else continue;
		  putimage(bulx[i],buly[i],imag_missiels[0],1);
		  putimage(ft2x,ft2y,imag_fighter2[ft2_type],1);
		  putimage(ft2x,ft2y,imag_fighter2[ft2_type],1);
		  putimage(ft2x,ft2y,imag_fighter2[ft2_type],1);
		  bulx[i] = buly[i] = 0;
		  ft2_type = random(10);
		  ft2x = 650;
		  while(1)
		  {
		   ft2y = random(420);
		   if(ft2y > 5) break;
		  }
		  break;
		 }
		}

/*-------------------------------------------------------------------------*/
	       /*
	       //Bomber  blasted
	       for(k=0;k<100;k++)
	       {
		if(bulx[i] >= B737x &&
		   bulx[i] <= B737x+50 &&
		   buly[i] >= B737y &&
		   buly[i] <= B737y+120)
		 {
		  if(blastx[k] == 0 && blasty[k] == 0)
		  {
		   blastx[k] = bulx[i]-15;
		   blasty[k] = buly[i]-35;
		  }
		  else continue;
		  putimage(bulx[i],buly[i],imag_missiels[0],1);
		  putimage(B737x,B737y,imag_B737[B737_type],1);
		  putimage(B737x,B737y,imag_B737[B737_type],1);
		  putimage(B737x,B737y,imag_B737[B737_type],1);
		  bulx[i] = buly[i] = 0;
		  B737_type = random(10);
		  B737x = 600;
		  while(1)
		  {
		   B737y = random(420);
		   if(B737y > 5) break;
		  }
		  break;
		 }
		}
	       if (bulx[i] > 620)
	       {
		putimage(bulx[i],buly[i],imag_missiels[0],1);
		bulx[i] = 0;buly[i] = 0;
	       }
	      }
	     }

/*-------------------------------------------------------------------------*/
	     /*
	     // show the blast scene
	     for(k=0;k<100;k++)
	     {
	      if(blastx[k] != 0 && blasty[k] != 0)
	      {
		for(i=0;i<4;i++)
		  putimage(blastx[k],blasty[k],imag_blast[i],1);
		for(i=0;i<4;i++)
		  putimage(blastx[k],blasty[k],imag_blast[i],1);
		for(i=0;i<4;i++)
		  putimage(blastx[k],blasty[k],imag_blast[i],1);
		for(i=0;i<4;i++)
		 putimage(blastx[k],blasty[k],imag_blast[i],1);
		putimage(blastx[k],blasty[k],imag_blast[3],1);
		putimage(blastx[k],blasty[k],imag_blast[3],1);
		blastx[k] = blasty[k] = 0;
		//hide the previous score
		i=score;j=0;
		while(i>0)
		{
		 k = i % 10;
		 putimage(580-j,5,imag_Numbers[10],0);
		 i /= 10;j += 14;
		}
		score+=5;
		display_Score(imag_Numbers,score);
		break;
	      }
	     }

/*-------------------------------------------------------------------------*/
	     /*
	     { /* Incoming chopers  movement */
	     /*
	      putimage(chopx,chopy,imag_choper[chop_type],1);
	      chopx -= 3;
	      putimage(chopx,chopy,imag_choper[chop_type],1);
	      if(chopx < 10)
	      {
	       putimage(chopx,chopy,imag_choper[chop_type],1);
	       chopx = 600; chop_type = random(10);
	       while(1)
	       {
		chopy = random(435);
		if(chopy > 5) break;
	       }
	      }
	      for(i=0;i<random(3);i++)
	      {
	       if(bulcx[i] == 0 &&
		   bulcy[i] == 0 &&
		      chopx < 550)
	       {
		bulcx[i] = chopx; bulcy[i] = chopy+11;
		if(target_Y1[i] == 0)
		 target_Y1[i] = my;
		putimage(bulcx[i],bulcy[i],imag_missiels[1],1);
		break;
	       }
	      }
	      for(i=0;i<3;i++)
	      {
	       if(bulcx[i] != 0 && bulcy[i] != 0)
	       {
		//sound(1200+i);
		putimage(bulcx[i],bulcy[i],imag_missiels[1],1);
		bulcx[i] -= 10;
		if(target_Y1[i] < bulcy[i] && target_Y1[i] != 0)
		 bulcy[i] -= 5;
		if(target_Y1[i] > bulcy[i])
		 bulcy[i] += 5;
		putimage(bulcx[i],bulcy[i],imag_missiels[1],1);
		if (bulcx[i] < 12)
		{
		 putimage(bulcx[i],bulcy[i],imag_missiels[1],1);
		 bulcx[i] = bulcy[i] = target_Y1[i] = 0;
		}
	       }
	      }
	     }

/*-------------------------------------------------------------------------*/
	     /*
	     { /* incoming fighter 1  movements  */
	     /*
	      putimage(ft1x,ft1y,imag_fighter1[ft1_type],1);
	      ft1x -= 3;
	      putimage(ft1x,ft1y,imag_fighter1[ft1_type],1);
	      if(ft1x < 0)
	      {
	       putimage(ft1x,ft1y,imag_fighter1[ft1_type],1);
	       ft1x = 600; ft1_type = random(10);
	       while(1)
	       {
		ft1y = random(380);
		if(ft1y > 50 &&  ft1y > chopy+150) break;
		if(ft1y > 50 &&
		   ft1y < chopy-150 &&
		   ft1y != chopy)
		 break;
	       }
	      }
	      for(i=0;i<random(3);i++)
	      {
	       if(bulf1_1x[i] == 0 &&
		   bulf1_1y[i] == 0 &&
		      ft1x < 550)
	       {
		bulf1_1x[i] = ft1x+18; bulf1_1y[i] = ft1y+24;
		bulf1_2x[i] = ft1x+18; bulf1_2y[i] = ft1y+56;
		putimage(bulf1_1x[i],bulf1_1y[i],imag_missiels[1],1);
		putimage(bulf1_2x[i],bulf1_2y[i],imag_missiels[1],1);
		break;
	       }
	      }
	      for(i=0;i<3;i++)
	      {
	       if(bulf1_1x[i] != 0 && bulf1_1y[i] != 0)
	       {
		putimage(bulf1_1x[i],bulf1_1y[i],imag_missiels[1],1);
		putimage(bulf1_2x[i],bulf1_2y[i],imag_missiels[1],1);
		bulf1_1x[i] -= 16; bulf1_2x[i] -= 16;
		if(my < bulf1_1y[i] && mx < bulf1_1x[i]) bulf1_1y[i] -= 1;
		if(my > bulf1_1y[i] && mx < bulf1_1x[i]) bulf1_1y[i] += 1;
		if(my < bulf1_2y[i] && mx < bulf1_2x[i]) bulf1_2y[i] -= 1;
		if(my > bulf1_2y[i] && mx < bulf1_2x[i]) bulf1_2y[i] += 1;
		putimage(bulf1_1x[i],bulf1_1y[i],imag_missiels[1],1);
		putimage(bulf1_2x[i],bulf1_2y[i],imag_missiels[1],1);
		if (bulf1_1x[i] < 12)
		{
		 putimage(bulf1_1x[i],bulf1_1y[i],imag_missiels[1],1);
		 putimage(bulf1_2x[i],bulf1_2y[i],imag_missiels[1],1);
		 bulf1_1x[i] = 0; bulf1_1y[i] = 0;
		 bulf1_2x[i] = 0; bulf1_2y[i] = 0;
		}
	       }
	      }
	     }

/*-------------------------------------------------------------------------*/
	     /*
	     { /* incoming fighter 2 movements */
	     /*
		putimage(ft2x,ft2y,imag_fighter2[ft2_type],1);
		ft2x -= 5;
		putimage(ft2x,ft2y,imag_fighter2[ft2_type],1);
		if(ft2x < 0)
		{
		 putimage(ft2x,ft2y,imag_fighter2[ft2_type],1);
		 ft2x = 650; ft2_type = random(10);
		 while(1)
		 {
		  ft2y = random(380);
		  if(ft2y > 50 &&  ft2y > ft1y+150) break;
		  if(ft2y > 50 &&
		     ft2y < ft1y-150 &&
		     ft2y != ft1y)
		   break;
		 }
		}
	       }
	      for(i=0;i<random(3);i++)
	      {
	       if(bulf2x[i] == 0 &&
		   bulf2y[i] == 0 &&
		      ft2x < 600)
	       {
		bulf2x[i] = ft2x+18; bulf2y[i] = ft2y+42;
		putimage(bulf2x[i],bulf2y[i],imag_missiels[1],1);
		break;
	       }
	      }
	      for(i=0;i<3;i++)
	      {
	       if(bulf2x[i] != 0 && bulf2y[i] != 0)
	       {
		putimage(bulf2x[i],bulf2y[i],imag_missiels[1],1);
		bulf2x[i] -= 16;
		putimage(bulf2x[i],bulf2y[i],imag_missiels[1],1);
		if (bulf2x[i] < 12)
		{
		 putimage(bulf2x[i],bulf2y[i],imag_missiels[1],1);
		 bulf2x[i] = 0; bulf2y[i] = 0;
		}
	       }
	      }

/*-------------------------------------------------------------------------*/
	     /*
	     { /* incoming BOMBER 737 movements */
	     /*
	      putimage(B737x,B737y,imag_B737[B737_type],1);
	      B737x -= 6;
	      putimage(B737x,B737y,imag_B737[B737_type],1);
	      if(B737x < 0)
	      {
	       putimage(B737x,B737y,imag_B737[B737_type],1);
	       B737x = 520; B737_type = random(10);
	       B737y = random(350);
	      }

	      for(i=0;i<random(5);i++)
	      {
	       if(bulB737_1x[i] == 0 &&
		   bulB737_1y[i] == 0 &&
		      B737x < 550)
	       {
		bulB737_1x[i] = B737x+50; bulB737_1y[i] = B737y+40;
		bulB737_2x[i] = B737x+5; bulB737_2y[i] = B737y+65;
		bulB737_3x[i] = B737x+50; bulB737_3y[i] = B737y+90;
		putimage(bulB737_1x[i],bulB737_1y[i],imag_missiels[1],1);
		putimage(bulB737_2x[i],bulB737_2y[i],imag_missiels[1],1);
		putimage(bulB737_3x[i],bulB737_3y[i],imag_missiels[1],1);
		break;
	       }
	      }
	      for(i=0;i<5;i++)
	      {
	       if(bulB737_1x[i] != 0 && bulB737_1y[i] != 0)
	       {
		 putimage(bulB737_1x[i],bulB737_1y[i],imag_missiels[1],1);
		 putimage(bulB737_2x[i],bulB737_2y[i],imag_missiels[1],1);
		 putimage(bulB737_3x[i],bulB737_3y[i],imag_missiels[1],1);
		 bulB737_1x[i] -= 16;
		 bulB737_2x[i] -= 16;
		 bulB737_3x[i] -= 16;
		 putimage(bulB737_1x[i],bulB737_1y[i],imag_missiels[1],1);
		 putimage(bulB737_2x[i],bulB737_2y[i],imag_missiels[1],1);
		 putimage(bulB737_3x[i],bulB737_3y[i],imag_missiels[1],1);
		if (bulB737_1x[i] < 18)
		{
		 putimage(bulB737_1x[i],bulB737_1y[i],imag_missiels[1],1);
		 putimage(bulB737_2x[i],bulB737_2y[i],imag_missiels[1],1);
		 putimage(bulB737_3x[i],bulB737_3y[i],imag_missiels[1],1);
		 bulB737_1x[i] = 0; bulB737_1y[i] = 0;
		 bulB737_2x[i] = 0; bulB737_2y[i] = 0;
		 bulB737_3x[i] = 0; bulB737_3y[i] = 0;
		}
	       }
	      }
	     }
	     */

/*-------------------------------------------------------------------------*/

	     // quit
	     /*
	     if(key == 1){ nosound();closegraph(); exit(0);}

	     {//screen animation
	      for(i=0;i<10;i++)
	      {
	       if(flag_aniX[i] > 0)
	       {
		putimage(aniX[i],25,imag_bullets[0],1);
		putimage(aniX[i],25,imag_bullets[1],1);
		putimage(aniX[i],458,imag_bullets[0],1);
		putimage(aniX[i],458,imag_bullets[1],1);
		aniX[i] += disX[i];
		putimage(aniX[i],25,imag_bullets[0],1);
		putimage(aniX[i],458,imag_bullets[0],1);
		if(aniX[i] > MaxX)
		{
		 aniX[i] = 0;
		 flag_aniX[i] = 0;
		}
	       }
	      }
	     }
	   }//end of while loop
	   */
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
	    int stangle = 0,
		endangle = 130,
		xradius = 30,
		yradius = 5,
		i;
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
	    int stangle = 0,
		endangle = 360,
		xradius = 20,
		yradius = 6,
		i;
	   setcolor(rang);
	   //rectangle(midx-25, midy-16,midx+55, midy+12);
	   ellipse(midx, midy, stangle, endangle, xradius, yradius);
	   line(midx,midy-yradius,midx + (xradius+5),midy-(yradius+10));
	   circle(midx,midy-8,1);
	   line(midx,midy-yradius,midx - (xradius+5),midy-(yradius+10));
	   for(i=28;i>0;i-=2)   circle(midx+19-i,midy-3,1);
	   for(i=30;i>0;i-=2)   circle(midx+18-i,midy-1,1);
	   circle(midx+19,midy,1);
	   for(i=32;i>0;i-=2)   circle(midx+18-i,midy+2,1);
	   for(i=34;i>0;i-=2)   circle(midx+18-i,midy+4,1);
	   circle(midx+5,midy+9,1);
	   circle(midx-5,midy+9,1);
	   setcolor(15);
	   for(i=0;i<6;i+=2)
	    line(midx-20+i,midy-i,midx-15+i,midy-i);
	   for(i=1;i<4;i++)    circle(midx+xradius+31,midy-5,i);
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
	 return NULL;
	}

/*-------------------------------------------------------------------------*/

	// two missiels
	void *Missiles(int midx,int midy,int rang,int side)
	{
	       int stangle = 0,
	       endangle = 130,
	       xradius = 7,
	       yradius = 3;
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
	   //rectangle(midx-8, midy-5,midx+8, midy+5);
	   //ellipse(midx, midy, endangle, stangle, xradius, yradius);
	   //ellipse(midx, midy,stangle, 220,xradius, yradius);
	   //ellipse(midx+7,midy, 0,360,1,2);
	   ellipse(midx,midy, 0,360,1,2);
	   return(Allocate(midx-3, midy-5,midx+3, midy+5));
	 }
	 cleardevice();
	 return NULL;
	}

/*-------------------------------------------------------------------------*/

	//13 fighters
	void *Fighter_one(int midx,int midy,int rang)
	{
	   int stangle = 0,
		endangle = 120,
		xradius = 25,
		yradius = 7;
	   setcolor(rang);
	   //rectangle(midx-22, midy-47,midx+26, midy+47);
	   ellipse(midx, midy, stangle, endangle, xradius, yradius);
	   ellipse(midx, midy, 242,stangle, xradius, yradius);
	   ellipse(midx-12,midy, 0,360,1,5);
	   ellipse(midx,midy-17, 0,360,8,2);
	   line(midx-6,midy-12,midx-6,midy-22);
	   ellipse(midx,midy+17, 0,360,8,2);
	   line(midx-6,midy+12,midx-6,midy+22);
	   ellipse(midx-16,midy, 0,360,5,2);
	   arc(midx-12,midy, 90,270,5);
	   arc(midx-16,midy, 90,270,3);
	   ellipse(midx, midy-5,0,180,3,40);
	   ellipse(midx, midy+5,180,0,3,40);
	   ellipse(midx+15, midy-5,0,180,2,10);
	   ellipse(midx+15, midy+5,180,0,2,10);
	   ellipse(midx+5, midy,0,360,20,5);
	   ellipse(midx+5, midy,0,360,20,3);
	   setfillstyle(CLOSE_DOT_FILL,rang);
	   floodfill(midx, midy,rang);
	   return(Allocate(midx-22, midy-47,midx+26, midy+47));
	}

/*-------------------------------------------------------------------------*/

	//13 fighters
	void *Fighter_two(int midx,int midy,int rang)
	{
	   int stangle = 0,
		endangle = 120,
		xradius = 25,
		yradius = 7;
	   setcolor(rang);
	   //rectangle(midx-22, midy-47,midx+26, midy+47);
	   ellipse(midx, midy, stangle, endangle, xradius, yradius);
	   ellipse(midx, midy, 242,stangle, xradius, yradius);
	   ellipse(midx-12,midy, 0,360,1,5);
	   ellipse(midx-16,midy-10, 0,360,1,7);
	   ellipse(midx-16,midy+10, 0,360,1,7);
	   ellipse(midx-16,midy, 0,360,5,2);
	   ellipse(midx, midy-5,0,180,3,40);
	   ellipse(midx, midy+5,180,0,3,40);
	   ellipse(midx+15, midy-5,0,180,2,10);
	   ellipse(midx+15, midy+5,180,0,2,10);
	   ellipse(midx+5, midy,0,360,20,3);
	   setfillstyle(CLOSE_DOT_FILL,rang);
	   floodfill(midx, midy,rang);
	   return(Allocate(midx-22, midy-47,midx+26, midy+47));
	}

/*-------------------------------------------------------------------------*/

	//B737
	void *B737(int midx,int midy,int rang)
	{
	  int i,j;
	 //rectangle(midx-61,midy-71,midx+61,midy+71);
	 setcolor(rang);
	 line(midx-60,midy,midx+60,midy-70);
	 moveto(midx+60,midy-70);lineto(midx+50,midy-50);
	 moveto(midx+50,midy-50);lineto(midx+20,midy-22);

	 moveto(midx+20,midy-22);lineto(midx+40,midy);
	 for(i=4,j=2;i<35 && j <19;i+=4,j+=2)
	 ellipse(midx-10,midy,0,360,i,j);
	 moveto(midx+40,midy);lineto(midx+20,midy+22);

	 line(midx-60,midy,midx+60,midy+70);
	 moveto(midx+60,midy+70);lineto(midx+50,midy+50);
	 moveto(midx+50,midy+50);lineto(midx+20,midy+22);
	 for(i=0;i<34;i+=4) floodfill(midx+i,midy,rang);
	 setfillstyle(LINE_FILL,rang);
	 floodfill(midx+35,midy,rang);
	 return(Allocate(midx-61,midy-71,midx+61,midy+71));
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

	void *Lifes(int midx,int midy)
	{
	 setcolor(2);
	 //rectangle(midx-3,midy+2,midx+11,midy+24);
	 settextstyle(3,0,2);
	 outtextxy(midx-32,midy,0);
	 return(Allocate(midx-3,midy+2,midx+11,midy+24));
	}

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
	 int i,j=1;
	 char ch = ' ';
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
	 ch = getchar();
	 switch(ch)
	 {
	  case '1':
		return 1;
	  case '2':
		return 2;
	  case '3':
		return 3;
	  case '4':
		return 4;
	  case '5':
		return 5;
	  default :
		return 1;
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

	void display_Life(void *img,int num)
	{
	  int i;
	  setcolor(6);
	  outtextxy(240,5,"LIFES:- ");
	  putimage(305,5,img,1);
	  outtextxy(440,5,"SCORE:-");
	}

/*-------------------------------------------------------------------------*/