#include "../includes/listener.hpp"

namespace GeoAudio {
Listener::Listener() {
    mPosition = {0.0f, 0.0f, 0.0f};
    mVelocity = {0.0f, 0.0f, 0.0f};
    mDirection = {0.0f, 0.0f, -1.0f};
}

Listener::~Listener() {}

void Listener::SetPosition(float x, float y, float z) {
    mPosition = {x, y, z};
    alListenerfv(AL_POSITION, &mPosition[0]);
}
void Listener::SetVelocity(float x, float y, float z) {
    mVelocity = {x, y, z};
    alListenerfv(AL_VELOCITY, &mVelocity[0]);
}
void Listener::SetDirection(float x, float y, float z) {
    mDirection = {x, y, z};
    ALfloat orientation[6] = {mDirection[0], mDirection[1], mDirection[2],
                              mUp[0],        mUp[1],        mUp[2]};
    alListenerfv(AL_ORIENTATION, orientation);
}
void Listener::SetUp(float x, float y, float z) { mUp = {x, y, z}; }
} // namespace GeoAudio
