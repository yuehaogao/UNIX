#include "everything.h"

int main(int argc, char* argv[]) {
    const int N = 20;        // Number of harmonics
    float phase = 0;
    float note = 60; 
    float frequency = mtof(note);
    const int durationInSec = 5;

    int sampleCount = SAMPLE_RATE * durationInSec;
    while (sampleCount > 0) {
        // Computer value and do phase increment
        float v = 0;
        for (int n = 1; n <= N; n++) {
            float harmonicPhase = phase * n;        // Harmonic phase
            v += sin(harmonicPhase) / (float)(n);   // Sum of harmonics
        }
        v *= 0.5;                                   // Normalize
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
