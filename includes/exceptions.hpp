#pragma once
#include <iostream>
#include <string>

#ifdef IGNORE_AUDIO_EXCEPTIONS
#define _AUDIO_THROW(x) std::cout << x.what() << std::endl
#else
#define _AUDIO_THROW(x) throw x
#endif // IGNORE_AUDIO_EXCEPTIONS

#define CHECK_AL_ERROR() std::cout << alGetString(alGetError()) << std::endl

namespace GeoAudio {
class AudioException : public std::exception {
  private:
    std::string mMessage;

  public:
    AudioException(std::string message) : mMessage(message) {}
    const char *what() const { return mMessage.c_str(); }
};

class AudioDeviceException : public AudioException {
  public:
    AudioDeviceException(std::string message) : AudioException(message) {}
};

class AudioContextException : public AudioException {
  public:
    AudioContextException(std::string message) : AudioException(message) {}
};

class InvalidAudioArgumentException : public AudioException {
  public:
    InvalidAudioArgumentException(std::string message)
        : AudioException(message) {}
};
} // namespace GeoAudio
