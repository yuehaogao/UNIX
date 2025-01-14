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
        for (int n = 1; n <= N; n += 2) {
            float harmonicPhase = phase * n;          // Harmonic phase
            v += sin(harmonicPhase) * pow(-1, ((n - 1) / 2)) * pow(n, 2);   // Sum of harmonics
        }
        v *= (8.0f / pow(pi, 2));                     // Normalize
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
