#include "tensorflow/lite/micro/examples/micro_speech/command_responder.h"


// Toggles the built-in LED every inference, and lights a colored LED depending
// on which word was detected.
void RespondToCommand(tflite::ErrorReporter* error_reporter,
                      int32_t current_time, const char* found_command,
                      uint8_t score, bool is_new_command) {
  static bool is_initialized = false;

  static int32_t last_command_time = 0;
  static int count = 0;
  static int certainty = 220;

    TF_LITE_REPORT_ERROR(error_reporter, "Heard %s (%d) @%dms", found_command,
                         score, current_time);
  if (is_new_command) {
    // If we hear a command, light up the appropriate LED
    //if (found_command[0] == 'y') {
    //  last_command_time = current_time;
    //  digitalWrite(LEDG, LOW);  // Green for yes
    //}
/*
    if (found_command[0] == 'n') {
      last_command_time = current_time;
      digitalWrite(LEDR, LOW);  // Red for no
    }

    if (found_command[0] == 'u') {
      last_command_time = current_time;
      digitalWrite(LEDB, LOW);  // Blue for unknown
    }*/
  }

  // If last_command_time is non-zero but was >3 seconds ago, zero it
  // and switch off the LED.
  /*
  if (last_command_time != 0) {
    if (last_command_time < (current_time - 3000)) {
      last_command_time = 0;
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDB, HIGH);
    }
    // If it is non-zero but <3 seconds ago, do nothing.
    return;
  }*/

  // Otherwise, toggle the LED every time an inference is performed.

  ++count;
  /*
  if (count & 1) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }*/
}
