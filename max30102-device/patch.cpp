// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library"

//Include C++ libraries
{{#global}}
#include <Wire.h>
#include <MAX30105.h>
#include <spo2_algorithm.h>
#include <heartRate.h>
{{/global}}

// Reserve memory to store an instance of the class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(MAX30105)];
};

// Define our custom type as a pointer on the class instance.
using Type = MAX30105*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    Type sensor = new (state->mem) MAX30105();

    emitValue<output_DEV>(ctx, sensor);
}
