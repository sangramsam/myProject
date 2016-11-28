/*******************************************************************************
		Main:												MCViewer.cpp

		Program:										ViewWindow.h

		Comment:										Header File for main window

		Author:											James Gant, gant@cs.wisc.edu
																Yu-Chi Lai, yu-chil@cae.wisc.edu

		Complete Date:							Mar 09, 2003

		Course:											CS777, Spring 2003

		Compiler:                   Visual C Studio
		Platform:                   Windows 2000
*******************************************************************************/

#ifndef _VIEWWINDOW_H_
#define _VIEWWINDOW_H_

#include "global/globals.h"
#include "math/vect3.h"
#include "ground.h"
#include "Draw/GLGraphics.h"
#include "LOPeration/Mutation.h"
#include "LOperation/LString.h"
#include "LOperation/LTurtle.h"

#include <vector>

#include <Fl/Fl.h>
#include <Fl/Fl_Gl_Window.h>

#define BUFSIZE 512

// Subclass the Fl_Gl_Window because we want to draw OpenGL in here.
class ViewWindow : public Fl_Gl_Window {
  public:
		// Constructor takes window position and dimensions, the title.
		ViewWindow(int x, int y, int w, int h, char *label);

		// Destructor
		~ViewWindow();

		// Draw() method invoked whenever the view changes or the window
		// otherwise needs to be redrawn.
		void	draw(void);

		// Event handling method. Uses only mouse events.
		int	handle(int);

		// Update the world according to any events that have happened since
		// the last time this method was called.
		bool	Update(float);

		bool  openLFile(char *filename);

  private:
		//*****************************************************************
		// Drawing Related Object
		//******************************************************************
		Ground ground;

		//*****************************************************************
		// View related information
		//*****************************************************************
		static const double FOV_X; // The horizontal field of view.
		double	fov_y;

		float	phi;	// Viewer's inclination angle.
		float	theta;	// Viewer's azimuthal angle.
		float	dist;	// Viewer's distance from the look-at point.

		// This may change according to body's final position
		float	x_at;	// The x-coord to look at.
		float	y_at;	// The y-coord to look at.
		float z_at; // The z-coord to look at.

		float x_at_old;
		float y_at_old;
		float z_at_old;
		float dist_old;
		// the eye position
		double eye[3];

		//***********************************************************
		// Mouse control related data
		//***********************************************************
		int   button;	// The mouse button that is down, -1 if none.
		// The location of the most recent mouse event
		int		x_last;	
		int		y_last;
		// The location of the mouse when the button was pushed
		int		x_down; 
		int		y_down;
		// The x-, y-coord to look at when the mouse went down.
		float	x_at_down;  
		float	y_at_down;  
		// The view inclination angle when the mouse button was pushed
		float phi_down;   
		// The view azimuthal angle when the mouse button was pushed
		float theta_down; 
		// The distance when the mouse button is pushed.
		float	dist_down;  
		//*****************************************
		// LSystem operator
		//*****************************************
		// The color for the Graphics
		std::vector<vect3<GLfloat> > colours;
		// The Drawing window
		GLGraphics *the_Graphics;
		// The LString variable
		LString    *the_LString;
		// The mutation variable;
		MutationParameters mul;
		// The Ltrutle element
		LTurtle    *the_LTurtle;
		bool       FileFlag;
		

	private:
		void	Drag(float);	// The function to call for mouse drag events
		void	setupModelView();
		void	setupProject();
		void	setLookAt(float x, float y, float z);
};


#endif
