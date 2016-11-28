/*******************************************************************************
		Main Program:			MCViewer.cpp

		Program:					ViewWindow.cpp

		Comment:					The main window

		Author:						James Gant, gant@cs.wisc.edu
											Yu-Chi Lai, yu-chil@cae.wisc.edu

		Complete Date:		Mar 09, 2003

		Course:						CS777, Spring 2003
		Compiler:         Visual C Studio
		Platform:         Windows 2000

*******************************************************************************/

#include "ViewWindow.h"
#include <Fl/math.h>
#include <Fl/gl.h>
#include <GL/glu.h>
#include <stdio.h>

const double ViewWindow::FOV_X = 45.0;

ViewWindow::ViewWindow(int x, int y, int width, int height, char *label)
	: Fl_Gl_Window(x, y, width, height, label)
{

	// Set the mouse button to zero
	button = -1;

  // Initial viewing parameters.
	phi   = 60.0f;
  theta = 0.0f;
  dist  = 250.0f;
  x_at  = 0.0f;
  y_at  = 2.0f;
	z_at  = 0.0f;

	// Initialize the graphic
	colours.clear();
	colours.push_back(vect3<GLfloat>( 1.0f, 1.0f, 1.0f));// White
	colours.push_back(vect3<GLfloat>( 1.0f, 0.0f, 0.0f));// Red
	colours.push_back(vect3<GLfloat>( 0.0f, 1.0f, 0.0f));// Green
	colours.push_back(vect3<GLfloat>( 0.0f, 0.0f, 1.0f));// Blue
	colours.push_back(vect3<GLfloat>( 1.0f, 1.0f, 0.0f));// Yellow
	colours.push_back(vect3<GLfloat>( 1.0f, 0.0f, 1.0f));// purple
	colours.push_back(vect3<GLfloat>( 0.0f, 1.0f, 1.0f));// Cyan
	colours.push_back(vect3<GLfloat>( 1.0f, 0.5f, 0.25f));// Bright Brown
	colours.push_back(vect3<GLfloat>( 0.5f, 0.25f, 0.25));// Deep Brown
	colours.push_back(vect3<GLfloat>( 0.0f, 0.5f, 0.0));// Deep Green
	colours.push_back(vect3<GLfloat>( 0.5f, 0.5f, 0.25));// Deep Green

  
	the_Graphics = new GLGraphics(&colours);

	// Initialize the LString
	the_LString	 = new LString(mul);
	the_LTurtle = new LTurtle(*the_LString, *the_Graphics);
	FileFlag = false;
}

ViewWindow::~ViewWindow()
{
	if(the_Graphics)
		delete the_Graphics;
	if(the_LString)
		delete the_LString;
	if(the_LTurtle)
		delete the_LTurtle;
}
	
void ViewWindow::draw(void)
{
  float   color[4], dir[4];

  if ( ! valid() ) {
		// Stuff in here doesn't change from frame to frame, and does not
		// rely on any coordinate system. It only has to be done if the
		// GL context is damaged.
		glClearColor(0, 0, 0, 1.0);

		// Turn on depth testing
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		// Turn on back face culling. Faces with normals away from the viewer
		// will not be drawn.
		glEnable(GL_CULL_FACE);

		// Enable lighting with one light.
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);

		// Ambient and diffuse lighting track the current color.
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

		// Turn on normal vector normalization. You don't have to give unit
		// normal vector, and you can scale objects.
		glEnable(GL_NORMALIZE);

		// Set up the viewport.
		glViewport(0, 0, w(), h());
		// Set up the persepctive transformation.
		setupProject();
		// Do some light stuff. Diffuse color, and zero specular color
		// turns off specular lighting.
		color[0] = 1.0f; color[1] = 1.0f; color[2] = 1.0f; color[3] = 1.0f;
		glLightfv(GL_LIGHT0, GL_DIFFUSE, color);

		color[0] = 0.0f; color[1] = 0.0f; color[2] = 0.0f; color[3] = 1.0f;
		glLightfv(GL_LIGHT0, GL_SPECULAR, color);

		// Initialize all the objects.
		ground.Initialize();

/*		the_Graphics->BeginStore();
		std::vector<vect3<GLfloat> > testVertices;
	  testVertices.push_back(vect3<GLfloat>( 1.0,  1.0, 0.0));
		testVertices.push_back(vect3<GLfloat>(-1.0,  1.0, 0.0));
		testVertices.push_back(vect3<GLfloat>(-1.0, -1.0, 0.0));
		testVertices.push_back(vect3<GLfloat>( 1.0, -1.0, 0.0));
	  testVertices.push_back(vect3<GLfloat>( 1.0,  1.0, 3.0));
		testVertices.push_back(vect3<GLfloat>(-1.0,  1.0, 3.0));
		testVertices.push_back(vect3<GLfloat>(-1.0, -1.0, 3.0));
		testVertices.push_back(vect3<GLfloat>( 1.0, -1.0, 3.0));
*/
//		the_Graphics->StoreHexahedron(&testVertices, 0);
/*	  testVertices.push_back(vect3<GLfloat>(  0.0,   0.0, 1.0));
		testVertices.push_back(vect3<GLfloat>( 10.0,   0.0, 1.0));
		testVertices.push_back(vect3<GLfloat>(  0.0,  10.0, 1.0));
		testVertices.push_back(vect3<GLfloat>( 20.0,   0.0, 1.0));
	  testVertices.push_back(vect3<GLfloat>(  0.0,  20.0, 1.0));
		testVertices.push_back(vect3<GLfloat>( 25.0,  25.0, 1.0));
		the_Graphics->StoreTriangleStrip(&testVertices, 0);*/
//		the_Graphics->EndStore();
  }

	glClearColor(0, 0, 0, 1.0);

  // Clear the screen. Color and depth.
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//*************************************************************************
	// This should be change according to the path
	//*************************************************************************
  // Set up the viewing transformation. The viewer is at a distance
	setupModelView();
  // Position the light source. This has to happen after the viewing
  // transformation is set up, so that the light stays fixed in world
  // space. This is a directional light - note the 0 in the w component.
  dir[0] = 1.0; dir[1] = 1.0; dir[2] = 1.0; dir[3] = 0.0;
  glLightfv(GL_LIGHT0, GL_POSITION, dir);

  // Draw stuff. Everything.
	glPushMatrix();
	ground.Draw();
	if(FileFlag)
		the_LTurtle->Draw();
	glPopMatrix();

}

void ViewWindow::Drag(float dt)
{
	int	    dx = x_down - x_last;
  int     dy = y_down - y_last;

  switch ( button )
  {
    case FL_LEFT_MOUSE:
				// Left button changes the direction the viewer is looking from.
				theta = theta_down + 360.0f * dx / (float)w();
				while ( theta >= 360.0f )
						theta -= 360.0f;
				while ( theta < 0.0f )
						theta += 360.0f;
				phi = phi_down + 90.0f * dy / (float)h();
				if ( phi > 89.0f )
						phi = 89.0f;

			break;
    case FL_MIDDLE_MOUSE:
			// Middle button moves the viewer in or out.
			dist = dist_down - ( 0.5f * dist_down * dy / (float)h() );
			if ( dist < 1.0f )
					dist = 1.0f;
			break;
    case FL_RIGHT_MOUSE: {
			// Right mouse button moves the look-at point around, so the world
			// appears to move under the viewer.
			float	x_axis[2];
			float	y_axis[2];

			x_axis[0] = -(float)sin(theta * M_PI / 180.0);
			x_axis[1] = (float)cos(theta * M_PI / 180.0);
			y_axis[0] = x_axis[1];
			y_axis[1] = -x_axis[0];

			x_at = x_at_down + 100.0f * ( x_axis[0] * dx / (float)w()
								+ y_axis[0] * dy / (float)h() );
			y_at = y_at_down + 100.0f * ( x_axis[1] * dx / (float)w()
								+ y_axis[1] * dy / (float)h() );
			} 
			break;
    default:;
  }
}

bool ViewWindow::Update(float dt)
{
    // Update the view. This gets called once per frame before doing the
    // drawing.
    if ( button != -1 ) // Only do anything if the mouse button is down.
		Drag(dt);

    return true;
}

int ViewWindow::handle(int event)
{
    // Event handling routine. Only looks at mouse events.
    // Stores a bunch of values when the mouse goes down and keeps track
    // of where the mouse is and what mouse button is down, if any.
    switch ( event )
    {
      case FL_PUSH:
        button = Fl::event_button();
				x_last = x_down = Fl::event_x();
				y_last = y_down = Fl::event_y();
				phi_down = phi;
				theta_down = theta;
				dist_down = dist;
				x_at_down = x_at;
				y_at_down = y_at;
				return 1;
      case FL_DRAG:
				x_last = Fl::event_x();
				y_last = Fl::event_y();
				return 1;
      case FL_RELEASE:
        button = -1;
				return 1;
    }

    // Pass any other event types on the superclass.
    return Fl_Gl_Window::handle(event);
}

//********************************************************
// Get the frame number
//********************************************************
void ViewWindow::setLookAt(float x, float y, float z)
{
	x_at = x;
	y_at = y;
	z_at = z;
}

void ViewWindow::setupProject()
{
	// Set up the viewing transformation. The viewer is at a distance
	// dist from (x_at, y_ay, z_at) in the direction (theta, phi) defined
	// by two angles. They are looking at (x_at, y_ay, 2.0) and z is up.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set up the persepctive transformation.
	fov_y = 360.0f / M_PI * atan(h() * tan(FOV_X * M_PI / 360.0) / w());
	gluPerspective(fov_y, w() / (float)h(), 1.0, 1000.0);
}

void ViewWindow::setupModelView()
{
  eye[0] = x_at + dist * sin(theta * M_PI / 180.0) * cos(phi * M_PI / 180.0);
  eye[1] = y_at + dist * sin(phi * M_PI / 180.0);
  eye[2] = z_at + dist * cos(theta * M_PI / 180.0) * cos(phi * M_PI / 180.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eye[0], eye[1], eye[2], x_at, y_at, z_at, 0.0, 1.0, 0.0);
	
}
bool  ViewWindow::openLFile(char *filename)
{
	the_LString->parserFile(filename);
	the_LString->Parse();
	the_LTurtle->InitDraw();
	FileFlag = true;
	return true;
}