import serial
import time
import board
import busio
import digitalio
from adafruit_displayio_ssd1322 import SSD1322
import displayio
import terminalio
from adafruit_display_text import label
import adafruit_character_lcd.character_lcd as character_lcd

#initialize lidar
lidar = serial.Serial("/dev/ttyS0",115200)

# GPIO PINs if using the EA DOGM163W-A.
lcd_rs = digitalio.DigitalInOut(board.D26)
lcd_en = digitalio.DigitalInOut(board.D19)
lcd_d4 = digitalio.DigitalInOut(board.D13)
lcd_d5 = digitalio.DigitalInOut(board.D6)
lcd_d6 = digitalio.DigitalInOut(board.D5)
lcd_d7 = digitalio.DigitalInOut(board.D11)

lcd_columns = 16
lcd_rows = 3

# SPI PINs if using the EA DOGM132L-5.
spi = busio.SPI(clock=board.SCK, MOSI=board.MOSI)
cs = digitalio.DigitalInOut(board.D5)
dc = digitalio.DigitalInOut(board.D6)
reset = digitalio.DigitalInOut(board.D9)

def read_lidar():
    while True:
        if lidar.in_waiting > 0:
            data = lidar.read(9)
            if data[0] == 0x59 and data[1] == 0x59:
                distance = data[2] + data[3] * 256
                return distance

def init_M163_lcd():
    lcd = character_lcd.Character_LCD_Mono(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7, lcd_columns, lcd_rows)
    return lcd

#displayio.release_displays()
def display_distance_M163(lcd, distance):
    lcd.clear()
    lcd.message = f"Distance: {distance} cm"

def init_M132_lcd():
    display_bus = displayio.FourWire(spi, command=dc, chip_select=cs, reset=reset)
    display = SSD1322(display_bus, width=132, height=32)

    # Create a display group
    splash = displayio.Group()
    display.show(splash)

    # Create a text label
    text = "Distance: -- cm"
    text_area = label.Label(terminalio.FONT, text=text, color=0xFFFF00, x=5, y=15)
    splash.append(text_area)
    return display, text_area

def display_distance_M132(text_area, distance):
    text_area.text = f"Distance: {distance} cm"

if __name__ == "__main__":
    display_type = input("Enter display used(DOGM163/DOGM132): ")
    
    if display_type == "DOGM163":
        lcd =init_M163_lcd()
        while True:
            distance = read_lidar()
            display_distance_M163(lcd, distance)
            time.sleep(1)
    elif display_type == "DOGM132":
        display, text_area = init_M132_lcd()
        while True:
            distance = read_lidar()
            display_distance_M132(text_area, distance)
            time.sleep(1)
    else:
        print("Invalid display used. Please enter either 'DOGM163' or 'DOGM132'.")