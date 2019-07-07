
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_INIT>(ctx))
        return;

    // Get a pointer to the `MAX30105` class instance
    auto sensor = getValue<input_DEV>(ctx);

    // Attempt to initialize MAX30102 module; if attempt fails emit pulse from error port
    if (!sensor->begin(Wire, I2C_SPEED_FAST)) {
        emitValue<output_ERR>(ctx, 1);
        return;
    }

    // Pulse that module initialized successfully
    emitValue<output_OK>(ctx, 1);

}
