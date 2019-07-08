#include "framebuffer.h"
#include <cstdio>

GLuint Framebuffer::currentId = 0;

Framebuffer::Framebuffer(GLuint colorTexture, std::optional<GLuint> depthTexture) {
    GLint currentFramebuffer;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &currentFramebuffer);

    glGenFramebuffers(1, &id);
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexture, 0);

    if (depthTexture) {
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, *depthTexture, 0);
    }

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        printf("[GL] Framebuffer is not complete!\n");
    }

    glBindFramebuffer(GL_FRAMEBUFFER, currentFramebuffer);
}

Framebuffer::~Framebuffer() { glDeleteFramebuffers(1, &id); }

void Framebuffer::bind() {
    if (currentId != id) {
        currentId = id;
        glBindFramebuffer(GL_FRAMEBUFFER, id);
    }
}

GLuint Framebuffer::get() { return id; }