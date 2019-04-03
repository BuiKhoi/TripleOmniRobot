void PidCalc() {
  int CalcedMotors[3] = {0};
  CalcedMotors[0] = CalcM1();
  CalcedMotors[1] = CalcM2();
  CalcedMotors[2] = CalcM3();
  SetSpeed(CalcedMotors);
}

int CalcM1() {
  return Motors[0];
}

int CalcM2() {
  return Motors[1];
}

int CalcM3() {
  return Motors[3];
}
