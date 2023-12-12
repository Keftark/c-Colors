<h1> Colors! </h1>

This project was created to make the terminal output more pleasant to read, but also to have fun!

<h2>Functions</h2>

There are several functions to call:

<h3>ToColor():</h3>

This function will print a string with a color gradient.

You can add as many colors as you like, as long as their number is greater than or equal to the number of characters.

The parameters are:

- `std::string msg`: The message to display.
- `Mode mode` (optional): To set the colors on the `foreground` or `background`. Without this parameter, it will change the foreground color.
- `int count` The amount of colors to be calculated.
- `...` The colors (ex: `Colors::Red`).

Examples:

	std::cout << std::endl << ToColor("Lorem ipsum dolor sit amet, consectetur adipiscing elit...", 4, Colors::Cyan, Colors::DeepPink, Colors::Green, Colors::Cyan) << std::endl;
<img src=https://github.com/Keftark/saves/blob/main/Colors/ToColor0.png width=463>

or

	std::cout << ToColor("Hello world!", 2, (Color){50, 255, 255}, (Color){255, 0, 93}) << std::endl;
<img src=https://github.com/Keftark/saves/blob/main/Colors/ToColor2.png width=96>

to add custom colors.

If you want to add a simple gradient between 2 colors, you can also call the `ToColor()` function with :

- `std::string msg`: The message to display.
- `Mode mode` (optional): To set the colors on the `foreground` or `background`. Without this parameter, it will change the foreground color.
- `Color start`: The starting color.
- `Color end`: The final color.

	std::cout << ToColor("Hello world!", Colors::MistyRose, Colors::Red) << std::endl;
<img src=https://github.com/Keftark/saves/blob/main/Colors/ToColor1.png width=98>

<h3>Rainbow():</h3>

This function will print a string with all the rainbow colors!

Obviously, the number of characters must be equal to or greater than the number of main rainbow colors, or the result won't live up to your expectations.

The parameters are:

- `std::string str`: The message to display.
- `Mode mode` (optional): To set the colors on the `foreground` or `background`. Without this parameter, it will change the foreground color.

Examples:

	std::cout << Rainbow("This is a short text.") << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowShort.png width=167>,

	std::cout << Rainbow("This is a longer text. It has to be LONGER! Yes, that's better...", foreground) << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowLong.png width=519>

or

	std::cout << Rainbow(
	"                                                                                        "
	, background) << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowBackground.png width=741>

<h3>RGB():</h3>

This function allows you to add a custom color to a text with a simple command.

The parameters are:

- `int r, g, b`: The r, g, b values from 0 to 255.
- `Mode mode` (optional): To set the color on the `foreground` or `background`. Without this parameter, it will only change the foreground color.

Examples:

	std::cout << RGB(165, 255, 0, background) << "Hello World!" << RESET << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGBBackground.png width=96>

or

	std::cout << RGB(165, 255, 0) << "Hello World!" << RESET << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGBForeground.png width=94>

<h3>RGB2():</h3>

This function allows you to add custom colors to the foreground and the background with a simple command.

The parameters are:

- `int fg_r, fg_g, fg_b`: The r, g, b values from 0 to 255 to apply to the foreground.
- `int bg_r, bg_g, bg_b`: The r, g, b values from 0 to 255 to apply to the background.

or

- `Color fg_color`: The foreground/font color. (`Colors::Red` or `(Color){255, 0, 0}`).
- `Color bg_color`: The background color. (`Colors::Blue` or `(Color){0, 0, 255}`).

Examples:

	std::cout << RGB2(255, 0, 0, 255, 255, 0) << "Hello World!" << RESET << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGB2_1.png width=96>

or

	std::cout << RGB2(Colors::Cyan, Colors::DarkMagenta) << "Hello World!" << RESET << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RGB2_2.png width=96>

<h2>Defines</h2>

There are multiple `#define` in the `Colors.hpp` file for common and custom colors.

Feel free to check them and add what you want!
