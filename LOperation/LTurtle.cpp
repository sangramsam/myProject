/*******************************************************************************
		Main Program:					Viewer.cpp

		Comment:							Basic LString Drawer

		Author:								Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:								CS777, Spring 2003
*******************************************************************************/
#include "LTurtle.h"
#include "../math/ExtraMath.h"
#include "../math/drand48.h"

//*******************************************************************
// Constructor of the turtle
//*******************************************************************
LTurtle::LTurtle(LString& inLString, GLGraphics& inGLGraphics):
								 the_LString(inLString), the_GLGraphics(inGLGraphics)
{
	// The sky direction to the z direction
  sky[0]= 0.0; 
	sky[1]= 0.0; 
	sky[2]= 1.0;
	// random amount
  rand_amount = 3;
	// The random seed
  RandSeed    = 10;
}


//**********************************************************************
// Destructor
//***********************************************************************
LTurtle::~LTurtle()
{
}

//*******************************************************************
// Initialize the draw center
//*******************************************************************
bool LTurtle::InitDraw()
{
	// The center vector
  static vect3<float>  the_centre;
	// The maximum length
  static double max_length = 0;
	// Check whether the LString and Graphic has been  
  if (CheckSetup() == false)
    return false;

	createString();

  // Clear the graphic buffer
  the_GLGraphics.Clear();
	// Set up the display list
  the_GLGraphics.BeginStore();
  // Calculate and draw the LString
  the_centre.assign(0.0, 0.0, 0);
  this->PlotLstring(the_centre, 1, 1);

  // End of the display list
  the_GLGraphics.EndStore();  

  return true;
}
//*************************************************************************
// Checks whether the string exist or not
//*************************************************************************
bool LTurtle::CheckSetup()
{
  if (!the_LString.FinalStringExists()) {
    Warning("Unparsed Lstring");
    return false;
  }
  return true;
}

//*******************************************************************
// Draw the picture
//*******************************************************************
bool LTurtle::Draw() 
{
  // Check whether the String has been set up
  if (CheckSetup() == false)
    return false;

	//*************************************************
  // Check whether there are some draw in the graphic
	//*************************************************
  if (the_GLGraphics.Is_Initialized() == false) {
    if (InitDraw() == false)
      return false;
  }

  //actually draw
  the_GLGraphics.Draw();
  return true;
}

//*******************************************************************
// Set up the rand seed
//*******************************************************************
void LTurtle::SetRandSeed(int i)
{
  RandSeed = i;
}

//**********************************************************************
// Process a production string
// The main program of the turtle program
//**********************************************************************
void LTurtle::PlotLstring(vect3<float> &centre, float height, float leafLength)
{
	vect3<float>   end;
  float32				 min_thick, fraction, r, a;
	float32				 thick_l, ang_l, dis_l, dis2_l, trope_l; // the last value of thick, angle, distance, half_distance, trope
	float32        unitLength, drawLength;
	float32				 val;		// The value inside the small blanket 
	float32        randAng;
  int						 r_depth;	// the total level of recursion
  bool					 last_recur = false; // Check whether it is the last recursion
	bool					 rand_set, poly_on = false;
  bool					 user_form = false, closed_form = false, trope_set;

  s_rec	 current_s;	// current state
	s_rec	 save;			// State to be save
  p_rec  current_p;
  stack<s_rec, vector<s_rec> >	s_stack;
  stack<p_rec, vector<p_rec> >	p_stack;

  //declare references (aliases) to commonly used members of current_s;
  vect3<float>  &pos					= current_s.pos;
  vect3<float>  &fow					= current_s.fow;
  vect3<float>  &lef					= current_s.lef;
  vect3<float>  &upp					= current_s.upp;
  vect3<float>  &last					= current_s.last;
  float32	      &dis					= current_s.dis;
  float32       &ang					= current_s.ang;
  float32	      &thick				= current_s.thick;
	float32       &thickness		= current_s.thickness;
	float32				&oldThickness = current_s.oldThickness;
  float32	      &dis2					= current_s.dis2;
  float32	      &tr						= current_s.tr;
  uint16				&col					= current_s.col;
	bool					&thickInit		= current_s.thickInit;  

  // Setup initial values and vects
  rand_set     = UI_IS_RAND_SET;
  trope_set    = UI_IS_TROPE_SET;
  trope_amount = UI_TROPE_AMOUNT;

  min_thick    = percent2unit(UI_MIN_THICK);
  tr           = UI_TR;
  fraction     = the_LString.get_fraction();
  ang					 = deg2rad(the_LString.get_ang());

	// This will change the length of the tree
  dis					 = percent2unit(UI_DIST);
  thick	       = percent2unit(the_LString.get_thick());
	thickness		 = thick * dis * height;
  dis2	       = dis / 2.0;
  col          = 0;
	thickInit		 = false;

  last.assign(1, 1, 1);
  pos = centre;
  fow.assign(0, 1, 0);
  lef.assign(1, 0, 0);
  upp.assign(0, 0, 1);

	// Set up the random seed
  SRndM(RandSeed);

	// Check whether the LString has been parse or not
	if(!the_LString.FinalStringExists())
		the_LString.Parse();

	// Extract the length of the final string
  size_t        StrLength = the_LString.FinalStringLength();
	// Set up the string position
  unsigned long StrPos    = 0;
	// Go through the entire string
  while ( StrPos < StrLength) {
		// The level of the string
    r_depth = the_LString.FinalStringRecLev();
		// the current char in the string 

    switch (the_LString.FinalStringChr(StrPos++)) {             
			default:
				break;
			// Marks last recursion level during growing phase
			case '@':          
				last_recur = !last_recur;
				// Store all vars and do fraction
				if (last_recur) {              
					thick_l = thick;
					ang_l		= ang;
					dis_l		= dis;
					dis2_l	= dis2;
					trope_l = trope_amount;
					//?????????????????????????????
					// Why need fraction
					dis						*= fraction;
					dis2					*= fraction;
					thick					*= fraction;
					ang						*= fraction;
					trope_amount	*= fraction;
	      } 
			// Restore
			else {                       
				thick				 = thick_l;
				ang					 = ang_l;
				dis					 = dis_l;
				dis2				 = dis2_l;
				trope_amount = trope_l;
      }
      break;
		//******************************************************************
		// Angle Operation
		//******************************************************************
    // Turn left of the up
    case '+':
      save.ang = ang;
      if (the_LString.Get_value(StrPos, val)) { //has brackets
				ang = deg2rad(val);
				if (last_recur)
					ang *= fraction * fraction; 
			}
			if(!poly_on)
				ang += Normalize(0.0, 1.0) * 0.5 * ang; 

			// Set up the rotation angle
      Set_rot(-ang, upp);
			// Set up the forward direction
      fow = fow.Util_t(C1, C2, C3);
			// Set up the left direction
      lef = lef.Util_t(C1, C2, C3);
			// Normalize the forward vector
      fow.normalize();
			// Normalize the left vector
      lef.normalize();
			// Recover the rotation angle
      ang = save.ang;
      break;
    // Turn right of the up 
    case '-':
			// 
      save.ang = ang;
      if (the_LString.Get_value(StrPos,val)) {
				ang = deg2rad(val);
				if (last_recur)
					ang *= fraction * fraction; 
      }
			if(!poly_on)
				ang += Normalize(0.0, 1.0) * 0.5 * ang; 
      Set_rot(ang, upp);
      fow = fow.Util_t(C1, C2, C3);
      lef = lef.Util_t(C1, C2, C3);
      fow.normalize();
      lef.normalize();
      ang = save.ang;
      break;
     // Pitch down left angle 
    case '&':
			// For restore the original angle
      save.ang = ang;
      if (the_LString.Get_value(StrPos, val)) {
				ang = deg2rad(val);
				if (last_recur)
					ang *= fraction * fraction;
      }
			if(!poly_on)
				ang += Normalize(0.0, 1.0) * 0.5 * ang; 
      Set_rot(ang, lef);
      fow=fow.Util_t(C1, C2, C3);
      upp=upp.Util_t(C1, C2, C3);
      fow.normalize();
      upp.normalize();
      ang = save.ang;
      break;
      
     // Pitch up left angle 
    case '^':
			// For restore the original angle
      save.ang = ang;
      if (the_LString.Get_value(StrPos, val)){
				ang = deg2rad(val);
				if (last_recur)
					ang *= fraction * fraction;
      }
			if(!poly_on)
				ang += Normalize(0.0, 1.0) * 0.5 * ang; 
      Set_rot(-ang, lef);
      fow=fow.Util_t(C1, C2, C3);
      upp=upp.Util_t(C1, C2, C3);
      fow.normalize();
      upp.normalize();
      ang = save.ang;
      break;
		// roll left CCW
    case '<':
      save.ang = ang;
      if (the_LString.Get_value(StrPos,val)) {
				ang = deg2rad(val);
				if (last_recur)
					ang *= fraction * fraction;
      }
			if(!poly_on)
				ang += Normalize(0.0, 1.0) * 0.5 * ang; 
      Set_rot(-ang, fow);
      lef=lef.Util_t(C1, C2, C3);
      upp=upp.Util_t(C1, C2, C3);
      lef.normalize();
      upp.normalize();
      ang = save.ang;
      break;
    // roll left CW  
    case '>':
      save.ang = ang;
      if (the_LString.Get_value(StrPos,val)) {
				ang = deg2rad(val);
				if (last_recur)
					ang *= fraction * fraction;
      }
			if(!poly_on)
				ang += Normalize(0.0, 1.0) * 0.5 * ang; 
      Set_rot(ang, fow);
      lef=lef.Util_t(C1, C2, C3);
      upp=upp.Util_t(C1, C2, C3);
      lef.normalize();
      upp.normalize();
      ang = save.ang;
      break;
		//????????????????????????????????????????????????????????
    case '`':
      r_depth = the_LString.FinalStringRecLev() - 
								the_LString.Get_RecursionChar(StrPos);
			break;
		//************************************************************
		// Special orientation command
		//************************************************************
		// Turn 180 around up vector
    case '|':
      Set_rot(3.141592654f, upp);
      fow=fow.Util_t(C1, C2, C3);
      lef=lef.Util_t(C1, C2, C3);
      fow.normalize();
      lef.normalize();
      break;
		// Turn 180 around the foward vector
    case '%':
      Set_rot(3.141592654f, fow);
      lef=lef.Util_t(C1, C2, C3);
      upp=upp.Util_t(C1, C2, C3);
      lef.normalize();
      upp.normalize();
      break;

		// Turn until horizontal
    case '$':
      if ((fow - sky).length() == (float32) 0.0)
				break;
      lef = fow * sky;
      upp = fow * lef;
      if (upp[_z] < (float32) 0.0) {
				upp = -upp;
				lef = -lef;
      }
      break;
		// Rotate about up, left, forward in a random direction
    case '~':
      if (the_LString.Get_value(StrPos, val)) {
				r = deg2rad(val);
				if (last_recur)
					r *= fraction;	//only draw a fraction
	    }
			else
				r = deg2rad(UI_RAND_AMOUNT);

			// Generate a random variable in this depth and rotate about up
      a = (Rnd(r_depth) * r * (float32) 2.0) - r;
      Set_rot(a, upp);
      fow = fow.Util_t(C1, C2, C3);
      lef = lef.Util_t(C1, C2, C3);
      fow.normalize();
      lef.normalize();

			// Generate a random variable in this depth and rotate about left
      a = (Rnd(r_depth) * r * (float32) 2.0) - r;
      Set_rot(a, lef);
      fow=fow.Util_t(C1, C2, C3);
      upp=upp.Util_t(C1, C2, C3);
      fow.normalize();
      upp.normalize();

			// Generate a random variable in this depth and rotate about foward
      a = (Rnd(r_depth) * r * (float32) 2.0) - r;
      Set_rot(a, fow);
      lef=lef.Util_t( C1, C2, C3);
      upp=upp.Util_t(C1, C2, C3);
      lef.normalize();
      upp.normalize();
      break;
    // Correction for the gravity  
    case 't':
			// Only have z component do not need to correct
      if ((fow[_x] == (float32) 0.0) && (fow[_y] == (float32) 0.0))
				break;
			// Save current tr
      save.tr = tr;
			// If trope is set, use the trope_amount, always false in current setting
      if (trope_set)
				tr = trope_amount;
      if (the_LString.Get_value(StrPos,val)) {
				tr = val;
			if (last_recur)
				tr *= fraction * fraction; //why
      }
      tr = save.tr;
      break;

		//************************************************************
		// Movement command
		//************************************************************
		// Move forward a full distance or val
    case 'F':
      save.dis = dis;
      if (the_LString.Get_value(StrPos, val)) {
				dis = percent2unit(val);
				if (last_recur)
					dis *= fraction;
      }

			// End pointer of current turtle
			unitLength = dis * height;
			drawLength = unitLength + unitLength * Normalize(0, 2) * 0.5;
			if(drawLength <= 0)
				drawLength = unitLength;
      end.plus_fac(pos, fow, drawLength);

		  thick = (thick < (float32) min_thick) ? min_thick : thick;
			thickness = thick * unitLength;
			if(!thickInit){
				oldThickness = thickness;
				thickInit = true;
			}

			Define_block(pos, end, upp, thickness, oldThickness, min_thick, col);

      pos = end;
      dis = save.dis;
			oldThickness = thickness;
      break;

		// Move forward a full distance or val
    case 'f':
      save.dis = dis;
      if (the_LString.Get_value(StrPos,val)) {
				dis = percent2unit(val);
				if (last_recur)
					dis *= fraction;
      }
			
			unitLength = leafLength * dis;
			drawLength = unitLength;
      pos.plus_fac(pos, fow, drawLength);
      if (poly_on) 
				current_p.push_back(pos);
      dis = save.dis;
      break;
		// Move forward a half distance or val
    case 'Z':
      save.dis2 = dis2;
      if (the_LString.Get_value(StrPos, val)) {
				dis2 = percent2unit(val);
				if (last_recur)
					dis2 *= fraction;
      }

			unitLength = dis2 * height ;
			drawLength = unitLength + unitLength * Normalize(0, 2) * 0.5;
			if(drawLength <= 0)
				drawLength = unitLength;
      end.plus_fac(pos, fow, drawLength);

		  thick = (thick < (float32) min_thick) ? min_thick : thick;
			thickness = thick * unitLength;
			if(!thickInit){
				oldThickness = thickness;
				thickInit = true;
			}
			Define_block(pos, end, upp, thickness, oldThickness, min_thick, col);
      pos  = end;
      dis2 = save.dis2;
			oldThickness = thickness;
      break;
      
    case 'z':
      save.dis2 = dis2;
      if (the_LString.Get_value(StrPos,val)) {
				dis2 = percent2unit(val);
				if (last_recur)
					dis2 *= fraction;
      }

			// Move the position forward
			unitLength = leafLength * dis2;
			drawLength = unitLength;
      pos.plus_fac(pos, fow, drawLength);
			//???????????????????????????????????
      if (poly_on) 
				current_p.push_back(pos);
      dis2 = save.dis2;
		  break;
    // Forward the distance but did not draw anything
    case 'g':
      save.dis = dis;
      if (the_LString.Get_value(StrPos,val)) {
				dis = percent2unit(val);
				if (last_recur)
					dis *= fraction;
      }
			unitLength = leafLength * dis;
			drawLength = unitLength;
      pos.plus_fac(pos, fow, drawLength);
      dis = save.dis;
      break;

    case '.':
			//???????????????????????????????????
      if (poly_on) 
				current_p.push_back(pos);
			else{
				unitLength = leafLength * dis;
				thick = (thick < (float32) min_thick) ? min_thick : thick;
				thickness = thick * unitLength;
				if(!thickInit){
					oldThickness = thickness;
					thickInit = true;
				}
			}
      break;
    
		//************************************************************
		// Structure command
		//************************************************************
		case '(':          
			StrPos--;
			the_LString.Get_value(StrPos, val);
			break;
		// Push the current state
    case '[':
      s_stack.push(current_s);
      break;
    // pop out the previous state
    case ']':
			// Pop out the current state
      current_s = s_stack.top();
      s_stack.pop();
      break;
    // Start polygon shape
    case '{': //start a new polygon structure
			//push the old polygon structure onto the stack
      if (poly_on) 
				p_stack.push(current_p);

			// Clear the polygon structure and restart it
      poly_on = true;
      current_p.clear();
      current_p.push_back(pos);
      break;
      
    case '}':
			printf("Eexute Draw operation %d\n", current_p.size());

			// Draw the current pattern
      Define_triangles(&current_p, col);

			// Clear it
      current_p.clear();
			// Turn off the poly state, it may for the leaf ????
      if (p_stack.empty()) {
				poly_on = false;
      } 
			// Go to the next state
			else {
				current_p = p_stack.top();
				p_stack.pop();
				poly_on = true;
      }
      break;
		//*************************************************
		// increment and decrement command
		//*************************************************
		// Increment the length
    case '\"':
			// Extract the value
      if (the_LString.Get_value(StrPos,val)) {
				r = val;
				// If this is the last recurrence
				if (last_recur) {
					dis  *= one + fraction * (r - one);
					dis2 *= one + fraction * (r - one);
				}
				else {
					dis  *= r;
					dis2 *= r;
				}
      } 
			else {
				if (last_recur) {
					dis  /= one + fraction * ((float32) LENGTH_DECR - one);
					dis2 /= one + fraction * ((float32) LENGTH_DECR - one);
				}
				else {
					dis  /= (float32) LENGTH_DECR;
					dis2 /= (float32) LENGTH_DECR;
				}
      }
      break;

		// Decrement the length
    case '\'':
      if (the_LString.Get_value(StrPos,val)) {
				r = val;
				if (last_recur) {
					dis  *= one + fraction * (r - one);
					dis2 *= one + fraction * (r - one);
				}
				else {
					dis  *= r;
					dis2 *= r;
				}
	    }
			else {
				if (last_recur) {
					dis  *= one + fraction * ((float32) LENGTH_DECR - one);
					dis2 *= one + fraction * ((float32) LENGTH_DECR - one);
				}
				else {
				  dis  *= (float32) LENGTH_DECR;
					dis2 *= (float32) LENGTH_DECR;
				}
      }// end of else
      break;

		// Increment the angle
    case ';':
      if (the_LString.Get_value(StrPos,val)) {
				if (last_recur)
					ang *= one + fraction * (val - one);
				else
					ang *= val;
      } 
			else {
				if (last_recur)
					ang /= one + fraction * ((float32) ANGLE_DECR - one);
				else
					ang /= (float32) ANGLE_DECR;
		  }
      break;

		// Decrement the angle
    case ':':
      if (the_LString.Get_value(StrPos,val)) {
				if (last_recur)
					ang *= one + fraction * (val - one);
				else
					ang *= val;
      }
			else {
				if (last_recur)
					ang *= one + fraction * ((float32) ANGLE_DECR - one);
				else
					ang *= (float32) ANGLE_DECR;
      }
      break;

		// Increment the thickness  
    case '?':
      if (the_LString.Get_value(StrPos,val)) {
				if (last_recur)
					thick *= one + fraction * (val - one);
				else
					thick *= val;
      } 
			else {
				if (last_recur)
					thick /= one + fraction * ((float32) THICK_DECR - one);
				else
					thick /= (float32) THICK_DECR;
      }
      break;
		// Decrement the thickness
    case '!':
      if (the_LString.Get_value(StrPos,val)) {
				if (last_recur)
					thick *= one + fraction * (val - one);
				else
					thick *= val;
      } 
			else {
				if (last_recur)
					thick *= one + fraction * ((float32) THICK_DECR - one);
				else
					thick *= (float32) THICK_DECR;
      }
      break;
		// Color it      
    case 'c':
      if (the_LString.Get_value(StrPos,val)) {
				col = (uint16) val;
      }
			else {
				col++;
      }
      break;
		}// end of switch
	}// end of while

}

//*************************************************************************
// Insert basic block. Here we build a cube shape directly on the input vects. 
//*************************************************************************
void LTurtle::Define_block(vect3<float> p1, vect3<float> p2, vect3<float> up, float32 thickness,
													 float32 oldThickness, float32 min_thick, uint16 c)
{                                
	float32 cosTheta[] = {1.0, 0.809017, 0.309017, -0.309017, -0.809017, 
											 -1.0, -0.809017, -0.309017, 0.309017, 0.809017};
	float32 sinTheta[] = {0.0, 0.587785, 0.951057, 0.951057, 0.587785,
												0.0, -0.587785, -0.951056, -0.951057, -0.587785};

	// Direction from p1 to p2
  vect3<float>  dis, d1, d2, d3;
  static p_rec  ver(22);
  float32       d;
  
  // Setup the direction from p1 to p2 if zero means no change at last
  dis = p2 - p1;
  d = dis.length();
  if (d == (float32) 0.0)
    return;

  // d1 for
  d1 = dis;
  d1.normalize();
  
  // d2 up
  d2 = up;
  d2.normalize();
  
  // d3 left
  d3 = d1 * d2;
  d3.normalize();
  
	ver[0] = p1;
	ver[1] = p2; 

	for(int i = 0; i < 10; i++){
		vect3<float> temp;
		temp.plus_fac(p1, d2, cosTheta[i] * oldThickness);
		ver[i + 2].plus_fac(temp, d3, sinTheta[i] * oldThickness);

		temp.plus_fac(p2, d2, cosTheta[i] * thickness);
		ver[i + 12].plus_fac(temp, d3, sinTheta[i] * thickness);
	}

  //8 vertices
  the_GLGraphics.StoreHexahedron(&ver, c);
}

//****************************************************
// Create the triangle state
//*****************************************************
void LTurtle::Define_triangles(p_rec *ver, uint16 c)
{
	
  if (ver->size() >= 3) 
    the_GLGraphics.StoreTriangleStrip(ver, c);
}
//**************************************************************
// Set up the rotation matrix
// Rotate according to the n CCW angle
// a: angle
// n: rotation axis
// Where is this algorithm coming from?
//**************************************************************
void LTurtle::Set_rot(float32 a, const vect3<float> n)
{                           
    float32 n11, n22, n33, nxy, nxz, nyz, sina, cosa;

    cosa = cos(a);
    sina = sin(a);

    n11 = n[_x] * n[_x];
    n22 = n[_y] * n[_y];
    n33 = n[_z] * n[_z];

    nxy = n[_x] * n[_y];
    nxz = n[_x] * n[_z];
    nyz = n[_y] * n[_z];

    C1[_x] = n11 + (one - n11) * cosa;
    C1[_y] = nxy * (one - cosa) - n[_z] * sina;
    C1[_z] = nxz * (one - cosa) + n[_y] * sina;

    C2[_x] = nxy * (one - cosa) + n[_z] * sina;
    C2[_y] = n22 + (one - n22) * cosa;
    C2[_z] = nyz * (one - cosa) - n[_x] * sina;

    C3[_x] = nxz * (one - cosa) - n[_y] * sina;
    C3[_y] = nyz * (one - cosa) + n[_x] * sina;
    C3[_z] = n33 + (one - n33) * cosa;
}


void LTurtle::generateRandomPosition()
{
	int			DNum = 10;
	double	DLength = 100;
	double	DWidth = 100;
  int     n_points = DNum;
	int     eachDimension = (int)sqrt(DNum);
  double  length = DLength;
	double	width  = DWidth;
  double  separationX = DLength / eachDimension / 2.5;
	double  separationY = DWidth / eachDimension / 2.5;
	double	separation = separationX * separationX + separationY * separationY;

  TreePosition.clear();
  for ( int i = 0 ; i < n_points ; i++ )  {
    Point2D p;
    p.x = drand48() * length - length * 0.5;
    p.y = drand48() * width - width * 0.5;

    bool too_close = false;
    for (unsigned int j = 0 ; ! too_close && j < TreePosition.size() ; j++ )  {
      double  d = ( TreePosition[j].x - p.x ) * ( TreePosition[j].x - p.x )
                + ( TreePosition[j].y - p.y ) * ( TreePosition[j].y - p.y );
      if ( d < separation )
          too_close = true;
    }
    if (!too_close ) {
			printf("%dth %f %f\n", i, p.x, p.y);
      TreePosition.push_back(p);
		}
    else
      i--; // redo it again
	}// end of for i

}
void LTurtle::createString()
{
	std::string temp;
	// For bushlike 1
	temp = "4\n"; 
	temp += "45\n"; 
	temp += "20\n";
	temp += "A\n";
	temp += "A=BCDEGHIJK\n";
	temp += "B=[~(30)L][;(0.5)CDEGHIJK]\n";
	temp += "C=[+~(30)L][+;(0.5)CDEGHIJK]\n";
	temp += "D=[-~(30)L][-;(0.5)CDEGHIJK]\n";
	temp += "E=[&~(30)L][&;(0.5)CDEGHIJK]\n";
	temp += "F=F\n";
	temp += "G=[^~(30)L][&;(0.5)~(10)CDEGHIJK]\n";
	temp += "H=[>(45)+~(30)L][>(45)+;(0.5)CDEGHIJK]\n";
	temp += "I=[>(45)-~(30)L][>(45)-;(0.5)CDEGHIJK]\n";
	temp += "J=[>(45)&~(30)L][>(45)&;(0.5)CDEGHIJK]\n";
	temp += "K=[>(45)^~(30)L][>(45)^;(0.5)CDEGHIJK]\n";
	temp += "L=c(7)FM!(0.8)c(10)FM!c(10)(0.8)c(9)FM!(0.8)c(9)FM!(0.8)c(2)FM!(0.8)c(2)FM!(0.8)c(0)FM!(0.8)c(0)FM!(0.8)c(0)FM\n";
	temp += "@\n";
	pattern.push_back(temp);

	// For bushlike 2
	temp = "7\n";
	temp += "22.5\n";
	temp += "20\n" ;
	temp += "c(9)A\n";
	temp += "A=[&FW\'A]>>>>>[&FW\'A]>>>>>>>[&FW\'A]\n";
	temp += "F=S>>>>>FW\n";
	temp += "S=FL\n";
	temp += "L=[c(2)\"(0.5){&&&&.-(30)f-(120)f+(99)\"(3.205)f}]\n";
	temp += "@\n";
	pattern.push_back(temp);

	// For herbaceous 1
	temp = "5\n";
	temp += "18\n";
	temp += "20\n";
	temp += "c(7)\"(0.25)C\n";
	temp += "C=FL>(180)L>(30)FFL>(180)L>(60)FFL>(180)L>(30)FL>(180)L>(30)FB\n";
	temp += "L=c(2)[{&&.-(30)f-(120)f+(99)\"(3.205)f}]\n";
	temp += "B=c(2)[P>>W>>W>>W>>W>>W>>W>>W>>W>>W>>W]\n";
	temp += "P=FF\n";
	temp += "W=[\"(0.1)~(30)c(1)!(0.1).!(400)F][c(4){&&&&~.-(30)f-(120)f+(99)\"(3.205)f}]\n";
	temp += "@\n";
	pattern.push_back(temp);

	// For herbaceous 2
	temp = "5\n";
	temp += "18\n";
	temp += "20\n";
	temp += "c(7)\"(0.25)A\n";
	temp += "A=I+[A+B]-->>[--L]I[++L]-[AB]++AB\n";
	temp += "I=FS[>>&&L][>>^^L]FS\n";
	temp += "S=SFS\n";
	temp += "L=c(2)[{&&.-(30)f-(120)f+(99)\"(3.205)f}]\n";
	temp += "B=c(2)[P>W>>>W>>>>W>>>>W>>>>W]\n";
	temp += "P=FF\n";
	temp += "W=[\"(0.1)~(30)c(1)!(0.1).!(400)F][c(4){&&&&.-(30)f-(120)f+(99)\"(3.205)f}]\n";
	temp += "@\n";
	pattern.push_back(temp);

	// For pine like 2
	temp = "5\n";
	temp += "20\n";
	temp += "40\n";
	temp += "c(7)C\n";
	temp += "A=[\"(0.5)[-(60)K]>(34)[-(70)K]>(46)[-(80)K]>(56)[-(90)K]>(20)[-(82)K]>(30)[-(79)K]>(23)[-(69)K]>(33)[-(66)K]>(33)[-(66)K]]\n";
	temp += "B=[\"(0.5)[-(60)K]>(45)[-(70)K]>(46)[-(80)K]>(53)[-(90)K]>(34)[-(82)K]>(43)[-(79)K]>(33)[-(66)K]]\n";
	temp += "D=[\"(0.5)[-(60)L]>(34)[-(70)L]>(46)[-(80)L]>(56)[-(90)L]>(20)[-(82)L]>(30)[-(79)L]>(23)[-(69)L]>(33)[-(66)L]>(33)[-(66)L]]\n";
	temp += "E=[\"(0.5)[-(60)M]>(45)[-(70)M]>(46)[-(80)M]>(53)[-(90)M]>(34)[-(82)M]>(43)[-(79)M]>(33)[-(66)M]]\n";
	temp += "G=[\"(0.5)[-(60)N]>(45)[-(70)N]>(46)[-(80)N]>(53)[-(90)N]>(34)[-(82)N]>(43)[-(79)N]>(33)[-(66)N]]\n";
	temp += "H=[\"(0.5)[-(60)O]>(45)[-(70)O]>(46)[-(80)O]>(53)[-(90)O]>(34)[-(82)O]>(43)[-(79)O]>(33)[-(66)O]]\n";
	temp += "I=[\"(0.5)[-(60)P]>(34)[-(70)P]>(46)[-(80)P]>(56)[-(90)P]>(20)[-(82)P]>(30)[-(79)P]>(23)[-(69)P]>(33)[-(66)P]>(33)[-(66)P]]\n";
	temp += "J=[\"(0.5)[-(60)Q]>(34)[-(70)Q]>(46)[-(80)Q]>(56)[-(90)Q]>(20)[-(82)Q]>(30)[-(79)Q]>(23)[-(69)Q]>(33)[-(66)Q]]\n";
	temp += "C=F!(0.8)>(12)AF!(0.8)>(14)BF!(0.8)>(16)DF!(0.8)>(17)EF!(0.8)>(20)GF!(0.8)>(10)GF!(0.8)>(15)HF!(0.8)>(11)IF!(0.8)JFT\n";
	temp += "K=F\'!(0.8)>(12)RF!(0.8)>(14)RF!(0.8)>(16)RF!(0.8)>(17)RF!(0.8)>(20)RF!(0.8)>(10)RF!(0.8)>(15)RF!(0.8)>(11)RFS\n";
	temp += "L=F!(0.8)>(12)RF\'!(0.8)>(14)RF\'!(0.8)>(16)RF!(0.8)>(17)RF!(0.8)>(20)RF!(0.8)>(10)RF!(0.8)>(15)RFS\n";
	temp += "M=\'F!(0.8)>(12)RF!(0.8)>(14)RF\'!(0.8)>(16)RF!(0.8)>(17)RF!(0.8)>(20)RF!(0.8)>(10)RFS\n";
	temp += "N=F!(0.8)>(12)RF!(0.8)>(14)RF!(0.8)>(16)RF\'!(0.8)>(17)RF!(0.8)>(20)RFS\n";
	temp += "O=F!(0.8)>(12)RF\'!(0.8)>(14)RF!(0.8)>(16)RF!(0.8)>(17)RFS\n";
	temp += "P=F\'!(0.8)>(12)RF\'!(0.8)>(14)RF!(0.8)>(16)RFS\n";
	temp += "Q=F!(0.8)>(12)RF\'!(0.8)>(14)RFS\n";
	temp += "R=[c(9)\"(0.5)[-(60)F]>(34)[-(70)F]>(46)[-(80)F]>(56)[-(90)F]>(20)[-(82)F]>(30)[-(79)F]>(23)[-(69)F]>(33)[-(66)FS]>(33)[-(66)F]]\n";
	temp += "S=[c(2)\"(0.5)[-(40)F]>(34)[-(40)F]>(28)[-(40)F]>(43)[-(40)F]>(12)[-(40)F]>(22)[-(40)F]]\n";
	temp += "T=[c(2)\"(0.1)[-(40)F]>(34)[-(40)F]>(28)[-(40)F]>(43)[-(40)F]>(12)[-(40)F]>(22)[-(40)F]]\n";
	temp += "f=z\n";
	temp += "@\n";
	pattern.push_back(temp);

		// For palm tree
	temp = "4\n";
	temp += "3\n";
	temp += "50\n";
	temp += "c(7)C\n";
	temp += "C=?(2.0)&FF!(0.9)F&F!(0.9)F&F!(0.9)F&F!(0.9)FF&F&F&FFE>(180)E\n";
	temp += "E=[^(90)B&(20)B&(20)B&(20)B&(20)B&(20)B&(20)B&(20)B&(20)B]\n";
	temp += "B=[D+(30)D+(30)D+(30)D+(30)D+(30)D]\n";
	temp += "D=[!(0.25)c(2)ZMtZM!(0.9)ZtMtZFM!(0.9)ZMtZM!(0.9)ZMZtMtZMZMZtMZMtZMZM!(0.9)ZMZM]\n";
	temp += "@\n";
	pattern.push_back(temp);

	// For common tree 1
	temp = "8\n";
	temp += "20\n";
	temp += "50\n";
	temp += "c(7)T\n";
	temp += "T=CCA\n";
	temp += "A=C[&L][%&L]B[&L][%&L]>(94)C[&L][%&L]B[&L][%&L]>(132)B[&L][%&L]>(70)B[&L][%&L]&(60)[C[&L][%&L]B[&L][%&L]>(70)C[&L][%&L]B[&L][%&L]>(37)B[&L][%&L]>(90)C[&L][%&L]B[&L][%&L]]\n";
	temp += "B=[&C[&L][%&L]C[&L][%&L]$A]\n";
	temp += "C=!(.9)~(5)tF[&L][%&L]\n";
	temp += "F=\'(1.25)F\'(.8)[&L][%&L]\n";
	temp += "L=[c(2){&&&.-(30)f(100)-(120)f(100)+(99)\"(3.205)f(100)}]\n";
	temp += "f=z\n";
	temp += "@\n";
	pattern.push_back(temp);

	// For common tree 2
	temp = "8\n";
	temp += "20\n";
	temp += "50\n";
	temp += "c(7)T\n";
	temp += "T=CCA\n";
	temp += "A=C&L%&LB&L%&L>(94)C&L%&LB&L%&L>(132)B&L%&L>(70)B&L%&L&(60)[C&L%&LB&L%&L]>(70)C[&L%&L]B[&L%&L]>(37)B[&L%&L]>(90)C[&L%&L]B[&L%&L]\n";
	temp += "B=FFC&FFC+FFC>-FFC^FFC\n";
	temp += "C=F>F&L%&L\n";
	temp += "F=\'(1.25)F\'(.8)[&L][%&L]\n";
	temp += "L=[c(2){&&&.-(30)f(100)-(120)f(100)+(99)\"(3.205)f(100)}]\n";
	temp += "f=z\n";
	temp += "@\n";
	pattern.push_back(temp);

	// For common tree 3
	temp = "10\n";
	temp += "20\n";
	temp += "50\n";
	temp += "c(7)T\n";
	temp += "T=CCA\n";
	temp += "A=CB[&(90)L>180L]>(94)CB[&(90)L>180L]>(132)B[&(90)L>180L]\n";
	temp += "B=[&C[&(90)L>180L]DC[&(90)L>180L]D$A]\n";
	temp += "D=[g(50)Lg(50)L]\n";
	temp += "C=!(.95)~(5)tFD\n";
	temp += "F=\'(1.25)FD\'(.8)\n";
	temp += "L=[f(200)c(2){+(30)f(200)-(120)f(200)-(120)f(200)}]\n";
	temp += "f=z\n";
	temp += "z=_\n";
	temp += "@\n";
	pattern.push_back(temp);


	// For common tree 4
	temp = "10\n";
	temp += "20\n";
	temp += "50\n";
	temp += "c(7)T\n";
	temp += "T=CCA\n";
	temp += "A=CB[&(90)L>180L]>(94)CB[&(90)L>180L]>(132)B[&(90)L>180L]\n";
	temp += "B=[&C[&(90)L>180L]DC[&(90)L>180L]D$A]>(90)[&C[&(90)L>180L]DC[&(90)L>180L]D$A]\n";
	temp += "D=[g(50)Lg(50)L]\n";
	temp += "C=!(.95)~(5)tFD\n";
	temp += "F=\'(1.25)FD\'(.8)\n";
	temp += "L=[f(200)c(2){+(30)f(200)-(120)f(200)-(120)f(200)}]\n";
	temp += "f=z\n";
	temp += "z=_\n";
	temp += "@\n";
	pattern.push_back(temp);

	// For tree without leaf
	temp = "8\n";
	temp += "20\n";
	temp += "50\n";
	temp += "c(8)T\n";
	temp += "T=CCA\n";
	temp += "A=CBD>(94)CBD>(132)BD>(70)BD&(60)[CBD>(70)CBD>(37)BD>(90)CBD]\n";
	temp += "B=[&CDCD$A]\n";
	temp += "C=!(.9)~(5)tF\n";
	temp += "F=\'(1.25)F\'(.8)\n";
	temp += "f=z\n";
	temp += "z=_\n";
	temp += "@\n";
	pattern.push_back(temp);
	// Other Funny stuff
	// Air horse
	temp = "18\n";
	temp += "10\n";
	temp += "200\n";
	temp += "C\n";
	temp += "C=LBW\n";
	temp += "B=[[\'\'aH]|[g]]\n";
	temp += "a=Fs+;\'a\n";
	temp += "g=Ft+;\'g\n";
	temp += "s=[::cc!!!!&&[FFcccZ]^^^^FFcccZ]\n";
	temp += "t=[c!!!!&[FF]^^FF]\n";
	temp += "L=O\n";	
	temp += "O=P\n";
	temp += "P=Q\n";
	temp += "Q=R\n";
	temp += "R=U\n";
	temp += "U=X\n";
	temp += "X=Y\n";
	temp += "Y=V\n";
	temp += "V=[cc!!!&&&&&&&&&[Zp]|[Zp]]\n";
	temp += "p=h>>>>>>>>>>>>h>>>>>>>>>>>>h\n";
	temp += "h=[++++!F\'\'\'p]\n";
	temp += "H=[cccci[>>>>>dcFFF][<<<<<ecFFF]]\n";
	temp += "d=Z!&Z!&:\'d\n";
	temp += "e=Z!^Z!^:\'e\n";
	temp += "i=-:\"i\n";
	temp += "W=[%[!!cb][<<<!!cb][>>>!!cb]]\n";
	temp += "b=Fl!+Fl+;\'b\n";
	temp += "l=[-cc{--z++z++z--|--z++z++z}]\n";
	temp += "@\n";
	pattern.push_back(temp);

	// Butter Fly
	temp = "10\n";
	temp += "20\n";
	temp += "80\n";
	temp += "L\n";
	temp += "L=[A][B][C][T][H]\n";
	temp += "A=[cc^(90)f(-2)FcccaFaFaFaFaFaF]\n";
	temp += "a=\'(.75)&(5)\n";
	temp += "H=[cccc&(90)\'F[f(-4)c+(90)\'\'Z][f(-4)c-(90)\'\'Z][J][K][M]]\n";
	temp += "J=ccccccjF\'\'F\'\'&F\'\'&&F\'\'&&F\'\'&&F\'\'&&F\'\'&&F\'\'&&F\n";
	temp += "j=!!!!\'\'\'\'\'\'\'\n";
	temp += "K=ccc+<<j^^F\'\'F\'\'F\'\'F\'\'F\'\'F\'\'^F\'\'^F\'\'^F\n";
	temp += "M=ccc->>j^^F\'\'F\'\'F\'\'F\'\'F\'\'F\'\'^F\'\'^F\'\'^F\n";
	temp += "k=!!!!\'\'\'\'\'\'\'\'\n";
	temp += "B=+(25)[{-(90)&&fff^^f^^^z^^f^^f}][c{+(-90)^(5)ff^^^f^^f^^z^^^f)}]\n";
	temp += "C=|-(25)[{-(90)&&fff^^f^^^z^^f^^f}][c{+(-90)^(5)ff^^^f^^f^^z^^^f)}]\n";
	temp += "N=|[ccc!!!!!!!!!!!!^^F^Z^Z]\n";
	temp += "O=|[ccc!!!!!!!!!!!!^^F^Z^^Z]\n";
	temp += "P=|[ccc!!!!!!!!!!!!^^F^^^Z^^^Z]\n";
	temp += "T=[-N][+N][-^O][+^O][<-^^^P][>+^^^P]\n";
	temp += "@\n";
	pattern.push_back(temp);
	// Ca
	temp = "15\n";
	temp += "20\n";
	temp += "80\n";
	temp += "A\n";
	temp += "A=[T][B]\n";
	temp += "T=c(1)+(90)^(5)[F--[n]++[m]++[m]++[o]]|^(10)>(180)[F--[q]++[p]++[p]++[r]]\n";
	temp += "m=!!!F\'^(5)F--c(3){f++f++f--|--f++f++f}\n";
	temp += "n=!!!F\'^(5)F\'^(5)F--\'\'c(3){f++f++f--|--f++f++f}\n";
	temp += "o=!!!F-c(3){f+f+f-|-f+f+f}\n";
	temp += "p=!!!F\'&(5)F--c(3){f++f++f--|--f++f++f}\n";
	temp += "q=!!!F\'&(5)F\'&(5)F--\'\'c(3){f++f++f--|--f++f++f}\n";
	temp += "r=!!!F-c(3){f+f+f-|-f+f+f}\n";
	temp += "B=ccc\'\'\'\'\'\'\'??bFbFbFFbFbF[[D][E]]F\'F\'\'\'F[[D][E]]F\'F\'\'F[[D][E]]FF\'[X][Y]\n";
	temp += "b=^(1)?(1.3)\n";
	temp += "D=^^!!!!c(6)-(85)FF\'F[---\'(.275)W]dddddd!!!c(4)F+\'F+\'F+(10)\'F\'F\'+F\n";
	temp += "E=^^!!!!c(6)+(85)FF\'F[+++\'(.275)Q]eeeeee!!!c(4)F-\'F-\'F+-10)\'F\'F\'-F\n";
	temp += "d=+(10)\'F[++++!!c(4)\'\'\'F\'\'F\'\'F\'\'F]\n";
	temp += "e=-(10)\'F[----!!c(4)\'\'\'F\'\'F\'\'F\'\'F]\n";
	temp += "X=^-(90)fc(2)!(.2)\"+++F[H]FF[-H]xxx[W]xxx[\'W]xxx[+\'(.5)W]xxxllllllll\"s\n";
	temp += "x=-(10)F!(.96)\n";
	temp += "l=+(10)F!(.96)\n";
	temp += "Y=^+(90)fc(2)!(.2)\"---F[I]FF[+I]lll[Q]lll[\'Q]lll[-\'(.5)Q]lllxxxxxxxx\"v\n";
	temp += "H=c(7)\"\"\"++!!!!FFF--c(3){f+f+f-|-f+f+f}\n";
	temp += "I=c(7)\"\"\"--!!!!FFFc(3){f+f+f-|-f+f+f}\n";
	temp += "s=c(7)!!!FF+FF+F\'^(5)F--c(3)\"\"{f++f++f--|--f++f++f}\n";
	temp += "v=c(7)!!!FF-FF-F\'^(5)F--c(3)\"\"{f++f++f--|--f++f++f}\n";
	temp += "W=+c(7)!!aaaaaaaaaaaaa\n";
	temp += "a=FF\'-(5)\n";
	temp += "Q=-c(7)!!jjjjjjjjjjjjj\n";
	temp += "j=FF\'+(5)\n";
	temp += "@\n";
	pattern.push_back(temp);

	// 
	temp = "9\n";
	temp += "19\n";
	temp += "25\n";
	temp += "A\n";
	temp += "A=U[---P]a\n";
	temp += "a=U[-P]B\n";
	temp += "B=U[+++P]b\n";
	temp += "b=U[+P]A\n";
	temp += "C=V[-D][+D]\n";
	temp += "D=V[-E][+E]\n";
	temp += "E=VV[-G][+G]\n";
	temp += "G=V-VV\n";
	temp += "P=WV[-C][+C]\n";
	temp += "U=f[---f+++X][+++f---Y]FFFFF\n";
	temp += "V=fFF\n";
	temp += "W=f[---F++++++F]F\n";
	temp += "X=FFFF\n";
	temp += "Y=X\n";
	temp += "@\n";
	pattern.push_back(temp);

	// Lobster
	temp = "13\n";
	temp += "20\n";
	temp += "30\n";
	temp += "A\n";
	temp += "A=|[B][[C][P]][M][\'\'\'&M][\'\'\'\'&&M]\n";
	temp += "B=[+(80)[aaaaa]][-(80)[bbbbb]]&\'[B]\n";
	temp += "a=>-\"[F\'\'\'c(14)Fc(5)D[c(4)\'\'\'\'\'\'\'{-f+f+f-|-f+f+f}]]\n";
	temp += "b=<+\"[F\'\'\'c(14)Fc(5)E[c(4)\'\'\'\'\'\'\'{-f+f+f-|-f+f+f}]]\n";
	temp += "D=!!!!!\'\'\'\'\'\'dddd\n";
	temp += "E=!!!!!\'\'\'\'\'\'eeee\n";
	temp += "d=$tZ++Z-\n";
	temp += "e=$tZ--Z+\n";
	temp += "M=^[[NZ][OZ]]\n";
	temp += "N=++<<\'\'\'^^???????!!!c(11)-(85)FF\'F[---\'(.275)W]nnnnnn\n";
	temp += "O=-->>\'\'\'^^???????!!!c(11)+(85)FF\'F[+++\'(.275)Q]oooooo\n";
	temp += "n=+(10)\'F[++++!!!c(10)\'\'\'F\'\'F\'\'F\'\'F]\n";
	temp += "o=-(10)\'F[----!!!c(10)\'\'\'F\'\'F\'\'F\'\'F]\n";
	temp += "W=+c(7)&(7)!wwwwwwwwwwwww\n";
	temp += "w=+(10)FF\'\n";
	temp += "Q=-c(7)&(7)!qqqqqqqqqqqqq\n";
	temp += "q=-(10)FF\'\n";
	temp += "C=+(65)\'\'\'\'\'\'\'\'\'c(9)F>>>>>>&&&wlwlwlwl\n";
	temp += "P=-(65)\'\'\'\'\'\'\'\'\'c(9)F<<<<<<&&&qsqsqsqs\n";
	temp += "r=c(3)[{-f+f+f-|-f+f+f}]\n";
	temp += "s=[+r][w\'r]\n";
	temp += "l=[-r][q\'r]\n";
	temp += "@\n";
}
