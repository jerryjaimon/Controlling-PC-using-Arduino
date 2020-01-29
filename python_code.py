import serial
import pyautogui

Arduino_Serial=serial.Serial('com9',9600)

while 1:
    incoming_data=str(Arduino_Serial.readline())
    print(incoming_data)

    if "Change window" in incoming_data:
       pyautogui.keyDown('alt')
       pyautogui.keyDown('tab')
    if "Enter" in incoming_data:
       pyautogui.keyUp('alt')
       pyautogui.keyUp('tab')

    if "Close" in incoming_data:
        pyautogui.hotkey('alt','f4')

