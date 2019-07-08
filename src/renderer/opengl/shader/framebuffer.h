#pragma once
#include <opengl.h>
#include <optional>
class Framebuffer {
    GLuint id;

   public:
    static GLuint currentId;

    Framebuffer(GLuint colorTexture, std::optional<GLuint> depthTexture = std::nullopt);
    ~Framebuffer();

    void bind();
    GLuint get();
};