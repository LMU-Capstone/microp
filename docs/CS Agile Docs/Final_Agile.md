# Retrospective Summary
  Natalia and Ian used SCRUM in their Agile planning with weekly standups Tuesdays at 8am. The springs were roughly broken up into Design and Preparation, Hardware Construction, and Validation & Verification. Standups were performed with Dr. Asghari of the EECE Department.  
  
## Learnings/Retrospective
1. This semester taught me the importance of documenting everything. Because of the plethora of documents we created, it is easy to answer questions about my project and justify. Every single product selected has tables to  backup our purchase and we have dozens of pages of project objectives and requirements that allow us to easily benchmark success.
2. I do not like Agile SCRUM much. I use Kanban at work and it personally works better for me. At least for this project, sprints felt artificial and unnecessary. I think it would work really well for software, but as a project that had lots of hardware, it required weird 'splits' in our work that Natalia and I didn't like. I think a series of 'ToDo' items fits better and would eliminate this weird split in work.
3. Currently, between the two classes, our work is split between 4 different 'repos'. I work in the GitHub for CS assignments; Natalia and I submit to Microsoft Teams for EE; Natalia and I personally work on OneDrive; and, both classes use Brightspace for submission. Next semester, I will work to unify our work into one location.
4. Testing should have been a larger part of our plan. While we were able to finish our testing on time, it was difficult are required a long few days of near-constant testing. Also, by using a personal laptop for testing, we were limited to the abilities of one laptop, which created performance issues.
5. Natalia and I both with we spent more time on designing the system. While we spent quite a lot finalizing our design and working parts, we spent less time on learning the concepts behind our purchases. This made the learning curve quite difficult once parts arrived as we had to quickly learn how to interface with our hardware to immediately begin tests.
6. Order early! Purchases take a lot of time to arrive and this created bottlenecks in our process.

# Epics / Stories

My stories were lost when sprints were completed and I'm very confused on how to recover them. To that end, they are re-typed here

**Stories don't make as much sense with hardware honestly. A lot of time is spent preparing for construction that doesn't create unique user stories (there are no new UX from selecting parts). Also, a lot of time is spent 1) testing hardware and 2) actually connecting hardware. If you want to dock points, I understand but I honestly can't think of a way to make stories for things like 'we bought the right parts by checking lots and lots spreadsheets and making decision matrices for each based on performance parameters'.**

### Sprint 1: Design 

  Goal: To finalize a design for the free space optical system, including plans for incremental testing. This design requirements are discussed in the requirements documents.
  
  Story: DelphinO Delta (DoD) is a customer requiring secure, fast communication between two abitrary, moving points. The design must meet the project obectives outlines in the requirements documentation. These communications are to be used in hostile environments and must be resilient communcation with explainable design.
  
  Ian and Natalia need a system that can be used to communicate at 1Gbps in free-space to test a dynamic movement system.

### Sprint 2: Parts Selection

  Goal: To find parts meeting design requirements and price limitations. These decisions are shown in the decision matrices.
  
  Story: As a customer, Ian wants a system that can operate as designed within budget. He requires parts that meet specifications, without adding delays to the building timeline.
  
  As a researcher, Natalia wants a system that does not have unexpected issues with compatibility.

### Sprint 3: Hardware Construction/Interface

  Goal: Assemble parts and test individual components to confirm they operate as intended. Interfaces must be constructed on the software side
  
  Story: As a researcher, Ian wants to be able to send data easily using standard TCP or UDP connections to allow for easier connections with existing libraries. The software must connect as an internet port 'behind the scenes'
  
  As a researcher, Ian wants his hardware to function and work together properly.

### Sprint 4: Hardware Continued and V&V

  Goal: Finish construction of MVP and perform fiber and unidirectional free space V&V to test parts individually.
  
  Story: As a customer, Natalia wants to be sure that each piece is working as intended and that no piece is simply 'barely functioning' and simply passed minimal testing. Rigorous testing is required to ensure this.
  
  As a reasearcher, Ian wants the device to send data at 1Gbps over fiber cable.

# LOE per story (estimated)

Sprint 1 - Design : 30hr (done before start of Agile work so not included specifically)
Sprint 2 - Parts Selection: 30
Sprint 3 - Hardware Construction/Interface: 30
Sprint 4 - Hardware Continued and and V&V: 27

# Burndown Chart

Differences are from continuously postponing the website. We are using an interim wix website for project deliverables in the meantime.

![image](https://user-images.githubusercontent.com/40191185/142334855-e64a6584-80b5-4247-8d00-97b36abb2d72.png)

This timeline is made to match the Gannt chart from the beginning of the semester.
![image](https://user-images.githubusercontent.com/40191185/142336489-955ff14b-749e-448f-b142-80aa064e1cbf.png)



# Board (link)
https://lmu-ee-capstone.atlassian.net/jira/software/projects/MIC/boards/1
