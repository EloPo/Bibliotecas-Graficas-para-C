
Mouse.h


/***************************************************************************
*cr                                                                       
*cr            (C) Copyright 1995-2016 The Board of Trustees of the           
*cr                        University of Illinois                       
*cr                         All Rights Reserved                        
*cr                                                                   
***************************************************************************/
 
/***************************************************************************
* RCS INFORMATION:
*
*      $RCSfile: Mouse.h,v $
*      $Author: johns $        $Locker:  $             $State: Exp $
*      $Revision: 1.68 $       $Date: 2016/11/28 03:05:02 $
*
***************************************************************************
* DESCRIPTION:
*
* The Mouse UI object, which maintains the current state of the 
* mouse, including what it is currently used for, and how much it has moved
* from one measurement to the next.  This also deals with any pop-up or
* pull-down menus available by using the mouse, as well as picking objects.
*
* A three-button mouse is assumed here, with the following usage:
*      1) Buttons 1 and 2 : manipulation and picking.
*      2) Button 3 (right): pop-up menu
*
* This is the general base class definition; specific versions for each
* windowing/graphics system may be supplied.  This class can function as
* it is, however, and will just be a 'zero' mouse - the buttons will never
* be pressed, and the cursor will always be at 0,0.
*
***************************************************************************/
#ifndef MOUSE_OBJ_H
#define MOUSE_OBJ_H
 
#include "UIObject.h"
#include "Command.h"
#include "NameList.h"

class Mouse : public UIObject {
public:
enum MoveMode {ROTATION, TRANSLATION, SCALING, LIGHT, USERPOINT, 
// All "picking" modes need to be listed after PICK, 
// and non-picking modes need to be listed before
// This is because later code does a check on 
// (enum value) >= PICK to determine if we are in 
// a "picking" mode
PICK, QUERY, CENTER, \
LABELATOM, LABELBOND, LABELANGLE, LABELDIHEDRAL, \
MOVEATOM, MOVERES, MOVEFRAG, MOVEMOL, MOVEREP,\
FORCEATOM, FORCERES, FORCEFRAG, \
ADDBOND};

enum MouseButton { B_NONE = 0, B_LEFT = 1, B_MIDDLE, B_RIGHT };

static const char *get_mode_str(MoveMode mode);
private:
MoveMode moveMode;          
MouseButton pickInProgress; 
// If zero, no picking operation is currently in progress.
// If something is currently being selected with the mouse
// and the button is still down, this flag indicates which button is 
// used.  In fact, pickInProgress = pick-button + 1. 
int moveObj;                
int currX, currY;           
int oldX, oldY;             
MouseButton buttonDown;     

float transInc, rotInc, scaleInc;
 
float xRotVel, yRotVel, zRotVel, scaling, RotVelScale;
 
int rocking_enabled;
 
int mouse_moved(void);
 
int mouse_userpoint(void);
 
void handle_winevent(long, long); 
   
public:
Mouse(VMDApp *);
virtual ~Mouse(void);
   
virtual void reset(void);
   
int move_mode(MoveMode, int = 0);
 
void stop_rotation(void);
 
virtual int check_event(void);
 
void set_rocking(int on);
};
class CmdMouseMode : public Command {
public:
CmdMouseMode(int mm, int ms)
: Command(MOUSE_MODE), mouseMode(mm), mouseSetting(ms) {}
 
int mouseMode, mouseSetting;
};
 
#endif
 
