/*****< btvend.h >*************************************************************/
/*      Copyright 2009 - 2014 Stonestreet One.                                */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  BTVEND - Stonestreet One Bluetooth Stack BTVEND Implementation Type       */
/*           Definitions, Constants, and Prototypes.                          */
/*                                                                            */
/*  Author:  Damon Lange                                                      */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   07/31/09  D. Lange       Initial creation.                               */
/******************************************************************************/
#ifndef __BTVENDH__
#define __BTVENDH__

#include "BTTypes.h"            /* Bluetooth Type Definitions/Constants.      */

   /* The following function is responsible for making sure that the    */
   /* Bluetooth Stack BTVEND module is Initialized correctly.  This     */
   /* function *MUST* be called before ANY other Bluetooth Stack BTVEND */
   /* function can be called.  This function returns zero if the Module */
   /* was initialized correctly, or a non-zero value if there was an    */
   /* error.                                                            */
   /* * NOTE * Internally, this module will make sure that this         */
   /*          function has been called at least once so that the       */
   /*          module will function.  Calling this function from an     */
   /*          external location is not necessary.                      */
int InitializeBTVENDModule(void);

   /* The following function is responsible for instructing the         */
   /* Bluetooth Stack BTVEND Module to clean up any resources that it   */
   /* has allocated.  Once this function has completed, NO other        */
   /* Bluetooth Stack BTBEND Functions can be called until a successful */
   /* call to the InitializeBTVENDModule() function is made.  The       */
   /* parameter to this function specifies the context in which this    */
   /* function is being called.  If the specified parameter is TRUE,    */
   /* then the module will make sure that NO functions that would       */
   /* require waiting/blocking on Mutexes/Events are called.  This      */
   /* parameter would be set to TRUE if this function was called in a   */
   /* context where threads would not be allowed to run.  If this       */
   /* function is called in the context where threads are allowed to run*/
   /* then this parameter should be set to FALSE.                       */
void CleanupBTVENDModule(Boolean_t ForceCleanup);

#endif
