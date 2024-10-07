# ACA-Project1-Part2
Project1 Part2

Suggested working steps:

5) Implement Data Forwarding (After all instructions are implemented, add forwarding for data hazards). Provide instructions for compiling and running each of your tests. 5 Points.
6) Implement Branch Speculation (After all instructions are implemented, implement speculate and squash (if needed.)) Provide instructions for compiling and running each of your tests. 5 Points.
Towards Midterm;
7) Implement GShare for the simulator. 5 Points.
**Description**
Implement a Gshare predictor for you in order pipeline processor.
You will implement a branch predictor that uses: 
1) 16-entry Branch History Table (BHT) that is initialized to all zeros with 4 bits of history. 
2) Xor, which takes the output of the BHT and the last 4 bits of your PC. 
3) This will index into a 16-entry pattern history table containing a 2-bit state machine. The initial state will be weakly NOT-TAKEN.
You will also implement a 16-entry branch target buffer organized as a fully associative cache with FIFO replacement. The branch target buffer tag is the PC of the branch instruction, and the data portion is the target address of the branch last time it was calculated. Entries are put into the BTB only when a branch is resolved and TAKEN. If you predict a branch to be taken but do not find an entry in the BTB, fetch (speculatively) from PC+1.
**Deliverable(s)**
1\. Link to your code on Github
2\. Instruction to run and compile the test for branches
