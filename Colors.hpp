/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:31:30 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/09 17:03:52 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdarg.h>

// Custom colors
#define LIGHTRED		"\033[38;2;255;100;100m"
#define LIME			"\033[38;2;165;255;0m"
#define DARKTEAL		"\033[38;2;0;100;100m"
#define TEAL			"\033[38;2;0;180;180m"
#define LIGHTTEAL		"\033[38;2;0;215;215m"
#define ROSERED			"\033[38;2;255;0;93m"
#define GOLD			"\033[38;2;204;146;50m"
#define ORANGE			"\033[38;2;255;145;0m"
#define BROWN			"\033[38;2;60;28;0m"

// Text Styles
#define RESET			"\033[0m"
#define BOLD			"\033[1m"
#define DIM				"\033[2m"
#define ITALIC			"\033[3m"
#define UNDERLINE		"\033[4m"
#define BLINK_SLOW		"\033[5m"
#define BLINK_RAPID		"\033[6m"
#define REVERSE_VIDEO	"\033[7m"
#define CONCEALED		"\033[8m"
#define CROSSED_OUT		"\033[9m"

// Text Colors
#define BLACK			"\033[0;30m"
#define RED				"\033[0;31m"
#define GREEN			"\033[0;32m"
#define YELLOW			"\033[0;33m"
#define BLUE			"\033[0;34m"
#define MAGENTA			"\033[0;35m"
#define CYAN			"\033[0;36m"
#define WHITE			"\033[0;37m"

// Background Colors
#define BG_BLACK		"\033[40m"
#define BG_RED			"\033[41m"
#define BG_GREEN		"\033[42m"
#define BG_YELLOW		"\033[43m"
#define BG_BLUE			"\033[44m"
#define BG_MAGENTA		"\033[45m"
#define BG_CYAN			"\033[46m"
#define BG_WHITE		"\033[47m"

struct Color
{
	int r, g, b;
};

class Colors
{
	public:
		static Color Blue;
		static Color Violet;
		static Color Cyan;
		static Color Red;
		static Color Green;
		static Color White;
		static Color Black;
		static Color Orange;
		static Color Brown;
		static Color DarkBrown;
		static Color RoyalBlue;
		static Color NightBlue;
		static Color Magenta;
		static Color DarkMagenta;
		static Color Yellow;
		static Color MistyRose;
		static Color Pink;
		static Color DeepPink;
};

typedef enum color_mode
{
	foreground = 38,
	background = 48
}				Mode;

std::string		RGB(int r, int g, int b, Mode mode = foreground);
std::string		Rainbow(std::string str, Mode mode = foreground);
std::string		ToColor(std::string str, Mode mode, int count, ...);
std::string		ToColor(std::string str, int count, ...);

#endif