#include <LedControl.h>

const int DIN = 12;
const int CS  = 10;
const int CLK = 11;
LedControl lc = LedControl(DIN, CLK, CS, 4); // 4 displays = 32 columns

// Button & Microphone
const int buttonPin = 2;   // Button on D2 (with GND)
const int micA0     = A0;  // Sound sensor AO to A0 (not DO)

// Struct for sound metrics
struct SoundMetrics { int peak; long activity; };

// Button timing settings
const unsigned long debounceMs   = 35;
const unsigned long doubleGapMs  = 450;   // Gap between double clicks
const unsigned long longPressMs  = 1200;  // Long press threshold

bool screenOn = false;     
int  currentIntensity = 8;

void setScreen(bool on) {
  screenOn = on;
  for (int i = 0; i < 4; i++) {
    lc.shutdown(i, !on);
    if (on) lc.setIntensity(i, currentIntensity);
    lc.clearDisplay(i);
  }
}

// 32x8 Images
const uint8_t Mood[] = { /* ... */ };
const uint8_t Game[] = { /* ... */ };
const uint8_t CH12[] = { /* ... */ };
const uint8_t OneEqRand[] = { /* ... */ };
const uint8_t TwoEqSound[] = { /* ... */ };

// Scrolling text: PRESS ONCE OR TWICE
const byte FONT[][8] = { /* ... */ };
const int charCount = 19;
const int scrollSpeed = 70;

// Emojis (32x8)
const uint8_t EMO_SMILE[32] = { /* ... */ };
const uint8_t EMO_SAD[32]   = { /* ... */ };
const uint8_t EMO_ENGRY[32] = { /* ... */ };
const uint8_t EMO_QUIT[32]  = { /* ... */ };
const uint8_t* EMOJIS[] = { EMO_SMILE, EMO_SAD, EMO_ENGRY, EMO_QUIT };
const int EMO_COUNT = sizeof(EMOJIS)/sizeof(EMOJIS[0]);
const unsigned long EMO_SHOW_MS = 2000;

// Sound thresholds
int SOUND_IGNORE_TH = 40;
int SOUND_LOUD_TH   = 100;
int ACTIVITY_TH     = 1800;

// Display functions
void displayFromRowMajor(const uint8_t* input) { /* ... */ }
byte rotateCounterClockwise(const byte fontChar[8], int col) { /* ... */ }
void showWord(byte word[4][8]) { /* ... */ }
void displayScrollingFrame(int offset) { /* ... */ }

// Sound calibration
void calibrateNoise(unsigned long ms = 1500) { /* ... */ }

// Button helpers
bool buttonRaw() { return digitalRead(buttonPin) == LOW; }
void pollLongPressToggle() { /* ... */ }

// Sound measurement
SoundMetrics measureSound(unsigned long totalMs = 1200, unsigned long blankMs = 250) { /* ... */ }

// Emoji selection by sound
int pickEmojiLevel(const SoundMetrics &m) { /* ... */ }
const uint8_t* emojiByLevel(int level) { /* ... */ }

// Emoji display
void showEmoji(const uint8_t* img, unsigned long ms = EMO_SHOW_MS) { /* ... */ }
int lastRandomIdx = -1;
void showRandomEmoji() { /* ... */ }

// Pre-scroll display sequence
void playPreScrollSequence() { /* ... */ }

// Scrolling message with click/long-press handling
void runScrollMessage() { /* ... */ }

// Setup
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(micA0, INPUT);
  for (int i = 0; i < 4; i++) {
    lc.shutdown(i, true);
    lc.clearDisplay(i);
  }
  randomSeed(analogRead(A5));
  calibrateNoise();
}

// Main loop
void loop() {
  if (!screenOn) {
    pollLongPressToggle();
    delay(5);
    return;
  }
  playPreScrollSequence();
  if (!screenOn) return;
  runScrollMessage();
}
