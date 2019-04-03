int MotorInput[3] = {2, 4, 6};
int MotorOutput[3] = {3, 5, 7};

const double Weight[3][3] = {{-0.333333, 0.577350, 0.333333}, {-0.333333, -0.577350, 0.333333}, {0.666666, 0, 0.333333}};

int Motors[3] = {0};
int Measured_Motor[3] = {0};

void setup() {
  Serial.begin(9600);
  PinInit();
  StopAllMotors();
  Serial.println("System Started");
}

void loop() {
  static int Controls[3] = {0};
  GetControl(Controls);
  ProcessDirection(Controls);
  PidCalc();
}

void PinInit() {
  for (int i=2; i<8; i++) {
    pinMode(i, OUTPUT);
  }
}
