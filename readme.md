<h1> Colors! </h1>

This project was created to make the terminal output more pleasant to read, but also to have fun!

There are several functions to call:

<h3>ToColor():</h3>

This function will print a string with a color gradient.

The parameters are:

- `std::string msg`: The message to display.
- `Color start`: The starting color.
- `Color end`: The ending color.

Examples:

	std::cout << ToColor("Hello world!", Colors::MistyRose, Colors::Red) << std::endl;

or

	std::cout << ToColor("Hello world!", (Color){255, 228, 225}, (Color){255, 0, 0}) << std::endl;

to add custom colors.

![ToColor1](https://github.com/Keftark/saves/blob/main/Colors/ToColor1.png)

<img src=https://github.com/Keftark/saves/blob/main/Colors/ToColor2.png width=96>

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

	std::cout << Rainbow("This is a beautiful background rainbow!", background) << std::endl;

<img src=https://github.com/Keftark/saves/blob/main/Colors/RainbowBackground.png width=313>