class Input {
public:
    virtual void test() = 0; // pure virtual function
};

class Button : Input {
public:
    void test() {

    }
};

class DrumPad : Input {
public:
    void test() {

    }
};