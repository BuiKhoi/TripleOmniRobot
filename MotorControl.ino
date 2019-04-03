void SetSpeed(int* motors) {
  for (int i=0; i<3; i++) {
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
