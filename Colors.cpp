/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:54:25 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/12 08:18:25 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"

/* Colors to call with `Colors::Red` for example */
Color Colors::Black = {255, 255, 255};
Color Colors::Blue = {0, 0, 255};
Color Colors::Brown = {60, 28, 0};
Color Colors::Cyan = {0, 255, 255};
Color Colors::DarkBrown = {43, 0, 0};
Color Colors::DarkMagenta = {139, 0, 139};
Color Colors::DeepPink = {255, 20, 147};
Color Colors::Green = {0, 255, 0};
Color Colors::Magenta = {255, 0, 255};
Color Colors::MistyRose = {255, 228, 225};
Color Colors::NightBlue = {25, 25, 112};
Color Colors::Orange = {255, 145, 0};
Color Colors::Pink = {255, 192, 203};
Color Colors::Red = {255, 0, 0};
Color Colors::RoyalBlue = {65, 105, 225};
Color Colors::Violet = {255, 0, 255};
Color Colors::White = {0, 0, 0};
Color Colors::Yellow = {255, 255, 0};


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

/* Returns the complete foreground and background color code with the given parameters. 
	@param r(foreground red) 0 - 255.
	@param g(foreground green) 0 - 255.
	@param b(foreground blue) 0 - 255.
	@param bg_r(background red) 0 - 255.
	@param bg_g(background green) 0 - 255.
	@param bg_b(background blue) 0 - 255.
*/
std::string RGB2(int r, int g, int b, int bg_r, int bg_g, int bg_b)
{
	return ("\033[38;2;" + std::to_string(r) + ";"
		+ std::to_string(g) + ";" + std::to_string(b) + ";48;2;"
		+ std::to_string(bg_r) + ";"
		+ std::to_string(bg_g) + ";" + std::to_string(bg_b) + "m");
}

std::string RGB2(Color fg_color, Color bg_color)
{
	return ("\033[38;2;" + std::to_string(fg_color.r) + ";"
		+ std::to_string(fg_color.g) + ";" + std::to_string(fg_color.b) + ";48;2;"
		+ std::to_string(bg_color.r) + ";"
		+ std::to_string(bg_color.g) + ";" + std::to_string(bg_color.b) + "m");
}

/* Returns a string with beautiful rainbow colors! 
	@param str The string to be printed.
	@param mode (optional) To change the foreground(character) or the background color.
*/
std::string Rainbow(std::string str, Mode mode)
{
	return (ToColor(str, mode, 7, Colors::Red, Colors::Yellow, Colors::Green, Colors::Cyan, Colors::Blue, Colors::Violet, Colors::Red));
}

/* Keeps the R, G, B values between 0 and 255. */
static int	SetMinMax(int value)
{
	if (value < 0)
		value = 0;
	else if (value > 255)
		value = 255;
		return (value);
}

/* Returns a string with color gradients between each color.
	@param str The string to be printed.
	@param mode To change the foreground(character) or the background color.
	@param count The amount of colors to be calculated.
	@param ... The colors (ex: `Colors::Red`).
*/
std::string		ToColor(std::string str, Mode mode, int count, ...)
{
	va_list		va;
	Color		color, fromColor, toColor;
	std::string result;
	size_t		length = str.length();
	double		div = (double)length / (count - 1);
	double		r_off, g_off, b_off;
	int			i = 0;

	if (count <= 1)
		return (Error_Msg("You must put at least 2 colors!"));
	if (length < count)
		return (Error_Msg("You must put less colors than the total character count!"));
	va_start(va, count);
	fromColor = va_arg(va, Color);
	while (i < length)
	{
		toColor = va_arg(va, Color);
		r_off = (toColor.r - fromColor.r) / div;
		g_off = (toColor.g - fromColor.g) / div;
		b_off = (toColor.b - fromColor.b) / div;
		for (size_t j = 0; j < div; j++)
		{
			if (i == length)
				break ;
			color.r = fromColor.r + r_off * (j + 1);
			color.g = fromColor.g + g_off * (j + 1);
			color.b = fromColor.b + b_off * (j + 1);
			result.append("\033[" + std::to_string(mode) + ";2;"
				+ std::to_string(SetMinMax(color.r)) + ";"
				+ std::to_string(SetMinMax(color.g)) + ";"
				+ std::to_string(SetMinMax(color.b)) + "m"
				+ str[i] + "\033[0m");
			i++;
		}
		fromColor = toColor;
	}
	va_end(va);
	return (result);
}

/* Returns a string with color gradients between each color.
	@param str The string to be printed.
	@param count The amount of colors to be calculated.
	@param ... The colors (ex: `Colors::Red`).
*/
std::string		ToColor(std::string str, int count, ...)
{
	va_list		va;
	Color		color, fromColor, toColor;
	std::string result;
	size_t		length = str.length();
	double		div = (double)length / (count - 1);
	double		r_off, g_off, b_off;
	int			i = 0;

	if (count <= 1)
		return (Error_Msg("You must put at least 2 colors!"));
	if (length < count)
		return (Error_Msg("You must put less colors than the total character count!"));
	va_start(va, count);
	fromColor = va_arg(va, Color);
	while (i < length)
	{
		toColor = va_arg(va, Color);
		r_off = (toColor.r - fromColor.r) / div;
		g_off = (toColor.g - fromColor.g) / div;
		b_off = (toColor.b - fromColor.b) / div;
		for (size_t j = 0; j < div; j++)
		{
			color.r = fromColor.r + r_off * (j + 1);
			color.g = fromColor.g + g_off * (j + 1);
			color.b = fromColor.b + b_off * (j + 1);
			result.append("\033[38;2;"
				+ std::to_string(SetMinMax(color.r)) + ";"
				+ std::to_string(SetMinMax(color.g)) + ";"
				+ std::to_string(SetMinMax(color.b)) + "m"
				+ str[i] + "\033[0m");
			i++;
		}
		fromColor = toColor;
	}
	va_end(va);
	return (result);
}

/* Returns a string with color gradients between both colors.
	@param str The string to be printed.
	@param start The starting color.
	@param end The final color.
*/
std::string		ToColor(std::string str, Color start, Color end)
{
	return (ToColor(str, 2, start, end));
}

/* Returns a string with color gradients between both colors.
	@param str The string to be printed.
	@param mode To change the foreground(character) or the background color.
	@param start The starting color.
	@param end The final color.
*/
std::string		ToColor(std::string str, Mode mode, Color start, Color end)
{
	return (ToColor(str, mode, 2, start, end));
}