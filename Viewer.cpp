/*******************************************************************************
		Main Program:			MCViewer.cpp

		Comment:					The main file for our program

		Author:						James Gant, gant@cs.wisc.edu
											Yu-Chi Lai, yu-chil@cae.wisc.edu

		Complete Date:		Mar 09, 2003

		Course:						CS777, Spring 2003
		Compiler:         Visual C Studio
		Platform:         Windows 2000

*******************************************************************************/

#include "global/globals.h"
#include "ViewWindow.h"
#include <stdio.h>

// Header file for FLTK
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Check_Button.H>

//***************************************************************
// Control related global variable
//***************************************************************
// The time per frame, in seconds (enforced only by timeouts.)
// renew rate when play it should be control by the real frame rate
static float  FRAME_TIME = 0.03333333f;

float STARTX			 = 100;
float STARTY			 = 100;
int		frames			 = 0;
int		currentFrame = 1;
int		totalEnd = -1;
int		startingItemNum = 0;

//*****************************************************************
// Window related pointer allocated
//******************************************************************

// The window with world view in it
static ViewWindow				*viewWindow; 

// The control window
static Fl_Window			*Control_window;

static Fl_Menu_Bar				*menu_bar;

//*******************************************************************
// Open the open dialog
//*******************************************************************

static void open_cb(){
	//viewWindow->deleteall();
	char *newfile = NULL;
	newfile = fl_file_chooser("Open File", "*.ls", "");
	if(newfile != NULL){
		if(!viewWindow->openLFile(newfile))
			return;
	}
	else
		return;
}

//*************************************************************
// Open the save dialog
//*************************************************************
static void saveas_cb(){
/*	char *newfile;

	newfile = fl_file_chooser("Save File As?", "*", "");
	if(newfile != NULL){
		viewWindow->writeScript(newfile);
	}*/
}

//**************************************************************
// Close BVH files
//**************************************************************
static void close_cb(){
/*	play = false;
	currentFrame = 1;
	frames = 1;
	viewWindow->deleteall();*/
}


//**************************************************************
// Close window
//**************************************************************
static void quit_cb(){exit(0);}

//****************************************************************
// Menu Item
//*****************************************************************
Fl_Menu_Item menuitems[] = {
		{ "&File",              0, 0, 0, FL_SUBMENU },
    { "Open L-System File ...",    FL_CTRL + 'o', (Fl_Callback *)open_cb },
    { "Save File &As...", FL_CTRL + 's', (Fl_Callback *)saveas_cb, 0, FL_MENU_DIVIDER },
    { "&Close BVH Files", FL_CTRL + 'w', (Fl_Callback *)close_cb,},
    { "E&xit", FL_CTRL + 'q', (Fl_Callback *)quit_cb, 0 },
    { 0 },
		{ 0 }
};


// This callback is called every 40th of a second if the system is fast
// enough. You should change the variable FRAME_TIME defined above if you
// want to change the frame rate.
static void Timeout_Callback(void *data)
{
    // Update the motion in the world. This both moves the view and
    // animates the train.
    viewWindow->Update(FRAME_TIME);
    viewWindow->redraw();

    // Do the timeout again
    Fl::repeat_timeout(FRAME_TIME, Timeout_Callback);
}

int main(int argc, char *argv[])
{
	// Set up the color mode
  Fl::visual(FL_RGB);
	// Create the control window
  Control_window = new Fl_Window(STARTX, STARTY, 810, 700, "Motion Capture Viewer");
	// Start the control window
	Control_window->begin();
	// Create the motion window
	viewWindow = new ViewWindow(5, 20, 800, 600, "");

	// Create the menu
	menu_bar = new Fl_Menu_Bar(0,0,810,20);
	menu_bar->box(FL_FLAT_BOX);
	menu_bar->copy(menuitems);
	
	Control_window->end();
	Control_window->show(argc, argv);

  Fl::add_timeout(0.0, Timeout_Callback, NULL);

  return Fl::run();
}
