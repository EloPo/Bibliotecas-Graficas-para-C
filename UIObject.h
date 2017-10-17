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
*      $RCSfile: UIObject.h,v $
*      $Author: johns $        $Locker:  $             $State: Exp $
*      $Revision: 1.39 $       $Date: 2016/11/28 03:05:05 $
*
***************************************************************************
* DESCRIPTION:
*
* User Interface Object base class.  All user interface modules are derived
* from this; it provides methods for registering with the command processor
* and 'signing up' for which commands it is interested in, as well as
* generating commands and events.
*
***************************************************************************/
#ifndef UIOBJECT_H
#define UIOBJECT_H
 
class CommandQueue;
class Command;
class VMDApp;

class UIObject {
int maxCmds;
char *doCmd;
 
  int is_on;

 protected:
  VMDApp *app;

   CommandQueue *cmdQueue;

   void runcommand(Command *);

   void command_wanted(int cmd);
  
   virtual void reset() {}
   
  int make_callbacks;
 
  virtual void do_on() {}
  virtual void do_off() {}

  public:
    UIObject(VMDApp *);       
    virtual ~UIObject(void);  
   
    void On() {
    do_on();
    is_on = 1;
   }
    void Off() {
    do_off();
    is_on = 0;
   }
  int active() const { return is_on; }

  int want_command(int cmd) {
  return !(cmd >= maxCmds || cmd < 0 || !doCmd[cmd]);
}
 
virtual int check_event() { return 0; }
 
virtual int act_on_command(int, Command *) { return 0; }
 
void set_callbacks(int on) { make_callbacks = on; }
};

#endif