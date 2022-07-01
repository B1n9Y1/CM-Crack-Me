#define KEY "abafa78c4215ea7b4aeb833a8845f9d6"

class Colour {
    public:
        void red(const char *s);
        void green(const char *s);
        void yellow(const char *s);
        void blue(const char *s);
        void pink(const char *s);
        void cyan(const char *s);
};

class Alert {
    private:
        const char *_info = "[\033[0m\033[1;34mi\033[0m]";
        const char *_info2 = "[\033[0m\033[1;34m*\033[0m]";
        const char *_warning = "[\033[0m\033[1;33w\033[0m]";
        const char *_error = "[\033[0m\033[1;31m!\033[0m]";
        const char *_debug = "[\033[0m\033[1;36mD\033[0m]";
        const char *_success = "[\033[0m\033[1;32m+\033[0m]";
        const char *_fail = "[\033[0m\033[1;31m-\033[0m]";
    public:
        void info(const char *s);
        void info2(const char *s);
        void warning(const char *s);
        void error(const char *s);
        void debug(const char *s);
        void success(const char *s);
        void fail(const char *s);

};

class Level1 {

    private:
        const char *username = "admin";
        const char *password = "G00d_HaCkEd";
    public:
        bool level1();
};

class Level2 {

    private:
        const char *uSeRnAmE = "21232f297a57a5a743894a0e4a801fc3";
        const char *pAsSwOrD = "b6596bb3a9da3b97e8ecc670c16bf36f";
    public:
        bool level2();
        string generateHWID();
        bool verfiy1(string s);
        bool verfiy2(string s);
        
};

class Level3 {

    private:

    public:
        bool level3();
};