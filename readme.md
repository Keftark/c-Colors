# Colors!

This project was created to make the terminal output more pleasant to read, but also to have fun while learning!

This project is designed to run on Linux and on c++98 version to meet the requirements of 42 school c++ subjects.

## Install:

Simply download the .hpp file and include it on your project.

# Functions

There are several functions to call:

## ToColor():

This function will print a colored string with the chosen color if there is a single color parameter.

There is a color reset at the end of the function.

The parameters are:

- `std::string msg`: The message to display.
- `Color color`: The color be applied to the string.

Example:
```C++
std::cout << ToColor("Hello world!", Colors::DeepPink()) << std::endl;
```

This function will also print a string with a color gradient if there are multiple color parameters.

You can add as many colors as you like, as long as their number is greater than or equal to the number of characters.

There is a color reset at the end of the function.

The parameters are:

- `std::string msg`: The message to display.
- `Mode mode` (optional): To apply the colors on the `foreground` or `background`. Without this parameter, it will change the foreground color.
- `int count` The amount of colors to be calculated.
- `...` The colors (ex: `Colors::Red()`).

Examples:
```C++
std::cout << ToColor("Lorem ipsum dolor sit amet, consectetur adipiscing elit...", 4, Colors::Cyan(), Colors::DeepPink(), Colors::Green(), Colors::Cyan()) << std::endl;
```
<img src=https://github.com/Keftark/saves/blob/main/Colors/ToColor0.png width=463>

or
```C++
std::cout << ToColor("Hello world!", 2, (Color){50, 255, 255}, (Color){255, 0, 93}) << std::endl;
```
<img src=https://github.com/Keftark/saves/blob/main/Colors/ToColor2.png width=96>

to add custom colors.

If you want to add a simple gradient between 2 colors, you can also call the `ToColor()` function with :

- `std::string msg`: The message to display.
- `Mode mode` (optional): To set the colors on the `foreground` or `background`. Without this parameter, it will change the foreground color.
- `Color start`: The starting color.
- `Color end`: The final color.

Example:

```C++
std::cout << ToColor("Hello world!", Colors::MistyRose(), Colors::Red()) << std::endl;
```
<img src=https://github.com/Keftark/saves/blob/main/Colors/ToColor1.png width=98>

## Rainbow():

This function will print a string with all the rainbow colors!

The number of characters must be equal to or greater than the number of main rainbow colors, or the result won't live up to your expectations.

The parameters are:

- `std::string str`: The message to display.
- `Mode mode` (optional): To set the colors on the `foreground` or `background`. Without this parameter, it will change the foreground color.

Examples:
```C++
std::cout << Rainbow("This is a short text.") << std::endl;
```

<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowShort.png width=167>,

```C++
std::cout << Rainbow("This is a longer text. It has to be LONGER! Yes, that's better...", foreground) << std::endl;
```
<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowLong.png width=519>

or
```C++
std::cout << Rainbow(
"                                                                                        "
, background) << std::endl;
```

<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowBackground.png width=741>

## RGB():

This function allows you to add a custom color to a text with a simple command.

The parameters are:

- `int r, g, b`: The r, g, b values from 0 to 255.
- `Mode mode` (optional): To set the color on the `foreground` or `background`. Without this parameter, it will only change the foreground color.

Examples:

```C++
std::cout << RGB(165, 255, 0, background) << "Hello World!" << RESET << std::endl;
```

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGBBackground.png width=96>

or
```C++
std::cout << RGB(Colors::Red()) << "Hello World!" << RESET << std::endl;
std::cout << RGB(165, 255, 0) << "Hello World!" << RESET << std::endl;
```

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGBForeground.png width=94>

## RGB2():

This function allows you to add custom colors to the foreground and the background with a simple command.

The parameters are:

- `int fg_r, fg_g, fg_b`: The r, g, b values from 0 to 255 to apply to the foreground.
- `int bg_r, bg_g, bg_b`: The r, g, b values from 0 to 255 to apply to the background.

or

- `Color fg_color`: The foreground/font color.
- `Color bg_color`: The background color.

Examples:
```C++
std::cout << RGB2(255, 0, 0, 255, 255, 0) << "Hello World!" << RESET << std::endl;
```

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGB2_1.png width=96>

or

```C++
std::cout << RGB2(Colors::Cyan(), Colors::DarkMagenta()) << "Hello World!" << RESET << std::endl;
```

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGB2_2.png width=96>

## ErrMsg():

This function will print an error message on the error fd.

The parameters are:

- `std::string msg`: The message to display.
- `bool foregroundOnly`: If true, prints the message in a vibrant red color. If false (by default), prints the message with a black background and a vibrent red color.

`foregroundOnly = false;`

<img src=https://github.com/Keftark/saves/blob/main/Colors/ErrorBG.png width=96>

`foregroundOnly = true;`

<img src=https://github.com/Keftark/saves/blob/main/Colors/Error.png width=96>

# Defines

There are multiple `#define` in the `Colors.hpp` file for common and custom colors.

Feel free to check them and add what you want!
