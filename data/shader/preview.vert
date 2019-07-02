in vec3 position;
in vec3 normal;

out vec3 fragNormal;

uniform mat4 mvp;

void main() {
    fragNormal = normal;
    gl_Position = mvp * vec4(position, 1.0);
}
