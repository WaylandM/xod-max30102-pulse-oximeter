
struct State {
    const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
    byte rates[RATE_SIZE]; //Array of heart rates
    byte rateSpot = 0;
    long lastBeat = 0; //Time at which the last beat occurred
    float beatsPerMinute;
    int beatAvg;
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    //auto inValue = getValue<input_IN>(ctx);
    //emitValue<output_OUT>(ctx, inValue);
}
