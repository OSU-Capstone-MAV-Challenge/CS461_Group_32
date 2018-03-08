⋅⋅*from smbus import SMBus
⋅⋅*from time import sleep

⋅⋅*x = 1
⋅⋅*while True:
⋅⋅* try:
⋅⋅*  i2cbus = SMBus(1)
⋅⋅*  i2cbus.write_byte(0x70, 0x51) #0x70 = 112, 0x51 = 81
⋅⋅*  #long   write_byte(int addr,char val)	Write Byte transaction.	
⋅⋅*  val = i2cbus.read_word_data(0x70, 0xe1) #0x70 = 112, 0xe1 = 225
⋅⋅*  #long   read_word_data(int addr,char cmd) Read Word Data transaction.		
⋅⋅*  print (val >> 8) & 0xff | (val>>8 & 0xff), 'cm'
⋅⋅*  #x >> y
⋅⋅*  #Returns x with the bits shifted to the right by y places. 
⋅⋅*  #This is the same as //'ing x by 2**y.
⋅⋅*  #print (val >> 8) & 0xff | (val>>8 & 0xff), 'cm'
⋅⋅*  #divide val by 2^8 and ignore the remains.
