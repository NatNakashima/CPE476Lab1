#ifndef GAME_H_
#define GAME_H_

#include <glm/glm.hpp>
#include <vector>

#include "camera.h"
#include "free_type_engine.h"
#include "graphics/gl_adapters/uniform_matrix.h"
#include "game_object.h"
#include "GroundPlane.h"
#include "input.h"
#include "graphics/mesh.h"
#include "SDLEngine.h"
#include "graphics/Shaders.h"
#include "units.h"

class Game {
   SDLEngine engine_;
   Shaders shaders_;
   GroundPlane ground_plane_;
   std::vector<GameObject> game_objects_;

   UniformMatrix projection_;
   Camera camera_;
   Mesh cube_mesh_;
   Input input_;
   FreeTypeEngine free_type_engine_;

   int creation_countdown_;
   int score_ = 0;
   float fps_ = 0.0f;

   void step(units::MS dt);
   void draw();

  public:
   Game();

   void mainLoop();
};

#endif // GAME_H_
