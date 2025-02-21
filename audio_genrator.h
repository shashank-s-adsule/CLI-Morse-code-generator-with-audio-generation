#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <string>

// Constants for audio
const int SAMPLE_RATE = 44100;          // 44.1 kHz sample rate
const double PI = 3.141592653589793;
const double TONE_FREQUENCY = 600.0;      // Tone frequency in Hz
const int BITS_PER_SAMPLE = 16;           // 16-bit audio
const int MAX_AMPLITUDE = 30000;          // Amplitude for the sine wave

// Morse code timing (in seconds)
const double DOT_DURATION = 0.1;          // Duration of a dot
const double DASH_DURATION = 0.3;         // Duration of a dash
const double INTER_ELEMENT_GAP = 0.125;     // Gap between dots and dashes

// WAV header structures
#pragma pack(push, 1)
struct WAVHeader {
    char chunkID[4] = { 'R', 'I', 'F', 'F' };
    uint32_t chunkSize;  // file size - 8 bytes
    char format[4] = { 'W', 'A', 'V', 'E' };
};

struct FmtSubchunk {
    char subchunk1ID[4] = { 'f', 'm', 't', ' ' };
    uint32_t subchunk1Size = 16;
    uint16_t audioFormat = 1;       // PCM
    uint16_t numChannels = 1;       // Mono
    uint32_t sampleRate = SAMPLE_RATE;
    uint32_t byteRate;              // = sampleRate * numChannels * bitsPerSample/8
    uint16_t blockAlign;            // = numChannels * bitsPerSample/8
    uint16_t bitsPerSample = BITS_PER_SAMPLE;
};

struct DataSubchunk {
    char subchunk2ID[4] = { 'd', 'a', 't', 'a' };
    uint32_t subchunk2Size;         // numSamples * numChannels * bitsPerSample/8
};
#pragma pack(pop)

// Function to generate a sine tone for a given duration (in seconds)
std::vector<int16_t> generateTone(double duration) {
    int numSamples = static_cast<int>(SAMPLE_RATE * duration);
    std::vector<int16_t> samples(numSamples);
    for (int i = 0; i < numSamples; i++) {
        double t = static_cast<double>(i) / SAMPLE_RATE;
        samples[i] = static_cast<int16_t>(MAX_AMPLITUDE * sin(2.0 * PI * TONE_FREQUENCY * t));
    }
    return samples;
}

// Function to generate silence for a given duration (in seconds)
std::vector<int16_t> generateSilence(double duration) {
    int numSamples = static_cast<int>(SAMPLE_RATE * duration);
    return std::vector<int16_t>(numSamples, 0);
}

// Function to encode a Morse code string (only supports '.' and '-')
// It will concatenate tone and silence segments into a single audio vector.
std::vector<int16_t> encodeMorse(std::vector<std::string>& morse) {
    std::vector<int16_t> audio;

    for(auto &str:morse)
    {
        if(str==".......")
        {
            auto gap=generateSilence(0.75);                 //for white space
            audio.insert(audio.end(),gap.begin(),gap.end());
        }
        else
        {
            for(char &c:str)
            {
                if (c == '.') {
                    // Append dot tone
                    auto dotTone = generateTone(DOT_DURATION);
                    audio.insert(audio.end(), dotTone.begin(), dotTone.end());
                    // Append gap
                    auto gap = generateSilence(INTER_ELEMENT_GAP);
                    audio.insert(audio.end(), gap.begin(), gap.end());
                } else if (c == '-') {
                    // Append dash tone
                    auto dashTone = generateTone(DASH_DURATION);
                    audio.insert(audio.end(), dashTone.begin(), dashTone.end());
                    // Append gap
                    auto gap = generateSilence(INTER_ELEMENT_GAP);
                    audio.insert(audio.end(), gap.begin(), gap.end());
                } 
                // else if (c == ' ') {
                //     // Use a longer gap to separate letters/words
                //     auto gap = generateSilence(0.3);
                //     audio.insert(audio.end(), gap.begin(), gap.end());
                // }
            }
            // append gap between letters
            auto gap=generateSilence(0.2);
            audio.insert(audio.end(),gap.begin(),gap.end());
        }
    }

    return audio;
}

void morse2audio(std::vector<std::string> &DATA, std::string &audio_dir)
{
    // encode message
    std::vector<int16_t> AudioData=encodeMorse(DATA);
    uint32_t numsamples=AudioData.size();

    //calcualate header values
    FmtSubchunk fmt;
    fmt.blockAlign=fmt.numChannels*(fmt.bitsPerSample/8);
    fmt.byteRate=fmt.sampleRate*fmt.blockAlign;

    DataSubchunk data;
    data.subchunk2Size = numsamples * fmt.blockAlign;

    WAVHeader header;
    header.chunkSize = 4 + (8 + fmt.subchunk1Size) + (8 + data.subchunk2Size);

    // open file in binary mode
    std::ofstream outFile(audio_dir, std::ios::binary);
    if(!outFile)
    {
        std:: cerr<<"\u001b[1;34m[\u001b[1;31mERROR\u001b[1;34m]:\u001b[0m Could not open file for writing.\n";
        exit(1);
    }

    // Write WAV header
    outFile.write(reinterpret_cast<const char*>(&header), sizeof(header));
    outFile.write(reinterpret_cast<const char*>(&fmt), sizeof(fmt));
    outFile.write(reinterpret_cast<const char*>(&data), sizeof(data));

    // Write audio data
    outFile.write(reinterpret_cast<const char*>(AudioData.data()), data.subchunk2Size);

    outFile.close();
}