//============================================================================
// Name        : Muhammad Ameen
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================
#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt

using namespace std;
int speed=30;
float z=350; 
float z2=50;
float t=550;
float t2=50;
float w=230;
float w1=230;
  float r = 130; 
	float r2 = 130;
char a3=BROWN,a2=BROWN,a=BROWN;
int level=0;
int arr[100]={0};
int score=0;
int life=3;
int check=1;
string Level;
void eatFood();

//collision detection
void collision()
{
     
if(z>t-10 && z<t+10 && z2>=t2-10 && z2<=t2+10) {
life--;
z=350;
z2=50;
t=550;
t2=50;
for(int i=0; i<65; i++){
arr[i]=0;
}
}                          
}

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;
void Menu(){
// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	


	char a=YELLOW;
	DrawString(100,650,"-------------------DODGE EM GAME-----------------",colors[RED]);
	DrawString(100,550,"----------------Press (s) Start NEW Game----------------",colors[RED]);
	DrawString(100,450,"----------------------CONTINUE---------------------",colors[RED]);
	DrawString(100,350,"------------------------HELP?----------------------",colors[RED]);
	
	int gap_turn =0;
	int sx = 60;
	int sy = 100;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[a];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	glutSwapBuffers();
	
	
}

void help(){
glClearColor(1/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors
DrawString(400,300,"we have to use keys for it",colors[RED]);
glutSwapBuffers();
}
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students
        string sr=to_string(score);
        string life1=to_string(life);
	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]);  
	//Display Score
	
	DrawString( 50, 850, "Score=", colors[BLACK]);
	DrawString( 130, 850, sr, colors[BLACK]);
	DrawString( 200, 850, "life=", colors[BLACK]);
	DrawString( 280, 850, life1, colors[BLACK]);
	DrawString( 350, 850, "Level", colors[BLACK]);
	DrawString( 450, 850, Level, colors[BLACK]);
	
	
	
	//DrawString( 150, 840,s , colors[MISTY_ROSE]);
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	// Drawing opponent car
	float x = t; 
	float y = t2; 
	float width = 15; 
	float height = 10;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 2.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect

	// Drawing Arena
	int gap_turn = 90;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[a];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
        
        
        //arena 2
        
        int gap_turn1 = 90;
	int sx1 = 120;
	int sy1 = 110;
	int swidth1 = 600/2 - gap_turn/2; // half width
	int sheight1 = 10;
	float *scolor1 = colors[a2];
	DrawRectangle(sx1, sy1, swidth1, sheight1, scolor1); // bottom left
	DrawRectangle(sx1 + swidth1 + gap_turn1, sy1, swidth1, sheight1, scolor1); // bottom right
	DrawRectangle(sx1+swidth1*2+gap_turn1, sy1+sheight1, sheight1*2, swidth1, scolor1); // right down
	DrawRectangle(sx1+swidth1*2+gap_turn1, sy1+sheight1+swidth1+gap_turn1, sheight1*2, swidth1, scolor1); // right up
	DrawRectangle(sx1 + swidth1 + gap_turn1, sy1+610, swidth1, sheight1, scolor1); // top left
	DrawRectangle(sx1, sy1+610, swidth1, sheight1, scolor1); // top right
	DrawRectangle(sx1-sheight1*2, sy1+sheight1+swidth1+gap_turn1, sheight1*2, swidth1, scolor1); // left up
	DrawRectangle(sx1-sheight1*2, sy1+sheight1, sheight1*2, swidth1, scolor1); // left down
        
        
        
        //Arena 3
        int gap_turn2 = 90;
	int sx2 = 220;
	int sy2 = 210;
	int swidth2 = 400/2 - gap_turn2/2; // half width
	int sheight2 = 10;
	float *scolor2 = colors[a3];
	DrawRectangle(sx2, sy2, swidth2, sheight2, scolor2); // bottom left
	DrawRectangle(sx2 + swidth2 + gap_turn2, sy2, swidth2, sheight2, scolor2); // bottom right
	DrawRectangle(sx2+swidth2*2+gap_turn2, sy2+sheight2, sheight2*2, swidth2, scolor2); // right down
	DrawRectangle(sx2+swidth2*2+gap_turn2, sy2+sheight2+swidth2+gap_turn2, sheight2*2, swidth2, scolor2); // right up
	DrawRectangle(sx2 + swidth2 + gap_turn2, sy2+410, swidth2, sheight2, scolor2); // top left
	DrawRectangle(sx2, sy2+410, swidth2, sheight2, scolor2); // top right
	DrawRectangle(sx2-sheight2*2, sy2+sheight2+swidth2+gap_turn2, sheight2*2, swidth2, scolor2); // left up
	DrawRectangle(sx2-sheight2*2, sy2+sheight2, sheight2*2, swidth2, scolor2); // left down
	
	
	//arena 4								
        
        int gap_turn3 =0;
	int sx3 = 320;
	int sy3 = 310;
	int swidth3 = 200/2 - gap_turn3/2; // half width
	int sheight3 = 10;
	float *scolor3 = colors[BROWN];
	DrawRectangle(sx3, sy3, swidth3, sheight3, scolor3); // bottom left
	DrawRectangle(sx3 + swidth3 + gap_turn3, sy3, swidth3, sheight3, scolor3); // bottom right
	DrawRectangle(sx3+swidth3*2+gap_turn3, sy3+sheight3, sheight3*2, swidth3, scolor3); // right down
	DrawRectangle(sx3+swidth3*2+gap_turn3, sy3+sheight3+swidth3+gap_turn3, sheight3*2, swidth3, scolor3); // right up
	DrawRectangle(sx3 + swidth3 + gap_turn3, sy3+210, swidth3, sheight3, scolor3); // top left
	DrawRectangle(sx3, sy3+210, swidth3, sheight3, scolor3); // top right
	DrawRectangle(sx3-sheight3*2, sy3+sheight3+swidth3+gap_turn3, sheight3*2, swidth3, scolor3); // left up
	DrawRectangle(sx3-sheight3*2, sy3+sheight3, sheight3*2, swidth3, scolor3); // left down
        
        
        //plAYers car
        float x3 = z; 
	float y3 = z2; 
	float width3 = 15; 
	float height3 = 10;
	float* color3 = colors[RED]; 
	float radius3 = 2.0;
	DrawRoundRect(x3,y3,width3,height3,color3,radius3); // bottom left tyre
	DrawRoundRect(x3+width3*3,y3,width3,height3,color3,radius3); // bottom right tyre
	DrawRoundRect(x3+width3*3,y3+height3*4,width3,height3,color3,radius3); // top right tyre
	DrawRoundRect(x3,y3+height3*4,width3,height3,color3,radius3); // top left tyre
	DrawRoundRect(x3, y3+height3*2, width3, height3, color3, radius3/2); // body left rect
	DrawRoundRect(x3+width3, y3+height3, width3*2, height3*3, color3, radius3/2); // body center rect
	DrawRoundRect(x3+width3*3, y3+height3*2, width3, height3, color3, radius3/2); // body right rect
       
        
        eatFood();
        
        
        
       if(life==0){
        pause();
        Menu();
        glutSwapBuffers();
}
       
       
       
        glutSwapBuffers(); // do not modify this line.. or draw anything below this line
        






}





/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT){
	if(z2>370 && z2<470){
	z-=100;
	}
	                                    /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/
		                                           // what to do when left key is pressed...

	} if (key== GLUT_KEY_RIGHT) {
	  if(z2>370 && z2<470){
	  z+=100;

               }
			                        //*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*

          }if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
           if(z>370 && z<470){
           z2+=100;
            }
            }
           if (key== GLUT_KEY_DOWN) {
			                   /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/
           if(z>370 && z<470){
             z2-=100;
             }
             }
             
            
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

	

	

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 's' || key == 'S')//do something if b is pressed
			{
	cout << "s pressed" << endl;
	level++;
                             
		
	}
	
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
 /////////////////////////////////////////////////////////////////////////oponent car//////////////////////////////////////////////////// 
void enemy1() {
 //right                                                 // implement your functionality here
if(t2==50 && t>=30 && t<=760){
t+=5;
}
//up
if(t==760 && t2>=50 && t2<=760){
t2+=5;
} 
//left up
if(t2>=750 && t>=30&& t<=760){
t-=5;
}
// down left
if(t2>=50 && t2<=760 && t==30 ){
t2-=5;
}
}
///////////////////////////////////////////////////////////////////second arena///////////////////////////////////////////////////////////
void enemy2(){
//right
if(t2==130 && t>=130 && t<650){
t+=5;
}
//up
 if(t2>=130 && t2<=650 && t==650){
t2+=5;
} 
//left
 if( t2==650 && t>=130 && t<=650){
t-=5;
}
//down
 if(t2>=130 && t2<=650 && t==130){
t2-=5;
}
}
/////////////////////////////////////////////////////////////////////inner arena 2////////////////////////////////////////////////////////
void enemy3(){
//right
if(t2==230 && t>=230 && t<=550){

t+=5;
} 
//up
if(t==550 && t2>=230 && t2<=550){
t2+=5;
} 
//left
 if(t2==550 && t>=230 && t<=550){
t-=5;
}
//down
 if(t2>=230 && t2<=550 && t==230 ){
t2-=5;
}
}
////////////////////////////////////////////////////////////////////players car//////////////////////////////////////////////////////////
void player(){

//up
if(z==130 && z2>=130 && z2<=650){

z2+=5;
} 
//right
 if(z2==650 && z>=130 && z<=650){
z+=5;
} 
//down
 if(z==650 && z2>=130 && z2<=650){
z2-=5;
}
//left
 if(z>=130 && z<=650 && z2==130 ){
z-=5;
}
}
////////////////////////////////////////////////////////////////////////outerarena///////////////////////////////////////////////////////
void player2(){
//up
if(z==30 && z2>=30 && z2<=750){
z2+=5;
}
//right
if(z2==750 && z>=30 && z<=760){
z+=5;
} 
//down
if(z==760 && z2>50&& z2<=750){
z2-=5;
}
//left
if(z>=30 && z<=760 && z2==50 ){
z-=5;
}
}
///////////////////////////////////////////////////////////////////////inner arena 2//////////////////////////////////////////////////////
void player3(){
//up
if(z==230 && z2>=230 && z2<=550){

z2+=5;
} 
//right
 if(z2==550 && z>=230 && z<=550){
z+=5;
} 
//down
 if(z==550 && z2>=230 && z2<=550){
z2-=5;
}
//left
 if(z>=230 && z<=550 && z2==230 ){
z-=5;

}
}
///////////////////////////////////////////////////////////enemy(2)///////////////////////////////////////////////////////////////////////
void enemy4(){
//up
if(w==230 && w1>=230 && w1<=550){

w1+=5;
} 
//right
 if(w1==550 && w>=230 && w<=550){
w+=5;
} 
//down
 if(w==550 && w1>=230 && w1<=550){
w1-=5;
}
//left
 if(w>=230 && w<=550 && w1==230 ){
w-=5;

}
}
/////////////////////////////////////////////////////////enemy(3)////////////////////////////////////////////////////////////////////
void enemy5(){
if(r==130 && r2>=130 && r2<=650){

r2+=5;
} 
//right
 if(r2==650 && r>=130 && r<=650){
r+=5;
} 
//down
 if(r==650 && r2>=130 && r2<=650){
r2-=5;
}
//left
 if(r>=130 && r<=650 && r2==130 ){
r-=5;
}
}
///////////////////////////////////////////////////////////intelligent car////////////////////////////////////////////////////////////////
void intelligent() {

//right
//if(z>=130 && z<=650 && z2>=130){
  // if(t2>370 && t2<470){
   //if(t<=120){
   //t+=100;
   //}
   //}
   //}
   //down 
   if(z>=130 && z<=650 && z>=130 && z2<=650){
   if(t>270 && t<370){
   if(t2>650){
   t2-=100;
   }
   }
   }
  //up
  if(z>=130 && z<=650 && z2>=130 && z2<=650){
  if(t>370 && t<470){
  if(t2<130){
  t2+=80;
  }
  }
  }
  
////////////////////////////////////////////////////////////////arena 3///////////////////////////////////////////////////////////////////
///down to up////////////
if(z>=230 && z<=550 && z2>=230 && z2<=550){
if(t>370 && t<470){
if(t2<230){
t2+=20;
}
}
}
//////up to down/////
 if(z>=230 && z<=550 && z>=230 && z2<=550){
   if(t>270 && t<370){
   if(t2>550){
   t2-=20;
   check=0;
   }
   }
   }
   
if(z>=230 && z<=550 && z>=230 && z2<=550){
if(t>270 && t<370){
if(t<=220){
t+=100;
}
}
}
}


void intelligent2(){
//right
if(z>=130 && z<=650 && z2>=130){
 if(t2>370 && t2<470){
 if(t<=120){
  t+=100;
  }
 }
   }
   //down 
   if(z>=130 && z<=650 && z>=130 && z2<=650){
   if(t>270 && t<370){
   if(t2>650){
   t2-=100;
   }
   }
   }
  //up
  if(z>=130 && z<=650 && z2>=130 && z2<=650){
  if(t>370 && t<470){
  if(t2<130){
  t2+=80;
  }
  }
  }

//left
if(z>=130 && z<=650 && z2>=130){
 if(t2>370 && t2<470){
 if(t>=750){
 t-=110;
 }
 }
 }
///arena 3////////////////
///down to up////////////
if(z>=230 && z<=550 && z2>=230 && z2<=550){
if(t>370 && t<470){
if(t2<230){
t2+=20;
}
}
}
//////up to down/////
 if(z>=230 && z<=550 && z>=230 && z2<=550){
   if(t>270 && t<370){
   if(t2>550){
   t2-=20;
   check=0;
   }
   }
   }
if(z>=230 && z<=550 && z>=230 && z2<=550){
if(t>270 && t<370){
if(t<=220){
t+=100;
}
}
}
}

/////////////////////////////////////////////////////////////////level2//////////////////////////////////////////////////////////////////
     
     
     
      void level2(){
      a=BLUE;
      a2=ORANGE;
      a3=PINK;
      eatFood();
      GameDisplay();
      enemy1();
      enemy2();
      enemy3();
      player();
      player2();
      player3();
      intelligent2();
      speed=20;
      
                                      
        
 }
  void level3(){
      a=BROWN;
      a2=CORAL;
      a3=ORANGE;
      eatFood();
      GameDisplay();
      enemy1();
      enemy2();
      enemy3();
      player();
      player2();
      player3();
      intelligent2();
      speed=10;
      
                                       
}
void level4(){
      a=BROWN;
      a2=CORAL;
      a3=ORANGE;
      eatFood();
      GameDisplay();
      enemy1();
      enemy2();
      enemy3();
      enemy4();
      enemy5();
      player();
      player2();
      player3();
      intelligent2();
      speed=10;

       //third enemy car
        float w = 230; 
	float w1 = 230; 
	float width3 = 15; 
	float height3 = 10;
	float* color3 = colors[BLACK]; 
	float radius3 = 2.0;
	DrawRoundRect(w,w1,width3,height3,color3,radius3); // bottom left tyre
	DrawRoundRect(w+width3*3,w1,width3,height3,color3,radius3); // bottom right tyre
	DrawRoundRect(w+width3*3,w1+height3*4,width3,height3,color3,radius3); // top right tyre
	DrawRoundRect(w,w1+height3*4,width3,height3,color3,radius3); // top left tyre
	DrawRoundRect(w, w1+height3*2, width3, height3, color3, radius3/2); // body left rect
	DrawRoundRect(w+width3, w1+height3, width3*2, height3*3, color3, radius3/2); // body center rect
	DrawRoundRect(w+width3*3, w1+height3*2, width3, height3, color3, radius3/2); // body right rect
        
      //fourth enemy car
      
      float r = 130; 
	float r2 = 130; 
	float width4 = 15; 
	float height4 = 10;
	float* color4 = colors[BLACK]; 
	float radius4 = 2.0;
	DrawRoundRect(r,r2,width4,height4,color4,radius4); // bottom left tyre
	DrawRoundRect(r+width4*3,r2,width4,height4,color4,radius4); // bottom right tyre
	DrawRoundRect(r+width4*3,r2+height4*4,width4,height4,color4,radius4); // top right tyre
	DrawRoundRect(r,r2+height4*4,width4,height4,color4,radius4); // top left tyre
	DrawRoundRect(r, r2+height4*2, width4, height4, color4, radius4/2); // body left rect
	DrawRoundRect(r+width4, r2+height4, width4*2, height4*3, color4, radius4/2); // body center rect
	DrawRoundRect(r+width4*3, r2+height4*2, width4, height4, color4, radius4/2); // body right rect
                                       
}

 
 
void Timer(int m) {
 

      enemy1();
      enemy2();
      enemy3();
      player();
      player2();
      player3();
      intelligent();
      glutPostRedisplay;


collision();

ostringstream convert;
convert<<check;
Level=convert.str();

//if(check==1&&score>=9){
//check=2;
//z=350;
//z2=50;
//t=550;
//t2=50;
//score=0;
//Level=2;

//level2();
          //next 1000/fps
//} 
if(check==2&&score>=9){
check=3;
z=350;
z2=50;
t=550;
t2=50;
score=0;
Level=3;

level3();
          //next 1000/fps
} 

if(check==1&&score>=9){
z=350;
z2=50;
t=550;
t2=50;
score=0;
Level=4;
level4();
          //next 1000/fps
}     
//if(life==0){
  //       glutDisplayFunc(Menu);
     //    glutPostRedisplay();

//}

        if(level>0){
        glutDisplayFunc(GameDisplay);
        }
                                             // once again we tell     thelibrary to call our Timer function after 
	glutTimerFunc(speed, Timer,0);             //next 1000/fps
	glutPostRedisplay();

	
}



/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x=473, int y=430) {
	cout << x << " " << y << endl;
	
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 940, height = 940; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("welcome peeps"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
        if(level==0){
        glutDisplayFunc(Menu);
        
       
        }
        
        
	//glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}



       void eatFood()
       {
       if(z==170 && z2+20==770 && arr[0]==0){
       
       arr[0]=1;
       score++;
       }
       if(arr[0]==1){
       DrawCircle(-170,770,5,colors[BLACK]);
       
        }
       else{DrawCircle(170,770,5,colors[BLACK]);}
        
        if(z==270 && (z2+20)==770 && arr[1]==0){
       
       arr[1]=1;
       score++;
       }
       if(arr[1]==1){
       DrawCircle(-270,-770,5,colors[BLACK]);
       
        }
        else{DrawCircle(270,770,5,colors[BLACK]);}
        
        
        if(z==370 && z2+20==770 && arr[2]==0){
       
       arr[2]=1;
       score++;
       }
       if(arr[2]==1){
       DrawCircle(-370,770,5,colors[BLACK]);
       
        }
       else{DrawCircle(370,770,5,colors[BLACK]);}
        
        
        if(z==470 && z2+20==770 && arr[3]==0){
       
       arr[3]=1;
       score++;
       }
       if(arr[3]==1){
       DrawCircle(-470,770,5,colors[BLACK]);
       
        }
       else{DrawCircle(470,770,5,colors[BLACK]);}
       
       
        if(z==570 && z2+20==770 && arr[4]==0){
       
       arr[4]=1;
       score++;
       }
       if(arr[4]==1){
       DrawCircle(-570,770,5,colors[BLACK]);
       
        }
       else{DrawCircle(570,770,5,colors[BLACK]);}
       
       
        if(z==670 && z2+20==770 && arr[5]==0){
       
       arr[5]=1;
       score++;
       }
       if(arr[5]==1){
       DrawCircle(-670,770,5,colors[BLACK]);
       
        }
       else{DrawCircle(670,770,5,colors[BLACK]);}
        
        
        if(z+10==770 && z2+20==770 && arr[6]==0){
       
       arr[6]=1;
       score++;
       }
       if(arr[6]==1){
       DrawCircle(-770,770,5,colors[BLACK]);
       
        }
       else{DrawCircle(770,770,5,colors[BLACK]);}
      
      
      ///right down
        
        if(z2==670 && z==760 && arr[7]==0){
       
       arr[7]=1;
       score++;
       }
       if(arr[7]==1){
       DrawCircle(-760,-670,5,colors[BLACK]);
       
        }
        else{ DrawCircle(760,670,5,colors[BLACK]);}
      //2
      
        
        if(z2==570 && z==760 && arr[8]==0){
       
       arr[8]=1;
       score++;
       }
       if(arr[8]==1){
       DrawCircle(-760,-570,5,colors[BLACK]);
       
        }
        else{ DrawCircle(760,570,5,colors[BLACK]);}
        //3
        
        
        if(z2==470 && z==760 && arr[9]==0){
       
       arr[9]=1;
       score++;
       }
       if(arr[9]==1){
       DrawCircle(-760,-470,5,colors[BLACK]);
       
        }
        else{ DrawCircle(760,470,5,colors[BLACK]);}
        
        //4
        
        if(z2==370 && z==760 && arr[10]==0){
       
       arr[10]=1;
       score++;
       }
       if(arr[10]==1){
       DrawCircle(-760,-370,5,colors[BLACK]);
       
        }
        else{ DrawCircle(760,370,5,colors[BLACK]);}
        //5
        
        if(z2==270 && z==760 && arr[11]==0){
       
       arr[11]=1;
       score++;
       }
       if(arr[11]==1){
       DrawCircle(-760,-270,5,colors[BLACK]);
       
        }
        else{ DrawCircle(760,270,5,colors[BLACK]);}
        
        //6
        if(z2==170 && z==760 && arr[12]==0){
       
       arr[12]=1;
       score++;
       }
       if(arr[12]==1){
       DrawCircle(-760,-170,5,colors[BLACK]);
       
        }
        else{ DrawCircle(760,170,5,colors[BLACK]);}
        
        
        //down left
       if(z==750 && z2+20==70 && arr[13]==0){
       
         arr[13]=1;
       score++;
       }
       if(arr[13]==1){
       DrawCircle(-750,-70,5,colors[BLACK]);
       }
       
       else{  
       DrawCircle(750,70,5,colors[BLACK]);}
        
        //2
        
        if(z==650 && z2+20==70 && arr[14]==0){
       
         arr[14]=1;
       score++;
       }
       if(arr[14]==1){
       DrawCircle(-650,-70,5,colors[BLACK]);
       }
       
       else{  
       DrawCircle(650,70,5,colors[BLACK]);}
        
        //3
        
        if(z==570 && z2+20==70 && arr[15]==0){
       
         arr[15]=1;
       score++;
       }
       if(arr[15]==1){
       DrawCircle(-570,-70,5,colors[BLACK]);
       }
       
       else{  
       DrawCircle(570,70,5,colors[BLACK]);}
       
       //4
       
       if(z==470 && z2+20==70 && arr[16]==0){
       
         arr[16]=1;
       score++;
       }
       if(arr[16]==1){
       DrawCircle(-470,-70,5,colors[BLACK]);
       }
       
       else{  
       DrawCircle(470,70,5,colors[BLACK]);}
        
         //5
         
          if(z==370 && z2+20==70 && arr[17]==0){
       
         arr[17]=1;
       score++;
       }
       if(arr[17]==1){
       DrawCircle(-370,-70,5,colors[BLACK]);
       }
       
       else{  
       DrawCircle(370,70,5,colors[BLACK]);}
       
       //6
       
        if(z==270 && z2+20==70 && arr[18]==0){
       
         arr[18]=1;
       score++;
       }
       if(arr[18]==1){
       DrawCircle(-270,-70,5,colors[BLACK]);
       }
       
       else{  
       DrawCircle(270,70,5,colors[BLACK]);}
       
       
       //7
        if(z==170 && z2+20==70 && arr[19]==0){
       
         arr[19]=1;
       score++;
       }
       if(arr[19]==1){
       DrawCircle(-170,-70,5,colors[BLACK]);
       }
       
       else{  
       DrawCircle(170,70,5,colors[BLACK]);}
       
       
       
       //left upppp
       
       if(z2==770 && z+40==70 && arr[21]==0){
       
       arr[21]=1;
       score++;
       }
       if(arr[21]==1){
       DrawCircle(-30,-770,5,colors[BLACK]);
       
        }
        else{ DrawCircle(70,770,5,colors[BLACK]);}
       
       
       
       
       if(z2+20==670 && z+40==70 && arr[21]==0){
       
       arr[21]=1;
       score++;
       }
       if(arr[21]==1){
       DrawCircle(-30,-670,5,colors[BLACK]);
       
        }
        else{ DrawCircle(70,670,5,colors[BLACK]);}
      //2
      
        
        if(z2+20==570 && z+40==70 && arr[22]==0){
       
      arr[22]=1;
       score++;
       }
       if(arr[22]==1){
       DrawCircle(-70,-570,5,colors[BLACK]);
       
        }
        else
        { 
       DrawCircle(70,570,5,colors[BLACK]);}
        //3
        
        
        if(z2==470 && z+40==70 && arr[23]==0){
       
       arr[23]=1;
       score++;
       }
       if(arr[23]==1){
       DrawCircle(-70,-470,5,colors[BLACK]);
       
        }
        else{ DrawCircle(70,470,5,colors[BLACK]);}
        
        //4
        
        if(z2==370 && z+40==70 && arr[24]==0){
       
       arr[24]=1;
       score++;
       }
       if(arr[24]==1){
       DrawCircle(-70,-370,5,colors[BLACK]);
       
        }
        else{ DrawCircle(70,370,5,colors[BLACK]);}
        //5
        
        if(z2==270 && z+40==70 && arr[25]==0){
       
       arr[25]=1;
       score++;
       }
       if(arr[25]==1){
       DrawCircle(-70,-270,5,colors[BLACK]);
       
        }
        else{ DrawCircle(70,270,5,colors[BLACK]);}
        
        //6
        if(z2+20==170 && z+40==70 && arr[26]==0){
       
       arr[26]=1;
       score++;
       }
       if(arr[26]==1){
       DrawCircle(-70,-170,5,colors[BLACK]);
       
        }
        else{ DrawCircle(70,170,5,colors[BLACK]);}
        
        if(z2==70 && z+40==70 && arr[62]==0){
       
       arr[62]=1;
       score++;
       }
       if(arr[62]==1){
       DrawCircle(-70,70,5,colors[BLACK]);
       
        }
        else{ DrawCircle(70,70,5,colors[BLACK]);}
        
        //////////////////////////////////////////////////////////SECOND ARENA///////////////////////////////////////////////////////////
      
      
      //up right  
       if(z==170 && z2+20==670 && arr[32]==0){
       
       arr[32]=1;
       score++;
       }
       if(arr[32]==1){
       DrawCircle(-170,670,5,colors[BLACK]);
       
        }
       else{DrawCircle(170,670,5,colors[BLACK]);}
      
      
      
      
      if(z==270 && z2+20==670 && arr[27]==0){
       
       arr[27]=1;
       score++;
       }
       if(arr[27]==1){
       DrawCircle(-270,670,5,colors[BLACK]);
       
        }
       else{DrawCircle(270,670,5,colors[BLACK]);}
        
        //2
        
         if(z==370 && z2+20==670 && arr[28]==0){
       
       arr[28]=1;
       score++;
       }
       if(arr[28]==1){
       DrawCircle(-370,670,5,colors[BLACK]);
       
        }
       else{DrawCircle(370,670,5,colors[BLACK]);}
       
       //3
       
        if(z==470 && z2+20==670 && arr[29]==0){
       
       arr[29]=1;
       score++;
       }
       if(arr[29]==1){
       DrawCircle(-470,670,5,colors[BLACK]);
       
        }
       else{DrawCircle(470,670,5,colors[BLACK]);}
       
       //4
       
        if(z==570 && z2+20==670 && arr[30]==0){
       
       arr[30]=1;
       score++;
       }
       if(arr[30]==1){
       DrawCircle(-570,670,5,colors[BLACK]);
       
        }
       else{DrawCircle(570,670,5,colors[BLACK]);}
       
       //5
       
        if(z+20==670 && z2+20==670 && arr[31]==0){
       
       arr[31]=1;
       score++;
       }
       if(arr[31]==1){
       DrawCircle(-670,670,5,colors[BLACK]);
       
        }
       else{DrawCircle(670,670,5,colors[BLACK]);}
       
       ///rigth down
       
    
        if(z2==570 && z+20==670 && arr[33]==0){
       
       arr[33]=1;
       score++;
       }
       if(arr[33]==1){
       DrawCircle(-670,-570,5,colors[BLACK]);
       
        }
        else{ DrawCircle(670,570,5,colors[BLACK]);}
        
        //2
        
         if(z2==470 && z+20==670 && arr[34]==0){
       
       arr[34]=1;
       score++;
       }
       if(arr[34]==1){
       DrawCircle(-670,-470,5,colors[BLACK]);
       
        }
        else{ DrawCircle(670,470,5,colors[BLACK]);}
        
         if(z2==370 && z+20==670 && arr[36]==0){
       
       arr[36]=1;
       score++;
       }
       if(arr[36]==1){
       DrawCircle(-670,-370,5,colors[BLACK]);
       
        }
        else{ DrawCircle(670,370,5,colors[BLACK]);}
        
         if(z2==270 && z+20==670 && arr[37]==0){
       
       arr[37]=1;
       score++;
       }
       if(arr[37]==1){
       DrawCircle(-670,-270,5,colors[BLACK]);
       
        }
        else{ DrawCircle(670,270,5,colors[BLACK]);}
        
         if(z2==170 && z+20==670 && arr[38]==0){
       
       arr[38]=1;
       score++;
       }
       if(arr[38]==1){
       DrawCircle(-670,-170,5,colors[BLACK]);
       
        }
        else{ DrawCircle(670,170,5,colors[BLACK]);}
        
        //up left
        
         if(z2==570 && z+40==170 && arr[39]==0){
       
       arr[39]=1;
       score++;
       }
       if(arr[39]==1){
       DrawCircle(-170,-570,5,colors[BLACK]);
       
        }
        else{ DrawCircle(170,570,5,colors[BLACK]);}
      
      
        if(z2==470 && z+40==170 && arr[40]==0){
       
       arr[40]=1;
       score++;
       }
       if(arr[40]==1){
       DrawCircle(-170,-470,5,colors[BLACK]);
       
        }
        else{ DrawCircle(170,470,5,colors[BLACK]);}
        
          if(z2==370 && z+40==170 && arr[41]==0){
       
       arr[41]=1;
       score++;
       }
       if(arr[41]==1){
       DrawCircle(-170,-370,5,colors[BLACK]);
       
        }
        else{ DrawCircle(170,370,5,colors[BLACK]);}
        
          if(z2==270 && z+40==170 && arr[42]==0){
       
       arr[42]=1;
       score++;
       }
       if(arr[42]==1){
       DrawCircle(-170,-270,5,colors[BLACK]);
       
        }
        else{ DrawCircle(170,270,5,colors[BLACK]);}
        
          if(z2==170 && z+40==170 && arr[43]==0){
       
       arr[43]=1;
       score++;
       }
       if(arr[43]==1){
       DrawCircle(-170,-170,5,colors[BLACK]);
       
        }
        else{ DrawCircle(170,170,5,colors[BLACK]);}
        
        
        //right down
        
          if(z+40==270 && z2+40==170 && arr[44]==0){
       
       arr[44]=1;
       score++;
       }
       if(arr[44]==1){
       DrawCircle(-270,-170,5,colors[BLACK]);
       
        }
        else{ DrawCircle(270,170,5,colors[BLACK]);}
        
        if(z+40==370 && z2+40==170 && arr[45]==0){
       
       arr[45]=1;
       score++;
       }
       if(arr[45]==1){
       DrawCircle(-370,-170,5,colors[BLACK]);
       
        }
        else{ DrawCircle(70,170,5,colors[BLACK]);}
        
        if(z+40==470 && z2+40==170 && arr[46]==0){
       
       arr[46]=1;
       score++;
       }
       if(arr[46]==1){
       DrawCircle(-470,-170,5,colors[BLACK]);
       
        }
        else{ DrawCircle(470,170,5,colors[BLACK]);}
        
        if(z+40==570 && z2+40==170 && arr[47]==0){
       
       arr[47]=1;
       score++;
       }
       if(arr[47]==1){
       DrawCircle(-570,-170,5,colors[BLACK]);
       
        }
        else{ DrawCircle(570,170,5,colors[BLACK]);}
        
        /////////////////////////////////////////////////third arena/////////////////////////////////////////////////////////////////
        
        
        //up right  
       if(z==270 && z2+20==570 && arr[48]==0){
       
       arr[48]=1;
       score++;
       }
       if(arr[48]==1){
       DrawCircle(-270,570,5,colors[BLACK]);
       
        }
       else{DrawCircle(270,570,5,colors[BLACK]);}
      
      
      
      
      if(z==370 && z2+20==570 && arr[48]==0){
       
       arr[48]=1;
       score++;
       }
       if(arr[48]==1){
       DrawCircle(-370,570,5,colors[BLACK]);
       
        }
       else{DrawCircle(370,570,5,colors[BLACK]);}
        
        //2
        
         if(z==470 && z2+20==570 && arr[49]==0){
       
       arr[49]=1;
       score++;
       }
       if(arr[49]==1){
       DrawCircle(-470,570,5,colors[BLACK]);
       
        }
       else{DrawCircle(470,570,5,colors[BLACK]);}
       
       //3
       
        if(z==570 && z2+20==570 && arr[50]==0){
       
       arr[50]=1;
       score++;
       }
       if(arr[50]==1){
       DrawCircle(-570,570,5,colors[BLACK]);
       
        }
       else{DrawCircle(570,70,5,colors[BLACK]);}
       
      
       
       ///rigth down
       
        
        //2
        if(z2==570 && z+20==570 && arr[63]==0){
       
       arr[63]=1;
       score++;
       }
       if(arr[63]==1){
       DrawCircle(-570,-570,5,colors[BLACK]);
       
        }
        else{DrawCircle(570,570,5,colors[BLACK]);}
        
        
         if(z2==470 && z+20==570 && arr[51]==0){
       
       arr[51]=1;
       score++;
       }
       if(arr[51]==1){
       DrawCircle(-570,-470,5,colors[BLACK]);
       
        }
        else{ DrawCircle(570,470,5,colors[BLACK]);}
        
         if(z2==370 && z+20==570 && arr[52]==0){
       
       arr[52]=1;
       score++;
       }
       if(arr[52]==1){
       DrawCircle(-570,-370,5,colors[BLACK]);
       
        }
        else{ DrawCircle(570,370,5,colors[BLACK]);}
        
         if(z2==270 && z+20==570 && arr[53]==0){
       
       arr[53]=1;
       score++;
       }
       if(arr[53]==1){
       DrawCircle(-570,-270,5,colors[BLACK]);
       
        }
        else{ DrawCircle(570,270,5,colors[BLACK]);}
        
         if(z2==170 && z+20==570 && arr[54]==0){
       
       arr[54]=1;
       score++;
       }
       if(arr[54]==1){
       DrawCircle(-570,-170,5,colors[BLACK]);
       
        }
        else{ DrawCircle(570,170,5,colors[BLACK]);}
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //up left
        
        
         if(z2==470 && z+40==270 && arr[55]==0){
       
       arr[55]=1;
       score++;
       }
       if(arr[55]==1){
       DrawCircle(-270,-470,5,colors[BLACK]);
       
        }
        else{ DrawCircle(270,470,5,colors[BLACK]);}
      
      
        if(z2==370 && z+40==270 && arr[56]==0){
       
       arr[56]=1;
       score++;
       }
       if(arr[56]==1){
       DrawCircle(-270,-370,5,colors[BLACK]);
       
        }
        else{ DrawCircle(270,370,5,colors[BLACK]);}
        
          if(z2==270 && z+40==270 && arr[57]==0){
       
       arr[57]=1;
       score++;
       }
       if(arr[57]==1){
       DrawCircle(-270,-270,5,colors[BLACK]);
       
        }
        else{ DrawCircle(270,270,5,colors[BLACK]);}
        
        
        
        
        //right down
        
          if(z+40==370 && z2+40==270 && arr[58]==0){
       
       arr[58]=1;
       score++;
       }
       if(arr[58]==1){
       DrawCircle(-370,-270,5,colors[BLACK]);
       
        }
        else{ DrawCircle(370,270,5,colors[BLACK]);}
        
        if(z+40==270 && z2+40==270 && arr[59]==0){
       
       arr[59]=1;
       score++;
       }
       if(arr[59]==1){
       DrawCircle(-270,-70,5,colors[BLACK]);
       
        }
        else{ DrawCircle(70,170,5,colors[BLACK]);}
        
        if(z+40==470 && z2+40==270 && arr[60]==0){
       
       arr[60]=1;
       score++;
       }
       if(arr[60]==1){
       DrawCircle(-470,-270,5,colors[BLACK]);
       
        }
        else{ DrawCircle(470,270,5,colors[BLACK]);}
        
        if(z+40==570 && z2+40==270 && arr[61]==0){
       
       arr[61]=1;
       score++;
       }
       if(arr[61]==1){
       DrawCircle(-570,-270,5,colors[BLACK]);
       
        }
        else{ DrawCircle(570,270,5,colors[BLACK]);}
      
      
      
      
   }   


#endif /* AsteroidS_CPP_ */
