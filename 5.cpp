#include <iostream>

using namespace std;

class Time {
public:
    Time(int h, int m = 0){
        setTime(h, m);
    }
    void setTime(int h, int m = 0){
        if (h < 0 || h > 23 || m < 0 || m > 59){
            abort();
        }
        hour = h;
        minute = m;
    }
    int getHour(){
        return hour;
    }
    int getMinute(){
        return minute;
    }
    int compare(Time t) {
        if ((hour > t.getHour()) || (hour == t.getHour() && minute > t.getMinute())) {
                return 1;
        }
        else if (hour == t.getHour() && minute == t.getMinute()) {
            return 0;
        }
        else {
            return -1;
        }
    }
    string dayTime() {
        if (hour < 12) {return "morning";}
        else if (hour == 12 && minute == 0) {return "noon";}
        else if (hour < 17) {return "afternoon";}
        else if (hour < 20) {return "evening";}
        else {return "night";}
    }
private:
    int hour,
        minute;
};

void menu(Time t){
    int opt;
    cout << "1: set time\n"
            "2: print time\n"
            "0: *Exit\n"
            "\nSelect an option: ";
    cin >> opt;
    if (opt == 1) {
        int h,
            m;
        cout << "\nhour: ";
        cin >> h;
        cout << "minute: ";
        cin >> m;
        t.setTime(h, m);
        cout << '\n';
    }
    else if (opt == 2){
        cout << '\n' << t.getHour() << ':' << t.getMinute() << "\nit's " << t.dayTime() << "!\n\n";
    }
    if (opt != 0){
        menu(t);
    }
}

int main(){
    Time t(0);

    menu(t);

    return 0;
}