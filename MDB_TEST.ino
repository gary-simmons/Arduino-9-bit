#include <SoftwareSerial.h>

SoftwareSerial mdb_serial(10, 11, true); // RX, TX
//int tx = 11;

int answer = 0;

uint8_t reset[] =
{
  0x10,
  0x10
};

uint8_t poll[] = 
{
0x12, 
0x12
};
uint8_t set[] = {
0x11, 
0x00,
0x02,
0x00,
0x00,
0x00,
0x13
};

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600, true);

  mdb_serial.begin(9600);

  Serial.println("Applciation Started ...");

  delay(3000);

  Serial.println("Reset Reader ...");
mdb_serial.writeAll(reset, 2);
read_mdb();
//  mdb_serial.writeModeBitOn(0x10);
//  mdb_serial.writeModeBitOff(0x10);
  //
delay(2000);
  //
Serial.println("Poll Reader ...");
mdb_serial.writeAll(poll, 2);
read_mdb();
  //  mdb_serial.writeModeBitOn(0x12);
  //  mdb_serial.writeModeBitOff(0x12);
  //
delay(2000);
  //
Serial.println("Setup Reader ...");
mdb_serial.writeAll(set, 7);
read_mdb();
  //  mdb_serial.writeModeBitOn(0x11);
  //  mdb_serial.writeModeBitOff(0x00);
  //  mdb_serial.writeModeBitOff(0x02);
  //  mdb_serial.writeModeBitOff(0x00);
  //  mdb_serial.writeModeBitOff(0x00);
  //  mdb_serial.writeModeBitOff(0x13);


}

void loop() // run over and over
{
//  Serial.println("Loopy ...");
//  //  mdb_serial.writeModeBitOn(0x10);
//  //  mdb_serial.writeModeBitOff(0x10);
//
////  mdb_serial.writeAll(reset, 2);
//
//  delay(1000);
}

void read_mdb()
{
  Serial.println("Waiting for MDB response ... ");
  while (!mdb_serial.available())
  {
    ;
  }
  delay(1000);
  while (mdb_serial.available())
  {
    Serial.print(mdb_serial.read(),BIN);
    Serial.print("\n");
//    answer = mdb_serial.read();
//    if (answer < 255)
//    {
//      Serial.print("Got MDB response ... ");
//      Serial.print(answer);
//      Serial.print("\n");
//    }
    delay(10);
  }
}
