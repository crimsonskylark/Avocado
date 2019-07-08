in vec3 fragNormal;

out vec4 outColor;

void main() {
    vec3 lightDir = normalize(vec3(-1., 1, -1.));
    float lightDot = dot(fragNormal, lightDir);
    lightDot = exp(-pow(0.5*(1-lightDot), 3.5));
    outColor = vec4(vec3(lightDot), 1.0);
}
