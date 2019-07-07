
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `MAX30105` class instance
    auto sensor = getValue<input_DEV>(ctx);

    sensor->setup(getValue<input_PWR>(ctx),
                  getValue<input_SA>(ctx),
                  getValue<input_LED>(ctx),
                  getValue<input_SR>(ctx),
                  getValue<input_PW>(ctx),
                  getValue<input_ADC>(ctx));
    emitValue<output_DONE>(ctx,1);
}
