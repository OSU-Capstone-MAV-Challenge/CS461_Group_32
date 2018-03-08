1. from smbus import SMBus
2. from time import sleep

3. x = 1
4. while True:
5. try:
6.  i2cbus = SMBus(1)
7.  i2cbus.write_byte(0x70, 0x51) #0x70 = 112, 0x51 = 81
8.  #long   write_byte(int addr,char val)	Write Byte transaction.	
9.  val = i2cbus.read_word_data(0x70, 0xe1) #0x70 = 112, 0xe1 = 225
10.  #long   read_word_data(int addr,char cmd) Read Word Data transaction.		
11. print (val >> 8) & 0xff | (val>>8 & 0xff), 'cm'
12.  #x >> y
13.  #Returns x with the bits shifted to the right by y places. 
14.  #This is the same as //'ing x by 2**y.
15.  #print (val >> 8) & 0xff | (val>>8 & 0xff), 'cm'
16.  #divide val by 2^8 and ignore the remains.
