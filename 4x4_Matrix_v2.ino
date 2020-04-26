// anodes
int row[] = {5, 6, 7, 8};

// cathodes
int col[] = {9, 10, 11, 12};

// tempo
int oneFourtyBPM = 396.5;

// bit patterns for each row
byte data[] = {
  0, 0, 0, 0
};

// defines the size of the matrix
int columns = 4;
int rows = 4;

// 140BPM
float sixtyFourthNote = 5.543;
float thirtySecondNote = 11.086;
float sixteenthNote = 26.254;
float eigthNote = 47.57;
float quarterNote = 99.425;
float halfNote = 198.861;
float wholeNote = 397.712;

int startTime = 0;
int endTime = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(row[i], OUTPUT);
    pinMode(col[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    alternatingRowAndCol_Even(quarterNote);
    alternatingRowAndCol_Odd(quarterNote);
  }
  waveAcross(quarterNote);
  waveDown(quarterNote);
  for (int i = 0; i < 2; i++) {
    squareIn(quarterNote);
  }
  waveAcross(eigthNote);
  waveDown(eigthNote);
  pinWheel(thirtySecondNote);
  reversePinWheel(thirtySecondNote);
  spiralIn(sixtyFourthNote);
  spiralOut(sixtyFourthNote);
  squareOut(quarterNote);
  for (int i = 0; i < 4; i++) {
    alternatingRowAndCol_Even(quarterNote);
    alternatingRowAndCol_Odd(quarterNote);
  }
  alterFallEven(quarterNote);
  alterFallOdd(quarterNote);
  for (int i = 0; i < 2; i++) {
    squareOut(quarterNote);
  }
  waterfall(thirtySecondNote);
  brokenPinwheel(quarterNote);
  almostFillFromBottomLeft(eigthNote);
  flash();
  flash();
}

void allOff() {
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(row[i], LOW);
    digitalWrite(col[i], HIGH);
  }
}

void allOn() {
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(row[i], HIGH);
    digitalWrite(col[i], LOW);
  }
}


void showPattern(float tempo) {
  for (int i = 0; i < tempo; i++) {
    for (int thisRow = 0; thisRow < rows; thisRow++)
    {
      allOff();
      digitalWrite(row[thisRow], HIGH);
      for (int thisCol = 0; thisCol < columns; thisCol++)
      {
        if (bitRead(data[thisRow], columns - thisCol - 1) == 1)
        {
          digitalWrite(col[thisCol], LOW);
        }
        else
        {         
          digitalWrite(col[thisCol], HIGH);
        }
      }
      delay(1);
    }
  }
}

//********PATTERNS*********

void allOn(float tempo) {
  data[0] = B1111;
  data[1] = B1111;
  data[2] = B1111;
  data[3] = B1111;

  showPattern(tempo);
}

void r1c1(float tempo) {
  data[0] = B1000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void r1c2(float tempo) {
  data[0] = B0100;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void r1c3(float tempo) {
  data[0] = B0010;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void r1c4(float tempo) {
  data[0] = B0001;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void r2c1(float tempo) {
  data[0] = B0000;
  data[1] = B1000;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void r2c2(float tempo) {
  data[0] = B0000;
  data[1] = B0100;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void r2c3(float tempo) {
  data[0] = B0000;
  data[1] = B0010;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void r2c4(float tempo) {
  data[0] = B0000;
  data[1] = B0001;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void r3c1(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B1000;
  data[3] = B0000;

  showPattern(tempo);
}

void r3c2(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0100;
  data[3] = B0000;

  showPattern(tempo);
}

void r3c3(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0010;
  data[3] = B0000;

  showPattern(tempo);
}

void r3c4(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0001;
  data[3] = B0000;

  showPattern(tempo);
}

void r4c1(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B1000;

  showPattern(tempo);
}

void r4c2(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0100;

  showPattern(tempo);
}

void r4c3(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0010;

  showPattern(tempo);
}

void r4c4(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0001;

  showPattern(tempo);
}

void alternatingRowAndCol_Even(float tempo) {
  data[0] = B0101;
  data[1] = B1010;
  data[2] = B0101;
  data[3] = B1010;

  showPattern(tempo);
}

void alternatingRowAndCol_Odd(float tempo) {
  data[0] = B1010;
  data[1] = B0101;
  data[2] = B1010;
  data[3] = B0101;

  showPattern(tempo);
}

void colOne(float tempo) {
  data[0] = B1000;
  data[1] = B1000;
  data[2] = B1000;
  data[3] = B1000;

  showPattern(tempo);
}

void colTwo(float tempo) {
  data[0] = B0100;
  data[1] = B0100;
  data[2] = B0100;
  data[3] = B0100;

  showPattern(tempo);
}

void colThree(float tempo) {
  data[0] = B0010;
  data[1] = B0010;
  data[2] = B0010;
  data[3] = B0010;

  showPattern(tempo);
}

void colFour(float tempo) {
  data[0] = B0001;
  data[1] = B0001;
  data[2] = B0001;
  data[3] = B0001;

  showPattern(tempo);
}

void rowOne(float tempo) {
  data[0] = B1111;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void rowTwo(float tempo) {
  data[0] = B0000;
  data[1] = B1111;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void rowThree(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B1111;
  data[3] = B0000;

  showPattern(tempo);
}

void rowFour(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B1111;

  showPattern(tempo);
}

void outerSquare(float tempo) {
  data[0] = B1111;
  data[1] = B1001;
  data[2] = B1001;
  data[3] = B1111;

  showPattern(tempo);
}

void innerSquare(float tempo) {
  data[0] = B0000;
  data[1] = B0110;
  data[2] = B0110;
  data[3] = B0000;

  showPattern(tempo);
}

void pinWheelPos1(float tempo) {
  data[0] = B1000;
  data[1] = B0100;
  data[2] = B0010;
  data[3] = B0001;

  showPattern(tempo);
}

void pinWheelPos2(float tempo) {
  data[0] = B0100;
  data[1] = B0100;
  data[2] = B0010;
  data[3] = B0010;

  showPattern(tempo);
}

void pinWheelPos3(float tempo) {
  data[0] = B0010;
  data[1] = B0010;
  data[2] = B0100;
  data[3] = B0100;

  showPattern(tempo);
}

void pinWheelPos4(float tempo) {
  data[0] = B0001;
  data[1] = B0010;
  data[2] = B0100;
  data[3] = B1000;

  showPattern(tempo);
}

void pinWheelPos5(float tempo) {
  data[0] = B0000;
  data[1] = B0011;
  data[2] = B0100;
  data[3] = B1000;

  showPattern(tempo);
}

void pinWheelPos6(float tempo) {
  data[0] = B0000;
  data[1] = B1100;
  data[2] = B0011;
  data[3] = B0000;

  showPattern(tempo);
}

void leftRow1(float tempo) {
  data[0] = B1100;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void rightRow1(float tempo) {
  data[0] = B0011;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void leftRow2(float tempo) {
  data[0] = B0000;
  data[1] = B1100;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void rightRow2(float tempo) {
  data[0] = B0000;
  data[1] = B0011;
  data[2] = B0000;
  data[3] = B0000;

  showPattern(tempo);
}

void leftRow3(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B1100;
  data[3] = B0000;

  showPattern(tempo);
}

void rightRow3(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0011;
  data[3] = B0000;

  showPattern(tempo);
}

void leftRow4(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B1100;

  showPattern(tempo);
}

void rightRow4(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B0011;

  showPattern(tempo);
}

void bottomLeftFill1(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B1000;

  showPattern(tempo);
}

void bottomLeftFill2(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B1100;
  data[3] = B1100;

  showPattern(tempo);
}

void bottomLeftFill3(float tempo) {
  data[0] = B0000;
  data[1] = B1110;
  data[2] = B1110;
  data[3] = B1110;

  showPattern(tempo);
}

void bottomLeftFill4(float tempo) {
  data[0] = B1111;
  data[1] = B1111;
  data[2] = B1111;
  data[3] = B1111;

  showPattern(tempo);
}

void waterfall2a(float tempo) {
  data[0] = B0100;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B1000;

  showPattern(tempo);
}

void waterfall2b(float tempo) {
  data[0] = B0000;
  data[1] = B0100;
  data[2] = B0000;
  data[3] = B1000;

  showPattern(tempo);
}

void waterfall2c(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0100;
  data[3] = B1000;

  showPattern(tempo);
}

void waterfall2d(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B1100;

  showPattern(tempo);
}

void waterfall3a(float tempo) {
  data[0] = B0010;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B1100;

  showPattern(tempo);
}

void waterfall3b(float tempo) {
  data[0] = B0000;
  data[1] = B0010;
  data[2] = B0000;
  data[3] = B1100;

  showPattern(tempo);
}

void waterfall3c(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0010;
  data[3] = B1100;

  showPattern(tempo);
}

void waterfall3d(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B1110;

  showPattern(tempo);
}

void waterfall4a(float tempo) {
  data[0] = B0001;
  data[1] = B0000;
  data[2] = B0000;
  data[3] = B1110;

  showPattern(tempo);
}

void waterfall4b(float tempo) {
  data[0] = B0000;
  data[1] = B0001;
  data[2] = B0000;
  data[3] = B1110;

  showPattern(tempo);
}

void waterfall4c(float tempo) {
  data[0] = B0000;
  data[1] = B0000;
  data[2] = B0001;
  data[3] = B1110;

  showPattern(tempo);
}

//*********ANIMATIONS********
//Note: some animations needed additional calibration to keep in tempo
void spiralIn(float tempo) {
  r1c1(tempo);
  r1c2(tempo);
  r1c3(tempo);
  r1c4(tempo);
  r2c4(tempo);
  r3c4(tempo);
  r4c4(tempo);
  r4c3(tempo);
  r4c2(tempo);
  r4c1(tempo);
  r3c1(tempo);
  r2c1(tempo);
  r2c2(tempo);
  r2c3(tempo);
  r3c3(tempo);
  r3c2(tempo);
  delay(12);
}

void spiralOut(float tempo) {
  r3c2(tempo);
  r3c3(tempo);
  r2c3(tempo);
  r2c2(tempo);
  r2c1(tempo);
  r3c1(tempo);
  r4c1(tempo);
  r4c2(tempo);
  r4c3(tempo);
  r4c4(tempo);
  r3c4(tempo);
  r2c4(tempo);
  r1c4(tempo);
  r1c3(tempo);
  r1c2(tempo);
  r1c1(tempo);
  delay(12);
}

void waveAcross(float tempo) {
  colOne(tempo);
  colTwo(tempo);
  colThree(tempo);
  colFour(tempo);
}

void waveDown(float tempo) {
  rowOne(tempo);
  rowTwo(tempo);
  rowThree(tempo);
  rowFour(tempo);
}

void squareIn(float tempo) {
  outerSquare(tempo);
  innerSquare(tempo);
}

void squareOut(float tempo) {
  innerSquare(tempo);
  outerSquare(tempo);
}

void pinWheel(float tempo) {
  pinWheelPos1(tempo);
  pinWheelPos2(tempo);
  pinWheelPos3(tempo);
  pinWheelPos4(tempo);
  pinWheelPos5(tempo);
  pinWheelPos6(tempo);
  pinWheelPos1(tempo);
  pinWheelPos2(tempo);
  pinWheelPos3(tempo);
  pinWheelPos4(tempo);
  pinWheelPos5(tempo);
  pinWheelPos6(tempo);
  pinWheelPos1(tempo);
  pinWheelPos2(tempo);
  pinWheelPos3(tempo);
  pinWheelPos4(tempo);
  pinWheelPos5(tempo - 3);
}

void reversePinWheel(float tempo) {
  pinWheelPos4(tempo);
  pinWheelPos3(tempo);
  pinWheelPos2(tempo);
  pinWheelPos1(tempo);
  pinWheelPos6(tempo);
  pinWheelPos5(tempo);
  pinWheelPos4(tempo);
  pinWheelPos3(tempo);
  pinWheelPos2(tempo);
  pinWheelPos1(tempo);
  pinWheelPos6(tempo);
  pinWheelPos5(tempo);
  pinWheelPos4(tempo);
  pinWheelPos3(tempo);
  pinWheelPos2(tempo);
  pinWheelPos1(tempo);
  pinWheelPos6(tempo - 3);
}

void brokenPinwheel(float tempo) {
  rowOne(tempo);
  colThree(tempo);
  delay(.5);
  rowThree(tempo);
  colTwo(tempo);
  delay(.5);
}

void alterFallEven(float tempo) {
  leftRow1(tempo);
  rightRow2(tempo);
  leftRow3(tempo);
  rightRow4(tempo);
  delay(1);
}

void alterFallOdd(float tempo) {
  rightRow1(tempo);
  leftRow2(tempo);
  rightRow3(tempo);
  leftRow4(tempo);
  delay(1);
}

void almostFillFromBottomLeft(float tempo) {
  bottomLeftFill1(tempo);
  bottomLeftFill2(tempo);
  bottomLeftFill3(tempo);
  allOff();
  delay(halfNote + 16);
}

void waterfall(float tempo) {
  r1c1(tempo / 6);
  r2c1(tempo / 6);
  r3c1(tempo / 6);
  r4c1(tempo * 8);
  delay(21);
  waterfall2a(tempo / 6);
  waterfall2b(tempo / 6);
  waterfall2c(tempo / 6);
  waterfall2d(tempo * 8);
  delay(22);
  waterfall3a(tempo / 6);
  waterfall3b(tempo / 6);
  waterfall3c(tempo / 6);
  waterfall3d(tempo * 8);
  delay(21);
  waterfall4a(tempo / 6);
  waterfall4b(tempo / 6);
  waterfall4c(tempo / 6);
  rowFour(tempo * 8);
  delay(22);
}

void flash() {
  allOn(eigthNote);
  allOff();
  delay(halfNote + 16);
}
