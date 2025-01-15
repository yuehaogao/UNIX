#include "everything.h"

int main(int argc, char* argv[]) {
    const int N = 20;        // Number of harmonics
    float phase = 0;

    for (float note = 127; note > 0; note -= 0.001) {
        float frequency = mtof(note);
        // Computer value and do phase increment
        float v = 0;
        for (int n = 1; n <= N; n += 2) {
            float harmonicPhase = phase * n;        // Harmonic phase
            v += sin(harmonicPhase) / (float)(n);   // Sum of harmonics
        }
        v *= (4.0f / pi);                           // Normalize
        mono(v * 0.707);
        phase += 2 * pi * frequency / SAMPLE_RATE; 
        
        // Wrap phase
        if (phase > 2 * pi) {       
            phase -= 2 * pi;
        }
    }

    return 0;
}
