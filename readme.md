<h1> Colors! </h1>

This project was created to make the terminal output more pleasant to read, but also to have fun!

<h2>Functions</h2>

There are several functions to call:

<h3>ToColor():</h3>

This function will print a string with a color gradient.

You can add as many colors as you like, as long as their number is greater than or equal to the number of characters.

The parameters are:

- `std::string msg`: The message to display.
- `Mode mode` (optional): To set the colors on the foreground or background. Without this parameter, it will change the foreground color.
- `int count` The amount of colors to be calculated.
- `...` The colors (ex: `Colors::Red`).

Examples:

	std::cout << ToColor("Hello world!", 2, Colors::MistyRose, Colors::Red) << std::endl;
<img src=https://github.com/Keftark/saves/blob/main/Colors/ToColor1.png width=98>

or

	std::cout << ToColor("Hello world!", 2, (Color){255, 228, 225}, (Color){255, 0, 0}) << std::endl;
<img src=https://github.com/Keftark/saves/blob/main/Colors/ToColor2.png width=96>

to add custom colors.



<h3>Rainbow()</h3>

This function will print a string with all the rainbow colors!

Obviously, the number of characters must be equal to or greater than the number of main rainbow colors, or the result won't live up to your expectations.

The parameters are:

- `std::string str`: The message to display.
- `Mode mode` (optional): To set the colors on the foreground or background. Without this parameter, it will change the foreground color.

Examples:

	std::cout << Rainbow("This is a short text.") << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowShort.png width=167>,

	std::cout << Rainbow("This is a longer text. It has to be LONGER! Yes, that's better...") << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowLong.png width=519>

or

	std::cout << Rainbow(
	"                                                                                        "
	, background) << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowBackground.png width=741>

<h3>RGB()</h3>

This function is a shortcut to add a custom color to a text.

The parameters are:

- `int R, int G, int B`: The r, g, b values from 0 to 255.
- `Mode mode` (optional): To set the color on the foreground or background. Without this parameter, it will change the foreground color.

Examples:

	std::cout << RGB(165, 255, 0, background) << "Hello World!" << RESET << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGBBackground.png width=96>

or

	std::cout << RGB(165, 255, 0) << "Hello World!" << RESET << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGBForeground.png width=94>


<h2>Defines</h2>

There are multiple `#define` in the `Colors.hpp` file for common and custom colors.

Feel free to check them and add what you want!
