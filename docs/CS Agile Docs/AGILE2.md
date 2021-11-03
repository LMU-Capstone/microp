Marine Infrared Communication Relays
Ian Green && Natalia Cedeno

# Updates
All changes to version
Version 2 updated the following:
- Added 'Hardware Overview' Section and new hardware diagrams (Line 29)
- Added 'House of Quality' section
- Added 'Improvement Plan' section
- Modified scope of document to reflect expansion to Hardware components (Line 15)
- Added section header for gannt chart
- Moved schedule above appendix into main body


# Scope of this document:
This document summarizes technical information about MICROP including a project description, deliverables, and problem statements.

# Project Description Summary
This project is a two-semester project. In the Fall 2021 semester, a static free space optical communication system will be designed, built, and tested for communication in the 10Ghz range. SATA connections will be used, limiting real transmit speed to 6Ghz maximum. This SATA connection to PC is novel and will be developed. Further software will be developed to create signals for communication at 6GHz, beyond the clock limit of available CPUs.

## Problem Being Solved
This project has the eventual aim of creating optical relays for over the horizon communication to allow for high-bandwidth communication between naval ships in RF denied environments. However, this semester will create a testbed for high bandwidth communication in the amateur environment. This is a novel approach to use SATA connections to a large desktop computer and will contribute to low-cost applications of free space optical communication systems. 

## Customers
Usage of free space optical communication is being used by the military in future developments for its high-bandwidth, low-sidelobe abilities in RF denied environments. However, as prices reduce, many users could find benefits from systems like this. High bitrates are increasingly desired by commerical customers and a cheap solution will allow hobbyist usage of the system.

# Justification
Free space optical communication systems can cost upwards of $10 million, with even cheap at home solutions priced at $500,000. This is prohibitive and makes research inaccessible to average users. Price reductions will improve research and allow amateur usage of advanced communication systems.

# Hardware Overview
The primary transceiver is a SFP module operating in the 850nm range. This device is connected to a media converter and a 170cm focal length lens is used to focus the beam. Additional collimation may be performed using the LC wire. 

Figure 1: Block diagram of hardware
![image](https://user-images.githubusercontent.com/40191185/140232601-5b7512a6-b707-49e5-a683-2796c40875e0.png)

Figure 2: Overview of System
![image](https://user-images.githubusercontent.com/40191185/140232676-52fd4d2f-dff5-4cfd-b3d8-08368df5482f.png)

# Software Technical Documentations
The tech stack is fairly simple on the systems side; however, implementation will be difficult. A hardware interface will be constructed and programmed. The specifics of the interface will be chosen during the research phase of this project.

On top of the hardware interface, two systems will be built. A control system will monitor the motors and point the transmitter and receiver at the desired unit. The second system will decode the received signal and encode transmitted signals.

Additional testing frameworks will be built using hardware in the loop testing. Packets must be sent and checked for errors to determine an error rate.

The KORUZA system is preferred due to its high bitrate; however, other open hardware systems like TwiBright's Ronja are considered. These systems will be selected based on EE department approval and further discussion with optics professor Dr. Asghari.

Figure 3 shows the technical specifications of the transceiver system.
![image](https://user-images.githubusercontent.com/40191185/134425809-ba5a7f2f-afd6-49e3-84e9-e4984ec8b118.png)

# Semester Deliverables:
The timeline is found in the Gannt Chart.xlsx and in Figure 2 of the 'MICROP Proposal.pdf'. At the end of this semester, the group will have demonstrated the ability to communicate through static free space optical systems.

Hardware construction will be completed mid-semester and transmit/receive programs will be completed. Dynamic movement and tracking software are to be introduced next semester as the continuation of this project.

Novel testing systems must be developed to test 10GHz transmit times on systems with CPUs below 4GHz and on wires with less than 6GHz bandwidth. 

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

# Schedule
Figure 5: Schedule of Work
![Screenshot from 2021-09-20 19-21-35](https://user-images.githubusercontent.com/40191185/134102124-98935948-cdea-476f-8c65-c09ea26ad542.png)


# Appendix:
https://lmu-ee-capstone.atlassian.net/jira/software/projects/MIC/boards/1/roadmap

https://github.com/LMU-Capstone/microp

https://github.com/LMU-Capstone/microp/tree/main/docs/CS%20Agile%20Docs


# MICROP Proposal
Marine Infrared Communication Relays by Natalia Cedeno and Ian Green

We propose the creation of a relay for optical communication in the infrared range for use in surface naval vessel communication. This device would be mounted on an unmanned aerial vehicle (UAV) to be flown during naval operations. While it can be used in commercial and personal applications, this is likely the best fit for use in military applications due to the larger budget and special needs of the US Department of Navy (DoN). This project will be a proof of concept for future Flying ad hoc networks (FANETs). It will demonstrate the ability to communicate between two moving objects with high variations in velocity.

The milestones are broken into 4 stages. The first stage is research and development, including parts ordering and design modifications to fit on a UAV. This phase is continuous and will last for most of the project. The second phase consists of building a static free-space optical communication (FSO) system in-lab without movement. This phase is expected to be completed by December 3rd, before the end of the first semester. The third phase will begin moving the receiver, and the fourth phase will move the transmitter. These two phases will be completed by February 10th and April 21st respectively. By the end of this project, both transmitter and receiver will move independently and track each other.

The US DoN requires high-bandwidth secure communication in radio frequency (RF) denied environments. DoN surface vessels collect large amounts of data that must be immediately shared fleetwide. For example, the Cooperative Engagement Capability and AEGIS systems of the DoN send large amounts of data between surface vessels. RF communication suffers from issues that make FSO a better option than traditional radio communication. First, RF communication suffers from high side lobe, sending signals in undesired directions. This undesired radiation allows for other vessels to receive the signal, including enemy ships. With the increasing importance of data in modern warfare, denial of enemy reception of data is paramount. Second, RF communication requires larger bandwidths to match the transmission rate of FSO systems. Larger bandwidths introduce issues of interference as RF bands become increasingly occupied by commercial interests. Third, the RF space has become contested through electronic warfare. Electronic attack systems are being investigated by multiple nations with the intention of disrupting RF systems. Making systems resilient to electronic attacks is vital to national security. Fourth, enemy vessels can track ships emitting RF through electronic surveillance systems. FSO systems operate in line of sight and emit primarily in a single direction, reducing the ability of enemy ships to track through surveillance systems.

However, despite these advantages, FSO systems suffer from the limitation of line of sight communication. Over the horizon communication is sometimes necessary for certain fleet configurations. Space-based FSO relays are available; however, they suffer from other issues. They face interference from weather phenomena like clouds. Communication systems in military applications must be resilient to weather. Space-based communication faces additional difficulty as orbits might not always line up well, increasing project costs significantly as more satellites are required for relays. 

Therefore, UAVs offer the ability to relay optical communication in areas where space-based relays are unavailable. They can be weather resilient and integrate well into the existing Navy infrastructure. The Navy has extensive air operation infrastructure in its aircraft carrier fleets, and most fleets have the capability to launch small fixed-wing aircraft. The US Airforce and US Navy both operate extensive UAV fleets that can be easily transitioned to data relays without significant interruption to their primary missions. 
This project will contribute directly to the defense of US interests through the US Navy by facilitating data sharing. It can be extended to the general DoD interest in data sharing between branches as terrestrial UAV relays can relay information in ocean, littoral, and land arenas. Although the primary application is military, this information could be used in commercial aviation. The ability to create FANETs with commercial aircraft could facilitate better data transmission to passenger planes, allowing passengers to browse the internet more easily. It would also be useful in disaster response, where FANETs could be used to create communication networks in areas where traditional communication systems have broken down.

In general, the research in FANETs has focused on the theoretical aspects such as routing between varying links and determining the fastest route through a FANET for a data packet. They have not focused on the practical issues of targeting FSO systems at moving targets in ad hoc networks.

The deliverable is a UAV-mountable system that can transit between two moving drones by automatically adjusting the direction of transmission. It will adjust for rapid changes in velocity. This design will be tested in the lab. Since the laser is within the safety limit for naked-eye viewing, additional testing will be carried out in non-ideal environments, including foggy conditions.

This project will consist of a free-space optical system and drones. The drones are already available in the lab. Open-source hardware solutions exist for free-space optical systems, including Twibright Lab’s Ronja solution and IRNAS’s KORUZA system. Ronja is significantly cheaper and has a longer range, but has a much lower transmission rate at approximately 10Mbps. KORUZA is more expensive and has a shorter range, but can achieve a bitrate of approximately 10Gbps. Ronja has a unit cost of $100 with two units totaling $200. KORUZA is approximately $200 per unit; however, this cost includes PCB builds that must be ordered in bulk. So the total cost is only $300 for two units. KORUZA, though, requires two Raspberry Pi Microcomputers (RPi). The RPis cost $80 per unit, bringing the total cost of the system to $460. This leaves a smaller margin of error for costs in the KORUZA system. However, the use of laboratory equipment could reduce this cost. For example, fasteners are likely available and many of the pieces can be 3D printed using LMU’s existing printers. Because it falls within the price range, the KORUZA system is preferred for its higher bitrate.

The timeline and division of responsibilities can be seen in Figure 2, with work split roughly in half between the transmit and receive sides between the two researchers.
