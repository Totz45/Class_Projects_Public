import lgpio
import time

# Define GPIO pins for LCD
LCD_RS = 26
LCD_E  = 19
LCD_D4 = 13
LCD_D5 = 6
LCD_D6 = 5
LCD_D7 = 11

LCD_WIDTH = 16  # 16 characters per row
LCD_LINES = 2   # 2-row display
LCD_CMD = True
LCD_CHR = False

# Initialize GPIO
h = lgpio.gpiochip_open(0)  # Open GPIO chip
lgpio.gpio_claim_output(h, LCD_RS)
lgpio.gpio_claim_output(h, LCD_E)
lgpio.gpio_claim_output(h, LCD_D4)
lgpio.gpio_claim_output(h, LCD_D5)
lgpio.gpio_claim_output(h, LCD_D6)
lgpio.gpio_claim_output(h, LCD_D7)

def lcd_command(cmd):
    lgpio.gpio_write(h, LCD_RS, LCD_CMD)
    lcd_write(cmd)

def lcd_display(message):
    lgpio.gpio_write(h, LCD_RS, LCD_CHR)
    for char in message:
        lcd_write(ord(char))

def lcd_write(bits):
    lgpio.gpio_write(h, LCD_D4, bits & 0x10)
    lgpio.gpio_write(h, LCD_D5, bits & 0x20)
    lgpio.gpio_write(h, LCD_D6, bits & 0x40)
    lgpio.gpio_write(h, LCD_D7, bits & 0x80)
    lgpio.gpio_write(h, LCD_E, True)
    time.sleep(0.0005)
    lgpio.gpio_write(h, LCD_E, False)
    time.sleep(0.0005)

    lgpio.gpio_write(h, LCD_D4, bits & 0x01)
    lgpio.gpio_write(h, LCD_D5, bits & 0x02)
    lgpio.gpio_write(h, LCD_D6, bits & 0x04)
    lgpio.gpio_write(h, LCD_D7, bits & 0x08)
    lgpio.gpio_write(h, LCD_E, True)
    time.sleep(0.0005)
    lgpio.gpio_write(h, LCD_E, False)
    time.sleep(0.0005)

# Main function
if __name__ == "__main__":
    lcd_command(0x01)  # Clear display
    lcd_display("Hello, World!")
