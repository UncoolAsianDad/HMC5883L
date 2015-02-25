#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define dID 0x1e

int fd;

int main(int argc, char* argv[])
{

  // suppress warnings
  (void)argc; (void)argv;


     if((fd=wiringPiI2CSetup(dID))<0)
        return 1;
    while (1) {
      wiringPiI2CWriteReg8(fd, 0x02, 0x00);


     int x = wiringPiI2CReadReg16(fd, 0x03);
     int y = wiringPiI2CReadReg16(fd, 0x04);
     int z = wiringPiI2CReadReg16(fd, 0x05);

     printf("X: %d, Y: %d, Z: %d\n\r", x,y,z);
	usleep(1000);

}
     return 0;
}
