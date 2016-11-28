/*******************************************************************************
			Main Program:	

			Comment:			Mutation related information

			Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

			Due Date:			

			Course:				CS777, Spring 2003
*******************************************************************************/

#ifndef _MUTATION_H
#define _MUTATION_H
#include "../global/globals.h"
#include <string>
// The total constrol paramter numbers
const int NumDoubleMutParams=29;

struct MutationParameters{
	// Default constructor
  MutationParameters(
		unsigned int	v_MaxMutTries     = 100,
		char					*v_DefaultNewRule       = "F",
		double				v_pr_R                  = 0.1,
		double				v_R_stdev               = 1,
		double				v_pr_A                  = 0.1,
		double				v_A_stdev               = 20,
		double				v_pr_T                  = 0.2,
		double				v_T_stdev               = 5,
		double				v_pr_length_gain_brack  = 0.5,
		double				v_pr_length_lose_brack  = 0.5,
		double				v_length_stdev          = 5,
		double				v_length_decr_stdev     = 0.05, 
		double				v_pr_angle_gain_brack   = 0.5,
		double				v_pr_angle_lose_brack   = 0.5,
		double				v_angle_stdev           = 10,
		double				v_angle_decr_stdev      = 5,
		double				v_pr_thick_gain_brack   = 0.5,
		double				v_pr_thick_lose_brack   = 0.5,
		double				v_thick_decr_stdev      = 0.05,
		double				v_pr_colour_gain_brack  = 0.5,
		double				v_pr_colour_lose_brack  = 0.5,
		double				v_pr_trope_gain_brack   = 0.5,
		double				v_pr_trope_lose_brack   = 0.5,
		double				v_tr_stdev              = 0.05,
		double				v_pr_randrot_gain_brack = 0.5,
		double				v_pr_randrot_lose_brack = 0.5,
		double				v_randrot_stdev         = 0.1,
		double				v_pr_add_or_del_rule    = 0.2,
		double				v_pr_add_rule           = 0.5,
		double				v_pr_add_to_rule        = 0.9,
		double				v_new_brack_dist_stdev  = 1.5
  );

	// The member variables
  unsigned long MaxMutTries;	// The maximum number of tries to generate random number to fit certain criteria
	// The default rule
	std::string		DefaultNewRule;
	// The memory space for the parameter
	double				ParamArr[NumDoubleMutParams];

  //shortcut references to the parameters
  double &pr_R;										// Recursion
  double &R_stdev;								// Standard deviation of recursion
  double &pr_A;										// Angle
  double &A_stdev;								// Standard deviation of angle
  double &pr_T;										// Thickness
  double &T_stdev;								// Standard deviation of thickness
  double &pr_length_gain_brack;		// The length gain and lose bracket
  double &pr_length_lose_brack;
  double &length_stdev;
  double &length_decr_stdev; 
  double &pr_angle_gain_brack;
  double &pr_angle_lose_brack;
  double &angle_stdev;
  double &angle_decr_stdev;
  double &pr_thick_gain_brack;
  double &pr_thick_lose_brack;
  double &thick_decr_stdev; 
  double &pr_colour_gain_brack;
  double &pr_colour_lose_brack;
  double &pr_trope_gain_brack;
  double &pr_trope_lose_brack;
  double &tr_stdev;
  double &pr_randrot_gain_brack;
  double &pr_randrot_lose_brack;
  double &randrot_stdev;
  double &pr_add_or_del_rule;
  double &pr_add_rule;
  double &pr_add_to_rule;
  double &new_brack_dist_stdev;
};

#endif _MUTATION_H