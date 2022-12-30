#include<iostream>
#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

using namespace std;

GLint i, j;
bool f=true;
float pos1=0,pos3=600,pos2=400;
float speed1=2.9f,speed2=2.5f,speed3=1.95f,cpos1=200,cpos2=400,cpos3=-250,cpos4=50,cpos5=490,sp1=2.0f;
float sun_x=620 ,sun_y=380,sp_x=0.5f,sp_y=1.0f;

GLint pos_car1, pos_car2 = 0;
GLint car1_speed = 2;
GLint car2_speed = 5;

GLfloat spin = 0.0;

void init()
{
	glClearColor(157.0f/255.0f, 216.0f/255.0f, 250.0f/255.0f, 1.0); //157, 216, 250
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

/// Field_Model
void Field(){

    ///Field - Lighter layer
    glPushMatrix();
    glBegin(GL_POLYGON);
    if(f)glColor3f(0.83, 1.293, 0.0);
    else glColor3f(0.7,0.8,0.0);
	glVertex2i(0, 70);
	glVertex2i(0, 120);
	glVertex2i(1000, 120);
	glVertex2i(1000, 70);
	glEnd();
	glPopMatrix();

    ///Field - Middle layer
    glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(0.533, 1.293, 0.0);
    else glColor3f(0.333,0.6,0.0);
	glVertex2i(0, 50);
	glVertex2i(0, 70);
	glVertex2i(1000, 70);
	glVertex2i(1000, 50);
	glEnd();
	glPopMatrix();

    ///Field - Shading
    glPushMatrix();
	glBegin(GL_POLYGON);
	if(f) glColor3f(0.1, 1.293, 0.0);
	else glColor3f(0.1,0.43,0.0);
	glVertex2i(0, 0);
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, 0);
	glEnd();
	glPopMatrix();
}

void Road()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    if(f) glColor3f(0.43, 0.43, 0.43);
    else glColor3f(0.23,0.23,0.23);
	glVertex2i(0, 120);
	glVertex2i(0, 210);
	glVertex2i(1000, 210);
	glVertex2i(1000, 120);
	glEnd();
	glPopMatrix();

	///divider
	glColor3f(0.83, 0.83, 0.83);
	glBegin(GL_LINES);
	for(j=0;j<=1000;j+=100) ///series of white lines
    {
        glVertex2i(20+j,165);
        glVertex2i(80+j,165);
    }
    glEnd();
}

void Field2()
{
    ///Field - Middle layer
    glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(0.83, 1.293, 0.0);
    else glColor3f(0.7,0.8,0.0);
	glVertex2i(0, 210);
	glVertex2i(0, 220);
	glVertex2i(1000, 220);
	glVertex2i(1000, 210);
	glEnd();
	glPopMatrix();
}

void big_hill_model(){
    ///Big Hill
    glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(0.1, 0.47, 0.0);
    else glColor3f(0.38, 0.41, 0.36);
	glVertex2i(0, 220);
	glVertex2i(150, 400);
	glVertex2i(300, 220);
	glEnd();
	glPopMatrix();

	///Big Hill - Shadow
	glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(0.27, 0.50, 0.17);
    else glColor3f(0.27, 0.32, 0.24);
	glVertex2i(220, 220);
	glVertex2i(150, 400);
	glVertex2i(300, 220);
	glEnd();
	glPopMatrix();
}

void Small_Hill_Model(){

///Small Hill
    glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(0.1, 0.47, 0.0);
    else glColor3f(0.11, 0.23, 0.32);
	glVertex2i(0, 220);
	glVertex2i(100, 330);
	glVertex2i(200, 220);
	glEnd();
	glPopMatrix();

	///Small Hill - Shadow
	glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(0.27, 0.50, 0.17);
    else glColor3f(0.19, 0.21, 0.24);
	glVertex2i(140, 220);
	glVertex2i(100, 330);
	glVertex2i(200, 220);
	glEnd();
	glPopMatrix();
}

void Hill_Big_One(){
    glPushMatrix();
    glTranslatef(30,0,0);
    big_hill_model();
    glPopMatrix();
}

void Hill_Big_Two(){
    glPushMatrix();
    glTranslatef(590,0,0);
    big_hill_model();
    glPopMatrix();
}

void Small_Hill_One()
{
    glPushMatrix();
    glTranslatef(-40,0,0);
    Small_Hill_Model();
    glPopMatrix();
}

void Small_Hill_Two()
{
    glPushMatrix();
    glTranslatef(500,0,0);
    Small_Hill_Model();
    glPopMatrix();
}

void Small_Hill_Three()
{
    glPushMatrix();
    glTranslatef(820,0,0);
    Small_Hill_Model();
    glPopMatrix();
}

///Tree Model
void Tree_Model()
{
    glPushMatrix();
    glScalef(0.6, 0.6, 0.6);
    glTranslatef(430, -230, 0);

    if(f)glColor3f(0.324, 0.793, 0.3);
    else glColor3f(0, 0.3, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    if(f) glColor3f(0.533, 1.293, 0);
    else glColor3f(0, 0.6, 0.3);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 370);
    glVertex2i(492, 460);
	glVertex2i(540, 370);
	glEnd();

	if(f) glColor3f(0.5, 0.3, 0);
	else glColor3f(0.3, 0.2, 0);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
}

void Tree_One(){

    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(70,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(140,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(270,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,-8,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-140,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-210,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-290,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-360,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-440,0,0);
    Tree_Model();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-510,0,0);
    Tree_Model();
    glPopMatrix();
}

void Tree_Two(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(-260,200,0);
    glScalef(1.2,1.2,1.2);
    Tree_Model();
    glPopMatrix();

    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(-420,200,0);
    glScalef(1.2,1.2,1.2);
    Tree_Model();
    glPopMatrix();

    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(-520,200,0);
    glScalef(1.2,1.2,1.2);
    Tree_Model();
    glPopMatrix();

    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(-100,200,0);
    glScalef(1.2,1.2,1.2);
    Tree_Model();
    glPopMatrix();

    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(-5,200,0);
    glScalef(1.2,1.2,1.2);
    Tree_Model();
    glPopMatrix();

    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(200,200,0);
    glScalef(1.2,1.2,1.2);
    Tree_Model();
    glPopMatrix();
}

///Circle
void circle(GLfloat x, GLfloat y, GLfloat rad){
    GLint triangle_amt=60;
    GLfloat t_pi = 2*PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0;i<=triangle_amt;i++){
        GLfloat dx=rad*cos(i*t_pi/triangle_amt), dy=rad*sin(i*t_pi/triangle_amt);
        ///cout<<"---"<<x<<" "<<y<<" "<<dx<<" "<<dy<<"---"<<endl;
        glVertex2f(x+dx,y+dy);
    }
    glEnd();
}

///Red car Model
void car1()
{
    glPushMatrix();
    glTranslatef(pos_car1, 0.0, 0.0);

    glPushMatrix();
    ///car roof
    glBegin(GL_POLYGON);
    if(f) glColor3ub(255, 64, 0);
    else glColor3ub(218, 43, 0);
    glVertex2f(640,170);
    glVertex2f(780,170);
    glVertex2f(740,200);
    glVertex2f(680,200);
    glEnd();

    ///car body
    glBegin(GL_POLYGON);
    if(f) glColor3ub(248, 43, 0);
    else glColor3ub(200, 13, 0);
    glVertex2f(640,140);
    glVertex2f(780,140);
    glVertex2f(780,170);
    glVertex2f(640,170);
    glEnd();

    ///Window_Front
    glBegin(GL_POLYGON);
    if(f) glColor3ub(204, 255, 204);
    else glColor3ub(225, 235, 0);
    glVertex2f(660,175);
    glVertex2f(700,175);
    glVertex2f(700,195);
    glVertex2f(680,195);
    glEnd();

    ///Window_Rear
    glBegin(GL_POLYGON);
    if(f) glColor3ub(204, 255, 204);
    else glColor3ub(225, 235, 0);
    glVertex2f(710,175);
    glVertex2f(760,175);
    glVertex2f(740,195);
    glVertex2f(710,195);
    glEnd();

    ///car 1st wheel
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    circle(675,140,15);

	glBegin(GL_POLYGON);
    glColor3ub(255, 200, 218);
    circle(675,140,4);

	///car 2nd wheel
	glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    circle(740,140,15);

    glBegin(GL_POLYGON);
    glColor3ub(255, 200, 218);
    circle(740,140,4);

    glPopMatrix();

    glPopMatrix();
}

///Blue car model

void car2()
{
    glPushMatrix();
    glTranslatef(pos_car2, 0.0, 0.0);

    glPushMatrix();
    ///car roof
    glBegin(GL_POLYGON);
    if(f) glColor3ub(0, 63, 254);
    else glColor3ub(0, 43, 238);
    glVertex2f(180,205);
    glVertex2f(290,205);
    glVertex2f(260,230);
    glVertex2f(210,230);
    glEnd();

    ///car body
    glBegin(GL_POLYGON);
    if(f) glColor3ub(0, 43, 248);
    else glColor3ub(0, 20, 218);
    glVertex2f(180,180);
    glVertex2f(290,180);
    glVertex2f(290,205);
    glVertex2f(180,205);
    glEnd();

    ///Window_Front
    glBegin(GL_POLYGON);
    if(f) glColor3ub(204, 255, 204);
    else glColor3ub(225, 235, 0);
    glVertex2f(275,210);
    glVertex2f(260,225);
    glVertex2f(240,225);
    glVertex2f(240,210);
    glEnd();

     ///Window_Rear
    glBegin(GL_POLYGON);
    if(f) glColor3ub(204, 255, 204);
    else glColor3ub(225, 235, 0);
    glVertex2f(195,210);
    glVertex2f(210,225);
    glVertex2f(230,225);
    glVertex2f(230,210);
    glEnd();

    ///car 1st wheel
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    circle(205,180,12);

	glBegin(GL_POLYGON);
    glColor3ub(255, 200, 218);
    circle(205,180,4);

	///car 2nd wheel
	glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    circle(265,180,12);

    glBegin(GL_POLYGON);
    glColor3ub(255, 200, 218);
    circle(265,180,4);

    glPopMatrix();

    glPopMatrix();
}

///Bushes Model

void Bush_Model(){

    if(f) glColor3f(0.533, 1.293, 0.0);
	else glColor3f(0.333,0.6,0.0);

    glPushMatrix();
    glTranslatef(430,90,0);
    circle(370,140,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420,88,0);
    circle(360,140,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,80,0);
    circle(375,160,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390,80,0);
    circle(370,145,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(430,80,0);
    circle(385,145,10);
    glPopMatrix();

}

void Bush_One()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Two()
{
    glPushMatrix();
    glTranslatef(-120,0,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Three()
{
    glPushMatrix();
    glTranslatef(-230,0,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Four()
{
    glPushMatrix();
    glTranslatef(-400,0,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Five()
{
    glPushMatrix();
    glTranslatef(-650,0,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Six()
{
    glPushMatrix();
    glTranslatef(180,0,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Seven()
{
    glPushMatrix();
    glTranslatef(-520,0,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Eight()
{
    glPushMatrix();
    glTranslatef(-350,0,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Nine()
{
    glPushMatrix();
    glTranslatef(180,-150,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Ten()
{
    glPushMatrix();
    glTranslatef(-100,-150,0);
    Bush_Model();
    glPopMatrix();
}

void Bush_Eleven()
{
    glPushMatrix();
    glTranslatef(-200,-150,0);
    Bush_Model();
    glPopMatrix();
}

///Houses Model

void house_model(){
    ///Roof
    glPushMatrix();
	glBegin(GL_POLYGON);
	if(f) glColor3f(.99, 0.0, 0.0);
    else glColor3f(.790, 0.0, 0.0);
	glVertex2i(285, 270);
	glVertex2i(285, 280);
	glVertex2i(380, 295);
	glVertex2i(380, 270);
	glEnd();
	glPopMatrix();

    ///Roof_Shadow
    glPushMatrix();
	glBegin(GL_POLYGON);
	if(f) glColor3f(.790, 0.0, 0.0);
    else glColor3f(.590, 0.0, 0.0);
	glVertex2i(285, 270);
	glVertex2i(285, 275);
	glVertex2i(380, 290);
	glVertex2i(380, 270);
	glEnd();
	glPopMatrix();

    ///Wall
    glPushMatrix();
	glBegin(GL_POLYGON);
	if(f) glColor3f(0.86, 0.82, 0.96);
    else glColor3f(.80, 0.78, 0.76);
	glVertex2i(290, 220);
	glVertex2i(290, 270);
	glVertex2i(375, 270);
	glVertex2i(375, 220);
	glEnd();
	glPopMatrix();

    ///Wall_Shadow
    glPushMatrix();
	glBegin(GL_POLYGON);
	if(f) glColor3f(0.76, 0.78, 0.80);
    else glColor3f(.79, 0.74, 0.69);
	glVertex2i(290, 220);
	glVertex2i(290, 270);
	glVertex2i(365, 270);
	glVertex2i(365, 220);
	glEnd();
	glPopMatrix();

    ///Door
    glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(0.56, 0.21, 0.16);
    else glColor3f(0.56, 0.34, 0.23);
	glVertex2i(325, 220);
	glVertex2i(325, 250);
	glVertex2i(340, 250);
	glVertex2i(340, 220);
	glEnd();
	glPopMatrix();

    ///Window1 (Left)
    glPushMatrix();
	glBegin(GL_POLYGON);
    if(f)glColor3f(0.13, 0.17, 0.38);
    else glColor3f(0.88, 0.86, 0.0);
	glVertex2i(295, 250);
	glVertex2i(295, 265);
	glVertex2i(310, 265);
	glVertex2i(310, 250);
	glPopMatrix();
	glEnd();
	glPopMatrix();

    ///Window2 (Right)
    glPushMatrix();
	glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    if(f)glColor3f(0.13, 0.17, 0.38);
    else glColor3f(0.88, 0.86, 0.0);
	glVertex2i(355, 250);
	glVertex2i(355, 265);
	glVertex2i(370, 265);
	glVertex2i(370, 250);
	glEnd();
	glPopMatrix();

	///Window2_reflection
	glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(0.21, 0.43, 0.56);
    else glColor3f(0.78, 0.76, 0.10);
	glVertex2i(365, 250);
	glVertex2i(365, 265);
	glVertex2i(370, 265);
	glVertex2i(370, 250);
	glEnd();
	glPopMatrix();

    ///House_Small_Roof
    glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(.790, 0.0, 0.0);
    else glColor3f(.590,0.0,0.0);
	glVertex2i(250, 240);
	glVertex2i(257, 255);
	glVertex2i(290, 255);
	glVertex2i(290, 240);
	glEnd();
	glPopMatrix();

    ///House_Small_Wall
    glPushMatrix();
	glBegin(GL_POLYGON);
    if(f) glColor3f(.555, .724, .930);
    else glColor3f(.555, .524, .830);
	glVertex2i(255, 220);
	glVertex2i(255, 240);
	glVertex2i(290, 240);
	glVertex2i(290, 220);
	glEnd();
	glPopMatrix();

    ///House_Small_Door
    glPushMatrix();
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(270, 220);
	glVertex2i(270, 230);
	glVertex2i(280, 230);
	glVertex2i(280, 220);
	glEnd();
    glPopMatrix();
}

void House_One()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    house_model();
    glPopMatrix();
}

void House_Two()
{
    glPushMatrix();
    glTranslatef(180,0,0);
    house_model();
    glPopMatrix();
}

void House_Three()
{
    glPushMatrix();
    glTranslatef(-250,0,0);
    house_model();
    glPopMatrix();
}

void House_Four()
{
    glPushMatrix();
    glTranslatef(700,0,0);
    house_model();
    glPopMatrix();
}

void House_Five()
{
    glPushMatrix();
    glTranslatef(400,0,0);
    house_model();
    glPopMatrix();
}

///Windmill_Stand///
void Windmill_Stand_Model(){

    if(f) glColor3f(0.98, 0.87, 0.78);
    else glColor3f(0.86, 0.83, 0.75);
    glBegin(GL_POLYGON);
    glVertex2i(375, 70);
    glVertex2i(380, 320);
    glVertex2i(384, 320);
    glVertex2i(390, 70);
    glEnd();
}

/// Windmill_Blades///

void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    //spin +=2;
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
   glPushMatrix();
    glRotatef(spin,0,0,90);
    //spin +=2;
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    //spin +=2;
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();
}
///Overall Windmill Form///

void Windmill(){

    ///Windmill_Stand
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    if(f) glColor3f(0.96, 0.87, 0.98);
    else glColor3f(0.84,0.79,0.87);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(2,70,10);
    glPopMatrix();

    ///Windmill_Blades
    if (f) glColor3f(0.96, 0.87, 0.98);
    else glColor3f(0.84,0.79,0.87);
    glPushMatrix();
    glTranslatef(380,320,0);
    Windmill_Blade();
    glPopMatrix();

}

void Windmill_One(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0,-10,0);
    Windmill();
    glPopMatrix();
}

void Windmill_Two(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,-60,0);
    Windmill();
    glPopMatrix();

}
void Windmill_Three(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(220,-30,0);
    Windmill();
    glPopMatrix();
}

void Windmill_Four()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(-220,-10,0);
    Windmill();
    glPopMatrix();
}

///Cloud Model-1 Structure
void cloudModel1(){
    if(f)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(320,210,15);///Left
    circle(340,225,16);///Top
    circle(360,210,16);///Right
    ///Bottom
    circle(330, 210, 16);
    circle(340, 210, 16);
    circle(350, 210, 16);

    glPopMatrix();

}
///Cloud Model-2 Structure
void cloudModel2(){
    if(f)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();
}
///Cloud Model-3 Structure
void cloudModel3(){

    glColor3f(1.25,0.924,0.930);

    glPushMatrix();
    circle(300,200,15);///Left
    circle(320,210,15);///Top_Left
    circle(340,220,16);///Top
    circle(360, 210, 15);///Top_Right
    circle(380,200,15);///Right
    circle(360,190,20);///Bottom_Right
    circle(320,190,20);///Bottom_Left
    circle(340,190,20);///Bottom
    glPopMatrix();
}

///Sky
/*void sky(){
    glPushMatrix();
    if(f)glColor3ub(157, 216, 250);
    else glColor3ub(4, 11, 51);
    glBegin(GL_POLYGON);
    glVertex2i(0,350);
    glVertex2i(1000,350);
    glVertex2i(1000,500);
    glVertex2i(0,500);
    glEnd();
    glPopMatrix();
}
*/

///Sun
void sun(){
    if(f){
        glPushMatrix();
        glColor3ub(252, 212, 64);
        glTranslatef(sun_x,sun_y,0.0);
        circle(0,0,30);
        glPopMatrix();
    }
}
///Moon
void moon(){
    if(!f){
        glPushMatrix();
        glColor3ub(255, 136, 18);
        circle(620,400,30);
        glColor3ub(4, 11, 51);
        circle(630,420,30);
        glPopMatrix();
    }
}
///Stars
void star(){
    if(!f){
        glPushMatrix();
        glColor3ub(255,255,255);
        glPointSize(4);
        glBegin(GL_POINTS);

        glVertex2i(100,400);
        glVertex2i(120,420);
        glVertex2i(150,450);
        glVertex2i(170,470);
        glVertex2i(200,430);
        glVertex2i(230,470);
        glVertex2i(350,460);
        glVertex2i(900,400);
        glVertex2i(580,470);
        glVertex2i(840,460);
        glVertex2i(750,400);
        glVertex2i(950,400);
        glVertex2i(760,420);
        glVertex2i(690,450);
        glVertex2i(550,470);
        glVertex2i(790,430);
        glVertex2i(830,470);
        glVertex2i(690,460);
        glVertex2i(590,400);
        glVertex2i(490,430);
        glVertex2i(330,470);
        glVertex2i(390,460);
        glVertex2i(460,400);
        glVertex2i(490,450);
        glVertex2i(30,470);
        glVertex2i(390,360);
        glVertex2i(460,300);
        glVertex2i(400,430);
        glVertex2i(930,370);
        glVertex2i(990,360);
        glVertex2i(960,300);
        glVertex2i(460,420);
        glVertex2i(220,370);
        glVertex2i(30,370);
        glVertex2i(290,360);
        glVertex2i(240,380);
        glVertex2i(700,450);
        glVertex2i(90,430);
        glVertex2i(600,370);
        glVertex2i(590,360);
        glVertex2i(540,300);
        //glVertex2i(570,200);
        //glVertex2i(600,230);
        //glVertex2i(630,270);
        //glVertex2i(590,260);
        //glVertex2i(680,200);
        glEnd();
        glPopMatrix();
    }
}

///cloud1
void cloud1(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos1,170,0);
        cloudModel1();
        glPopMatrix();
    }
}
///cloud2
void cloud2(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos2,270,0);
        cloudModel2();
        glPopMatrix();
    }
}
///cloud3
void cloud3(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos3,200,0);
        cloudModel3();
        glPopMatrix();
    }
}
///cloud4
void cloud4(){
    glPushMatrix();
    glTranslatef(cpos4,250,0);
    cloudModel2();
    glPopMatrix();
}

///cloud5
void cloud5(){
    glPushMatrix();
    glTranslatef(cpos5,220,0);
    cloudModel1();
    glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0,0.0,1.0);

	Field();
    Road();

    Hill_Big_One();
    Hill_Big_Two();
    Small_Hill_One();
    Small_Hill_Two();
    Small_Hill_Three();

    Bush_One();
    Bush_Two();
    Bush_Three();
    Bush_Five();
    Bush_Six();
    Bush_Seven();
    Bush_Eight();

    House_One();
    House_Two();
    House_Three();
    House_Five();
    House_Four();
    Bush_Four();
    Tree_Two();

    Field2();

    car2();
    car1();
    Windmill_One();
    Windmill_Two();
    Windmill_Three();
    Windmill_Four();

    Tree_One();

    //sky();
	star();
	sun();
    moon();
    cloud1();
    cloud2();
    cloud3();
    cloud4();
    cloud5();
	glFlush();
	glutSwapBuffers();
}

void night()
{
    if(!f){
        glClearColor(4.0f/255.0f,11.0/255.0f,51.0/255.0f,0.0);
    }
    /*else{
        glClearColor(157.0f/255.0f, 216.0f/255.0f, 250.0f/255.0f, 1.0);
    }*/
    glFlush();
}

void update(int value){

    ///Cloud Control
    if(cpos1>750)cpos1=-320;
    if(cpos2<-350)cpos2=650;
    if(cpos3>750)cpos3=-320;
    if(cpos4>750)cpos4=-320;
    if(cpos5<-350)cpos5=650;
    cpos1+=sp1;
    cpos2-=sp1;
    cpos3+=sp1;
    cpos4+=sp1;
    cpos5-=sp1;
    ///Sun Control
    if(sun_y>480){
        sun_x=650;
        sun_y=360;
        f=0;
        night();
    }

    sun_x-=sp_x;
    sun_y+=sp_y;

    glutTimerFunc(100, update, 0);
    glutPostRedisplay();
}


void moving_car1(int value)
{
    if (pos_car1 < -1000)
        pos_car1 = 500;

    pos_car1 -= car1_speed;
    glutPostRedisplay();
    glutTimerFunc(10, moving_car1, 0);
}

void moving_car2(int value)
{
    if (pos_car2 > 1100)
        pos_car2 = -200;

    pos_car2 += car2_speed;
    glutPostRedisplay();
    glutTimerFunc(40, moving_car2, 0);
}




//controlling windmill movement
bool wind = true;
void windmill_movement()
{
    if(wind)
        spin +=.3;

    else if(!wind)
        spin -=.2;
    else
        spin = 0.0;

    glutIdleFunc(windmill_movement);
    glutPostRedisplay();
}

float _rain = 0.0f;
bool rainday = false;
void Rain(int value)
{
    if (rainday)
    {
        _rain += 0.01f;

        glBegin(GL_POINTS);
        for (int i = 1; i <= 1000; i++)
        {
            int x = rand(), y = rand();
            x %= 1000;
            y %= 500;
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(x, y);
            glVertex2d(x + 3, y + 3);
            glEnd();
        }

        glutPostRedisplay();
        glutTimerFunc(5, Rain, 0);
        glFlush();
    }
}

void mouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            wind = true;
            glutIdleFunc(windmill_movement); ///anti-clockwise rotation
        }
        break;

    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            wind = false;
            glutIdleFunc(windmill_movement); ///clockwise rotation
        }
        break;
    default:
        break;
    }
}

void handleKeypress(unsigned char key, int x, int y){
	switch (key){

	     ///Switch Day and Night Modes
        case 'd':
            f=1;
            glClearColor(157.0f/255.0f, 216.0f/255.0f, 250.0f/255.0f, 1.0);
            break;
        case 'n':
            f=0;
            glutIdleFunc(night);
            break;

            ///Rain controls
        case 'a':
            rainday = true;
            Rain(_rain);
            break;
        case 'c':
            rainday = false;
            break;

	///red car controls
	    case 'f':
        car1_speed += 1;
        break;

        case 'b':
        car1_speed -= 1 ;
        break;

        case 'h':
        car1_speed = 0;
        break;

    ///blue car controls
        case 'x':
        car2_speed += 3;
        break;

        case 'y':
        car2_speed -= 3 ;
        break;

        case 'z':
        car2_speed = 0;
        break;

	    ///Windmill controls
        case 'l':
            wind = true;
            glutIdleFunc(windmill_movement);
            break;
        case 'r':
            wind = false;
            glutIdleFunc(windmill_movement);
            break;
        case 's':
            glutIdleFunc(NULL);
            break;

        glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
    cout<<"/////***CG PROJECT: WINDMILL COUNTRYSIDE***/////\n"<<endl;

    cout << "///// SCENE CONTROLS /////" << endl;
    cout << "Press 'N' to switch to night mode." << endl;
    cout << "Press 'D' to switch to day mode." << endl;
    cout << "Press 'A' to start raining." << endl;
    cout << "Press 'C' to stop raining.\n" << endl;

    cout << "///// RED CAR CONTROLS /////" << endl;
    cout << "Press 'F' to speed up car." << endl;
    cout << "Press 'B' to slow down car." << endl;
    cout << "Press 'H' to stop the car." << endl;
    cout << "Press 'B' to go backwards.\n" << endl;

    cout << "///// BLUE CAR CONTROLS /////" << endl;
    cout << "Press 'X' to speed up car." << endl;
    cout << "Press 'Y' to slow car." << endl;
    cout << "Press 'Z' to stop the car." << endl;
    cout << "Press 'Y' to go backwards.\n" << endl;

    cout << "///// WINDMILL CONTROLS //////" << endl;
    cout << "Press 'L' or left click for anticlockwise rotation." << endl;
    cout << "Press 'R' or right click for clockwise rotation." << endl;
    cout << "Press 'S' to stop movement." << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("WINDMILL COUNTRYSIDE");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(mouse);
    glutTimerFunc(1000, update, 0);
    glutTimerFunc(1000, moving_car1, 0);
    glutTimerFunc(1000, moving_car2, 0);
	glutMainLoop();
}
