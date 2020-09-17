#include <arduino-timer.h>

auto timer = timer_create_default(); // create a timer with default settings
const int interruptPin = 2;
volatile int rollBackVariable;
volatile int saved;
unsigned long button_time = 0;  
unsigned long last_button_time = 0; 

const int ARRAY_SIZE = 256;

char* memoryAddresses[] = {
  //32 Registers
  address0, address1, address2, address3, address4, address5, address6, address7, address8, address9, address10,
  address11, address12, address13, address14, address15, address16, address17, address18, address19, address20,
  address21, address22, address23, address24, address25, address26, address27, address28, address29, address30,
  address31, address32,

  //64 I/O Registers
  address33, address34, address35, address36, address37, address38, address39, address40, address41, address42, 
  address43, address44, address45, address46, address47, address48, address49, address50, address51, address52,
  address53, address54, address55, address56, address57, address58, address59, address60, address61, address62,
  address63, address64, address65, address66, address67, address68, address69, address70, address71, address72, 
  address73, address74, address75, address76, address77, address78, address79, address80, address81, address82,
  address83, address84, address85, address86, address87, address88, address89, address90, address91, address93,
  address94, address95, address96,

  //160 Ext I/O Registers
  address97, address98, address99, address100, address101, address102, address103, address104, address105, address106, 
  address107, address108, address109, address110, address111, address112, address113, address114, address115, address116,
  address117, address118, address119, address120, address121, address122, address123, address124, address125, address126,
  address127, address128, address129, address130, address131, address132, address133, address134, address135, address136, 
  address137, address138, address139, address140, address141, address142, address143, address144, address145, address146,
  address147, address148, address149, address150, address151, address152, address153, address154, address155, address156,
  address157, address158, address159, address160, address161, address162, address163, address164, address165, address166, 
  address167, address168, address169, address170, address171, address172, address173, address174, address175, address176,
  address177, address178, address179, address180, address181, address182, address183, address184, address185, address186, 
  address187, address188, address189, address190, address191, address192, address193, address194, address195, address196,
  address197, address198, address199, address200, address201, address202, address203, address204, address205, address206,
  address207, address208, address209, address210, address211, address212, address213, address214, address215, address216,
  address217, address218, address219, address220, address221, address222, address223, address224, address225, address226,
  address227, address228, address229, address230, address231, address232, address233, address234, address235, address236, 
  address237, address238, address239, address240, address241, address242, address243, address244, address245, address246,
  address247, address248, address249, address250, address251, address252, address253, address254, address255,
 };

char* tempMemoryAddresses[] = {
  //32 Registers
  _address0, _address1, _address2, _address3, _address4, _address5, _address6, _address7, _address8, _address9, _address10,
  _address11, _address12, _address13, _address14, _address15, _address16, _address17, _address18, _address19, _address20,
  _address21, _address22, _address23, _address24, _address25, _address26, _address27, _address28, _address29, _address30,
  _address31, _address32,

  //64 I/O Registers
  _address33, _address34, _address35, _address36, _address37, _address38, _address39, _address40, _address41, _address42, 
  _address43, _address44, _address45, _address46, _address47, _address48, _address49, _address50, _address51, _address52,
  _address53, _address54, _address55, _address56, _address57, _address58, _address59, _address60, _address61, _address62,
  _address63, _address64, _address65, _address66, _address67, _address68, _address69, _address70, _address71, _address72, 
  _address73, _address74, _address75, _address76, _address77, _address78, _address79, _address80, _address81, _address82,
  _address83, _address84, _address85, _address86, _address87, _address88, _address89, _address90, _address91, _address93,
  _address94, _address95, _address96,

  //160 Ext I/O Registers
  _address97, _address98, _address99, _address100, _address101, _address102, _address103, _address104, _address105, _address106, 
  _address107, _address108, _address109, _address110, _address111, _address112, _address113, _address114, _address115, _address116,
  _address117, _address118, _address119, _address120, _address121, _address122, _address123, _address124, _address125, _address126,
  _address127, _address128, _address129, _address130, _address131, _address132, _address133, _address134, _address135, _address136, 
  _address137, _address138, _address139, _address140, _address141, _address142, _address143, _address144, _address145, _address146,
  _address147, _address148, _address149, _address150, _address151, _address152, _address153, _address154, _address155, _address156,
  _address157, _address158, _address159, _address160, _address161, _address162, _address163, _address164, _address165, _address166, 
  _address167, _address168, _address169, _address170, _address171, _address172, _address173, _address174, _address175, _address176,
  _address177, _address178, _address179, _address180, _address181, _address182, _address183, _address184, _address185, _address186, 
  _address187, _address188, _address189, _address190, _address191, _address192, _address193, _address194, _address195, _address196,
  _address197, _address198, _address199, _address200, _address201, _address202, _address203, _address204, _address205, _address206,
  _address207, _address208, _address209, _address210, _address211, _address212, _address213, _address214, _address215, _address216,
  _address217, _address218, _address219, _address220, _address221, _address222, _address223, _address224, _address225, _address226,
  _address227, _address228, _address229, _address230, _address231, _address232, _address233, _address234, _address235, _address236, 
  _address237, _address238, _address239, _address240, _address241, _address242, _address243, _address244, _address245, _address246,
  _address247, _address248, _address249, _address250, _address251, _address252, _address253, _address254, _address255,
 };


int addresses[] = {
  //32 Registers:
  0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E,
  0x000F, 0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017, 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D,
  0x001E, 0x001F, 

    //64 I/O Registers: 
  0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 
  0x002F, 0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D,
  0x003E, 0x003F, 0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 
  0x004D, 0x004E, 0x004F, 0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005A, 0x005B, 
  0x005C, 0x005D, 0x005E, 0x005F, 
  
  //160 Ext I/O Registers: 
  0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D,
  0x006E, 0x006F, 0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007A, 0x007B, 
  0x007C, 0x007D, 0x007E, 0x007F, 0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 
  0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F, 0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 
  0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F, 0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 
  0x00A6, 0x00A7, 0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF, 0x00B0, 0x00B1, 0x00B2, 0x00B3, 
  0x00B4, 0x00B5, 0x00B6, 0x00B7, 0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,  0x00C0, 0x00C1, 
  0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7, 0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
  0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7, 0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD,
  0x00DE, 0x00DF, 0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7, 0x00E8, 0x00E9, 0x00EA, 0x00EB, 
  0x00EC, 0x00ED, 0x00EE, 0x00EF, 0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7, 0x00F8, 0x00F9, 
  0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF,
  
  };

void setup() {
  attachInterrupt(digitalPinToInterrupt(interruptPin), recovery, FALLING);
  timer.every(1, checkpoint); // call the toggle_led function every 1000 millis (1 second)
  Serial.begin(9600);  //turn on serial communication
}

void loop() {
  timer.tick(); // tick the timer
  Serial.println(factorial(5));
  delay(100);
}

int factorial(int n) 
{ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

void recovery() {
  cli();
  malicious(); // This is a function that I will write it later.
               // I will not tell you what I will be doing in this function, it is going to 
               // destroy some registers of the processor.
               // The idea is that the checkpoint/recovery should be able to cancel this function out.
  //******************************* 
       //Implement the actual recovery here: you should restor all registers 
       //from what you saved in the checkpoint funciton. 
  //******************************* 
  for (int i = 0; i < ARRAY_SIZE; i++ )
  {
      memoryAddresses[i] = tempMemoryAddresses[i];
  }
  
  Serial.print("Recovery done at the time:");
  Serial.println(micros());
  sei();    
  }    
}

void checkpoint() {
  //At this routine you should save all register somewhere in memory for later recovery 

  for (int i = 0; i < ARRAY_SIZE; i++ )
  {
      memoryAddresses[i] = (char*)addresses[i];
      tempMemoryAddresses[i] = (char*)memoryAddresses[i];
  }
  
  
}

void malicious(void){
  //I will do some malicious things here to destroy some of your registers. 
  //Your code should stand it. 

}
