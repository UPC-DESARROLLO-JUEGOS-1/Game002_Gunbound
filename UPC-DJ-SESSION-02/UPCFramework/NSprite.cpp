#include "NSprite.h"
#include "NFramework.h"
#include "NShaderManagment.h"
#include "NSpriteShader.h"
#include "dtSpriteVertex.h"

void NSprite::Initialize(float x, float y, const std::string path) {
	NDrawable2D::Initialize(x, y);

	NFramework* framework = NFramework::GET_FRAMEWORK();
	NContentManagement* contentManagement = framework->GetContentManagement();
	NShaderManagment* shaderManagement = framework->GetShaderManagment();

	const std::string baseShaderPath = "Shaders/SpriteShader";
	mCurrentShader = shaderManagement->LoadAndGetShader<NSpriteShader>(baseShaderPath);
	
	mContent = contentManagement->LoadAndGetContent<NImageContent>(path);
	mWidth = mContent->GetWidth();
	mHeight = mContent->GetHeight();

	dtSpriteVertex vertexData[6]; // 3 vertices por triangluo, 2 triangulos/quad
	// ::: PRIMER TRIANGULO :::
	// primer vertice
	vertexData[0].SetPosition(mWidth, mHeight);
	vertexData[0].SetColor(255, 255, 255, 255);
	vertexData[0].SetUV(1.0f, 1.0f);
	// segundo vertice
	vertexData[1].SetPosition(0, mHeight);
	vertexData[1].SetColor(255, 255, 255, 255);
	vertexData[1].SetUV(0.0f, 1.0f);
	// tercer vertice
	vertexData[2].SetPosition(0, 0);
	vertexData[2].SetColor(255, 255, 255, 255);
	vertexData[2].SetUV(0.0f, 0.0f);

	// ::: SEGUNDO TRIANGULO :::
	// primer vertice
	vertexData[3].SetPosition(0, 0);
	vertexData[3].SetColor(255, 255, 255, 255);
	vertexData[3].SetUV(0.0f, 0.0f);
	// segundo vertice
	vertexData[4].SetPosition(mWidth, 0);
	vertexData[4].SetColor(255, 255, 255, 255);
	vertexData[4].SetUV(1.0f, 0.0f);
	// tercer vertice
	vertexData[5].SetPosition(mWidth, mHeight);
	vertexData[5].SetColor(255, 255, 255, 255);
	vertexData[5].SetUV(1.0f, 1.0f);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void NSprite::Draw(float dt) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	mCurrentShader->Use();

	GLuint wvpLocation = mCurrentShader->GetUniformLocation("wvp");
	glm::mat4 cameraMatrix = mRenderCamera->GetResultMatrix();
	glm::mat4 resulMatrix = cameraMatrix * mWorldMatrix;
	// Pasamos la data de la matrix al shader
	glUniformMatrix4fv(wvpLocation, 1, GL_FALSE, &(resulMatrix[0][0]));

	// activo la textura
	glActiveTexture(GL_TEXTURE0);
	// Hago binding de la textura a la GPU
	glBindTexture(GL_TEXTURE_2D, mContent->GetTextureId());

	glBindBuffer(GL_ARRAY_BUFFER, mVBO_ID);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(dtSpriteVertex),
		(void*)offsetof(dtSpriteVertex, Position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(dtSpriteVertex),
		(void*)offsetof(dtSpriteVertex, Color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, sizeof(dtSpriteVertex),
		(void*)offsetof(dtSpriteVertex, UV));

	// Dibuja en pantalla
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	mCurrentShader->Unuse();
}