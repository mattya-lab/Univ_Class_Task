#include "bits/stdc++.h"

using namespace std;

/*
 * 3pi-linefollower - demo code for the Pololu 3pi Robot
 *
 * This code will follow a black line on a white background, using a
 * very simple algorithm. It demonstrates auto-calibration and use of
 * the 3pi IR sensors, motor control, bar graphs using custom
 * characters, and music playback, making it a good starting point for
 * developing your own more competitive line follower.
 *
 * http://www.pololu.com/docs/0J21
 * http://www.pololu.com
 * http://forum.pololu.com
 *
 */

// The 3pi include file must be at the beginning of any program that
// uses the Pololu AVR library and 3pi.
#include<pololu/3pi.h>

// This include file allows data to be stored in program space. The
// ATmegaxx8 has 16x more program space than RAM, so large
// pieces of static data should be stored in program space.
#include<avr/pgmspace.h>

// Introductory messages. The "PROGMEM" identifier causes the data to
// go into program space.
const char welcome_line1[] PROGMEM = " Pololu";
const char welcome_line2[] PROGMEM = "3\xf Robot";
const char demo_name_line1[] PROGMEM = "line";
const char demo_nameline2[] PROGMEM = "follower";

// A couple of simple tunes, stored in program space.
const char welcome[] PROGMEM = ">g32>>c32";
const char go[] PROGMEM = "L16 cdegreg4";

// Data for generating the characters used in load_custom_characters
// and display_readings. By reading levels[] starting at various
// offsets, we can generate all of the 7 extra characters needed for a
// bargraph. This is also stored in program space.
const char levels[] PROGMEM = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
};

// This function loads custom characters into the LCD. UP to 8
// characters can be loaded; we use them for 7 levels of a bar graph.
void load_custom_characters() {
    lcd_load_custom_character(levels + 0, 0);
    lcd_load_custom_character(levels + 1, 1);
    lcd_load_custom_character(levels + 2, 2);
    lcd_load_custom_character(levels + 3, 3);
    lcd_load_custom_character(levels + 4, 4);
    lcd_load_custom_character(levels + 5, 5);
    lcd_load_custom_character(levels + 6, 6);
    lcd_load_custom_character(levels + 7, 7);
}

// This function desplays the sensor reading using a bar graph.
void display_readings(const unsigned int* calibrated_values) {
    unsigned char i;
    for (i = 0; i < 5; i++) {
        // Initialize the array of characters that we will use for the 
        // graph. Using the space, an extra copy of the one-bar
        // characters in the array.
        const char display_characters[10] = { ' ', 0, 0, 1, 2, 3, 4, 5, 6, 255 };

        // The variable c will have values from 0 to 9, since
        // calibrated values are in the range of 0 to 1000, and
        //1000/101 is 9 with integer math.
        char c = display_characters[calibrated_values[i] / 101];

        // Display the bar graph character.
        print_character(c);
    }
}

// Initialize the 3pi, displays a welcome message, calibrates, and
// plays the initial music.
void initialize() {
    unsigned int counter;   // used as a simple timer
    unsigned int sensor[5]; // an array to hold sensors values

    // This must be called at the beginning of the 3pi code, to set up the
    // sensors. We used a value of 2000 for the timeout, which
    // corresponds to 2000*0.4 us = 0.8 ms on our 20 MHz processor.
    pololu_3pi_init(2000);
    load_custom_characters(); // load the custom characters

    // Play welcome music and display a message
    print_from_program_space(welcome_line1);
    lcd_goto_xy(0, 1);
    print_from_program_space(welcome_line2);
    play_from_program_space(welcome);
    delay_ms(1000);

    clear();
    print_from_program_space(demo_name_line1);
    lcd_goto_xy(0, 1);
    print_from_program_space(demo_name_line2);
    delay_ms(1000);

    // Display battery voltage and wait for button press
    while (!button_is_pressed(BUTTON_B))
    {
        int bat = read_battery_millvolts();

        clear();
        print_long(bat);
        print("mV");
        lcd_goto_xy(0, 1);
        print("Press B");

        delay_ms(100);
    }

    // Always wait for the button to released so that 3pi doesn't 
    // start moving until your hand is away from it.
    wait_for_button_release(BUTTON_B);
    delay_ms(100);

    // Auto-calibration: turn right and left while calibrating the
    // sensors.
    for ( counter = 0; counter < 80; counter++)
    { 
        if (counter < 20 || counter >= 60)
            set_motors(40, -40);
        else
            set_motors(-40, 40);

        // This function records a set of sensor reading and keeps
        // track of the minimum and maximum values encountered. The
        // IR_EMITTERS ON argument means that the IR LEDs will be
        // turned on during the reading, which is usually what you
        // want
        calibrate_line_sensors(IR_EMITTERS_ON);

        // since our counter runs to 80, the total delay will be 
        // 80 * 20 = 1600 ms.
        delay_ms(20);
    }
    set_motors(0, 0);

    // Display calibrated values as a bar graph.
    while (!button_is_pressed(BUTTON_B))
    {
        // Read the sensor values and get the position measurement.
        unsigned int position = read_line(sensors, IR_EMITTERS_ON);
        
        // Display the position measurement, which will go from 0
        // (when the leftmost sensor is over the line) to 4000 (when
        // the rightmost sensor is over the line) on the 3pi, along
        // with a bar graph of the sensor readings. This allows you
        // to make sure the robot is ready to go.
        clear();
        print_long(position);
        lcd_goto_xy(0, 1);
        display_readings(sensors);

        delay_ms(100);
    }
    wait_for_button_release(BUTTON_B);

    clear();

    print("GO!");

    // Play music and wait for it to finish before we start driving.
    play_from_program_space(go);
    while (is_playing());
}

// This is the main function, where the code starts. All c programs
// must have a main() function defined somewhere.
int main()
{
    unsigned int sensors[5]; // an array to hold sensor values

    // set up the 3pi
    initialize();

    // This is the "main loop" - it will run forever.
    while (1)
    {
        // Get the position of the line. Note that we *must* provide 
        // the "sensors" argument to read_line() here, even though we
        // are not interested in the individual sensor readings.
        unsigned int position = read_line(sensors, IR_EMITTERS_ON);

        if (position < 1000)
        {
            // We are far to the right of the line: turn left.

            // Set the right motor to 100 and the left motor to zero,
            // to do a sharp turn to the left. Note that the maximum
            // values of either motor speed is 255, so we are driving
            // it at just about 40% of the max.
            set_motors(0, 100);

            //Just for run, indicate the direction we are turning on
            // the LEDs.
            left_led(1);
            right_led(0);
        }
        else if (position < 3000)
        {
            // We are somewhat close to being centered on the line:
            // drive straight.
            set_motors(100, 100);
            left_led(1);
            right_led(1);
        }
        else
        {
            // We are far to the left of the line: turn right.
            set_motors(100, 0);
            left_led(0);
            right_led(1);
        }
    }

    // This part of the code is never reached. A robot should
    // never reach the end of its program, or unpredictable behavior
    // will result as random code starts getting executed. If you
    // really want to stop all actions at some point, set your motors
    // to 0, 0 and run the following command to loop forever:
    //
    // while(1);
}
, 

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
