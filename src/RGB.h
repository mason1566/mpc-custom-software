#ifndef RGB_COLOUR
#define RGB_COLOUR

class RGB {
public:
// Constructors
    RGB(float redPercent, float greenPercent, float bluePercent);
    RGB(int red, int green, int blue); // max values of 127
    
// Public Member Functions
    // Setters
    void setRed(int red) { _red = normalizeColourValue(red); };
    void setGreen(int green) { _green = normalizeColourValue(green); };
    void setBlue(int blue) { _blue = normalizeColourValue(blue); };

    // Getters
    int getRed() const { return _red; };
    int getGreen() const { return _green; };
    int getBlue() const { return _blue; };

// Static Variables
    static int MAX_VALUE;
    static int MIN_VALUE;

    // COLOUR CONSTANTS
    static RGB BLACK;
    static RGB WHITE;
    static RGB RED;
    static RGB GREEN;
    static RGB BLUE;

protected:
    int _red, _green, _blue;

// Protected Member Functions
    static int normalizeColourValue(int colourValue);
};

#endif