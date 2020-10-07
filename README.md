# Controlling PC using Arduino
The program contains code for two ultrasonic sensors that measures the distance from the computer to the hand. The program uses this data to map it to various commands and uses it to control the computer.
Please upload the code and run python code to control your PC.

# Actions:<br>
  <b>VLC Media Player:</b><br>
     &nbsp;&nbsp;&nbsp;<b>Pause/Play:</b> Keep the hand in front of right sensor (less than 3 cm)<br>
     &nbsp;&nbsp;&nbsp;<b>Increase Volume:</b> Move hand away from the sensor in front of the right sensor<br>
     &nbsp;&nbsp;&nbsp;<b>Fast Forward</b> Show the hand in front of right sensor for less than 3 secs.<br>
     &nbsp;&nbsp;&nbsp;<b>Decrease Volume:</b> Move hand towards the sensor.<br>
  <b>Chrome:</b><br>
     &nbsp;&nbsp;&nbsp;<b>Change Tab(Clockwise;Ctrl+Tab Equivalent):</b> Move hand away from the sensor in front of the right sensor<br>
     &nbsp;&nbsp;&nbsp;<b>Pause youtube video</b> Show the hand in front of right sensor for less than 3 secs.<br>
     &nbsp;&nbsp;&nbsp;<b>Change Tab(Anti-clockwise;Ctrl+Shift+Tab Equivalent):</b> Move hand towards the sensor.<br>
<b> Powerpoint/Libre:</b><br>
     &nbsp;&nbsp;&nbsp;<b>Move to next slide while presenting</b> Show the hand in front of right sensor for less than 3 secs.<br>
<i>Note:Functionality for left sensor is not added. More actions can be added for that sensor by modying the Python file.</i>
