# S_BAND-For-Child-Safety
The objective of this project is to enhance child safety and provide peace of mind to mothers by developing a wrist band composed of two bands(S_BAND). These bands will be designed to address  concerns related to child safety in various environments.

**Aim of S_BAND:**

Our project aims to provide mothers with a reliable and user-friendly solution for child safety in potentially Hazardous areas( i.e edges of buildings, heavy traffic areas, shopping malls, etc..,), ultimately reducing the risks associated with child super vision in such environments.
 
 Now a days this problem changing very difficult challenge to all parents, so we have decided to find a perfect solution to this problem in a manner of intelligent with low cost.

**Implementation Requirements:**

Two nRF24L0 modules, LED’S, Buzzer, 3 Jumper wires, 2 Arduino Uno boards also we can use Riscduino board.

**nRF24L0 module:**

![image](https://github.com/CHANDRA-SEKHAR-APPIKONDA/S_BAND-For-Child-Safety/assets/145449508/3f9d22f8-a884-45a3-8951-a9f3e2f1d7f7)

**Arduino Uno:**

![image](https://github.com/CHANDRA-SEKHAR-APPIKONDA/S_BAND-For-Child-Safety/assets/145449508/e725d263-c363-46c7-a740-7747a45f29e1)

•	By using SPI(Serial Peripheral Interface) Protocol we are established communication between two nRF modules.

•	When child is within the range (Safe / Alert zone) then LED blinks with respect to the data packets it receiving (Mother band).

•	At the same time mother able to see in which zone her child is in serial monitor. (Safe zone, Alert zone, Danger zone).

•	When child crossed the alert zone it means when child entering into danger zone (Like Accidents in heavy traffic, Hazardous areas).

•	Then immediately NRF get disconnected in two bands.

•	When the module disconnected, then buzzer present in mother band  get  chime and LED glows constantly.

•	Then mother will able to save her child when child moving away from mother.

•	In this way we provided to enhance child safety and peace of mind to mothers. 

•	In earlier days we have seen so many child deaths(both mentally disabled and abled child and physically handicap child) due to unexpected situations this will change to more pandemic to all employed mothers .

**Block Diagram:**

![image](https://github.com/CHANDRA-SEKHAR-APPIKONDA/S_BAND-For-Child-Safety/assets/145449508/29091089-f08c-49fa-89eb-9887314aa731)


**Rough sketch:**

![image](https://github.com/CHANDRA-SEKHAR-APPIKONDA/S_BAND-For-Child-Safety/assets/145449508/fd7b8db7-7c7d-43d4-81f1-c8b6e13035b3)

**Implementation Results:**

we have implemented this project like for every one second transmitters sends the data packet  of child to the receiver nothing but motherd band.

  ![image](https://github.com/CHANDRA-SEKHAR-APPIKONDA/S_BAND-For-Child-Safety/assets/145449508/c237c966-1e79-4de9-ba11-567a23eb7fc7)

  ![image](https://github.com/CHANDRA-SEKHAR-APPIKONDA/S_BAND-For-Child-Safety/assets/145449508/bab82d12-ff97-4c3c-a863-9ae7abcaa38f)

**Note:**

-->we have Succesfully completed this project by using Arduino uno with error free, in implementation results we are provided only few values of snapshots.

--> we are tried to implement this project on Riscduino board firmware, we compiled successfully but this firmware not able to read the few included libraries(i.e SPI, RS24, Tone[Buzzer]) due to this we got few errors in the log file.

**Future scope:**

-->This project may increase the market scalability for.

-->until now we are completed for alert signal to mother but we can extend this project by using GPS module for tracking location.

-->Further we Enhance this project including few highly featured modules in this way also this product may get more profit for Mechants.


