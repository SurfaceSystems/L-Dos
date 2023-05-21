// Lite NT v_9.0

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;
typedef string String;

/*
         Class: System_out
         Since: 1.0
         Example: System_out out;
         The class for output console
        */
class System_out {
    public: 
        /*
         Put text in the screen 
         Since: 1.0 updated 2.0
         Example: out.print();
         It prints the %text% variable with the %options%.
         Options:
         %s -> No new line
         %n -> New line at the end
         %d -> Delete text and no new line
         %p -> Delete text and new line at the end
        */
        void print(String text, String options) {
            if(options == "%s") {
                cout << text;
            } else if(options == "%n") {
                cout << text << "\n";
            } else if(options == "%d") {
                system("CLS");
                cout << text;
            } else if(options == "%p") {
                system("CLS");
                cout << text << "\n";
            } else {
            throw new exception;
        }
        }
};

enum IN {
  
    // 13 is ASCII for carriage
    // return
    IN_BACK = 8,
    IN_RET = 13
  
};

/*
         Class: System_in
         Since: 1.0
         Example: System_in in;
         The class for input console
        */
class System_in {
    private:
    string takePasswdFromUser(
    char sp = 250)
{
    // Stores the password
    string passwd = "";
    char ch_ipt;
  
    // Until condition is true
    while (true) {
  
        ch_ipt = getch();
  
        // if the ch_ipt
        if (ch_ipt == IN::IN_RET) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() != 0) {
            passwd.pop_back();
  
            // Cout statement is very
            // important as it will erase
            // previously printed character
            cout << "\b \b";
  
            continue;
        }
  
        // Without using this, program
        // will crash as \b can't be
        // print in beginning of line
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() == 0) {
            continue;
        }
  
        passwd.push_back(ch_ipt);
        cout << sp;
    }
}


    public:
        /*
         Ask for text 
         Since: 1.0 updated 2.0
         Example: String username = in.scani("%s");
         It make a user input with the %options% configuration
         options:
         %s -> New line at the begin
         %n -> No new line
        */
        String scani(String options) {
            String ret;
            if(options == "%s") {
                cout << "\n";
                getline(cin, ret);
            } else if(options == "%n") {
                getline(cin, ret);
            } else {
            throw new exception;
        }
            return ret;
        }
        /*
         Ask for password 
         Since: 1.0 updated 2.0
         Example: String password = in.scanipass("%s");
         It make a user input with the char 250 and its configurations.
         options:
         %s -> New line at the begin
         %n -> No new line
        */
        String scanipass(String options) {
            String ret;
            if(options == "%s") {
                cout << "\n";
                ret = takePasswdFromUser();
            } else if(options == "%n") {
                ret = takePasswdFromUser();
            } else {
            throw new exception;
        }
            return ret;
        } 
};

/*
         Class: Window
         Since: 1.0
         Example: Window window;
         The class for modifing console
        */
class Window {
    public:
        /*
         Go to the determinate position 
         Since: 1.0
         Example: window.goToXY(4,4);
         Put the cursor in the determinated position of the console
        */
        void goToXY(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
  
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
        /*
         Clear the screen 
         Since: 1.0
         Example: window.clear();
         It run the command "CLS" in the console
        */
        void clear() {
            system("cls");
        }
        /*
         Pause the screen 
         Since: 1.0
         Example: window.pause();
         Run the command "pause" in the console
        */
        void pause() {
            system("pause");
        }
        /*
         Change the background color of the console
         Since: 1.0
         Example: window.setBackgroundColorForeground('A', '2');
         Change the color of the console using "Color" console's command
        */
        void setBackgroundColorForeground(char background, char foreground) {
            system("Color " + background + foreground);
            getBackgroundColor = background;
            getForegroundColor = foreground;
        }
        /*
         Returns the value of the background color of the console
         Since: 1.0
         Example: char bg = window.getBackgroundColor;
         Return: char
        */
        char getBackgroundColor;
        /*
         Returns the value of the foreground color of the console
         Since: 1.0
         Example: char bg = window.getForegroundColor;
         Return: char
        */
        char getForegroundColor;
        /*
         Returns the value of the background color and foreground of the console
         Since: 1.0
         Example: char bg = window.getColor();
         Return: String
        */
        string getColor() {
            char colors = getBackgroundColor + getForegroundColor;
            return to_string(colors);
        }
        /*
         Waits the miliseconds that are set in the %time% parameter
         Since: 2.0
         Example: window.wait(1000);
        */
       void wait(long time) {
        Sleep(time);
       }
};

/*
         Class: File
         Since: 1.0
         Example: File file;
         The class for reading and writing files
        */
class File {
    public:
    /*
         Returns the text of the selected file
         Since: 1.0
         Example: String foo = file.readFile("foo.txt");
         Return: String
        */
        String readFile(String filename) {
            String ret, lret;
            fstream readFileC(filename);
            while (getline(readFileC, lret)) {
                ret.append(lret);
            }
            readFileC.close();
            return ret;          
        }
        /*
         Write text o the selected file
         Since: 1.0
         Example: file.writeFile("foo.txt", "Hello World!");
        */
       void writeFile(String filename, String text) {
            fstream w(filename);
            w >> text;
            w.close();
       }
       /*
         Check if the file is empty
         Since: 1.0
         Example: bool isEmpty = file.isEmpty("foo.txt");
         Return: Bool
        */
       bool isEmpty(String filename) {
        return readFile(filename).empty();
       } 
       /*
         Get the size of the file in the determinate way
         Since: 1.0 updated 2.0
         Example: float foo = file.size("foo.txt", file.BYTES);
         Return: float
        */
       float size(String filename,int op) {
        if(op == 0) {
            return readFile(filename).length();
        } else if(op == 1) {
            return readFile(filename).length() / 1000;
        } else if(op == 2) {
            return readFile(filename).length() / 100000000;
        } else if(op == 3) {
            return readFile(filename).length() / 100000000000;
        } else {
            throw new exception;
        }
       };
       int BYTES = 0;
    int MEGABYTES = 1;
    int GIGABYTES = 2;
    int TERABYTES = 3;
};

/*
         Class Measure
         Since: 2.0
         Example: Measure measure;
         The class to calculate data types
        */
class Measure {
    public:
    /*
         Return the ASCII caracter of the determinated int
         Since: 2.0
         Example: char c100 = measure.int__char(100);
         Return: char
        */
        char int__char(int character) {
            return (char) character;
        }/*
         Return the int of the determinated ASCII character
         Since: 2.0
         Example: int n100 = measure.char__int('d');
         Return: int
        */
        char char__int(char character) {
            return (int) character;
        }
        /*
         Return the millisecons of the determinated seconds;
         Since: 2.0
         Example: long 2segs = measure.toMilliseconds(2);
         Return: long
        */
        long toMillisecons(long seconds) {
            return seconds * 1000;
        }
							int calcString(String calc) {} 
};

/*
 Class: EventHandler
 Since: 2.0
 Example: EventHandler event;
 The class for event handling
 */
class EventHandler {
    public:
    int LEFT_KEY = 0;
    int RIGHT_KEY = 1;
 /*
         Is a array with the mouse x and y position
         Since: 2.0
         Example: int x = event.mouXY[0], y = event.mou[1];
         Return: int[2]
        */    
        int mouXY[2] = {0,0}; /*
         Update the variable mouXY
         Since: 2.0
         Example: event.updateMousePosition();
        */
        void updateMousePosition() {
            POINT p;
            GetCursorPos(&p);
            mouXY[0] = p.x;
            mouXY[1] = p.y;
        }
         /*
         Return if the determinated key of the mouse was pressed.
         Since: 2.0
         Example: bool leftMousePressed = event.isClicked(event.LEFT_KEY);
         Return: bool
         Options:
         event.LEFT_KEY -> The left key of the button
         event.RIGHT_KEY -> The right key of the button
        */
        boolean isClicked(int option) {
            if(option == 0 && GetAsyncKeyState(VK_LBUTTON) & 1) {
                return true;
            } else if(option == 2 && GetAsyncKeyState(VK_RBUTTON) & 1) {
                return false;
            } else {
                throw new exception;
                return false;
            }
            return false;
        } 
         /*
         Return the character that was pressed in the keyboard
         Since: 2.0
         Example: char keypressed = event.getKeyPressed();
         Return: char or int
        */
        char getKeyPressed() {
            if(kbhit()) {
                return getch();
            }
            return '@';
        }
         /*
         Return if any key was pressed
         Since: 2.0
         Example: bool ispressed = event.isKeyPressed();
         Return: bool
        */
        boolean isKeyPressed() {
            if(kbhit()) {
                return true;
            }
            return false;
        }
         /*
         Return true if the determinated key was pressed
         Since: 2.0
         Example: bool isDpressed = event.isDKeyPressed('d');
         Return: bool
        */boolean isDKeyPressed(char dkey) {
            if(kbhit()) {
                if(dkey == (char) getch()) {
                    return true;
                }
                return false;
            }
            return false;
        }
};