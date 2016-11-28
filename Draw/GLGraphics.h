/*******************************************************************************
		Main Program:					Viewer.cpp

		Comment:							Drawer interface

		Author:								Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:								CS777, Spring 2003
*******************************************************************************/

#ifndef GLGRAPHICS_H
#define GLGRAPHICS_H

#include "../global/globals.h"
#include "../math/vect3.h"

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <vector>
#include <stdio.h>


class GLGraphics
{
	public:
		 // Constructor
		GLGraphics(std::vector <vect3<GLfloat> > *colour_array);

		void StoreHexahedron(std::vector <vect3<float> > *vertex, unsigned short int colour);

		void StoreTriangleStrip(std::vector <vect3<float> > *vertex, unsigned short int colour);
		// Starting the display list
		void BeginStore();
		// Ending of the display list
		void EndStore();
		// Draw the scene
		void Draw();
		// Reset the draw
		void Clear();
		// This scene has ever been stored
		bool Is_Initialized();

	private:
		// Color maps
		const std::vector<vect3<GLfloat> > *colours;
		// Rendering flag
		bool    initialized;
		// Display list
		GLuint  theLsys;
};

#endif
