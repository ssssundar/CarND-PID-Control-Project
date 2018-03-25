#include <iostream>
#include "PID.h"


using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {

  p_error_ = 0.0;
  i_error_ = 0.0;
  d_error_ = 0.0;

  Kp_ = 0.0;
  Ki_ = 0.0;
  Kd_ = 0.0;

  prev_cte_ = 0.0;
  int_cte_ = 0.0;
  diff_cte_ = 0.0;

}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;

  std::cout << "Kp_: " << Kp_ << " Ki_: " << Ki_ << " Kd_: " << Kd_ << std::endl;
}

void PID::UpdateError(double cte) {

  diff_cte_ = cte - prev_cte_;
  prev_cte_ = cte;
  int_cte_ += cte;

  p_error_ = Kp_ * cte;
  i_error_ = Ki_ * cte;
  d_error_ = Kd_ * diff_cte_; 

  
}

double PID::TotalError() {

  return ( p_error_ + i_error_ + d_error_ );

}

