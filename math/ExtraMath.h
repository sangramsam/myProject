#ifndef _EXTRAMATH_H
#define _EXTRAMATH_H

#include <stdlib.h>
#include <math.h>

//******* simple functions ******

//convert percentages into unit measures
inline double percent2unit(double p)
{
  return (p / 100.0);
}

//convert angles in degrees into radians
inline double deg2rad(double a)
{ //returns a / 180 * PI
  return (a * 0.017453293);
}

//****** more complex functions *******
//produce normally distributed random numbers
//code taken from the C FAQ
inline float Normalize(float mean, float stdev) 
{
	static double V1, V2, S;
	static int phase = 0;
	double X;
  
  if(phase == 0) {
    do {
      double U1 = (double) rand() / RAND_MAX;
      double U2 = (double) rand() / RAND_MAX;
      
      V1 = 2 * U1 - 1;
      V2 = 2 * U2 - 1;
      S = V1 * V1 + V2 * V2;
    } while(S >= 1 || S == 0);

    X = V1 * sqrt(-2 * log(S) / S);
  } else
    X = V2 * sqrt(-2 * log(S) / S);

  phase = 1 - phase; //reuse the random numbers
  
  return (X * stdev + mean);
}

//************** random number generators *******************
// these rely on the ThinAir libraries, and are generally 
// accessed by the Rnd() and Rnd(int) calls. Rnd() returns
// a random number between 0 and 1, and Rnd(int) returns a 
// random number between 0 and 1 from a series specified by 
// the (int) given. In other words, if, after seeding with a 
// specified number (say 1), you call {Rnd(0); Rnd(0); Rnd(0)}, 
// and this gives                     {0.4313; 0.8142; 0.1357},
// then seeding with 1 and calling    {Rnd(0); Rnd(1); Rnd(0); Rnd(0)},
// should give something like         {0.4313; 0.0012; 0.8142; 0.1357}.
// i.e. the results when Rnd(x) is called twice should be independent
// of the fact that Rnd(y) might be called in between (where y != x).  
//*************************************************************

#undef RAND_MAX
#include "./ThinAir/rand_rng.h"
#include "./ThinAir/erndmcnm.h"

//define the precise pRNG we decide to use from the thinair library
#define RANDOM_NUMBER_GENERATOR Knuth27RandGen

inline void setup_Rnd(){
  setup_rand( new RANDOM_NUMBER_GENERATOR() );
}

//the rnd_base_single routine copes with Rnd() calls, and SRndS calls 
//(which re-seed the random number generator behind the Rnd() call) 
inline float rnd_base_single(const unsigned long int seed, bool Restart)
{
  static RANDOM_NUMBER_GENERATOR pRNG;
  if (Restart) {
    pRNG.IntSeed(seed);
    return 0;
  } else {
    return  pRNG.FloatNumber();
  };
}

inline void SRndS(int seed)
{
  rnd_base_single(seed, true);
}

inline float Rnd()
{
  return rnd_base_single(0, false);
}

//the rnd_base_multiple routine copes with Rnd(int) calls, and SRndM
//calls (to re-seed the Rnd(int) generator mechanism)
inline double rnd_base_multiple(const unsigned long int level_or_seed, bool Restart){
  static  RANDOM_NUMBER_GENERATOR pRNG;
  //store each level as a RandGenToken
  static  RandGenToken **state_arrays=NULL;
  static unsigned short int array_size=0;
  static unsigned long int seed=1;
  static signed long int lastlevelcalled=-1;
  unsigned short int i;
  if (Restart) {
    if (state_arrays!=NULL) {
      for(i=0;i<array_size;i++)
				delete state_arrays[i];
      free(state_arrays);
      state_arrays=NULL;
    }
    array_size=0;
    seed=level_or_seed;
    lastlevelcalled=-1;
    return 0;
  } // end of if Restart
	else {
    if (level_or_seed>=array_size) {
      state_arrays=(RandGenToken **) realloc(state_arrays,sizeof(RandGenToken *)*(level_or_seed+1));
	    if (state_arrays==NULL) {
				array_size=0;
				return 0;
      } // end of if state_array
			else {
				//store the last used value
				if (lastlevelcalled >= 0)
					*state_arrays[lastlevelcalled]=pRNG.CreateToken();
				lastlevelcalled=(signed long int) level_or_seed;

				for (i = array_size;i <= level_or_seed; i++) {
					//seed with the saved seed value plus the level number
					pRNG.IntSeed(seed+i);
					//discard one value, to get things going.
					pRNG.FloatNumber();
					state_arrays[i]=new RandGenToken();
					*state_arrays[i] = pRNG.CreateToken();
				}// end of for
				array_size=level_or_seed+1;
      }// end of else
   }// end of level_or_seed
    
	 if (lastlevelcalled==(signed long int) level_or_seed)
		 return pRNG.FloatNumber();
   else {
      *state_arrays[lastlevelcalled]=pRNG.CreateToken();
      pRNG.SetToken(*state_arrays[level_or_seed]);
      lastlevelcalled=(signed long int) level_or_seed;
      return pRNG.FloatNumber();
    }// end of else
  }// end of else
}

inline float Rnd(unsigned int level)
{
  return rnd_base_multiple(level,false);
}

inline void SRndM(int seed)
{
  rnd_base_multiple(seed,true);
}



//SRnd reseeds both Rnd() and Rnd(int) random number generators
inline void SRnd(int seed)
{
  rnd_base_single(seed,true);
  rnd_base_multiple(seed,true);
}

#undef RANDOM_NUMBER_GENERATOR
#endif
