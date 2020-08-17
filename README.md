# terminal-art
generate pixel art inside the terminal

## Concept:
This is a program that will print pixel art images to the terminal. By using ANSI escape sequences for colors and ASCII UTF-8 encoded characters, we can print out boxes to the terminal and color them to produce images.

## Next steps:
- [ ] Add more colors
- [ ] Input colors and image from another file
  - consider a PPM or CSV file as input
- [ ] Add the ability to save / export to a separate file. 
  - This wouldn't look good if it wasn't exported to a terminal, due to the ANSI escape colors. 

## Truecolor:

In order to make this work in the most optimal way (reading individual RGB values from a PPM file and exporting each pixel to the terminal), we need to have a terminal that has Truecolor support. The was ANSI escape codes are done are to support encoded values using lists of values delineated with semicolons. Certain terminal emulators (including the one I am currently using URxvt, or rxvt-unicode) do not natively support this ANSI encoding. 

Here's a command that should test your terminal for it's support of Truecolor encoding:
> printf "\x1b[38;2;255;100;0mTRUECOLOR\x1b[0m\n"

[You can read more about Truecolor support and your terminal emulator here.](https://gist.github.com/XVilka/8346728#now-supporting-truecolor)
