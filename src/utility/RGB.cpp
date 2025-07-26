#include "RGB.h"

/* COLOUR CONSTANTS */
RGB RGB::BLACK { 0, 0, 0 };
RGB RGB::WHITE { 127, 127, 127 };
RGB RGB::RED { 127, 0, 0 };
RGB RGB::GREEN { 0, 127, 0 };
RGB RGB::BLUE { 0, 0, 127 };

/* CLASS-SPECIFIC CONSTANTS */
int RGB::MIN_VALUE { 0 };
int RGB::MAX_VALUE { 127 };

RGB RGB::operator*(float value) const {
    if (value < 0) value = 0.0f;
    else if (value > 1) value = 1.0f;

    int newRed = getRed() * value;
    int newGreen = getGreen() * value;
    int newBlue = getBlue() * value;

    RGB newColour { newRed, newGreen, newBlue };
    return newColour;
};

RGB RGB::operator*(int value) const {
    if (value < RGB::MIN_VALUE) value = RGB::MIN_VALUE;
    else if (value > RGB::MAX_VALUE) value = RGB::MAX_VALUE;

    float percentage = (float)value / RGB::MAX_VALUE;

    int newRed = getRed() * percentage;
    int newGreen = getGreen() * percentage;
    int newBlue = getBlue() * percentage;

    RGB newColour { newRed, newGreen, newBlue };
    return newColour;
};

/* CONSTRUCTORS */
// RGB colour Constructor using float Percentage values between 0 and 1 (inclusive)
RGB::RGB(float redPercent, float greenPercent, float bluePercent) {
    // Lambda expression used to normalize the colourPercent to be between 0 and 1 (inclusive)
    auto normalizePercentage = [](float colourPercent) {
        if (colourPercent < 0) return 0.0f;
        else if (colourPercent > 1) return 1.0f;
        else return colourPercent;
    };

    // Normalize the colours
    redPercent = normalizePercentage(redPercent);
    greenPercent = normalizePercentage(greenPercent);
    bluePercent = normalizePercentage(bluePercent);

    // Set the colours
    _red = RGB::MAX_VALUE * redPercent;
    _green = RGB::MAX_VALUE * greenPercent;
    _blue = RGB::MAX_VALUE * bluePercent;
};

// RGB colour Constructor using int values between 0 and 127 (inclusive)
RGB::RGB(int red, int green, int blue) {
    // Normalize and set the colours
    _red = normalizeColourValue(red);
    _green = normalizeColourValue(green);
    _blue = normalizeColourValue(blue);
};

/* MEMBER FUNCTIONS */
int RGB::normalizeColourValue(int colourValue) {
    if (colourValue < RGB::MIN_VALUE) return RGB::MIN_VALUE;
    else if (colourValue > RGB::MAX_VALUE) return RGB::MAX_VALUE;
    else return colourValue;
};