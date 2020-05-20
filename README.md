# Yin-Yang
- The aim of this project is to use core C++ to create images.
- In this project, a Yin and yang image is generated using simple mathematical calculations.
- The result is, a .pgm image showing the black and white image on a gray background.
- This project shows how simple maths combined with any coding language can generate visually appealing images.
- Technical details:
	- The image is generated in 3 layers.
	- The first layer generates a large circle of diameter 512. This circle has white pixels on left half of x-axis and black pixels on right half of x-axis.
	- The second layer generates 2 circles of diameter 256. One circle (white in color) lies on top half of layer 1 and the other one (black in color) lies on bottom
	half of layer 1.
	- The third layer generates 2 circles of diameter 64. One circle (black in color) lies on top of first circle generated layer 2 and the other one (white in color) lies
	on top of second circle generated layer 2.
- Technologies used:
	- Language: C++
	- IDE: Code::Blocks
	- Graphic Viewer: IrfanView
