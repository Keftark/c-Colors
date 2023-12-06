/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:54:25 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/06 17:37:19 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"

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

/* Returns the complete color code with the given parameters. 
	@param r(red) 0 - 255.
	@param g(green) 0 - 255.
	@param b(blue) 0 - 255.
	@param mode (optional) to change the font color, the background...
*/
std::string RGB(int r, int g, int b, Mode mode)
{
	return ("\033["  + std::to_string(mode) + ";2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m");
}

/* Returns the R, G, B values of the character according to its place in the string. 
	@param index the index of the processed character.
	@param length the max length of the string.
*/
static Color GetRainbowColor(int index, int length)
{
	Color	color;
	double	mult = length / 6.0;
	double	mult2 = 255 / mult;
	double 	mod = fmod(index, mult);
	double	result = mod * mult2;

	if (result > 254)
		result = 0;
	switch ((int)(index / mult))
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
	std::string rainbow;
	std::string result;
	int			length = str.length() % 255;

	for (size_t i = 0; i < length; i++)
	{
		color = GetRainbowColor(i, length);
		result.append("\033[" + std::to_string(mode) + ";2;" + std::to_string(color.r) + ";"
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
std::string		ToColor(std::string str, Color start, Color end)
{
	Color       color = start;
	std::string rainbow;
	std::string result;
	int			length = str.length();
	double r_off, g_off, b_off;
	double r_col = 0, g_col = 0, b_col = 0;

	r_off = (end.r - start.r) / (double)length;
	g_off = (end.g - start.g) / (double)length;
	b_off = (end.b - start.b) / (double)length;
	for (size_t i = 0; i < length; i++)
	{
		r_col += r_off;
		g_col += g_off;
		b_col += b_off;
		color.r = start.r + r_col;
		color.g = start.g + g_col;
		color.b = start.b + b_col;
		result.append("\033[38;2;" + std::to_string(color.r) + ";"
		+ std::to_string(color.g) + ";" + std::to_string(color.b)
		+ "m" + str[i] + "\033[0m");
	}
	return (result);
}
