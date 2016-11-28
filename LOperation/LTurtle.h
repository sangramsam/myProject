/*******************************************************************************
		Main Program:					Viewer.cpp

		Comment:							Basic LString Drawer

		Author:								Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:								CS777, Spring 2003
*******************************************************************************/

#ifndef LTURTLE_H
#define LTURTLE_H

#include "Lstring.h"
#include "../global/globals.h"
#include "../math/vect3.h"
#include "../Draw/GLGraphics.h"

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stack>

typedef std::vector<vect3<float> > p_rec;

// Settings stack used for solving [] references 
typedef struct s_rec {
    vect3<float>	pos;            // position in 3space of turtle origin 
    vect3<float>	fow;            // forward direction 
    vect3<float>	lef;            // left direction 
    vect3<float>	upp;            // up direction 
    vect3<float>	last;           // last position used for connecting cylinders 
    vect3<float>	last_v[9];      // last vertices of object used for connecting cylinders */
    float32				dis;						// value of F distance 
    float32				ang;						// value of basic angle 
    float32				thick;					// value of thickness 
		float32       thickness;
		float32       oldThickness;		// The previous draw thickness
    float32				dis2;						// value of Z distance 
    float32				tr;							// trope value ?????????????????
    uint16				col;						// current color 
    uint16				last_col;				// color of last object 
		bool          thickInit;      // Thickness initial flag
} s_rec;

struct Point2D{
 double  x, y;
};

class LTurtle
{
	public:
		// Constructor and destructor
		LTurtle(LString &inLString, GLGraphics &inGLGrphics);
		~LTurtle();
			
		// Initialize the drawing element and this may not be changed when fitting into maya
		bool  InitDraw();
		// Draw the LString
		bool  Draw();

		// Set up the random seed
		void  SetRandSeed(int i);
		// Initialize string
		void createString();

	private:
		// Check whether the String and Graphic has been set up
		bool  CheckSetup();
		// Plot the LString
		void	PlotLstring(vect3<float> &centre, float height, float leafLength);
		// Create the branch of tree
		void  Define_block(vect3<float> p1, vect3<float> p2, vect3<float> up, float32 thick, float32 oldThick,
											 float32 min_thick, uint16 c); //draws a cuboid
		// Create the polygon
		void  Define_triangles(p_rec *ver, uint16 c); //draws a triangle strip

		// Set up the coordinate system by rotating n axis by a
		void  Set_rot(float32 a, vect3<float> n);
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// Generate random position for forest
		void	generateRandomPosition();

	private:
		LString&		the_LString;					// Operating string variable
		GLGraphics&	the_GLGraphics;				// Operating Graphic variable should be change in the future
			
		int           RandSeed;						// The seed of the random variable
		float32				rand_amount;				// 
		float32				trope_amount;				// Correct amount
		vect3<float>  trope, C1, C2, C3;	//	Trope is for gravity correction, C1, C2, C3 are three coordinate axis
		
		vect3<float>  sky;								// The sky direction
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++
		std::vector<Point2D> TreePosition;// The Tree Position
		std::vector<std::string> pattern;
};


#endif
