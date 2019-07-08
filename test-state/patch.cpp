
struct State {
    uint8_t x = 0;
    static const uint8_t rs = 4;
    uint8_t rates[rs];
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // get state
    State* state = getState(ctx);

    state->x = state->x+1;

    emitValue<output_OUT>(ctx,state->x);
    emitValue<output_RS>(ctx,state->rs);

    
    //auto inValue = getValue<input_IN>(ctx);
    //emitValue<output_OUT>(ctx, inValue);
}
