# terminal-art
generate pixel art inside the terminal

## Concept:
This is a program that will print pixel art images to the terminal. It uses .ppm files to store the image and prints it to the terminal. 

## Running:
Your terminal emulator **MUST** have Truecolor support to run this program. 

You can use the Makefile's commands to run the program. 

  - `make default` will compile and run the command with the default image.

I've installed the [Termite](https://github.com/thestinger/termite) terminal emulator locally and can run the program. This should work with any terminal emulator with Truecolor support. 

I have not tested it besides with Termite and urxvt, of which only Termite worked. 

## Truecolor:

This program takes input from .ppm files, a format which stores each pixel as individual R, G, and B values in a text file. You can read more on the format [here](http://netpbm.sourceforge.net/doc/ppm.html).

This program uses ANSI encoded color values over a Unicode character, the [full block](https://www.fileformat.info/info/unicode/char/2588/index.html)█. The 24-bit or Truecolor format for these ANSI escape codes are not available for all terminals. From a quick glance at the list, it should be supported by Windows and macOS's default terminals. If you're rolling your own distro, I'd consider downloading one of the other provided terminals from the link below in order to make this work. 

Here's a command that should test your terminal for its support of Truecolor encoding:
> printf "\x1b[38;2;255;100;0mTRUECOLOR\x1b[0m\n"

[You can read more about Truecolor support and your terminal emulator here.](https://gist.github.com/XVilka/8346728#now-supporting-truecolor)

## Making Images:

A word of caution: this program is not for larger images. I've tried up to 32x32 and that took up most of my screen. I know for a fact that this doesn't work for images of size 512x512, because that has caused a segmentation fault.

I'm using a program called ImageMagick on a *nix machine to produce these images. Here's a template command:

> convert <input_image_name>.<input_image_file_extension> -resize <size1>x<size2> -compress none <output_image_name>.ppm

Replace <input_image_name> and <output_image_name> with those of your choice. And <input_image_file_extension> with the correct extension. Here's an example of what I mean.

> convert minecraft_grass.jpg -resize 16x16 -compress none minecraft_grass.ppm 

This converts the JPG to a 16x16 PPM P3 file. The -compress none ensures that the file is in the correct PPM P3 format. Without that, it converts to a PPM P6 format which is not readable by my program. 