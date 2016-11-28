/*******************************************************************************
		Main:												MCViewer.cpp

		Program:										ground.H

		Comment:										Header File for creating the ground

		Author:											James Gant, gant@cs.wisc.edu
																Yu-Chi Lai, yu-chil@cae.wisc.edu

		Complete Date:							Mar 09, 2003

		Course:											CS777, Spring 2003

		Compiler:                   Visual C Studio
		Platform:                   Windows 2000
*******************************************************************************/


#ifndef _GROUND_H_
#define _GROUND_H_

#include <Fl/gl.h>

class Ground {
  private:
    GLubyte display_list;   // The display list that does all the work.
    GLuint  texture_obj;    // The object for the grass texture.
    bool    initialized;    // Whether or not we have been initialised.
	float WIDTH;
	float LENGTH;

  public:
    // Constructor. Can't do initialization here because we are
    // created before the OpenGL context is set up.
    Ground(void) { 
		display_list = 0; 
		initialized = false;
		WIDTH = 100.0f;
		LENGTH = 100.0f;
	};

    // Destructor. Frees the display lists and texture object.
    ~Ground(void);

    // Initializer. Creates the display list.
    bool    Initialize(void);

    // Does the drawing.
    void    Draw(void);
};


#endif
