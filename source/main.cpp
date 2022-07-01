#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "level.h"
#include "systeminfo.cpp"
#include "md5.cpp"
using namespace std;

///////////////////////////////////////////////

void Colour::red(const char *s) {
    printf("\033[0m\033[1;31m%s\033[0m", s);
}

void Colour::green(const char *s) {
    printf("\033[0m\033[1;32m%s\033[0m", s);
}

void Colour::yellow(const char *s) {
    printf("\033[0m\033[1;33m%s\033[0m", s);
}

void Colour::blue(const char *s) {
    printf("\033[0m\033[1;34m%s\033[0m", s);
}

void Colour::pink(const char *s) {
    printf("\033[0m\033[1;35m%s\033[0m", s);
}

void Colour::cyan(const char *s) {
    printf("\033[0m\033[1;36m%s\033[0m", s);
}

void Alert::info(const char *s) {
    printf("%s %s\n", this->_info, s);
}
void Alert::info2(const char *s) {
    printf("%s %s\n", this->_info2, s);
}
void Alert::warning(const char *s) {
    printf("%s %s\n", this->_warning, s);
}
void Alert::error(const char *s) {
    printf("%s %s\n", this->_error, s);
}
void Alert::debug(const char *s) {
    printf("%s %s\n", this->_debug, s);
}
void Alert::success(const char *s) {
    printf("%s %s\n", this->_success, s);   
}
void Alert::fail(const char *s) {
    printf("%s %s\n", this->_fail, s);
}

///////////////////////////////////////

Colour color;
Alert alert;
MD5 md5;

bool Level1::level1() {
    string password, username;
    while (true) {
        system("cls");
        color.green("Level 1 - Easy");
        cout << "Username :";cin >> username;cout << "\n";
        cout << "Password :";cin >> password;cout << "\n";
        if ((username == this->username) && (password == this->password)) {
            alert.success("Login Success!");
            return true;
        } else {
            alert.fail("Password or username incorrect!");
            system("pause");
            continue;
        }
    }
    return false;
}

bool Level2::level2() {
    string password, username, hwidI;
    while (true) {
        system("cls");
        color.blue("Level 2 - Normal");  
        cout << "Username :";cin >> username;cout << "\n";
        cout << "Password :";cin >> password;cout << "\n";  
        cout << "Reg ID:";cin >> hwidI;cout << "\n";
        if ((md5.encode(username)==this->uSeRnAmE) && (md5.encode(password)==this->pAsSwOrD) && (verfiy1(hwidI) == true) && (verfiy2(hwidI) == true)) {
            cout << "\u004c\u006f\u0067\u0069\u006e\u0020\u0053\u0075\u0063\u0063\u0065\u0073\u0073" << "\n";
            cout << "\u0049\u0020\u0063\u0061\u006e\u0027\u0074\u0020\u0062\u0065\u006c\u0069\u0065\u0076\u0065\u0020\u0079\u006f\u0075\u0020\u0070\u0061\u0073\u0073\u0065\u0064\u002c\u0020\u0066\u006c\u0061\u0067\u007b\u0062\u0063\u0065\u0033\u0031\u0039\u0063\u0033\u0066\u0032\u0033\u0030\u0064\u0064\u0062\u0035\u0062\u0031\u0037\u0036\u0033\u0065\u0030\u0034\u0033\u0064\u0039\u0062\u0034\u0063\u0038\u0030\u007d" << "\n";
            return true;
        } else {
            cout << "\u004c\u006f\u0067\u0069\u006e\u0020\u0046\u0061\u0069\u006c" << "\n";
            system("cls");
            continue;
        }
    }
    return false;
}

string Level2::generateHWID() {
    int a, b, c, d, e, f, g;
    char *HWID;
    const char *cpuType = getCpuType().data();
    const char *cpuManufactureID = getManufactureID().data();
    const char *mac;
    const char *encrypted = md5.encode(HWID).data(); //a8f5f167f44f4964e6c998dee827110c 18 14
    const char *hd_seiral = execCmd("\u0077\u006d\u0069\u0063\u0020\u0070\u0061\u0074\u0068\u0020\u0077\u0069\u006e\u0033\u0032\u005f\u0070\u0068\u0079\u0073\u0069\u0063\u0061\u006c\u006d\u0065\u0064\u0069\u0061\u0020\u0067\u0065\u0074\u0020\u0053\u0065\u0072\u0069\u0061\u006c\u004e\u0075\u006d\u0062\u0065\u0072").data();
    const char *cpuManufactureID;
    char *result;
    mac = getNetworkInfo();
    sprintf(HWID, "\u0063\u0070\u0075\u0054\u0079\u0070\u0065\u003a%s\u0020\u007c\u0020\u0063\u0070\u0075\u004d\u0061\u006e\u0049\u0044\u003a\u0020%s\u0020\u007c\u0020\u0068\u0064\u0073\u003a\u0020%s\u0020\u007c\u0020\u006d\u0061\u0063\u003a\u0020%s\u0020\u007c\u0020\u006b\u0065\u0079\u003a%s\u0020\u003e\u0020\u006b\u0065\u0079\u006e\u0075\u006d\u003a\u0020%s", cpuType, cpuManufactureID, hd_seiral, mac, KEY);
    a = strlen(mac) + strlen(HWID) + strlen(encrypted) + strlen(hd_seiral) + strlen(cpuManufactureID) + strlen(cpuType);b = 123;c = a - b + a + (b * 10) - a * 2;d = ((a + b) * (a - b)) + ((a + b) * 4);e = d + c + b * 2 - 1000;f = e;g = f;
    string result;
    sprintf(result, "%s %d",encrypted,a);
    return result;
}

bool Level2::verfiy1(string s) {
    string hwid;
    hwid = this->generateHWID();
    try {
        for (int i = 16;i <= 32;i++) {
            if (s[i] == hwid[i]) {
                continue;
            } else {
                return false;
                //2rd verfiy fail
            }
        }
        return true;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

bool Level2::verfiy2(string s) {
    string hwid;
    hwid = this->generateHWID();
    try {

        for (int i = 16;i <= 32;i++) {
            if (s[i] == hwid[i]) {
                continue;
            } else {
                return false;
                //2rd verfiy fail
            }
        }
        return true;
        
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

bool Level3::level3() {
    system("powershell curl -o Level3.py https://raw.githubusercontent.com/B1n9Y1/CM-Crack-Me/main/download/Level3.exe");
    cout << "\u0059\u006f\u0075\u0020\u006e\u0065\u0065\u0064\u0020\u0074\u006f\u0020\u0067\u0065\u0074\u0020\u0074\u0068\u0065\u0020\u0066\u006c\u0061\u0067\u0020\u0069\u006e\u0020\u0074\u0068\u0065\u0020\u006e\u0065\u0077\u006c\u0079\u0020\u006f\u0070\u0065\u006e\u0065\u0064\u0020\u0050\u0079\u0074\u0068\u006f\u006e\u0020\u0061\u0070\u0070\u006c\u0069\u0063\u0061\u0074\u0069\u006f\u006e" << endl;
    cout << "\u0047\u006f\u006f\u0064\u0020\u004c\u0075\u0063\u006b" << endl;
    cout << "\u0050\u0079\u0074\u0068\u006f\u006e\u0020\u0061\u0070\u0070\u006c\u0069\u0063\u0061\u0074\u0069\u006f\u006e\u0020\u0069\u0073\u0020\u0064\u006f\u0077\u006e\u006c\u006f\u0061\u0064\u0065\u0064\u0020\u0066\u0072\u006f\u006d\u0020\u0047\u0069\u0074\u0048\u0075\u0062\u002e\u0020\u0049\u0066\u0020\u0079\u006f\u0075\u0020\u0063\u0061\u006e\u0027\u0074\u0020\u0064\u006f\u0077\u006e\u006c\u006f\u0061\u0064\u0020\u0069\u0074\u002c\u0020\u0070\u006c\u0065\u0061\u0073\u0065\u0020\u0063\u0068\u0065\u0063\u006b\u0020\u0079\u006f\u0075\u0072\u0020\u006e\u0065\u0074\u0077\u006f\u0072\u006b" << endl;
    return true;
}


//////////////////////

int main() {
    Level1 level1;
    Level2 level2;
    Level3 level3;

    int choiced = choice();
    bool result;
    if (choiced == 1) {
        result = level1.level1();
        if (result) {
            color.green("Well done! flag{bce319c3f230ddb5b1763e043d9b4c80}");
            return 0;            
        } else {
            alert.error("illegal return");
            return 1;               
        }
    } else if (choiced == 2) {
        result = level2.level2();
        if (result) {
            return 0;            
        } else {
            return 1;               
        }  
    } else if (choiced == 3) {
        level3.level3();
        cout << "bye" << endl;
        return 0;
    } else if (choice == 0) {
        return 0;        
    } else {
        alert.error("illegal return");
        return 1;        
    }

    return 0;
}

int choice() {
    while (true) {
        system("cls");
        alert.info("Choose the Level");
        alert.info("Press Ctrl+C or input \"exit\" to exit the program");
        color.blue("typer");
        cout << " >";
        string input;
        cout << "\n";
        cin >> input;
        if (input == "Level3" || "level3" || "3")
            return 1;
        else if (input == "Level3" || "level3" || "3")
            return 2;
        else if (input == "Level3" || "level3" || "3")
            return 3;
        else if (input == "exit")
            return 0;
        else
            cout << "what the fuck is " << input << endl;
            continue;
    }
}
