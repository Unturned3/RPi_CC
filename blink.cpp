
#include <gpiod.hpp>
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    // This blinks the Camera LED (CAM_GPIO1)
    const std::string chipname = "gpiochip2";
    const unsigned int line_num = 6;
    const std::chrono::milliseconds delay(500);

    try {
        // Open the GPIO chip
        gpiod::chip chip(chipname, gpiod::chip::OPEN_BY_NAME);

        // Get the GPIO line for the ACT LED
        gpiod::line line = chip.get_line(line_num);

        // Request the line as an output and set its initial state to low
        line.request({"blink-act-led", gpiod::line_request::DIRECTION_OUTPUT, 0}, 0);

        // Blink the LED
        while (true) {
            line.set_value(1); // Turn LED on
            std::this_thread::sleep_for(delay);

            line.set_value(0); // Turn LED off
            std::this_thread::sleep_for(delay);
	    std::cout<<"HELLO" <<std::endl;
        }

    } catch (const std::system_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
