#include <GL/gl.h>
#include<iostream>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;

#define PI 3.141592653589
GLfloat cloud1Position=0;
GLfloat cloud1speed=1.4;
GLfloat cloud2Position=0;
GLfloat cloud2speed=1.8;
GLfloat cloud3Position=0;
GLfloat cloud3speed=1.6;
GLfloat sunXAxis=0;
GLfloat sunspeed=0.2;
GLfloat ambulancePosition=0;
GLfloat ambulacespeed=2.8;
GLfloat doctorPosition=0;
GLfloat doctorspeed=0.4;
GLfloat humanPosition1=0;
GLfloat humanspeed=0.1;
GLfloat humanPosition2=0;
GLfloat humanPosition3=0;
GLfloat humanPosition4=0;
GLfloat humanPosition5=0;
GLfloat humanPosition=0;
GLfloat policecarPosition1=0;
GLfloat policecarPosition2=0;
GLfloat policecarspeed=2.3;

// Function to Print Text
void print(char *string,
	GLfloat r, GLfloat g, GLfloat b, GLfloat a,
	GLint x, GLint y,
	GLfloat w, GLfloat h,
	GLfloat strokeSize) {
	glPushMatrix();

	glColor4f(r, g, b, a);
	glTranslatef(x, y, 0);
	glScalef(w, h, 0);

	glPointSize(strokeSize);
	glLineWidth(strokeSize);

	while (*string)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *string++);

	glPopMatrix();

	glLineWidth(1);
	glPointSize(1);
}

void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx, GLfloat sy,
	GLfloat radius) {
		glPushMatrix();

		glTranslatef(x, y, 0);
		glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
		glColor3ub(r, g, b);
    for (GLfloat i = 0; i < 360; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

		glPopMatrix();
}

// Function to Draw Circle
void drawSemiCircle(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat radius,
	GLfloat start_angle, GLfloat end_angle) {
		glPushMatrix();

		glTranslatef(tx, ty, 0);
		glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
		glColor3ub(r, g, b);
    for (GLfloat i = start_angle; i < end_angle; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

		glPopMatrix();
}


//Building
void building(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    double r1 = 102;
    double g1 = 178;
    double b1 = 255;

    glBegin(GL_QUADS);
    glColor3ub (204,204,255);
    glVertex2i(0,160);
    glVertex2i(100,160);
    glVertex2i(100,310);
    glVertex2i(0,310);
    //2
    glVertex2i(172,290);
    glVertex2i(200,290);
    glVertex2i(200,270);
    glVertex2i(172,270);

    glVertex2i(280,160);
    glVertex2i(295,160);
    glVertex2i(295,280);
    glVertex2i(280,280);

    glVertex2i(305,160);
    glVertex2i(295,160);
    glVertex2i(295,270);
    glVertex2i(305,270);

    glVertex2i(305,160);
    glVertex2i(360,160);
    glVertex2i(360,320);
    glVertex2i(305,320);
    //3
    glVertex2i(420,160);
    glVertex2i(470,160);
    glVertex2i(470,320);
    glVertex2i(425,320);

    //4
    glVertex2i(620,160);
    glVertex2i(690,160);
    glVertex2i(690,300);
    glVertex2i(620,300);

    glVertex2i(690,160);
    glVertex2i(710,160);
    glVertex2i(710,250);
    glVertex2i(690,250);

    glVertex2i(760,160);
    glVertex2i(710,160);
    glVertex2i(710,330);
    glVertex2i(760,330);
    glEnd();
    //2nd layer
    glBegin(GL_QUADS);
    glColor3ub (180,180,180);
    //1
    glVertex2i(152,220);
    glVertex2i(72,220);
    glVertex2i(72,290);
    glVertex2i(152,290);

    glVertex2i(142,310); //from roof
    glVertex2i(82,310);
    glVertex2i(82,290);
    glVertex2i(142,290);

    glVertex2i(137,310);
    glVertex2i(87,310);
    glVertex2i(87,315);
    glVertex2i(137,315);

    glVertex2i(127,320);
    glVertex2i(97,320);
    glVertex2i(97,315);
    glVertex2i(127,315);

    //3
    glVertex2i(280,160);
    glVertex2i(200,160);
    glVertex2i(200,290);
    glVertex2i(280,290);

    glVertex2i(270,320);
    glVertex2i(210,320);
    glVertex2i(210,290);
    glVertex2i(270,290);
    //5
    glVertex2i(440,300);
    glVertex2i(360,300);
    glVertex2i(360,160);
    glVertex2i(440,160);


    //2
    glColor3ub (200,200,200); //light one
    glVertex2i(152,160);
    glVertex2i(200,160);
    glVertex2i(200,270);
    glVertex2i(152,270);

    //4
    glVertex2i(280,250);
    glVertex2i(360,250);
    glVertex2i(360,160);
    glVertex2i(280,160);

    glEnd();

    //1st layer
    glColor3ub (132,132,132);
    glBegin(GL_QUADS);
    //1
    glVertex2i(0,160);
    glVertex2i(40,160);
    glVertex2i(40,230);
    glVertex2i(0,230);

    //2
    glVertex2i(45,160);
    glVertex2i(92,160);
    glVertex2i(92,265);
    glVertex2i(45,265);

    //3
    glVertex2i(87,160);
    glVertex2i(160,160);
    glVertex2i(160,220);
    glVertex2i(87,220);

    glVertex2i(160,160);
    glVertex2i(190,160);
    glVertex2i(190,190);
    glVertex2i(160,190);

    glVertex2i(190,160);
    glVertex2i(200,160);
    glVertex2i(200,165);
    glVertex2i(190,165);
    //4
    glVertex2i(200,160);
    glVertex2i(230,160);
    glVertex2i(230,220);
    glVertex2i(200,220);

    glVertex2i(230,160);
    glVertex2i(235,160);
    glVertex2i(235,205);
    glVertex2i(230,205);

    glVertex2i(235,160);
    glVertex2i(255,160);
    glVertex2i(255,190);
    glVertex2i(235,190);

    //5
    glVertex2i(260,160);
    glVertex2i(310,160);
    glVertex2i(310,200);
    glVertex2i(260,200);
    //6
    glVertex2i(310,160);
    glVertex2i(380,160);
    glVertex2i(380,230);
    glVertex2i(310,230);

    glVertex2i(400,160);
    glVertex2i(380,160);
    glVertex2i(380,200);
    glVertex2i(400,200);
    //7
    glVertex2i(410,160);
    glVertex2i(470,160);
    glVertex2i(470,240);
    glVertex2i(410,240);
    //8
    glVertex2i(477,305);
    glVertex2i(513,305);
    glVertex2i(513,285);
    glVertex2i(477,285);

    glVertex2i(482,305);
    glVertex2i(507,305);
    glVertex2i(507,310);
    glVertex2i(482,310);

    glVertex2i(487,310);
    glVertex2i(502,310);
    glVertex2i(502,315);
    glVertex2i(487,315);

    glVertex2i(492,310);
    glVertex2i(498,310);
    glVertex2i(498,330);
    glVertex2i(492,330);

    //9
    glVertex2i(590,160);
    glVertex2i(650,160);
    glVertex2i(650,280);
    glVertex2i(590,280);

    glVertex2i(760,160);
    glVertex2i(670,160);
    glVertex2i(670,220);
    glVertex2i(760,220);


    //roof
    glColor3ub (112,112,112);
    //1
    glVertex2i(0,230);
    glVertex2i(40,230);
    glVertex2i(40,235);
    glVertex2i(0,235);

    glVertex2i(10,235);
    glVertex2i(30,235);
    glVertex2i(30,240);
    glVertex2i(10,240);

    //2
    glVertex2i(48,270);
    glVertex2i(87,270);
    glVertex2i(87,275);
    glVertex2i(48,275);

    glVertex2i(52,275);
    glVertex2i(70,275);
    glVertex2i(70,280);
    glVertex2i(52,280);

    //3
    glVertex2i(87,220);
    glVertex2i(157,220);
    glVertex2i(157,225);
    glVertex2i(87,225);

    glVertex2i(87,190);
    glVertex2i(160,190);
    glVertex2i(160,200);
    glVertex2i(87,200);
    //4
    glVertex2i(200,220);
    glVertex2i(230,220);
    glVertex2i(230,225);
    glVertex2i(200,225);

    glVertex2i(235,190);
    glVertex2i(255,190);
    glVertex2i(255,195);
    glVertex2i(235,195);

    //5
    glVertex2i(260,200);
    glVertex2i(310,200);
    glVertex2i(310,205);
    glVertex2i(260,205);

    glVertex2i(255,205);
    glVertex2i(310,205);
    glVertex2i(310,210);
    glVertex2i(255,210);
    //6
    glVertex2i(310,230);
    glVertex2i(380,230);
    glVertex2i(380,240);
    glVertex2i(310,240);

    glVertex2i(315,215);
    glVertex2i(325,215);
    glVertex2i(325,220);
    glVertex2i(315,220);

    glVertex2i(335,215);
    glVertex2i(345,215);
    glVertex2i(345,220);
    glVertex2i(335,220);

    glVertex2i(355,215);
    glVertex2i(365,215);
    glVertex2i(365,220);
    glVertex2i(355,220);

    glVertex2i(315,185);
    glVertex2i(335,185);
    glVertex2i(335,188);
    glVertex2i(315,188);

    glVertex2i(345,185);
    glVertex2i(365,185);
    glVertex2i(365,188);
    glVertex2i(345,188);
    //7
    glVertex2i(410,240);
    glVertex2i(470,240);
    glVertex2i(470,245);
    glVertex2i(410,245);
    //9
    glVertex2i(760,225);
    glVertex2i(670,225);
    glVertex2i(670,220);
    glVertex2i(760,220);

    glVertex2i(675,210);
    glVertex2i(760,210);
    glVertex2i(760,205);
    glVertex2i(675,205);

    //yellow
    glColor3ub (255,255,51);
    glVertex2i(270,190);
    glVertex2i(305,190);
    glVertex2i(305,193);
    glVertex2i(270,193);




    //shades
    //2
    glColor3ub (200,200,200);
    glVertex2i(48,265);
    glVertex2i(87,265);
    glVertex2i(87,270);
    glVertex2i(48,270);

    glVertex2i(50,160);
    glVertex2i(57,160);
    glVertex2i(57,255);
    glVertex2i(50,255);

    glVertex2i(65,160);
    glVertex2i(72,160);
    glVertex2i(72,255);
    glVertex2i(65,255);

    glVertex2i(80,160);
    glVertex2i(87,160);
    glVertex2i(87,255);
    glVertex2i(80,255);
    //8
    glColor3ub (180,180,180);
    glVertex2i(470,160);
    glVertex2i(530,160);
    glVertex2i(530,245);
    glVertex2i(470,245);

    glVertex2i(450,280);
    glVertex2i(540,280);
    glVertex2i(540,245);
    glVertex2i(450,245);

    glColor3ub (210,210,210);
    glVertex2i(455,280);
    glVertex2i(535,280);
    glVertex2i(535,285);
    glVertex2i(455,285);

    glVertex2i(470,240);
    glVertex2i(540,240);
    glVertex2i(540,245);
    glVertex2i(470,245);
    //9
    glColor3ub (160,160,160);
    glVertex2i(590,160);
    glVertex2i(530,160);
    glVertex2i(530,295);
    glVertex2i(590,295);

    glVertex2i(610,160);
    glVertex2i(670,160);
    glVertex2i(670,260);
    glVertex2i(610,260);


    //window and door
    //1
    glColor3ub (r1,g1,b1);
    glVertex2i(12,160);
    glVertex2i(26,160);
    glVertex2i(26,180);
    glVertex2i(12,180);

    glVertex2i(5,190);
    glVertex2i(12,190);
    glVertex2i(12,200);
    glVertex2i(5,200);

    glVertex2i(15,190);
    glVertex2i(22,190);
    glVertex2i(22,200);
    glVertex2i(15,200);

    glVertex2i(25,190);
    glVertex2i(32,190);
    glVertex2i(32,200);
    glVertex2i(25,200);

    glVertex2i(5,210);
    glVertex2i(12,210);
    glVertex2i(12,220);
    glVertex2i(5,220);

    glVertex2i(15,210);
    glVertex2i(22,210);
    glVertex2i(22,220);
    glVertex2i(15,220);

    glVertex2i(25,210);
    glVertex2i(32,210);
    glVertex2i(32,220);
    glVertex2i(25,220);

    //3
    glVertex2i(95,205);
    glVertex2i(110,205);
    glVertex2i(110,215);
    glVertex2i(95,215);

    glVertex2i(130,205);
    glVertex2i(145,205);
    glVertex2i(145,215);
    glVertex2i(130,215);

    glVertex2i(95,185);
    glVertex2i(110,185);
    glVertex2i(110,170);
    glVertex2i(95,170);

    glVertex2i(130,185);
    glVertex2i(145,185);
    glVertex2i(145,170);
    glVertex2i(130,170);

    glVertex2i(165,160);
    glVertex2i(180,160);
    glVertex2i(180,180);
    glVertex2i(165,180);
    //4
    glVertex2i(205,215);
    glVertex2i(215,215);
    glVertex2i(215,205);
    glVertex2i(205,205);

    glVertex2i(218,215);
    glVertex2i(228,215);
    glVertex2i(228,205);
    glVertex2i(218,205);

    glVertex2i(205,200);
    glVertex2i(215,200);
    glVertex2i(215,190);
    glVertex2i(205,190);

    glVertex2i(218,200);
    glVertex2i(228,200);
    glVertex2i(228,190);
    glVertex2i(218,190);

    glVertex2i(205,185);
    glVertex2i(210,185);
    glVertex2i(210,177);
    glVertex2i(205,177);

    glVertex2i(215,185);
    glVertex2i(220,185);
    glVertex2i(220,177);
    glVertex2i(215,177);

    glVertex2i(225,185);
    glVertex2i(230,185);
    glVertex2i(230,177);
    glVertex2i(225,177);

    //5
    glVertex2i(270,190);
    glVertex2i(285,190);
    glVertex2i(285,175);
    glVertex2i(270,175);

    glVertex2i(290,190);
    glVertex2i(305,190);
    glVertex2i(305,175);
    glVertex2i(290,175);

    glColor3ub (255,255,51);
    glVertex2i(270,190);
    glVertex2i(305,190);
    glVertex2i(305,193);
    glVertex2i(270,193);
    //6
    glColor3ub (r1,g1,b1);
    glVertex2i(315,215);
    glVertex2i(325,215);
    glVertex2i(325,195);
    glVertex2i(315,195);

    glVertex2i(335,215);
    glVertex2i(345,215);
    glVertex2i(345,195);
    glVertex2i(335,195);

    glVertex2i(355,215);
    glVertex2i(365,215);
    glVertex2i(365,195);
    glVertex2i(355,195);

    glVertex2i(315,185);
    glVertex2i(335,185);
    glVertex2i(335,170);
    glVertex2i(315,170);

    glVertex2i(345,185);
    glVertex2i(365,185);
    glVertex2i(365,170);
    glVertex2i(345,170);

    glVertex2i(385,170);
    glVertex2i(395,170);
    glVertex2i(395,180);
    glVertex2i(385,180);

    glVertex2i(382,185);
    glVertex2i(392,185);
    glVertex2i(392,195);
    glVertex2i(382,195);

    //7
    glVertex2i(420,230);
    glVertex2i(430,230);
    glVertex2i(430,210);
    glVertex2i(420,210);

    glVertex2i(450,230);
    glVertex2i(460,230);
    glVertex2i(460,210);
    glVertex2i(450,210);

    glVertex2i(420,200);
    glVertex2i(430,200);
    glVertex2i(430,180);
    glVertex2i(420,180);

    glVertex2i(450,200);
    glVertex2i(460,200);
    glVertex2i(460,180);
    glVertex2i(450,180);
    //8
    glVertex2i(502,295);
    glVertex2i(507,295);
    glVertex2i(507,287);
    glVertex2i(502,287);

    glVertex2i(492,295);
    glVertex2i(497,295);
    glVertex2i(497,287);
    glVertex2i(492,287);

    glVertex2i(482,295);
    glVertex2i(487,295);
    glVertex2i(487,287);
    glVertex2i(482,287);

    glVertex2i(460,270);
    glVertex2i(490,270);
    glVertex2i(490,260);
    glVertex2i(460,260);

    glVertex2i(500,270);
    glVertex2i(530,270);
    glVertex2i(530,260);
    glVertex2i(500,260);

    glColor3ub (112,112,112);
    glVertex2i(480,240);
    glVertex2i(483,240);
    glVertex2i(483,160);
    glVertex2i(480,160);

    glVertex2i(490,240);
    glVertex2i(493,240);
    glVertex2i(493,160);
    glVertex2i(490,160);

    glVertex2i(500,240);
    glVertex2i(503,240);
    glVertex2i(503,160);
    glVertex2i(500,160);

    glVertex2i(510,240);
    glVertex2i(513,240);
    glVertex2i(513,160);
    glVertex2i(510,160);


    //9
    glColor3ub (r1,g1,b1);
    glVertex2i(620,175);
    glVertex2i(635,175);
    glVertex2i(635,195);
    glVertex2i(620,195);

    glVertex2i(660,175);
    glVertex2i(645,175);
    glVertex2i(645,195);
    glVertex2i(660,195);

    glVertex2i(620,205);
    glVertex2i(635,205);
    glVertex2i(635,200);
    glVertex2i(620,200);

    glVertex2i(660,205);
    glVertex2i(645,205);
    glVertex2i(645,200);
    glVertex2i(660,200);

    glVertex2i(620,210);
    glVertex2i(635,210);
    glVertex2i(635,235);
    glVertex2i(620,235);

    glVertex2i(660,210);
    glVertex2i(645,210);
    glVertex2i(645,235);
    glVertex2i(660,235);

    glVertex2i(552,280);
    glVertex2i(570,280);
    glVertex2i(570,250);
    glVertex2i(552,250);

    glVertex2i(552,240);
    glVertex2i(570,240);
    glVertex2i(570,210);
    glVertex2i(552,210);

    glVertex2i(552,200);
    glVertex2i(570,200);
    glVertex2i(570,170);
    glVertex2i(552,170);

    glVertex2i(680,175);
    glVertex2i(700,175);
    glVertex2i(700,205);
    glVertex2i(680,205);

    glVertex2i(725,175);
    glVertex2i(705,175);
    glVertex2i(705,205);
    glVertex2i(725,205);

    glVertex2i(730,175);
    glVertex2i(750,175);
    glVertex2i(750,205);
    glVertex2i(730,205);

    //2nd layer
    //4
    glColor3ub (r1,g1,b1);
    glVertex2i(290,240);
    glVertex2i(300,240);
    glVertex2i(300,230);
    glVertex2i(290,230);

    glVertex2i(290,220);
    glVertex2i(300,220);
    glVertex2i(300,210);
    glVertex2i(290,210);
    //5
    glVertex2i(435,295);
    glVertex2i(420,295);
    glVertex2i(420,245);
    glVertex2i(435,245);

    glVertex2i(400,295);
    glVertex2i(415,295);
    glVertex2i(415,245);
    glVertex2i(400,245);
    glEnd();
    glPopMatrix();
}

void drawHumamsShirtAndTrousers(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Bottom Shirt
	glColor3ub(shirt_r, shirt_g, shirt_b);
	glBegin(GL_POLYGON);
	glVertex2f(0, 20);
	glVertex2f(100, 20);
	glVertex2f(100, 100);
	glVertex2f(0, 100);
	glEnd();

	// Top Shirt
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(135, 105);
	glVertex2f(120, 175);
	glVertex2f(100, 200);
	glVertex2f(50, 180);
	glVertex2f(0, 200);
	glVertex2f(-20, 175);
	glVertex2f(-35, 105);
	glVertex2f(0, 100);
	glEnd();

	// Left Trouser
	glColor3ub(37, 107, 202);
	glBegin(GL_POLYGON);
	glVertex2f(0, 25);
	glVertex2f(0, -100);
	glVertex2f(35, -100);
	glVertex2f(65, 25);
	glEnd();

	// Right Trouser
	glBegin(GL_POLYGON);
	glVertex2f(35, 25);
	glVertex2f(65, -100);
	glVertex2f(100, -100);
	glVertex2f(100, 25);
	glEnd();

	glPopMatrix();
}

void drawHumam(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	drawSemiCircle(-1, -35, .6, 1,
		203, 166, 108,
		20, -90, 90);

	// Face
  drawCircle(0, 0,
		232, 190, 123,
		1, 1,
		24);

	// Left Eye
	drawCircle(-8, 0,
		250, 250, 250,
		1, 1,
		4);
	drawCircle(-6, 0,
		10, 10, 10,
		1, 1,
		2);

	// Right Eye
	drawCircle(8, 0,
		250, 250, 250,
		1, 1,
		4);
	drawCircle(10, 0,
		10, 10, 10,
		1, 1,
		2);




	// Cap
	drawSemiCircle(0, 10, 1, 1,
		0, 0, 0,
		24, -90, 90);



		//mask
	drawSemiCircle(0, 0, 1, 1,
		0, 200, 250,
		24, 90, 270);

	// Hands
	drawCircle(-42, -82,
		232, 190, 123,
		1, 1,
		10);
	drawCircle(38, -82,
		232, 190, 123,
		1, 1,
		10);

	// Shirt and Trousers
	drawHumamsShirtAndTrousers(-32, -125,
		.6, .5,
		shirt_r, shirt_g, shirt_b);

	// Left Shoe
	drawSemiCircle(-21, -178,
		1.2, 1,
		20, 20, 20,
		10,
		-90, 90);

	// Right Shoe
	drawSemiCircle(18, -178,
		1.2, 1,
		20, 20, 20,
		10,
		-90, 90);

	glPopMatrix();
}

void drawTree(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Bark
	glBegin(GL_POLYGON);
	glColor3ub(86, 46, 11);
	glVertex2f(0, 0);
	glVertex2f(40, 0);
	glColor3ub(71, 36, 6);
	glVertex2f(35, 200);
	glVertex2f(5, 200);
	glEnd();

	// Tree
	//drawCircle(20, 200, 5, 80, 10, 1, 8, 20);

	//glRotatef(360,1.0f,1.0f,0.0f);
	float j=30;
	for(int i=180;i<420;i=i+10)
    {
       drawCircle(20, i, 5, 80, 10, 5, 2, j);
       j=j-1.2;
    }




	// Apples
	drawCircle(27, 234, 255, 0, 0, 1, 1.2, 5);
	drawCircle(-15, 270, 255, 0, 0, 1, 1.2, 5);
	drawCircle(47, 255, 255, 0, 0, 1, 1.2, 5);
	drawCircle(-2, 228, 255, 0, 0, 1, 1.2, 5);
	drawCircle(72, 216, 255, 0, 0, 1, 1.2, 5);

	glPopMatrix();
}

void drawHospital(GLfloat tx, GLfloat ty,
                    GLfloat sx, GLfloat sy) {
	// Tuition Building
	glPushMatrix();
	glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);





	glColor3ub(190, 190, 190);
	glVertex2f(25, 175);
	glVertex2f(300, 175);
	glColor3ub(190, 190, 190);
	glVertex2f(300, 500);
	glVertex2f(25, 500);
	glEnd();

	// Tuition Building Border
	//glBegin(GL_LINE_LOOP);
	//glColor3ub(20, 20, 20);
	//glVertex2f(25, 175);
	//glVertex2f(300, 175);
	//glVertex2f(300, 500);
	//glVertex2f(25, 500);
	//glEnd();

	// Tuition Board
	glBegin(GL_POLYGON);
	glColor3ub(255, 218, 154);
	glVertex2f(50, 525);
	glVertex2f(180, 525);
	glVertex2f(180, 475);
	glVertex2f(50, 475);
	glEnd();

	// Tuition Board Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(50, 525);
	glVertex2f(180, 525);
	glVertex2f(180, 475);
	glVertex2f(50, 475);
	glEnd();

	print("SCHOOL", 255, 255,255, 1, 65, 492, .15, .15, 1.3);



// Tuition Rectangular Window
	glBegin(GL_POLYGON);
for(int i=240;i<=450;i=i+40){

	glColor3ub(59, 91, 132);
	glVertex2f(50, i);
	glVertex2f(50, 440);
	glVertex2f(270, 440);
	glColor3ub(97, 131, 159);
	glVertex2f(270, i);
	glEnd();

	// Tuition Rectangular Window Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(50, i);
	glVertex2f(50, 240);
	glVertex2f(270, 240);
	glVertex2f(270, i);
	glEnd();

	// Tuition Rectangular Window Panes
	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(150, i);
	glVertex2f(150, 240);
	glVertex2f(50, 260);
	glVertex2f(270, 260);
}



	glEnd();
	glPopMatrix();
}



void drawSchool(GLfloat tx, GLfloat ty,
                   GLfloat sx, GLfloat sy
                   ) {
	// School Building

	glPushMatrix();
	glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);



	glBegin(GL_POLYGON);
  glColor3ub(184, 88, 68);
  glVertex2f(400, 175);
	glVertex2f(1000, 175);
	glVertex2f(1000, 600);
	glColor3ub(241, 130, 94);
	glVertex2f(400, 600);
	glEnd();

	// School Building Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(400, 175);
	glVertex2f(1000, 175);
	glVertex2f(1000, 500);
	glVertex2f(400, 500);
	glEnd();

	// School Board
	glBegin(GL_POLYGON);
	glColor3ub(183, 184, 188);
	glVertex2f(570, 530);
	glVertex2f(830, 530);
	glVertex2f(830, 470);
	glVertex2f(570, 470);
	glEnd();

	// School Board Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(570, 530);
	glVertex2f(830, 530);
	glVertex2f(830, 470);
	glVertex2f(570, 470);
	glEnd();

	print("HOSPITAL", 255, 0, 0, 1, 580, 485, .3, .3, 1.5);

  // School Door
	glBegin(GL_POLYGON);
	glColor3ub(183, 184, 188);
	glVertex2f(600, 175);
	glVertex2f(600, 280);
	glVertex2f(800, 280);
	glVertex2f(800, 175);
	glEnd();

	// School Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(600, 175);
	glVertex2f(600, 280);
	glVertex2f(800, 280);
	glVertex2f(800, 175);
	glEnd();

	// School Door Divider
	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(700, 280);
	glVertex2f(700, 175);
	glEnd();

	// School Windows
	for (int i = 0; i <= 500; i+=100) {
		for (int j = 0; j <= 100; j+=80) {
			glBegin(GL_POLYGON);
			glColor3ub(59, 91, 132);
			glVertex2f(425 + i, 450 - j);
			glVertex2f(475 + i, 450 - j);
			glVertex2f(475 + i, 400 - j);
			glColor3ub(97, 131, 159);
			glVertex2f(425 + i, 400 - j);
			glEnd();

			glBegin(GL_LINE_LOOP);
			glColor3ub(20, 20, 20);
			glVertex2f(425 + i, 450 - j);
			glVertex2f(475 + i, 450 - j);
			glVertex2f(475 + i, 400 - j);
			glVertex2f(425 + i, 400 - j);
			glEnd();

			glLineWidth(4);
			glBegin(GL_LINES);
			glColor3ub(140, 75, 55);
			glVertex2f(425 + i, 400 - j);
			glVertex2f(475 + i, 400 - j);
			glEnd();
			glLineWidth(1);
		}
	}

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(425, 280);
	glVertex2f(475, 280);
	glVertex2f(475, 200);
	glColor3ub(97, 131, 159);
	glVertex2f(425, 200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(425, 280);
	glVertex2f(475, 280);
	glVertex2f(475, 200);
	glVertex2f(425, 200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(525, 280);
	glVertex2f(575, 280);
	glVertex2f(575, 200);
	glColor3ub(97, 131, 159);
	glVertex2f(525, 200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(525, 280);
	glVertex2f(575, 280);
	glVertex2f(575, 200);
	glVertex2f(525, 200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(825, 280);
	glVertex2f(875, 280);
	glVertex2f(875, 200);
	glColor3ub(97, 131, 159);
	glVertex2f(825, 200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(825, 280);
	glVertex2f(875, 280);
	glVertex2f(875, 200);
	glVertex2f(825, 200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(925, 280);
	glVertex2f(975, 280);
	glVertex2f(975, 200);
	glColor3ub(97, 131, 159);
	glVertex2f(925, 200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(925, 280);
	glVertex2f(975, 280);
	glVertex2f(975, 200);
	glVertex2f(925, 200);


	glEnd();
	glPopMatrix();
}
void DrawUnivarsity(GLfloat tx, GLfloat ty,
             GLfloat sx, GLfloat sy){
    ///==================================== Draw Building Univarsity
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
	glColor3ub(190, 50, 50);
    glVertex2i(610,420);
    glVertex2i(760,420);
    glVertex2i(760,600);
    glVertex2i(610,600);
    glEnd();

    int UnivarsityY1=585,UnivarsityY2=582;
	for(int i=0;i<7;i++){
        //=================floor of building 1
        if(i==2 || i==3){

        }
        else{
            glBegin(GL_POLYGON);
            glColor3ub(153, 153, 102);
            glVertex2i(610,UnivarsityY1);
            glVertex2i(760,UnivarsityY1);
            glVertex2i(760,UnivarsityY2);
            glVertex2i(610,UnivarsityY2);
            glEnd();
        }
        UnivarsityY1=UnivarsityY1-25;
        UnivarsityY2=UnivarsityY2-25;
	}


    print("EW UNIVARSITY", 0, 0, 0, 1, 620, 500, .10, .3, 1.5);



    glPopMatrix();

}

void PS_drawRoad(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(40, 40, 40);
	glVertex2f(300, 275);
	glVertex2f(500, 275);
	glVertex2f(500, 200);
	glVertex2f(300, 200);
	glEnd();



	for(int i=300;i<500;i=i+5){
    glBegin(GL_POLYGON);
    if(i%2==0){
      glColor3ub(250, 250, 250);
    }
    else{
        glColor3ub(0, 0, 0);
    }

	glVertex2f(i, 275);
	glVertex2f(i+5, 275);
	glVertex2f(i+5, 280);
	glVertex2f(i, 280);
	glEnd();
	}



	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	for(int i=300;i<=500;i=i+5)
    {
        glVertex2f(i, 235);   //white marks in middle
    }



	glEnd();
	glLineWidth(1);
	glPopMatrix();
}


void DrawCould(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy)
    {
    //Cloud

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    drawSemiCircle(500, 400,
		7.2, 5.1,
		200, 230, 255,
		10,
		0, 360);
    drawSemiCircle(480, 420,
		3.2, 5.1,
		200, 230, 255,
		10,
		0, 360);
   drawSemiCircle(520, 410,
		3.2, 5.1,
		200, 230, 255,
		10,
		0, 360);
   drawSemiCircle(510, 380,
		3.2, 5.1,
		200, 230, 255,
		10,
		0, 360);

    glPopMatrix();

    }

void DrawCouldRain(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy)
    {
    //Cloud

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    drawSemiCircle(500, 400,
		7.2, 5.1,
		119,136,153,
		10,
		0, 360);
    drawSemiCircle(480, 420,
		3.2, 5.1,
		119,136,153,
		10,
		0, 360);
   drawSemiCircle(520, 410,
		3.2, 5.1,
		119,136,153,
		10,
		0, 360);
   drawSemiCircle(510, 380,
		3.2, 5.1,
		119,136,153,
		10,
		0, 360);

    glPopMatrix();

    }

void drawBackground(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
	glColor3ub(12, 172, 232); // Sky Blue
	glVertex2f(0, 400);
	glVertex2f(1400, 400);

	glColor3ub(82, 163, 42); // Green Grass
	glVertex2f(1400, 90);
	glVertex2f(0, 90);
	glEnd();

		// Background
	glBegin(GL_POLYGON);
	glColor3ub(135, 206, 250); // Sky Blue
	glVertex2f(0, 900);
	glVertex2f(1400, 900);
	glVertex2f(1400, 150);
	glVertex2f(0, 150);
	glEnd();


	glPopMatrix();
}
void drawBackgroundNight(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
	glColor3ub(0, 172, 232); // Sky Blue
	glVertex2f(0, 400);
	glVertex2f(1400, 400);

	glColor3ub(82, 163, 42); // Green Grass
	glVertex2f(1400, 90);
	glVertex2f(0, 90);
	glEnd();

		// Background
	glBegin(GL_POLYGON);
	glColor3ub(25,25,112); // Sky Blue
	glVertex2f(0, 900);
	glVertex2f(1400, 900);
	glVertex2f(1400, 150);
	glVertex2f(0, 150);
	glEnd();

	//stars
        drawCircle(300, 400,
		250, 250, 250,
		7, 14,
		.1);
        drawCircle(200, 500,
		250, 250, 250,
		7, 14,
		.2);
        drawCircle(100, 550,
		250, 250, 0,
		7, 14,
		.2);
		 drawCircle(100, 400,
		250, 250, 250,
		7, 14,
		.25);
		 drawCircle(400, 550,
		250, 250, 0,
		7, 14,
		.3);
		 drawCircle(600, 600,
		250, 250, 250,
		7, 14,
		.2);
		 drawCircle(900, 700,
		250, 250, 250,
		7, 14,
		.2);
		 drawCircle(700, 650,
		250, 250, 250,
		7, 14,
		.2);
		 drawCircle(800, 550,
		250, 250, 0,
		7, 14,
		.3);
		 drawCircle(650, 500,
		250, 250, 250,
		7, 14,
		.3);
		drawCircle(750, 380,
		250, 250, 250,
		7, 14,
		.3);
        drawCircle(150, 480,
		250, 250, 250,
		7, 14,
		.25);

		for(int i=0;i<500;i++)
        {

        int x=rand()%1100;
        int y=rand()%800;
        if(y>300){
         drawCircle(x, y,
		250, 250, 250,
		7, 14,
		.1);
        }
        }

	glPopMatrix();
}


void drawBackgroundRain(GLfloat tx, GLfloat ty,
                 GLfloat sx, GLfloat sy) {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


	glBegin(GL_POLYGON);
	glColor3ub(12, 172, 232); // Sky Blue
	glVertex2f(0, 400);
	glVertex2f(1400, 400);

	glColor3ub(82, 163, 42); // Green Grass
	glVertex2f(1400, 90);
	glVertex2f(0, 90);
	glEnd();

		// Background
	glBegin(GL_POLYGON);
	glColor3ub(65,105,225); // Sky Blue
	glVertex2f(0, 900);
	glVertex2f(1400, 900);
	glVertex2f(1400, 150);
	glVertex2f(0, 150);
	glEnd();


	glPopMatrix();
}


void signBoard(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy)
{
       glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

     //signboard;
    glBegin(GL_POLYGON);
    glColor3ub(255, 218, 154);
    glVertex2f(600, 300);
	glVertex2f(550, 300);
	glVertex2f(550, 250);
	glVertex2f(600, 250);
    glEnd();
    print("Covid Test", 0, 0, 0, 1, 550, 275, .05, .1, 1.5);


    //signboard border
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(600, 300);
	glVertex2f(550, 300);
	glVertex2f(550, 250);
	glVertex2f(600, 250);
    glEnd();


     //signboard handel
     glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
    glVertex2f(555, 250);
	glVertex2f(560, 250);
	glVertex2f(560, 210);
	glVertex2f(555, 210);
    glEnd();
    glPopMatrix();




}

void Ambulance(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy)
{
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);
    //glPointSize(4);


 glBegin(GL_POLYGON);
    glColor3ub (1, 1,1);
    glVertex2i(30,60);
	glVertex2i(33,65);
	glVertex2i(60,65);
	glVertex2i(63,60);
glEnd();
//glFlush ();

glBegin(GL_LINES);
    glColor3ub (0,0,0);
    glVertex2i(30,60);
	glVertex2i(63,60);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
 glColor3f (1, 1,1);
    glVertex2i(20,35);
	glVertex2i(29,60);
	glVertex2i(64,60);
	glVertex2i(70,35);
glEnd();
//glFlush ();
//glass1
glBegin(GL_POLYGON);
    glColor3f (0.5, 0.5,1.5);
    glVertex2i(25,40);
	glVertex2i(30,55);
	glVertex2i(40,55);
	glVertex2i(40,40);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (0, 0,0);
    glVertex2i(25,38);
	glVertex2i(25,45);
	glVertex2i(27,45);
	glVertex2i(27,38);
glEnd();
//glFlush ();
//glass2
glBegin(GL_POLYGON);
    glColor3f (0.5, 0.5,1.5);
    glVertex2i(45,40);
	glVertex2i(45,55);
	glVertex2i(55,55);
	glVertex2i(55,40);
glEnd();
//glFlush ();
//+
glBegin(GL_QUADS);
    glColor3f (1, 0,0);
    glVertex2i(62,42);
	glVertex2i(59,42);
	glVertex2i(59,52);
	glVertex2i(62,52);
glEnd();
//glFlush ();

glBegin(GL_QUADS);
    glColor3f (1, 0,0);
    glVertex2i(65,45);
	glVertex2i(56,45);
	glVertex2i(56,48);
	glVertex2i(65,48);
glEnd();
//glFlush ();
//door
glBegin(GL_QUADS);
    glColor3f (0, 0,0);
    glVertex2i(35,36);
	glVertex2i(35,38);
	glVertex2i(40,36);
	glVertex2i(40,38);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (1, 1,1);
    glVertex2i(15,32);
	glVertex2i(20,35);
	glVertex2i(70,35);
	glVertex2i(70,32);
glEnd();
//glFlush ();
//red
glBegin(GL_POLYGON);
    glColor3f (1, 0,0);
    glVertex2i(13,30);
	glVertex2i(15,32);
	glVertex2i(70,32);
	glVertex2i(70,30);
glEnd();
//glFlush ();
		glBegin(GL_POLYGON);
		glColor3f(0,0,0);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(30+cos(angle)*1,15+sin(angle)*1);
		}
	glEnd();
	//glFlush ();

		glBegin(GL_POLYGON);
		glColor3f(1,1,1);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(30+cos(angle)*.5,15+sin(angle)*0.5);
		}
	glEnd();
	//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (1, 1,1);
    glVertex2i(10,15);
	glVertex2i(13,30);
	glVertex2i(70,30);
	glVertex2i(70,15);
glEnd();
//glFlush ();
//light
glBegin(GL_POLYGON);
    glColor3f (1.2, 0.2,0.2);
    glVertex2i(11.3,22.0);
	glVertex2i(12,26);
	glVertex2i(14,26);
	glVertex2i(14,22);
glEnd();
//glFlush ();

//light 2
glBegin(GL_POLYGON);
    glColor3f (1.2, 0.2,0.2);
    glVertex2f(68,22.0);
	glVertex2i(68,26);
	glVertex2i(70,26);
	glVertex2i(70,22);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (1.2, 1.2,0.2);

	glVertex2i(68,26);
    glVertex2i(68,29);
    glVertex2i(70,29);
	glVertex2i(70,26);

glEnd();
//glFlush ();


glBegin(GL_POLYGON);
    glColor3f (0.3,0.3,0.3);
    glVertex2i(9,15);
	glVertex2i(9,20);
	glVertex2i(20,20);
	glVertex2i(20,15);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (0.3,0.3,0.3);
    glVertex2i(66,15);
	glVertex2i(66,20);
	glVertex2i(71,20);
	glVertex2i(71,15);
glEnd();
//glFlush ();
//1
glBegin(GL_POLYGON);
    glColor3f (0.3,0.3,0.3);
    glVertex2i(34,65);
	glVertex2i(35,66);
	glVertex2i(38,66);
	glVertex2i(39,65);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (0,0,1);
    glVertex2i(35,66);
	glVertex2i(35,69);
	glVertex2i(38,69);
	glVertex2i(38,66);
glEnd();
//glFlush ();


//wheel front
drawCircle(25, 12,
		0, 0, 0,                 //sun motion
		7, 14,
		.9);

drawCircle(25, 12,
		112, 128, 144,                 //sun motion
		7, 14,
		.6);

drawCircle(25, 12,
		0, 0, 0,                 //sun motion
		7, 14,
		.1);

		//wheel back
drawCircle(60, 12,
		0, 0, 0,                 //sun motion
		7, 14,
		.9);

drawCircle(60, 12,
		112, 128, 144,                 //sun motion
		7, 14,
		.6);

drawCircle(60, 12,
		0, 0, 0,                 //sun motion
		7, 14,
		.1);



   glPopMatrix();
}




void PoliceCar(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy)
               {


    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
    glColor3f (1, 1,1);
    glVertex2i(0,20);
	glVertex2i(3,30);
	glVertex2i(95,30);
	glVertex2i(100,20);
    glEnd();
//glFlush ();

glBegin(GL_POLYGON);
 glColor3f (0.8, 0.8,0.8);
    glVertex2i(3,30);
	glVertex2i(4,32);
	glVertex2i(94,32);
	glVertex2i(95,30);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (1, 1,1);
    glVertex2i(4,32);
	glVertex2i(6,40);
	glVertex2i(87,40);
	glVertex2i(93,32);
glEnd();
//glFlush ();
//blue
glBegin(GL_POLYGON);
    glColor3f (0.7, 0.7,1.7);
    glVertex2i(93,32);
	glVertex2i(90.8,35);
	glVertex2i(88,35);
	glVertex2i(88,32);
glEnd();
//glFlush ();
//red
glBegin(GL_POLYGON);
    glColor3f (1.5, 0.5,0.5);
    glVertex2i(88,32);
	glVertex2i(88,35);
	glVertex2i(86,35);
	glVertex2i(86,32);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (1.5, 0.5,0.5);
    glVertex2i(4,32);
	glVertex2i(4.8,35);
	glVertex2i(7,35);
	glVertex2i(7,32);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (1,1,1);
    glVertex2i(15,40);
	glVertex2i(25,60);
	glVertex2i(62,60);
	glVertex2i(75,40);
glEnd();
//glFlush ();
//glass1
glBegin(GL_POLYGON);
    glColor3f (0.5, 0.5,1.5);
    glVertex2i(18,40);
	glVertex2i(26,57);
	glVertex2i(43,57);
	glVertex2i(43,40);
glEnd();
//glFlush ();

glBegin(GL_LINE_STRIP);
    glColor3f (0, 0,0);
    glVertex2i(18,40);
	glVertex2i(26,57);
	glVertex2i(43,57);
	glVertex2i(43,40);
glEnd();
//glFlush ();

//glass2
glBegin(GL_POLYGON);
    glColor3f (0.5, 0.5,1.5);
    glVertex2i(46,40);
	glVertex2i(46,57);
	glVertex2i(62,57);
	glVertex2i(73,40);
glEnd();
//glFlush ();

glBegin(GL_LINE_STRIP);
    glColor3f (0, 0,0);
    glVertex2i(46,40);
	glVertex2i(46,57);
	glVertex2i(62,57);
	glVertex2i(73,40);
glEnd();
//glFlush ();
//Door1
glBegin(GL_LINE_STRIP);
    glColor3f (0, 0,0);
    glVertex2i(18,40);
	glVertex2i(18,20);
	glVertex2i(43,20);
	glVertex2i(43,40);
glEnd();
//glFlush ();
//Door2
glBegin(GL_LINE_STRIP);
    glColor3f (0, 0,0);
    glVertex2i(46,40);
	glVertex2i(46,20);
	glVertex2i(73,20);
	glVertex2i(73,40);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (0.3, 0.3,0.3);
    glVertex2i(54,60);
	glVertex2i(56,61);
	glVertex2i(58,61);
	glVertex2i(60,60);
glEnd();
//glFlush ();

glBegin(GL_POLYGON);
    glColor3f (0, 0,1);
    glVertex2i(52,61);
	glVertex2i(52,65);
	glVertex2i(61,65);
	glVertex2i(61,61);
glEnd();
//glFlush ();

glBegin(GL_QUADS);
    glColor3f (1, 0,0);
    glVertex2i(55,61);
	glVertex2i(55,65);
	glVertex2i(58,65);
	glVertex2i(58,61);
glEnd();
//glFlush ();

//blue
glBegin(GL_POLYGON);
    glColor3f (0.3, 0.3,1.3);
    glVertex2i(8,32);
	glVertex2i(8,38);
	glVertex2i(85,38);
	glVertex2i(85,32);
glEnd();
//glFlush ();
//P
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2i(20,33);
	glVertex2i(20,37);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(20,37);
	glVertex2d(23,37);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(23,37);
	glVertex2d(23,35);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(23,35);
	glVertex2d(20,35);
glEnd();
//glFlush ();
//O
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(25,33);
	glVertex2d(25,37);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(25,37);
	glVertex2d(28,37);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(28,37);
	glVertex2d(28,33);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(28,33);
	glVertex2d(25,33);
glEnd();
//glFlush ();
//L
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(30,33);
	glVertex2d(30,37);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(30,33);
	glVertex2d(33,33);
glEnd();
//glFlush ();
//I
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(35,33);
	glVertex2d(35,37);
glEnd();
//glFlush ();
//C
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(37,37);
	glVertex2d(39,37);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(37,33);
	glVertex2d(37,37);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(37,33);
	glVertex2d(39,33);
glEnd();
//glFlush ();
//E
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(41,37);
	glVertex2d(44,37);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(41,33);
	glVertex2d(41,37);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(41,35);
	glVertex2d(43,35);
glEnd();
//glFlush ();
glBegin(GL_LINES);
    glColor3f (0,0,0);
    glVertex2d(41,33);
	glVertex2d(44,33);
glEnd();
//glFlush ();

//Star
glBegin(GL_TRIANGLES);
    glColor3f (1,1,0);
    glVertex2d(60,37);
	glVertex2d(62,36);
	glVertex2d(58,36);
glEnd();
//glFlush ();
glBegin(GL_TRIANGLES);
    glColor3f (1,1,0);
	glVertex2d(58,36);
    glVertex2d(55,35);
    glVertex2d(57,34);
glEnd();
//glFlush ();
glBegin(GL_TRIANGLES);
    glColor3f (1,1,0);
    glVertex2d(57,34);
    glVertex2d(60,33.5);
    glVertex2d(55,32.5);
glEnd();
//glFlush ();
glBegin(GL_TRIANGLES);
    glColor3f (1,1,0);
    glVertex2d(60,33.5);
    glVertex2d(65,32.5);
    glVertex2d(63,34);
glEnd();
//glFlush ();
glBegin(GL_TRIANGLES);
    glColor3f (1,1,0);
    glVertex2d(63,34);
    glVertex2d(65,35);
    glVertex2d(62,36);
glEnd();
//glFlush ();
glBegin(GL_POLYGON);
    glColor3f (1, 1,0);
    glVertex2d(57,34);
	glVertex2d(58,36);
	glVertex2d(63,36);
	glVertex2d(64,33);
glEnd();
//glFlush ();
//wheel1
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0,0,0);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*10,15+sin(angle)*10);
		}
	glEnd();
//	glFlush ();

	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5,0.5,0.5);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*8,15+sin(angle)*8);
		}
	glEnd();
	//glFlush ();

			glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8,0.8,0.8);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*5.5,15+sin(angle)*5.5);
		}
	glEnd();
	//glFlush ();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.2,0.2,0.2);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*5,15+sin(angle)*5);
		}
	glEnd();
	//glFlush ();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1,1,1);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(20+cos(angle)*1.5,15+sin(angle)*1.5);
		}
	glEnd();
	//glFlush ();

//wheel2
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0,0,0);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*10,15+sin(angle)*10);
		}
	glEnd();
	//glFlush ();


	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5,0.5,0.5);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*8,15+sin(angle)*8);
		}
	glEnd();
	//glFlush ();

				glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8,0.8,0.8);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*5.5,15+sin(angle)*5.5);
		}
	glEnd();
	//glFlush ();

			glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.2,0.2,0.2);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*5,15+sin(angle)*5);
		}
	glEnd();
	//glFlush ();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.5,1.5,1.5);
		for(int i=0;i<=360;i++)
		{
			float angle = i*3.1416/180;
			glVertex2f(67+cos(angle)*1.5,15+sin(angle)*1.5);
		}
	glEnd();
	//glFlush ();

	glPopMatrix();
}




void drawDoctors(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy)
{
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);


       glBegin(GL_POLYGON);
    glColor3ub (0,255,250);
    glVertex2i(605,245);
	glVertex2i(670,245);    //PETAIENT
	glVertex2i(671,265);
	glVertex2i(605,265);
    glEnd();

    drawHumam(600, 295,
		0.25, 0.45,
		255, 250, 255);


    drawHumam(670, 295,
		0.25, 0.45,
		255, 250, 255);




    glBegin(GL_POLYGON);
    glColor3ub (255,0,0);
    glVertex2i(605,265);
	glVertex2i(595,265);
	glVertex2i(595,260);
	glVertex2i(605,260);     //red doctor sign
   glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (255,0,0);
    glVertex2i(602,270);
	glVertex2i(598,270);
	glVertex2i(598,255);
	glVertex2i(602,255);
   glEnd();

     glBegin(GL_POLYGON);
    glColor3ub (255,0,0);
    glVertex2i(675,265);
	glVertex2i(665,265);
	glVertex2i(665,260);
	glVertex2i(675,260);     //red doctor sign
   glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (255,0,0);
    glVertex2i(672,270);
	glVertex2i(668,270);
	glVertex2i(668,255);
	glVertex2i(672,255);
   glEnd();

    glPopMatrix();


}

void rain()
{
    glLineWidth(3);
    for(int i=0;i<1000;i++)
    {

        int x=rand()%1080;
        int y=rand()%1000;
    glBegin(GL_LINES);
    glColor3ub (255,255,255);
    glVertex2i(x,y);
    glVertex2i(x+5,y-10);
    glEnd();
    }


}



void lampPost(GLfloat tx, GLfloat ty,
               GLfloat sx, GLfloat sy,
               GLfloat light_r, GLfloat light_g,GLfloat light_b)
{
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);



      glBegin(GL_POLYGON);
    glColor3ub (0,0,0);
    glVertex2i(52,320);      //handel
	glVertex2i(58,320);
	glVertex2i(58,230);
	glVertex2i(52,230);
   glEnd();


    drawCircle(55, 320,
		light_r,light_g,light_b,                //light
		7, 14,
		2);


    glPopMatrix();
}

void NightView()
{

glClear (GL_COLOR_BUFFER_BIT);
//glColor3ub (128, 128, 128);
glPointSize(5.0);

drawBackgroundNight(0,110,
                  1,1.2);


glPushMatrix();
glTranslatef(sunXAxis,0.0f,0.0f);
drawCircle(1050, 900,
		255, 255, 255,                 //moon motion
		7, 14,
		5);
glPopMatrix();




glPushMatrix();
glTranslatef(cloud1Position,0.0f,0.0f);
DrawCould(-800,500,                          //first cloud motion
          2,1);
glPopMatrix();


glPushMatrix();
glTranslatef(cloud2Position,0.0f,0.0f);
DrawCould(100,500,                        //third cloud motion
          1.5,.8);
glPopMatrix();

glPushMatrix();
glTranslatef(cloud3Position,0.0f,0.0f);
DrawCould(100,580,                        //second cloud motion
          1,.8);
glPopMatrix();




PS_drawRoad(-2000,-600,
             6,3);
building(0,65,
         1.5,1.4);


drawHospital(5,110,
               .35,.9);

DrawUnivarsity(-150,-430,
       1.5,1.7);

drawSchool(200,130,
              0.4,0.8);

signBoard(-70,40,
          1,1);


glPushMatrix();
glTranslatef(humanPosition1,0.0f,0.0f);
drawHumam(420, 305,
		0.2, 0.35,
		255, 250, 0);
glPopMatrix();

/*glPushMatrix();
glTranslatef(humanPosition2,0.0f,0.0f);
drawHumam(350, 305,
		0.2, 0.35,
		255, 0, 250);*/
glPopMatrix();

glPushMatrix();
glTranslatef(humanPosition3,0.0f,0.0f);
drawHumam(290, 305,
		0.2, 0.35,
		0, 0, 250);
glPopMatrix();


/*glPushMatrix();
glTranslatef(humanPosition4,0.0f,0.0f);
drawHumam(220, 305,
		0.2, 0.35,
		150, 10, 100);*/

glPopMatrix();

glPushMatrix();
glTranslatef(humanPosition5,0.0f,0.0f);
drawHumam(150, 305,
		0.2, 0.35,
		255, 0, 0);
glPopMatrix();


 drawTree(100,245,                   //tree
          .2,.45);
 drawTree(200,245,                   //tree
          .2,.45);
 drawTree(650,245,                   //tree
          .2,.45);
 drawTree(700,245,                   //tree
          .2,.45);



for(int i=0;i<=1000;i+=100)
{

   lampPost(i,0,
            1,1,
            255,255,0);
}



glPushMatrix();
glTranslatef(doctorPosition,0.0f,0.0f);
drawDoctors(0,0,
            1,1);
glPopMatrix();


glPushMatrix();
glTranslatef(ambulancePosition,0.0f,0.0f);
   glBegin(GL_POLYGON);
    glColor3ub (255,255,0);
    glVertex2i(360,190);
    glVertex2i(450,170);
	                       //head light
	glVertex2i(550,200);
	glVertex2i(550,210);

	 glEnd();

Ambulance(500,150,
          3,2.8);
glPopMatrix();

glPushMatrix();
glTranslatef(policecarPosition1,0.0f,0.0f);
glBegin(GL_POLYGON);
    glColor3ub (255,255,0);
    glVertex2i(730,70);
	glVertex2i(850,20);          //head light
	glVertex2i(950,30);
	 glVertex2i(700,90);
	 glEnd();
PoliceCar(500,20,
          2.5,2.5);
glPopMatrix();
glEnd();
glPushMatrix();
glTranslatef(policecarPosition2,0.0f,0.0f);

glBegin(GL_POLYGON);
    glColor3ub (255,255,0);
    glVertex2i(230,70);
	glVertex2i(350,20);          //head light
	glVertex2i(450,30);
	 glVertex2i(200,90);
   glEnd();
PoliceCar(0,10,
          2.5,2.5);    //police car
glPopMatrix();


glFlush();


}



void RainView()
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);




drawBackgroundRain(0,110,
                  1,1.2);



glPushMatrix();
glTranslatef(cloud1Position,0.0f,0.0f);
DrawCouldRain(-800,500,                          //first cloud motion
          2,1);
glPopMatrix();


glPushMatrix();
glTranslatef(cloud2Position,0.0f,0.0f);
DrawCouldRain(100,500,                        //third cloud motion
          1.5,.8);
glPopMatrix();

glPushMatrix();
glTranslatef(cloud3Position,0.0f,0.0f);
DrawCouldRain(100,580,                        //second cloud motion
          1,.8);
glPopMatrix();




PS_drawRoad(-2000,-600,
             6,3);
building(0,65,
         1.5,1.4);


drawHospital(5,110,
               .35,.9);

DrawUnivarsity(-150,-430,
       1.5,1.7);

drawSchool(200,130,
              0.4,0.8);

signBoard(-70,40,
          1,1);


/*glPushMatrix();
glTranslatef(humanPosition1,0.0f,0.0f);
drawHumam(420, 305,
		0.2, 0.35,
		255, 250, 0);
glPopMatrix();

glPushMatrix();
glTranslatef(humanPosition2,0.0f,0.0f);
drawHumam(350, 305,
		0.2, 0.35,
		255, 0, 250);
glPopMatrix();

glPushMatrix();
glTranslatef(humanPosition3,0.0f,0.0f);
drawHumam(290, 305,
		0.2, 0.35,
		0, 0, 250);
glPopMatrix();


glPushMatrix();
glTranslatef(humanPosition4,0.0f,0.0f);
drawHumam(220, 305,
		0.2, 0.35,
		150, 10, 100);

glPopMatrix();

glPushMatrix();
glTranslatef(humanPosition5,0.0f,0.0f);
drawHumam(150, 305,
		0.2, 0.35,
		255, 0, 0);
glPopMatrix();
*/

 drawTree(100,245,                   //tree
          .2,.45);
 drawTree(200,245,                   //tree
          .2,.45);
 drawTree(650,245,                   //tree
          .2,.45);
 drawTree(700,245,                   //tree
          .2,.45);

for(int i=0;i<=1000;i+=100)
{

   lampPost(i,0,
            1,1,
            176,224,230);
}

/*glPushMatrix();
glTranslatef(doctorPosition,0.0f,0.0f);
drawDoctors(0,0,
            1,1);
glPopMatrix();
*/

glPushMatrix();
glTranslatef(humanPosition,0.0f,0.0f);
drawHumam(150, 250,
		0.2, 0.35,
		255, 0, 0);
drawSemiCircle(150, 255,           //man walking in rain
		5.2, 11.1,
		50,50,50,
		5,
		-90, 90);
glPopMatrix();


glPushMatrix();
glTranslatef(humanPosition,0.0f,0.0f);
drawHumam(420, 250,
		0.2, 0.35,
		255, 250, 0);
drawSemiCircle(420, 255,           //man walking in rain
		5.2, 11.1,
		50,50,50,
		5,
		-90, 90);
glPopMatrix();



glPushMatrix();
glTranslatef(ambulancePosition,0.0f,0.0f);
Ambulance(500,150,       //ambulance
          3,2.8);
glPopMatrix();

glPushMatrix();
glTranslatef(policecarPosition1,0.0f,0.0f);
PoliceCar(500,20,
          2.5,2.5);                            //police car
glPopMatrix();
glEnd();
glPushMatrix();
glTranslatef(policecarPosition2,0.0f,0.0f);
PoliceCar(0,10,                                //police car
          2.5,2.5);
glPopMatrix();


rain();
glEnd();
glFlush();


}




void DayView()
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);

drawBackground(0,110,
                  1,1.2);


glPushMatrix();
glTranslatef(sunXAxis,0.0f,0.0f);
drawCircle(1050, 900,
		250, 250, 0,                 //sun motion
		7, 14,
		5);
glPopMatrix();




glPushMatrix();
glTranslatef(cloud1Position,0.0f,0.0f);
DrawCould(-800,500,                          //first cloud motion
          2,1);
glPopMatrix();


glPushMatrix();
glTranslatef(cloud2Position,0.0f,0.0f);
DrawCould(100,500,                        //third cloud motion
          1.5,.8);
glPopMatrix();

glPushMatrix();
glTranslatef(cloud3Position,0.0f,0.0f);
DrawCould(100,580,                        //second cloud motion
          1,.8);
glPopMatrix();




PS_drawRoad(-2000,-600,
             6,3);
building(0,65,
         1.5,1.4);


drawHospital(5,110,
               .35,.9);

DrawUnivarsity(-150,-430,
       1.5,1.7);

drawSchool(200,130,
              0.4,0.8);

signBoard(-70,40,
          1,1);


glPushMatrix();
glTranslatef(humanPosition1,0.0f,0.0f);
drawHumam(420, 305,
		0.2, 0.35,
		255, 250, 0);
glPopMatrix();

glPushMatrix();
glTranslatef(humanPosition2,0.0f,0.0f);
drawHumam(350, 305,
		0.2, 0.35,
		255, 0, 250);
glPopMatrix();

glPushMatrix();
glTranslatef(humanPosition3,0.0f,0.0f);
drawHumam(290, 305,
		0.2, 0.35,
		0, 0, 250);
glPopMatrix();


glPushMatrix();
glTranslatef(humanPosition4,0.0f,0.0f);
drawHumam(220, 305,
		0.2, 0.35,
		150, 10, 100);

glPopMatrix();

glPushMatrix();
glTranslatef(humanPosition5,0.0f,0.0f);
drawHumam(150, 305,
		0.2, 0.35,
		255, 0, 0);
glPopMatrix();


 drawTree(100,245,                   //tree
          .2,.45);
 drawTree(200,245,                   //tree
          .2,.45);
 drawTree(650,245,                   //tree
          .2,.45);
 drawTree(700,245,                   //tree
          .2,.45);

for(int i=0;i<=1000;i+=100)
{

   lampPost(i,0,
            1,1,
            176,224,230);
}

glPushMatrix();
glTranslatef(doctorPosition,0.0f,0.0f);
drawDoctors(0,0,
            1,1);
glPopMatrix();


glPushMatrix();
glTranslatef(ambulancePosition,0.0f,0.0f);
Ambulance(500,150,
          3,2.8);
glPopMatrix();


glPushMatrix();
glTranslatef(policecarPosition1,0.0f,0.0f);
PoliceCar(500,20,
          2.5,2.5);                            //police car
glPopMatrix();
glEnd();
glPushMatrix();
glTranslatef(policecarPosition2,0.0f,0.0f);
PoliceCar(0,10,                                //police car
          2.5,2.5);
glPopMatrix();


glFlush();


}
void update(int value) {


  cloud1Position+=cloud1speed;
  cloud2Position+=cloud2speed;
  cloud3Position+=cloud3speed;
  sunXAxis-=sunspeed;
  ambulancePosition-=ambulacespeed;
  doctorPosition-=doctorspeed;
  humanPosition1+=humanspeed;
  humanPosition2+=humanspeed+.08;
  humanPosition3+=humanspeed+.05;
  humanPosition4+=humanspeed+.08;
  humanPosition5+=humanspeed+.09;
  humanPosition+=humanspeed+.5;
  policecarPosition1+=policecarspeed+1;
   policecarPosition2+=policecarspeed+2;
 // printf("%f\n",policecarPosition1);

  if(sunXAxis<-1100)    //sun reassign position
  {
      sunXAxis=0;
  }

    if(cloud1Position>1000)    //cloud 1 reassign position
  {
      cloud1Position=-400;
  }
  if(cloud2Position>250)       //cloud 2 reassign position
  {
      cloud2Position=-1000;
  }
    if(cloud3Position>500)     //cloud 3 reassign position
  {
      cloud3Position=-700;
  }

 if(ambulancePosition<-750)
 {
     ambulancePosition=600;   //ambulance position reassign
 }

 if(ambulancePosition>0 && ambulancePosition<1)
 {
     ambulancePosition+=2.79;           //ambulance break
     doctorPosition=0;
 }

 if(doctorPosition<-115)
 {
     doctorPosition=ambulancePosition;     //doctor motion
 }

 if(humanPosition1>50)
 {
     humanPosition1=-500;     //firse human
 }
  if(humanPosition2-70>50)
 {
     humanPosition2=-430;        // second human;
 }
   if(humanPosition3-140>50)
 {
     humanPosition3=-360;        // trird human;
 }
    if(humanPosition4-210>50)
 {
     humanPosition4=-300;        // fourth human;
 }

     if(humanPosition5-280>50)
 {
     humanPosition5=-250;        // fifth human;
 }
      if(humanPosition>800)
 {
     humanPosition=-450;        // fifth human;
 }

 if(policecarPosition1>500)
 {
     policecarPosition1=-1000;           //police car motion
 }

  if(policecarPosition2>1000)
 {
     policecarPosition2=-500;          //police car motion
 }


	glutPostRedisplay();
    glutTimerFunc(1, update, 0);
}


void display(void)
{

glClear (GL_COLOR_BUFFER_BIT);
//glColor3ub (128, 128, 128);
glPointSize(5.0);

DayView();
glEnd();
glFlush ();

}
void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {


  break;
    case 'd':
   //   PlaySound(NULL,0,0);
       //PlaySound(TEXT("ambulance.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
   //    PlaySound(TEXT("police.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
      glutDisplayFunc(DayView);



      break;
    case 'n':

      //  PlaySound(NULL,0,0);
    //   PlaySound(TEXT("ambulance.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        glutDisplayFunc(NightView);

        break;


         break;
    case 'r':
       // PlaySound(NULL,0,0);
     //   PlaySound(TEXT("rain.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        glutDisplayFunc(RainView);
        break;


        default:
     glutPostRedisplay();
    break;
	}
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
     //        PlaySound(NULL,0,0);
       //PlaySound(TEXT("ambulance.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			glutDisplayFunc(NightView);


	}


		if (button == GLUT_RIGHT_BUTTON)
	{

     //        PlaySound(NULL,0,0);
       //PlaySound(TEXT("ambulance.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
   //    PlaySound(TEXT("police.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			glutDisplayFunc(DayView);


	}
			if (button == GLUT_MIDDLE_BUTTON)
	{

     //       PlaySound(NULL,0,0);
       // PlaySound(TEXT("rain.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
			glutDisplayFunc(RainView);


	}
}

void init() {
   glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}
int main(int argc,char** argv)
{


    printf("\nEnter 'd' for day view.");
    printf("\nEnter 'n' for night view.");
    printf("\nEnter 'r' for rain view.");


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("LOCKDOWN VIEW");     // creating the window
	//glutFullScreen();       // making the window full screen
	//glutInitWindowPosition(0,0);
	//PlaySound(TEXT("police.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	glutDisplayFunc(DayView);
	init();
	glutTimerFunc(1, update, 0);

	glutKeyboardFunc(handleKeypress);
	glutMouseFunc(handleMouse);
	//glutTimerFunc(10, update, 0);

	glutMainLoop();
	return 0;
}
