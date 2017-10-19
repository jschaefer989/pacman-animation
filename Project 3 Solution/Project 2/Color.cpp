#include "Color.h"

#include <GL/glut.h>
#include <cstdio>
#include <cmath>

#define GAMMA	(2.2f/2.2f)

Color::Color(float red, float green, float blue,
	float alpha)
{
	// Copy the color channels
	vals[0] = red;
	vals[1] = green;
	vals[2] = blue;
	vals[3] = alpha;

	// Apply gamma correction (will look dim without this)
	gammaEncode();
}

Color::Color(unsigned int RGBHex, float alpha)
{
	// Copy the alpha value
	vals[3] = alpha;

	// Separate out the red, green, and blue from the hex value
	vals[2] = (unsigned char)(RGBHex & 0x0000FF);
	vals[1] = (unsigned char)((RGBHex & 0x00FF00) >> 8);
	vals[0] = (unsigned char)((RGBHex & 0xFF0000) >> 16);

	// This is here to help with debugging should something be wrong with colors.
	// Note: If you uncomment this you will get extra output.
	//printf("#%6X --> [%u, %u, %u]\n", RGBHex, vals[0], vals[1], vals[2]);

	// Note: Web hex values usually do not need gamma correction
}

void Color::tellOpenGL() const
{
	// Set this color as the currently active OpenGL color
	glColor4ub((unsigned char)floor(vals[0] + 0.5),
		(unsigned char)floor(vals[1] + 0.5),
		(unsigned char)floor(vals[2] + 0.5),
		(unsigned char)floor(vals[3] + 0.5));
}

// Getters for the different components of this color
float Color::getRed() const { return vals[0]; }
float Color::getGreen() const { return vals[1]; }
float Color::getBlue() const { return vals[2]; }
float Color::getAlpha() const { return vals[3]; }

// Gamma correction: this brightens the color slightly so that
// it looks correct on the monitor.  Adjust GAMMA above to modify.
// (see https://en.wikipedia.org/wiki/Gamma_correction for details)
void Color::gammaEncode()
{
	float Rf = powf(vals[0] / 255.0f, GAMMA);
	float Gf = powf(vals[1] / 255.0f, GAMMA);
	float Bf = powf(vals[2] / 255.0f, GAMMA);

	vals[0] = (float)(Rf * 255);
	vals[1] = (float)(Gf * 255);
	vals[2] = (float)(Bf * 255);
}