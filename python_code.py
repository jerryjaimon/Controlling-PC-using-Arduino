
"""
import pyautogui  # Required to to perform actions
from win32gui import GetWindowText, GetForegroundWindow
while(1):
    print (GetWindowText(GetForegroundWindow()))"""
import serial  # Serial imported for Serial communication
import time  # Required to use delay functions
import sys
import os
import pyautogui
import subprocess
import re

#Establishing communication with serial port.
ArduinoSerial = serial.Serial('/dev/ttyACM2' ,9600)  # Create Serial port object called arduinoSerialData
time.sleep(2)  # wait for 2 seconds for the communication to get established

def get_active_window_title():
    root = subprocess.Popen(['xprop', '-root', '_NET_ACTIVE_WINDOW'], stdout=subprocess.PIPE)
    stdout, stderr = root.communicate()

    m = re.search(b'^_NET_ACTIVE_WINDOW.* ([\w]+)$', stdout)
    if m != None:
        window_id = m.group(1)
        window = subprocess.Popen(['xprop', '-id', window_id, 'WM_NAME'], stdout=subprocess.PIPE)
        stdout, stderr = window.communicate()
    else:
        return None

    match = re.match(b"WM_NAME\(\w+\) = (?P<name>.+)$", stdout)
    if match != None:
        return match.group("name").strip(b'"')
    return None


if __name__ == "__main__":
     while 1:
        incoming = str (ArduinoSerial.readline())  # read the serial data and print it as line
        print (incoming)
        str1=str(get_active_window_title())
        if 'VLC' in str1:
            if '4' in incoming:
                pyautogui.typewrite(['space'], 0.2)
            if '2' in incoming:
                pyautogui.hotkey('right')
            if '5' in incoming:
                pyautogui.hotkey('ctrl', 'down')
            if '6' in incoming:
                pyautogui.hotkey('ctrl', 'up')
            incoming = "";
        elif 'Chrome' in str1:
            if '5' in incoming:
                pyautogui.hotkey('ctrl' ,'shift' ,'tab')
                time.sleep(0.5)

            if '6' in incoming:
                pyautogui.hotkey('ctrl' ,'tab')
                time.sleep(0.25)
            if '2' in incoming:
                pyautogui.hotkey('space')
            incoming = "";
        elif 'Presenting' in str1:
            if '2' in incoming:
                pyautogui.hotkey('right')

