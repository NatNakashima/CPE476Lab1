#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/glm.hpp>

#include "vec_constants.h"

struct Camera {
   Camera();

   // Convert axis from local space before translate/rotate.
   void translateForward(float amount);
   void translateStrafe(float amount);
   void rotatePitch(float degrees);
   void rotateYaw(float degrees) {
      yaw_ += degrees;
   }

   glm::mat4 viewMatrix() const;

  private:
   glm::vec3 unitDirection() const;

   glm::vec3 world_position_;
   float pitch_ = 0.0f, yaw_ = 0.0f;
};

#endif // CAMERA_H_
