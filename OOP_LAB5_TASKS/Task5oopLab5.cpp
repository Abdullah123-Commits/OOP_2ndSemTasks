
#include <iostream>

class Car {
private:
    int engine_hp;
    int seating_capacity;
    int no_of_speakers;

public:
    Car(int hp, int seats, int speakers) : engine_hp(hp), seating_capacity(seats), no_of_speakers(speakers) {}

    void updateAttributes(int& hp_ref, int& seats_ref, int& speakers_ref, int hp, int seats, int speakers) const {
        hp_ref = hp;
        seats_ref = seats;
        speakers_ref = speakers;
    }

    int& get_hp_ref() { return engine_hp; }
    int& get_seats_ref() { return seating_capacity; }
    int& get_speakers_ref() { return no_of_speakers; }

    void display() const {
        std::cout << "Engine HP: " << engine_hp << "\n";
        std::cout << "Seating Capacity: " << seating_capacity << "\n";
        std::cout << "Number of Speakers: " << no_of_speakers << "\n";
    }
};

int main() {
    Car myCar(200, 5, 4);
    myCar.display();
    myCar.updateAttributes(myCar.get_hp_ref(), myCar.get_seats_ref(), myCar.get_speakers_ref(), 250, 7, 10);
        std::cout << "\nAfter Updating\n";

    myCar.display();
    
    return 0;
}
