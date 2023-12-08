/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:54:25 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/08 18:05:05 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"

/* Colors to call with `Colors::Red` for example */
Color Colors::Blue = {0, 0, 255};
Color Colors::Cyan = {0, 255, 255};
Color Colors::Red = {255, 0, 0};
Color Colors::Green = {0, 255, 0};
Color Colors::Black = {255, 255, 255};
Color Colors::White = {0, 0, 0};
Color Colors::Brown = {60, 28, 0};
Color Colors::DarkBrown = {43, 0, 0};
Color Colors::Orange = {255, 145, 0};
Color Colors::RoyalBlue = {65, 105, 225};
Color Colors::NightBlue = {25, 25, 112};
Color Colors::DarkMagenta = {139, 0, 139};
Color Colors::Magenta = {255, 0, 255};
Color Colors::Yellow = {255, 255, 0};
Color Colors::MistyRose = {255, 228, 225};
Color Colors::Pink = {255, 192, 203};
Color Colors::DeepPink = {255, 20, 147};


std::string	Error_Msg(std::string msg)
{
	std::cout << std::endl << RED << "Error:" << RESET << std::endl <<
		std::setw(8) << "" << LIGHTRED << msg << RESET << std::endl;
	return (NULL);
}

/* Returns the complete color code with the given parameters. 
	@param r(red) 0 - 255.
	@param g(green) 0 - 255.
	@param b(blue) 0 - 255.
	@param mode (optional) To change the foreground(character) or the background color.
*/
std::string RGB(int r, int g, int b, Mode mode)
{
	return ("\033["  + std::to_string(mode) + ";2;" + std::to_string(r) + ";"
		+ std::to_string(g) + ";" + std::to_string(b) + "m");
}

/* Returns the R, G, B values of the character according to its place in the string. 
	@param index The index of the processed character.
	@param length The max length of the string.
*/
static Color GetRainbowColor(size_t index, size_t length)
{
	Color	color;
	double	mult = length / 6.0;
	double	result = fmod(index, mult) * 255 / mult;

	if (result > 254)
		result = 0;
	switch ((size_t)(index / mult))
	{
		case (0): // red to yellow
			color.r = 255;
			color.g = result;
			color.b = 0;
		break;
		case (1): // to green
			color.r = 255 - result;
			color.g = 255;
			color.b = 0;
		break;
		case (2): // to cyan
			color.r = 0;
			color.g = 255;
			color.b = result;
		break;
		case (3): // to blue
			color.r = 0;
			color.g = 255 - result;
			color.b = 255;
		break;
		case (4): // to violet
			color.r = result;
			color.g = 0;
			color.b = 255;
		break;
		case (5): // to red
			color.r = 255;
			color.g = 0;
			color.b = 255 - result;
		break;
		default: // if there is a problem with the values
			color.r = 255;
			color.g = 255;
			color.b = 255;
		break;
	}
	return (color);
}

/* Returns a string with beautiful rainbow colors! 
	@param str The string to be printed.
	@param mode (optional) To change the font color or the background
*/
std::string Rainbow(std::string str, Mode mode)
{
	Color       color;
	std::string result;
	size_t		length = str.length() % 255;

	for (size_t i = 0; i < length; i++)
	{
		color = GetRainbowColor(i, length);
		result.append("\033[" + std::to_string(mode) + ";2;"
			+ std::to_string(color.r) + ";"
			+ std::to_string(color.g) + ";" + std::to_string(color.b)
			+ "m" + str[i] + "\033[0m");
	}
	return (result);
}

/* Returns a string with a color gradient between `start` and `end`.
	@param str The string to be printed.
	@param start The starting color.
	@param end The ending color.
*/
std::string		ToColor(std::string str, int count, ...)
{
	va_list		va;
	Color		color, fromColor, toColor;
	std::string result;
	size_t		length = str.length();
	double		div = length / (count - 1);
	double		r_off, g_off, b_off;
	int			i = 0;

	if (count <= 1)
	{
		Error_Msg("You must put at least 2 colors!");
		return (NULL);
	}
	if (length < count)
	{
		Error_Msg("You must put less colors than the total character count!");
		return (NULL);
	}
	va_start(va, count);
	fromColor = va_arg(va, Color);
	while (i < length)
	{
		toColor = va_arg(va, Color);
		if (toColor.r > 255 || toColor.g > 255 || toColor.b > 255)
			toColor = fromColor;
		r_off = (toColor.r - fromColor.r) / (double)div;
		g_off = (toColor.g - fromColor.g) / (double)div;
		b_off = (toColor.b - fromColor.b) / (double)div;
		for (size_t j = 0; j < div; j++)
		{
			color.r = fromColor.r + r_off * (j + 1);
			color.g = fromColor.g + g_off * (j + 1);
			color.b = fromColor.b + b_off * (j + 1);
			result.append("\033[38;2;" + std::to_string(color.r) + ";"
			+ std::to_string(color.g) + ";" + std::to_string(color.b)
			+ "m" + str[i] + "\033[0m");
			i++;
		}
		fromColor = toColor;
	}
	va_end(va);
	return (result);
}
