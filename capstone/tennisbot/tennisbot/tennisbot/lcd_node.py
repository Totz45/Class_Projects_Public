
# The wiring for the LCD is as follows:
# 1 : GND
# 2 : 5V
# 3 : Contrast (0-5V)*
# 4 : RS (Register Select)
# 5 : R/W (Read Write)       - GROUND THIS PIN
# 6 : Enable or Strobe
# 7 : Data Bit 0             - NOT USED
# 8 : Data Bit 1             - NOT USED
# 9 : Data Bit 2             - NOT USED
# 10: Data Bit 3             - NOT USED
# 11: Data Bit 4
# 12: Data Bit 5
# 13: Data Bit 6
# 14: Data Bit 7
# 15: LCD Backlight +5V**
# 16: LCD Backlight GND

#import
import lgpio
import time

# Define GPIO to LCD mapping
LCD_RS = 7
LCD_E  = 8
LCD_D4 = 25
LCD_D5 = 24
LCD_D6 = 23
LCD_D7 = 18


# Define some device constants
LCD_WIDTH = 16    # Maximum characters per line
LCD_CHR = True
LCD_CMD = False

LCD_LINE_1 = 0x80 # LCD RAM address for the 1st line
LCD_LINE_2 = 0xC0 # LCD RAM address for the 2nd line

# Timing constants
E_PULSE = 0.0005
E_DELAY = 0.0005

def main():
    # Main program block

    # open the gpio chip and set the outputs
    h = lgpio.gpiochip_open(0)
    lgpio.gpio_claim_output(h, LCD_E) # E
    lgpio.gpio_claim_output(h, LCD_RS) # RS
    lgpio.gpio_claim_output(h, LCD_D4) # DB4
    lgpio.gpio_claim_output(h, LCD_D5) # DB5
    lgpio.gpio_claim_output(h, LCD_D6) # DB6
    lgpio.gpio_claim_output(h, LCD_D7) # DB7


    # Initialise display
    lcd_init()

    while True:

        # Send some test
        lcd_string("Rasbperry Pi",LCD_LINE_1)
        lcd_string("16x2 LCD Test",LCD_LINE_2)

        time.sleep(3) # 3 second delay

        # Send some text
        lcd_string("1234567890123456",LCD_LINE_1)
        lcd_string("abcdefghijklmnop",LCD_LINE_2)



        time.sleep(3) # 3 second delay

        # Send some text
        lcd_string("RaspberryPi-spy",LCD_LINE_1)
        lcd_string(".co.uk",LCD_LINE_2)

        time.sleep(3)

        # Send some text
        lcd_string("Follow me on",LCD_LINE_1)
        lcd_string("Twitter @RPiSpy",LCD_LINE_2)

        time.sleep(3)

def lcd_init():
    # Initialise display
    lcd_byte(0x33,LCD_CMD) # 110011 Initialise
    lcd_byte(0x32,LCD_CMD) # 110010 Initialise
    lcd_byte(0x06,LCD_CMD) # 000110 Cursor move direction
    lcd_byte(0x0C,LCD_CMD) # 001100 Display On,Cursor Off, Blink Off
    lcd_byte(0x28,LCD_CMD) # 101000 Data length, number of lines, font size
    lcd_byte(0x01,LCD_CMD) # 000001 Clear display
    time.sleep(E_DELAY)

def lcd_byte(bits, mode):
    # Send byte to data pins
    # bits = data
    # mode = True  for character
    #        False for command

    lgpio.gpio_write(h, LCD_RS, mode) # RS

    # High bits
    lgpio.gpio_write(h, LCD_D4, False)
    lgpio.gpio_write(h, LCD_D5, False)
    lgpio.gpio_write(h, LCD_D6, False)
    lgpio.gpio_write(h, LCD_D7, False)
    if bits&0x10==0x10:
        lgpio.gpio_write(h, LCD_D4, True)
    if bits&0x20==0x20:
        lgpio.gpio_write(h, LCD_D5, True)
    if bits&0x40==0x40:
        lgpio.gpio_write(h, LCD_D6, True)
    if bits&0x80==0x80:
        lgpio.gpio_write(h, LCD_D7, True)

    # Toggle 'Enable' pin
    lcd_toggle_enable()

    # Low bits
    lgpio.gpio_write(h, LCD_D4, False)
    lgpio.gpio_write(h, LCD_D5, False)
    lgpio.gpio_write(h, LCD_D6, False)
    lgpio.gpio_write(h, LCD_D7, False)
    if bits&0x01==0x01:
        lgpio.gpio_write(h, LCD_D4, True)
    if bits&0x02==0x02:
        lgpio.gpio_write(h, LCD_D5, True)
    if bits&0x04==0x04:
        lgpio.gpio_write(h, LCD_D6, True)
    if bits&0x08==0x08:
        lgpio.gpio_write(h, LCD_D7, True)

    # Toggle 'Enable' pin
    lcd_toggle_enable()

def lcd_toggle_enable():
    # Toggle enable
    time.sleep(E_DELAY)
    lgpio.gpio_write(h, LCD_E, True)
    time.sleep(E_PULSE)
    lgpio.gpio_write(h, LCD_E, False)
    time.sleep(E_DELAY)

def lcd_string(message,line):
    # Send string to display




    message = message.ljust(LCD_WIDTH," ")

    lcd_byte(line, LCD_CMD)

    for i in range(LCD_WIDTH):
        lcd_byte(ord(message[i]),LCD_CHR)

if __name__ == '__main__':

    try:
        main()
    except KeyboardInterrupt:
        pass
    finally:
        lcd_byte(0x01, LCD_CMD)
        lcd_string("Goodbye!",LCD_LINE_1)
        lgpio.gpiochip_close(h)