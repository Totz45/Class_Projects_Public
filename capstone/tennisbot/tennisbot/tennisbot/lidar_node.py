import time
import serial


ser = serial.Serial("/dev/ttyAMA0", 115200)
count = 0
# ser = serial.Serial("COM12", 115200)

def read_lidar():
    while True:
        counter = ser.in_waiting # count the number of bytes of the serial port
        if counter > 8:
            bytes_serial = ser.read(9)
            ser.reset_input_buffer()

            if bytes_serial[0] == 0x59 and bytes_serial[1] == 0x59: 
                print("Printing python3 portion") 

                distance = bytes_serial[2] + bytes_serial[3]*256 # multiplied by 256, because the binary data is shifted by 8 to the left (equivalent to "<< 8").                                              # Dist_L, could simply be added resulting in 16-bit data of Dist_Total.
                
                temperature = bytes_serial[6] + bytes_serial[7]*256
                temperature = (temperature/8) - 256
                
                # Count incremented by 1
                count += 1
                
                print("Distance:"+ str(distance))
                if temperature != 0:
                    print("Temperature:" + str(temperature))
                    print("Count:" + str(count))
                ser.reset_input_buffer()



if __name__ == "__main__":
    try:
        if ser.isOpen() == False:
            ser.open()
        read_lidar()
    except KeyboardInterrupt: # ctrl + c in terminal.
        if ser != None:
            ser.close()
            print("program interrupted by the user")