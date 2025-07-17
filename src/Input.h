#ifndef INPUT
#define INPUT

class Input {
public:
    int idCode;
    
    Input(int id) : idCode {id} {};
};

class Button : Input {
public:
    Button(int id) : Input(id) {};
};

class DrumPad : Input {
public:
    DrumPad(int id) : Input(id) {};
};

#endif