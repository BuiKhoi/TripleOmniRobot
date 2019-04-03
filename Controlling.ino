void GetControl(int* Controls) {
  Controls[0] = 255;
  Controls[1] = 0;
  Controls[2] = 0;
}

void ProcessDirection(int* Controls) {
  for (int i=0; i<3; i++) {
    Motors[i] = 0;
  }
  
  for (int i=0; i<3; i++) {
    int temp = 0;
    for (int j=0; j<3; j++) {
      Motors[i] += Weight[i][j] * Controls[j];
    }
  }
}
