# TECHIN-511-AFabrication

Title: Light-up Painting

Overview: The Light-up painting comprises a custom easel made from reclaimed red wine barrel staves and Fir framing boards taken from a house in West Seattle, a picture frame made from stained plywood, and art hand painted over a rastered acrylic sheet. The frame includes built in electronics and LEDs that light the painting from behind, accentuating its features. The easel’s base includes a 3D printed port which connects to an inverse port housed in the base of the frame. A successful connection between the two ports brings the painting to colorful life.

Overall design structure:
You can find the design scructure schematic picture named circuit.png

The design is about two part: 
1. First part is controlled by a Feather 328p. 
2. The second part is built by three circuit playground express, and the board in second part is controlled seperatelly.
3. The software design and method in the three circuit playground express board and feather 328p board is similar. We setup the input and output pin at the beginning once circuit runs. Then, the microcontroller is in a loop forever. At the beginning of the loop, we reset all signals in input into high. Then, we read the input if the signal is low. If it is high, it means our painting did not connect to the holder, so we setup our microcontroller to first mode. If it is low, it means our microcontroller is able to read the ground from the other part, so the painting is connected to the holder. We set up our microcontroller into mode B.


Feather 328p:
The base part is about the feather 328p. This part is compiled by arduino. You could upload the code by arduino. Also, you can find the code bellow.


Circuit playground express:
The canvas part is drived by three circuit playground express boards. You can find the specific boad with the file name. The programming language is about javascript. You can simply put the file into the board，or you can find the code bellow.
Also, you can open the file with makecode and revise it.






