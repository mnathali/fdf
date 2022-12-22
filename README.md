# Fdf

## Description

Fdf is the first graphical project. The program paints pixel by pixel image of 3D map by x,y,z coordinates. A image is readed from file sended as parameter. Exampels of maps are presented in ```test_maps``` directory. So, execute like this ```./fdf test_maps/<some_example>```

Example:

![alt text](https://github.com/mnathali/fdf/blob/main/Fdf_maps.jpg)

## Compilling and launch

The project uses [minilibx](https://harm-smits.github.io/42docs/libs/minilibx.html) library that has functions to opening a window and pushing images to it and so forth.

So, before compiling the project you have to clone MLX library inside the project's directory and create it:

```git clone https://github.com/42Paris/minilibx-linux.git && ./mlx_linux/configure```

As MLX library is clonned use ```make``` command to compile executable with name ```fdf```. There is also ```make bonus``` rule to create executable that has additional functions like zooming of image using wheel of mouse and shifting of image using arrows on your keyboard.

## Implementation

At the beginning we consider 2D map and then convert it to 3D by adding conversions of coordinates using trigonometric functions or more precisely 0.866 coeff (sin(pi/3) == cos(pi/6)). Next we draw lines from one point to another. So the whole image is a set of lines.
