#version 130

attribute vec2 aPosition;
attribute vec2 aTexCoord;
varying vec2 vTexCoord;
void main() {
   gl_Position = vec4(aPosition, 0, 1);
   vTexCoord = aTexCoord;
}
