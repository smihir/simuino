// EEPROM
class eeprom {

 public:
  int read(int address);
  void write(int address, int value);
  
  // Wrappers for debug functionality
  int readX(int z,int address);
  void writeX(int z,int address, int value);
};
eeprom EEPROM;

int eepromStorage[1000]; // 0 - 511 allowed
int value = 998;

int eeprom::read(int address) 
{
  
  if(address > 0 && address < 512)value = eepromStorage[address];
  servuinoFunc(S_EEPROM_READ,address,value,NULL,0);
  return(value);
}
void eeprom::write(int address, int value) 
{
  if(address > 0 && address < 512 && value >= 0 && value < 256)eepromStorage[address] = value;
  servuinoFunc(S_EEPROM_WRITE,address,value,NULL,0);
  return;
}

int eeprom::readX(int z,int address) 
{
  ino(z);
  return(read(address));
}
void eeprom::writeX(int z,int address, int value) 
{
  ino(z);
  write(address,value);
  return;
}


