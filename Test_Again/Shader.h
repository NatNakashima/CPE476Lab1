#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include <map>
#include <string>
#include <vector>

#include "gl_adapters/buffer_object.h"
#include "gl_adapters/gl_shader.h"

struct Shader {
   Shader(
         const std::string& name,
         const std::vector<std::string>& attributes,
         const std::vector<std::string>& uniforms);

   template <typename T>
   ArrayBufferObject createArrayBufferObject(
         const std::vector<T>& data,
         const std::string& attribute,
         size_t num_components) {
      return ArrayBufferObject{createBufferObject(data), attribute_locations_.at(attribute), num_components};
   }

   void use();

   void bindIndexBuffer(const IndexBufferObject& index_buffer);
   void bindAndEnableAttributes(const std::vector<ArrayBufferObject>& array_buffer_objects);
   void disableAttributes(const std::vector<ArrayBufferObject>& array_buffer_objects);

  private:
   GLShader gl_shader_;
   std::map<std::string, GLint> attribute_locations_;
   std::map<std::string, GLint> uniform_locations_;
};

#endif // SHADER_H_