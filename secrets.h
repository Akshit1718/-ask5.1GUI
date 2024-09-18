from tkinter import *
import tkinter.font as FONT
import RPi.GPIO as GPIO
from gpiozero import LED

GPIO.setmode(GPIO.BCM)

# Updated LED pins
red_led = LED(17)
blue_led = LED(27)
green_led = LED(22)

win = Tk()
win.title("LED Controller")
myFont = FONT.Font(family='Helvetica', size=14, weight='bold')

def updateStatus(message):
    statusLabel.config(text=message)

def redLedToggle():
    if red_led.is_lit:
        red_led.off()
        redLedButton["text"] = "Turn RED LED ON"
        updateStatus("Red LED is now OFF")
    else:
        red_led.on()
        redLedButton["text"] = "Turn RED LED OFF"
        updateStatus("Red LED is now ON")
    blue_led.off()
    blueLedButton["text"] = "Turn BLUE LED ON"
    green_led.off()
    greenLedButton["text"] = "Turn GREEN LED ON"

def blueLedToggle():
    if blue_led.is_lit:
        blue_led.off()
        blueLedButton["text"] = "Turn BLUE LED ON"
        updateStatus("Blue LED is now OFF")
    else:
        blue_led.on()
        blueLedButton["text"] = "Turn BLUE LED OFF"
        updateStatus("Blue LED is now ON")
    red_led.off()
    redLedButton["text"] = "Turn RED LED ON"
    green_led.off()
    greenLedButton["text"] = "Turn GREEN LED ON"

def greenLedToggle():
    if green_led.is_lit:
        green_led.off()
        greenLedButton["text"] = "Turn GREEN LED ON"
        updateStatus("Green LED is now OFF")
    else:
        green_led.on()
        greenLedButton["text"] = "Turn GREEN LED OFF"
        updateStatus("Green LED is now ON")
    red_led.off()
    redLedButton["text"] = "Turn RED LED ON"
    blue_led.off()
    blueLedButton["text"] = "Turn BLUE LED ON"

def close():
    GPIO.cleanup()
    win.destroy()

# Updated button texts
redLedButton = Button(win, text="Turn RED LED ON", font=myFont, command=redLedToggle, bg='red', height=2, width=30)
redLedButton.grid(row=0, column=1)

blueLedButton = Button(win, text="Turn BLUE LED ON", font=myFont, command=blueLedToggle, bg='blue', height=2, width=30)
blueLedButton.grid(row=1, column=1)

greenLedButton = Button(win, text="Turn GREEN LED ON", font=myFont, command=greenLedToggle, bg='green', height=2, width=30)
greenLedButton.grid(row=2, column=1)

exitButton = Button(win, text="EXIT", font=myFont, command=close, bg='yellow', height=2, width=30)
exitButton.grid(row=4, column=1)

# Status Label to show LED states
statusLabel = Label(win, text="", font=myFont)
statusLabel.grid(row=3, column=1)

win.protocol("WM_DELETE_WINDOW", close)
win.mainloop()
