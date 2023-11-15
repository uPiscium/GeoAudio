#include "../includes/source.hpp"

namespace GeoAudio {
AudioContext::AudioContext() {
    mDevice = alcOpenDevice(nullptr);
    if (!mDevice) {
        _AUDIO_THROW(AudioDeviceException("Failed to open device"));
    }
    mContext = alcCreateContext(mDevice, nullptr);
    if (!mContext) {
        _AUDIO_THROW(AudioContextException("Failed to create context"));
    }
    alcMakeContextCurrent(mContext);
    mListener = Listener();
}

AudioContext::~AudioContext() {
    alcMakeContextCurrent(nullptr);
    if (mContext) {
        alcDestroyContext(mContext);
    }
    if (mDevice) {
        alcCloseDevice(mDevice);
    }
}

AudioSource::AudioSource(AudioFormat format) : mFormat(format) {
    alGenBuffers(1, &mBuffer);
    alGenSources(1, &mSource);
}

AudioSource::~AudioSource() {
    alSourcei(mSource, AL_BUFFER, 0);
    alDeleteSources(1, &mSource);
    alDeleteBuffers(1, &mBuffer);
}

void AudioSource::SetBuffer(const std::vector<ALshort> &data,
                            ALsizei frequency) {
    mBufferData = data;
    alBufferData(mBuffer, (ALenum)mFormat, &data[0],
                 data.size() * sizeof(ALshort), frequency);
    alSourcei(mSource, AL_BUFFER, mBuffer);
}
void AudioSource::SetBuffer(const ALshort *data, ALsizei size,
                            ALsizei frequency) {
    mBufferData = std::vector<ALshort>(data, data + size);
    alBufferData(mBuffer, (ALenum)mFormat, data, size * sizeof(ALshort),
                 frequency);
    alSourcei(mSource, AL_BUFFER, mBuffer);
}

void AudioSource::SetLooping(bool loop) {
    mLooping = loop;
    alSourcei(mSource, AL_LOOPING, mLooping);
}
void AudioSource::SetPitch(float pitch) {
    mPitch = pitch;
    alSourcef(mSource, AL_PITCH, mPitch);
}
void AudioSource::SetPosition(const std::vector<float> &position) {
    mPosition = position;
    alSourcefv(mSource, AL_POSITION, &mPosition[0]);
}
void AudioSource::SetPosition(float x, float y, float z) {
    mPosition = {x, y, z};
    alSourcefv(mSource, AL_POSITION, &mPosition[0]);
}
void AudioSource::SetVelocity(const std::vector<float> &velocity) {
    mVelocity = velocity;
    alSourcefv(mSource, AL_VELOCITY, &mVelocity[0]);
}
void AudioSource::SetVelocity(float x, float y, float z) {
    mVelocity = {x, y, z};
    alSourcefv(mSource, AL_VELOCITY, &mVelocity[0]);
}
void AudioSource::SetVolume(float volume) {
    if (volume < 0.0f || volume > 1.0f) {
        _AUDIO_THROW(InvalidAudioArgumentException(
            "Volume must be between 0.0 and 1.0"));
    }
    mVolume = volume;
    alSourcef(mSource, AL_GAIN, mVolume);
}
void AudioSource::SetPlayPoint(float seconds) {
    mPlayPoint = seconds;
    alSourcef(mSource, AL_SEC_OFFSET, mPlayPoint);
}

void AudioSource::Play() {
    alSourcei(mSource, AL_BUFFER, mBuffer);
    alSourcePlay(mSource);
}
void AudioSource::Stop() { alSourceStop(mSource); }
void AudioSource::Pause() { alSourcePause(mSource); }
} // namespace GeoAudio
