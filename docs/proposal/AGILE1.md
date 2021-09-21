Marine Infrared Communication Relays
Ian Green && Natalia Cedeno

# Scope of this document:
Project Description, justification, and scope are found in 'MICROP Proposal.pdf'. This document will focus on the software components of this project. For simplicity, this document is copied at the end of this markdown file in its entirety.


# Software Technical Documentations
The tech stack is fairly simple on the systems side; however, implementation will be difficult. A hardware interface will be constructed and programmed. The specifics of the interface will be chosen during the research phase of this project.

On top of the hardware interface, two systems will be built. A control system will monitor the motors and point the transmitter and receiver at the desired unit. The second system will decode the received signal and encode transmitted signals.

Additional testing frameworks will be built using hardware in the loop testing. Packets must be sent and checked for errors to determine an error rate.

The KORUZA system is preferred due to its high bitrate; however, other open hardware systems like TwiBright's Ronja are considered. These systems will be selected based on EE department approval and further discussion with optics professor Dr. Asghari.

# Semester Deliverables:
The timeline is found in the Gannt Chart.xlsx and in Figure 1 of the 'MICROP Proposal.pdf'. At the end of this semester, the group will have demonstrated the ability to communicate through static free space optical systems.

Hardware construction will be completed mid-semester and transmit/receive programs will be completed. Dynamic movement and tracking software are to be introduced next semester as the continuation of this project.

# Appendix:
https://lmu-ee-capstone.atlassian.net/jira/software/projects/MIC/boards/1/roadmap

https://github.com/LMU-Capstone/microp


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

The timeline and division of responsibilities can be seen in Figure 1, with work split roughly in half between the transmit and receive sides between the two researchers.



Figure 1: Schedule of Work

![Screenshot from 2021-09-20 19-21-35](https://user-images.githubusercontent.com/40191185/134102124-98935948-cdea-476f-8c65-c09ea26ad542.png)
