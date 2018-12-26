#ifndef MYMOTOR_H
#define MYMOTOR_H


class myMotor {
  public:
  int pwm;
  int dir;
  int brk;
    myMotor(int,int,int);
    void function(int , int );
    void select();
 
  private:

};
#endif
