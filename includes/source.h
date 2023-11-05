#pragma once
#include <vector>

#include "../resources/includes/openal/al.h"
#include "../resources/includes/openal/alc.h"

#include "exceptions.h"
#include "listener.h"

namespace GeoAudio {
enum class AudioFormat {
    MONO8 = AL_FORMAT_MONO8,
    MONO16 = AL_FORMAT_MONO16,
    STEREO8 = AL_FORMAT_STEREO8,
    STEREO16 = AL_FORMAT_STEREO16
};

class AudioContext {
  private:
    ALCdevice *mDevice = nullptr;
    ALCcontext *mContext = nullptr;
    Listener mListener;

  public:
    AudioContext();
    ~AudioContext();

    void SetCurrent() const { alcMakeContextCurrent(mContext); }

    const Listener &GetListener() const { return mListener; }
    Listener &GetListener() { return mListener; }
};

class AudioSource {
  private:
    ALuint mBuffer = 0;
    ALuint mSource = 0;
    AudioFormat mFormat;
    std::vector<ALshort> mBufferData;
    std::vector<float> mPosition;
    std::vector<float> mVelocity;
    std::vector<float> mDirection;
    float mPitch = 1.0f;
    float mVolume = 1.0f;
    float mPlayPoint = 0.0f;
    bool mLooping = false;

  public:
    AudioSource(AudioFormat format);
    ~AudioSource();

    void SetBuffer(const std::vector<ALshort> &data, ALsizei frequency);
    void SetBuffer(const ALshort *data, ALsizei size, ALsizei frequency);
    void SetLooping(bool loop);
    void SetPitch(float pitch);
    void SetPosition(float x, float y, float z);
    void SetPosition(const std::vector<float> &position);
    void SetVelocity(float x, float y, float z);
    void SetVelocity(const std::vector<float> &velocity);
    void SetVolume(float volume);
    void SetPlayPoint(float seconds);

    const std::vector<ALshort> &GetBuffer() const { return mBufferData; }
    std::vector<float> GetPosition() { return mPosition; }
    std::vector<float> GetVelocity() { return mVelocity; }
    std::vector<float> GetDirection() { return mDirection; }
    float GetPitch() { return mPitch; }
    float GetVolume() { return mVolume; }
    float GetPlayPoint() { return mPlayPoint; }
    size_t GetBufferSize() { return mBufferData.size(); }
    ALuint GetBufferID() { return mBuffer; }
    ALuint GetSourceID() { return mSource; }

    bool IsPlaying() const { return mLooping; }

    void Play();
    void Stop();
    void Pause();
    void Rewind();
};
} // namespace GeoAudio
