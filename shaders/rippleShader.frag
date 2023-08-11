#version 130
// attributes from vertShader.vert
varying vec4 vColor;
varying vec2 vTexCoordinate;

// uniforms
uniform sampler2D uTexture;
uniform float uTime;

void main() {
	float yFloat = float(gl_FragCoord.y);
	float uFloat = float(uTime);
	float coef = sin(yFloat * 0.1 + 1 * uFloat);
	vec2 vTexCoord = vTexCoordinate;
	vTexCoord.y +=  coef * 0.03;
	gl_FragColor = vColor * texture2D(uTexture, vTexCoord);
}
