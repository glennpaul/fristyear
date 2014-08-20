#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) {
    return value * value;
}

int main (void) {

    // Variables
    double Age,
           Cash;

    cout << "How old are you? " << endl;
    cin >> Age;
    if (Age>15) {
        cout << "Oh cool! You know who was 15 once? Paul! You should go buy hi some food and discuss this as you guys eat." << endl;
    } else {
        cout << "You're young! Respect Paul since he's your elder. A proper way of showing respect is buying him something to drink. An Ice Cap from Timmies perhaps?";
    } // end if
    cout << endl;
    cout << "Don't have that much money? How much money do you have?" << endl;
    cin >> Cash;
    if (Cash>3) {
        cout << "That's enough for an Ice Cap! Go buy him one. Snippity Snap, you slave. Umm, I mean friend.";
    } else {
        cout << "Go get a job, you bum. Then buy Paul some food! :3";
    } // end if
    cout << endl;
    cout << "Oh yeah, this program cost 3$ to run. Pay by buying Paul some food. You're a true friend. <3";

    system("PAUSE"); return 0;

}
