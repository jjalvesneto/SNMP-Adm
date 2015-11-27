/*
This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  Note: InfraredReceiver can ONLY be connected to D2 when use this lib.
*/

#ifndef INFRARED_RECEIVER_H
#define INFRARED_RECEIVER_H


#define DBG(x) Serial.print(x);
#define DBGLN(x) Serial.println(x);

// NEC protocol parameters
#define BUFFERSIZE 40
#define IR_NUM_BITS 32     // number of bits sent by IR remote
#define FirstLastBit 15      // divide 32 bits into two 15 bit chunks for integer variables. Ignore center two bits. they are all the same.
#define BIT_1_MSEC 1600           // Binary 1 threshold (Microseconds)
#define BIT_1_MSEC_MAX 2500
#define BIT_0_MSEC 450            // Binary 0 threshold (Microseconds)
#define START_PULSE_MSEC 4000 // Start bit threshold (Microseconds)
#define VERIFY_REMOTE 16128  // verifies first bits are 11111100000000. Different remotes may have different start codes

/*!
Receive remote codes from an IR remote. Interrupt 0 driven\n
Supports NEC protocol remote controls (most are NEC protocol)\n
*/
class InfraredReceiver
{
 public:
  InfraredReceiver();
  int read();
  void begin();
  uint16_t pulseMsec[IR_NUM_BITS+5];
  int rawCode;
  
 private:
   virtual int decode(int key);
   void pulse_to_bits(unsigned char bits[], int numBits);
   int verifyRemote(unsigned char bits[]);
   int bits_to_int(unsigned char bits[], int zeroBitCnt);
};

#endif // INFRARED_RECEIVER_H