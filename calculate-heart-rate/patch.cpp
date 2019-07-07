
struct State {
    const byte RATE_SIZE; //Increase this for more averaging. 4 is good.
    uint8_t rates[RATE_SIZE]; //Array of heart rates
    uint8_t rateSpot;
    long lastBeat; //Time at which the last beat occurred
    float beatsPerMinute;
    int beatAvg;
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // get state
    State* state = getState(ctx);

    if (isSettingUp())
    {
        state->RATE_SIZE = 4;
        state->rates[state->RATE_SIZE];
        state->rateSpot = 0;
        state->lastBeat = 0;
    }

    long irValue = getValue<input_IR>(ctx);
    
    if (checkForBeat(irValue) == true)
    {
        //We sensed a beat!
        emitValue<output_BEAT>(ctx,1);
        long delta = millis() - state->lastBeat;
        state->lastBeat = millis();
        state->beatsPerMinute = 60 / (delta / 1000.0);
        if (state->beatsPerMinute < 255 && state->beatsPerMinute > 20)
        {
            state->rates[state->rateSpot++] = (uint8_t)state->beatsPerMinute; //Store this reading in the array
            state->rateSpot %= state->RATE_SIZE; //Wrap variable
            //Take average of readings
            state->beatAvg = 0;
            for (byte x = 0 ; x < state->RATE_SIZE ; x++)
                state->beatAvg += state->rates[x];
            state->beatAvg /= state->RATE_SIZE;
            emitValue<output_BPM>(ctx,state->beatsPerMinute);
            emitValue<output_AvgBPM>(ctx,state->beatAvg);
        }
    }
    emitValue<output_DONE>(ctx,1);
}
