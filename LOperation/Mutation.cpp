/*******************************************************************************
			Main Program:	

			Comment:			Mutation related information

			Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

			Due Date:			

			Course:				CS777, Spring 2003
*******************************************************************************/

#include "Mutation.h"
//*********************************************
// Mutation Parameter methods 
// *********************************************
MutationParameters::MutationParameters(  
		// defaults for these values are set in the corresponding header file
		unsigned int v_MaxMutTries,
		char         *v_DefaultNewRule,
		double       v_pr_R,
		double       v_R_stdev,
		double       v_pr_A,
		double       v_A_stdev,
		double       v_pr_T,
		double       v_T_stdev,
		double       v_pr_length_gain_brack,
		double       v_pr_length_lose_brack,
		double       v_length_stdev,
		double       v_length_decr_stdev, 
		double       v_pr_angle_gain_brack,
		double       v_pr_angle_lose_brack,
		double       v_angle_stdev,
		double       v_angle_decr_stdev,
		double       v_pr_thick_gain_brack,
		double       v_pr_thick_lose_brack,
		double       v_thick_decr_stdev,
		double       v_pr_colour_gain_brack,
		double       v_pr_colour_lose_brack,
		double       v_pr_trope_gain_brack,
		double       v_pr_trope_lose_brack,
		double       v_tr_stdev,
		double       v_pr_randrot_gain_brack,
		double       v_pr_randrot_lose_brack,
		double       v_randrot_stdev,
		double       v_pr_add_or_del_rule,
		double       v_pr_add_rule,
		double       v_pr_add_to_rule,
		double       v_new_brack_dist_stdev
	  ):
		//allocate aliases
		pr_R                 (ParamArr[0]),
		R_stdev              (ParamArr[1]),
		pr_A                 (ParamArr[2]),
		A_stdev              (ParamArr[3]),
		pr_T                 (ParamArr[4]),
		T_stdev              (ParamArr[5]), 
		pr_length_gain_brack (ParamArr[6]),
		pr_length_lose_brack (ParamArr[7]),
		length_stdev         (ParamArr[8]),
		length_decr_stdev    (ParamArr[9]), 
		pr_angle_gain_brack  (ParamArr[10]),
		pr_angle_lose_brack  (ParamArr[11]),
		angle_stdev          (ParamArr[12]),
		angle_decr_stdev     (ParamArr[13]),
		pr_thick_gain_brack  (ParamArr[14]),
		pr_thick_lose_brack  (ParamArr[15]),
		thick_decr_stdev     (ParamArr[16]), 
		pr_colour_gain_brack (ParamArr[17]),
		pr_colour_lose_brack (ParamArr[18]),
		pr_trope_gain_brack  (ParamArr[19]),
		pr_trope_lose_brack  (ParamArr[20]),
		tr_stdev             (ParamArr[21]),
		pr_randrot_gain_brack(ParamArr[23]),
		pr_randrot_lose_brack(ParamArr[24]),
		randrot_stdev        (ParamArr[24]),
		pr_add_or_del_rule   (ParamArr[25]),
		pr_add_rule          (ParamArr[26]),
		pr_add_to_rule       (ParamArr[27]),
		new_brack_dist_stdev (ParamArr[28])
{
  //place parameters given into the aliases
  MaxMutTries           = v_MaxMutTries;
  DefaultNewRule        = v_DefaultNewRule;
  pr_R                  = v_pr_R;
  R_stdev               = v_R_stdev;
  pr_A                  = v_pr_A;
  A_stdev               = v_A_stdev;
  pr_T                  = v_pr_T;
  T_stdev               = v_T_stdev; 
  pr_length_gain_brack  = v_pr_length_gain_brack;
  pr_length_lose_brack  = v_pr_length_lose_brack;
  length_stdev          = v_length_stdev;
  length_decr_stdev     = v_length_decr_stdev; 
  pr_angle_gain_brack   = v_pr_angle_gain_brack;
  pr_angle_lose_brack   = v_pr_angle_lose_brack;
  angle_stdev           = v_angle_stdev;
  angle_decr_stdev      = v_angle_decr_stdev;
  pr_thick_gain_brack   = v_pr_thick_gain_brack;
  pr_thick_lose_brack   = v_pr_thick_lose_brack;
  thick_decr_stdev      = v_thick_decr_stdev; 
  pr_colour_gain_brack  = v_pr_colour_gain_brack;
  pr_colour_lose_brack  = v_pr_colour_lose_brack;
  pr_trope_gain_brack   = v_pr_trope_gain_brack;
  pr_trope_lose_brack   = v_pr_trope_lose_brack;
  tr_stdev              = v_tr_stdev;
  pr_randrot_gain_brack = v_pr_randrot_gain_brack;
  pr_randrot_lose_brack = v_pr_randrot_lose_brack;
  randrot_stdev         = v_randrot_stdev;
  pr_add_or_del_rule    = v_pr_add_or_del_rule;
  pr_add_rule           = v_pr_add_rule;
  pr_add_to_rule        = v_pr_add_to_rule;
  new_brack_dist_stdev  = v_new_brack_dist_stdev;
}
