void SetSpeed(int* motors) {
  MotorMapping(motors);
  for (int i = 0; i < 3; i++) {
    if (motors[i] >= 0) {
      analogWrite(MotorInput[i], motors[i]);
      digitalWrite(MotorOutput[i], LOW);
    } else {
      analogWrite(MotorOutput[i], - motors[i]);
      digitalWrite(MotorInput[i], LOW);
    }
    Serial.print(motors[i]);
    Serial.print(" . ");
  }
  Serial.println();
}

void StopAllMotors() {
  int motors[3] = {0};
  SetSpeed(motors);
}

void MotorMapping(int* motors) {
  int maxx = MINIMUM_MOTOR_SPEED;

  for (int i = 0; i < 3; i++) {
    if (motors[i] > maxx) {
      maxx = motors[i];
    }
  }
  if (maxx > MAXIMUM_MOTOR_SPEED) {
    float ratio = MAXIMUM_MOTOR_SPEED / maxx;
    for (int i = 0; i < 3; i++) {
      motors[i] *= ratio;
    }
  }

  int minn = MAXIMUM_MOTOR_SPEED;
  for (int i = 0; i < 3; i++) {
    if (motors[i] < minn) {
      minn = motors[i];
    }
  }
  if (minn < MINIMUM_MOTOR_SPEED) {
    float ratio = abs(MINIMUM_MOTOR_SPEED / minn);
    for (int i=0; i<3; i++) {
      motors[i] *= ratio;
    }
  }
}
