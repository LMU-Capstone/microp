# Scope of Document
This document contains only the information that was added in Agile 2 and is not in Agile 1.

# Hardware Overview
The primary transceiver is a SFP module operating in the 850nm range. This device is connected to a media converter and a 170cm focal length lens is used to focus the beam. Additional collimation may be performed using the LC wire. 

Figure 1: Block diagram of hardware
![image](https://user-images.githubusercontent.com/40191185/140232601-5b7512a6-b707-49e5-a683-2796c40875e0.png)

Figure 2: Overview of System
![image](https://user-images.githubusercontent.com/40191185/140232676-52fd4d2f-dff5-4cfd-b3d8-08368df5482f.png)

# Improvement Plan
WHAT your team wants to improve on and WHY before presenting for your final presentation
1. We are improving our test software to test via fiber cable. This better allows for backend testing without worrying about issues in the FSOC portion of the system. This required the purcahse of an LC cable; however, this additional purchase can help in collimating the beam.
2. We are moving from C++ to Python to facilitate easier network programming. Although C++ works well with our interface and is very fast, it will make future development more difficult. Eventually, we will need to move our software to a Raspberry Pi and send our data over WiFi. This is a challenge on C++ and Python will make it easier. Python is able to meet our 1Gbps requirement
3. We are changing our steering system from motorized to scanner based. By moving to a scanner, we increase the cost and complexity of the system but increase the reliability of aiming and its speed. Testing found the motor to be too slow for the requirements
4. We updated our lens from 150cm to 170cm to allow for more spacing between our lense and SFP module/media converter because wires required more spacing in front of the media converter.
5. We are changing to an ethernet connection in lieu of direct to usb connections to make interfacing with additional devices easier. The USB connection would require USB3.1+ standards, which was unreasonable with the Raspberry Pis available and within cost. Instead, Ethernet is easier to find at high bitrates.

# House of Quality
Figure 4: A House of Quality Decision Matrix
![image](https://user-images.githubusercontent.com/40191185/140232859-f4a6c398-6abe-4995-b05d-5a9e53c808e4.png)
