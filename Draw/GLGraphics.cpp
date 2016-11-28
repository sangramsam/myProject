/*******************************************************************************
		Main Program:					Viewer.cpp

		Comment:							Graphic drawing interface

		Author:								Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:								CS777, Spring 2003
*******************************************************************************/
#include "GLGraphics.h"

//***************************************************************************
// Constructor
//***************************************************************************
GLGraphics::GLGraphics(std::vector <vect3<GLfloat> > *colour_array):
  colours(colour_array)
{
  initialized = false;
  theLsys = 0;
}

//***************************************************************************
// Store
//***************************************************************************
void GLGraphics::StoreHexahedron(std::vector <vect3<float> > *vertex, unsigned short int colour)
{
  //Vertices used for each side of the cube 
  static GLubyte side[10][4] = {{ 2, 3, 13, 12}, 
																{ 3, 4, 14, 13}, 
																{ 4, 5, 15, 14},
																{ 5, 6, 16, 15},
																{ 6, 7, 17, 16},
																{ 7, 8, 18, 17},
																{ 8, 9, 19, 18},
																{ 9,10, 20, 19},
																{10,11, 21, 20},
																{11, 2, 12, 21}};

  //Vertices used for each side of the cube 
  static GLubyte bottom[10][3] = {	{ 0, 3, 2}, 
																{ 0, 4, 3}, 
																{ 0, 5, 4},
																{ 0, 6, 5},
																{ 0, 7, 6},
																{ 0, 8, 7},
																{ 0, 9, 8},
																{ 0,10, 9},
																{ 0,11,10},
																{ 0, 2,11}};

  //Vertices used for each side of the cube 
  static GLubyte top[10][3] = {	{ 1, 12, 13}, 
																		{ 1, 13, 14}, 
																		{ 1, 14, 15},
																		{ 1, 15, 16},
																		{ 1, 16, 17},
																		{ 1, 17, 18},
																		{ 1, 18, 19},
																		{ 1, 19, 20},
																		{ 1, 20, 21},
																		{ 1, 21, 12}};
  //Storage for each of the 8 vertices
  static GLfloat   ver[66];
  
  if (vertex->size() == 22) {    //assume 8 vertices
    vect3<GLfloat> d1, d2, normal;

    //transfer the data into the "ver" storage array
    for (int i = 0; i < 22; i++) {
      ver[i * 3]=((*vertex)[i])[0];
      ver[i * 3 + 1]=((*vertex)[i])[1];
      ver[i * 3 + 2]=((*vertex)[i])[2];
    }

    //set the colour
    glColor3fv((*colours)[colour%(colours->size())].data);

    //point the GL functions at the storage array
    glVertexPointer(3, GL_FLOAT, 0, ver);


		// Calculate the bottom face normal
		d1 = (*vertex)[3] - (*vertex)[0];
		d2 = (*vertex)[2] - (*vertex)[0];

    normal = d1 * d2;
    normal.normalize();
    glNormal3fv(normal.data);
		for(int i = 0; i < 10; i++)
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom[i]);

		// Calculate the top face normal
		d1 = (*vertex)[12] - (*vertex)[1];
		d2 = (*vertex)[13] - (*vertex)[1];

    normal = d1 * d2;
    normal.normalize();
    glNormal3fv(normal.data);
		for(int i = 0; i < 10; i++)
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, top[i]);
    
		for(int i = 0; i < 10; i++){
			int index1 = i + 2;
			if(index1 > 11)
				index1 = 2;
			int index2 = i + 3;
			if(index2 > 11)
				index2 = 2;
			int index3 = i + 12;
			if(index3 > 21)
				index3 = 12;

			// Calculate the top face normal
			d1 = (*vertex)[index2] - (*vertex)[index1];
			d2 = (*vertex)[index3] - (*vertex)[index1];

			normal = d1 * d2;
			normal.normalize();
			glNormal3fv(normal.data);
			glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, side[i]);
		}
  }// end of if
}

//***************************************************************************
// Store Triangle strip
//***************************************************************************
void GLGraphics::StoreTriangleStrip(std::vector <vect3<float> > *vertex, unsigned short int colour)
{
	vect3<float>     center(0, 0, 0);

	int i;

	for(i = 0; i < (*vertex).size(); i++)
		center += (*vertex)[i];
	
	center /= (float)(*vertex).size();

	
  glBegin(GL_TRIANGLES);
	for ( i = 0; i < (*vertex).size(); i++ ){
    vect3<GLfloat>  d[2], normal;

		int index0, index1;
		index0 = i; 
		index1 = i + 1;

		if(index1 >= (*vertex).size())
			index1 = 1;

    d[0] = center - (*vertex)[index0];
    d[1] = (*vertex)[index1] - (*vertex)[index0];
    normal = d[0] * d[1];
    normal.normalize();
    glNormal3fv(normal.data);

    glVertex3f(center[0], center[1], center[2]);
    glVertex3f((*vertex)[index0][0], (*vertex)[index0][1], (*vertex)[index0][2]);
    glVertex3f((*vertex)[index1][0], (*vertex)[index1][1], (*vertex)[index1][2]);
	}
	glEnd();

}

//***************************************************************************
// Set up the display list
//***************************************************************************
void GLGraphics::BeginStore()
{    
	// True if initialisation finished
  initialized = false;

	// Generate a drawing list
  theLsys  = glGenLists(1);
  if (theLsys==0) { 
    printf("Bugger, could not allocate glList!\n");  
    abort();
  }
  glNewList(theLsys, GL_COMPILE);
	// Set up the flag why need this one, it should be used in the server and client
  glEnableClientState (GL_VERTEX_ARRAY);
}

//***************************************************************************
// Terminate the drawing list
//***************************************************************************
void GLGraphics::EndStore()
{
  glEndList();
  initialized = true;
}

void GLGraphics::Draw()
{
	// Output the image
  if (theLsys != 0) 
    glCallList(theLsys);
}

//**********************************************************************
// Reset the Graphics
//**********************************************************************
void GLGraphics::Clear()
{
	// Delete the display list
  if (theLsys!=0)
    glDeleteLists(theLsys, 1);
  theLsys = 0;
	// Set the render and outputdone to false
  initialized = false;
}

//**********************************************************************
// Check whether the scene has ever been initialize
//**********************************************************************
bool GLGraphics::Is_Initialized()
{
  return initialized;
}


