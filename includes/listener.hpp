#pragma once
#include <vector>

#include "openal/al.h"
#include "openal/alc.h"

#include "exceptions.h"

namespace GeoAudio {
class Listener {
  private:
    std::vector<float> mPosition;
    std::vector<float> mVelocity;
    std::vector<float> mDirection;
    std::vector<float> mUp;

  public:
    Listener();
    ~Listener();

    void SetPosition(float x, float y, float z);
    void SetVelocity(float x, float y, float z);
    void SetDirection(float x, float y, float z);
    void SetUp(float x, float y, float z);

    const std::vector<float> &GetPosition() { return mPosition; }
    const std::vector<float> &GetVelocity() { return mVelocity; }
    const std::vector<float> &GetDirection() { return mDirection; }
    const std::vector<float> &GetUp() { return mUp; }
};
} // namespace GeoAudio
