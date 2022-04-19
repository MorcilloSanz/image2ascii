# image2ascii :space_invader:

Convert an image to ASCII and save it into a file, assigning a symbol to each pixel.

Let **f** be a function which assigns the position of a symbol of a set of symbols to each color (grey scale)

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/f2.png)
![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/f.png)

Where the set X is the color set (red set in the image) 

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/X.png)

And the Y set is the positions set (blue set in the image)

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/Y.png)

The assignment is given by the function **f**

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/fun.png)

## Compilation and usage
Use **C++11** at least for compiling purposes
```
sh compile.sh
./image2ascii image.png
```
It will save it in a file **output.txt**

# Example

<table style="padding:10px">
  <tr>
    <td><img src="./img/saturno.png" width = 440px height = 355px></td>
    <td><img src="./img/saturnoIDE.png" width = 440px height = 355px></td>
  </tr>
  <tr>
    <td><img src="./img/anonymous.png" width = 440px height = 355px></td>
    <td><img src="./img/anonymousIDE.png" width = 440px height = 355px></td>
  </tr>
</table>