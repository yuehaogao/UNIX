#include "everything.h"

int main(int argc, char* argv[]) {
    float phase = 0;
    float note = 60;
    float frequency = mtof(note); 
    const int durationInSec = 5;

    int sampleCount = SAMPLE_RATE * durationInSec;
    while (sampleCount > 0) {
        // Computer value and do phase increment
        float v = sin(phase);
        mono(v * 0.707);
        phase += 2 * pi * frequency / SAMPLE_RATE;

        // Wrap phase
        if (phase > 2 * pi) {       
            phase -= 2 * pi;
        }

        sampleCount--;
    }

    return 0;
}
