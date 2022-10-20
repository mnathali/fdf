# Fdf

## Description

Fdf is the first graphical project. The program paints pixel by pixel image of 3D map by x,y,z coordinates.

Example:

![alt text](https://github.com/mnathali/fdf/blob/main/Fdf_maps.jpg)

## Compilling and launch

The project uses [minilibx](https://harm-smits.github.io/42docs/libs/minilibx.html) library that has functions to opening a window and pushing images to it and so forth.

Makefile will compile the project but it is needed to have compiled minilibx beside fdf. Makefile's rules may be changed to compile the project depending on your system and where minilibx library is.

## Implementation

At the beginning we consider 2D map and then convert it to 3D by adding conversions of coordinates using trigonometric functions or more precisely 0.866 coeff (sin(pi/3) == cos(pi/6)). Next we draw lines from one point to another so the image is set of lines. Also the bonus part can zoom 3D image using wheel of mouse and make transverse movements using arrows on keyboard.
