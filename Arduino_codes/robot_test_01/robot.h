#ifndef ROBOT__H
#define ROBOT__H

#include <AFMotor.h>

class Robot {
  private:
    AF_DCMotor motor_lft;
    AF_DCMotor motor_rit;

    unsigned int lft_sp = 200;
    unsigned int rit_sp = 200;

    unsigned int lft_pin;
    unsigned int rit_pin;

    unsigned int Acc;

  public:
    Robot(unsigned int lft, unsigned int rit) ;

    void setup() ;
    
    void Forward();
    void Backward();

    void Right();
    void Left();

    //
    void EnhancedLeft();
    void EnhancedRight();
    //

    void Stop();
    //    void setSpeeds(unsigned int sp_lft, unsigned int sp_rit){
    //      setLftSp(sp_lft); setRitSp(sp_rit);
    //    }
    //
    //    void setLftSp(unsigned int sp){
    //      lft_sp = sp;
    //    }
    //    void setRitSp(unsigned int sp){
    //      rit_sp = sp;
    //    }
    //
    //    void setAcc(unsigned int acc)
    //    {
    //      Acc = acc;
    //    }
    //    void toggleAcc(){
    //      Acc *= -1;
    //    }
};
#endif
