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
    int padNumber; // MPC signals involving drumpad use idCode for incoming and padNumber for outgoing

    DrumPad(int id, int padNum) : Input(id), padNumber {padNum} {};
};

#endif